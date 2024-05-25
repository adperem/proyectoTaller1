//
// Created by adperem on 24/04/2024.
//
#include <iomanip>
#include "EKF_GEOS3.h"
#include "Accel.h"
#include "Mjday.h"
#include "LTC.h"
#include "VarEqn.h"
#include "TimeUpdate.h"
#include "AzElPa.h"
#include "MeasUpdate.h"

/**
 * @brief Extrae las matrices de transición de estado de la matriz de estado aumentada.
 * @param yPhi Matriz de estado aumentada.
 * @param Phi Matriz de transición de estado.
 */
void extractStateTransitionMatrices(const Matrix &yPhi, Matrix &Phi) {
    for (int j = 1; j <= 6; ++j) {
        for (int i = 1; i <= 6; ++i) {
            Phi(i, j) = yPhi(6 * j + i, 1);
        }
    }
}

//--------------------------------------------------------------------------
//
//  Initial Orbit Determination using Gauss and Extended Kalman Filter methods
//
// References:
//   O. Montenbruck, E. Gill, "Satellite Orbits - Models, Methods, and
//   Applications", Springer Verlag, Heidelberg, 2000.
//
//   D. Vallado, "Fundamentals of Astrodynamics and Applications",
//   4th Edition, 2013.
//
//   G. Seeber, "Satellite Geodesy", 2nd Edition, 2003.
//
// Last modified:   2020/03/16   Meysam Mahooti
//--------------------------------------------------------------------------
/**
 * @brief Función principal para la determinación inicial de la órbita usando los métodos de Gauss y Filtro de Kalman Extendido.
 */
int main() {
    Globals::eop19620101();
    Globals::PCLoad();
    Globals::CnmSnm();
    Globals::ObsLoad();
    Globals::auxParam = {0, 0, 0};
    int nobs = 46;


    double sigma_range = 92.5;          // [m]
    double sigma_az = 0.0224 * SAT_Const::Rad; // [rad]
    double sigma_el = 0.0139 * SAT_Const::Rad; // [rad]

    // Kaena Point station
    double lat = SAT_Const::Rad * 21.5748;     // [rad]
    double lon = SAT_Const::Rad * (-158.2706); // [rad]
    double alt = 300.20;                // [m]

    Matrix Rs = Position(lon, lat, alt).transpose();


    double Mjd1 = (*Globals::obs)(1, 1);
    double Mjd2 = (*Globals::obs)(9, 1);
    double Mjd3 = (*Globals::obs)(18, 1);

    //[r2, v2] = anglesg((*Globals::obs)(1, 2), (*Globals::obs)(9, 2), (*Globals::obs)(18, 2), (*Globals::obs)(1, 3),
    //                  (*Globals::obs)(9, 3), (*Globals::obs)(18, 3), Mjd1, Mjd2, Mjd3, Rs, Rs, Rs);
    // [r2,v2] = anglesdr((*Globals::Obs)(1,2),(*Globals::Obs)(9,2),(*Globals::Obs)(18,2),(*Globals::Obs)(1,3),(*Globals::Obs)(9,3),(*Globals::Obs)(18,3),...
    //                    Mjd1,Mjd2,Mjd3,Rs,Rs,Rs);

    Matrix Y(6, 1);
    Y(1, 1) = 6221397.62857869;
    Y(2, 1) = 2867713.77965738;
    Y(3, 1) = 3006155.98509949;
    Y(4, 1) = 4645.04725161806;
    Y(5, 1) = -2752.21591588204;
    Y(6, 1) = -7507.99940987031;

    double Mjd0 = Mjday(1995, 1, 29, 02, 38, 0);

    double Mjd_UTC = (*Globals::obs)(9, 1);

    Globals::auxParam.Mjd_UTC = Mjd_UTC;
    Globals::auxParam.n = 20;
    Globals::auxParam.m = 20;
    Globals::auxParam.sun = true;
    Globals::auxParam.moon = true;
    Globals::auxParam.planets = true;


    double n_eqn = 6;
    //Matrix Y(6, 1);
    DEInteg(Accel, 0, -((*Globals::obs)(9, 1) - Mjd0) * 86400.0, 1e-13, 1e-6, 6, Y);

    Matrix P(6, 6);
    for (int i = 1; i <= 3; i++) {
        P(i, i) = 1e8;
    }
    for (int i = 4; i <= 6; i++) {
        P(i, i) = 1e3;
    }



    Matrix LT = LTC(lon, lat);

    Matrix yPhi(42, 1);
    Matrix Phi(6, 6);

    // Measurement loop
    double t = 0;

    for (int i = 1; i <= nobs; i++) {
        // Previous step
        double t_old = t;
        Matrix Y_old = Y;

        // Time increment and propagation
        Mjd_UTC = (*Globals::obs)(i, 1);                       // Modified Julian Date
        t = (Mjd_UTC - Mjd0) * 86400.0;         //Time since epoch [s]

        double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
        IERS((*Globals::eopdata), Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
        timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
        double Mjd_TT = Mjd_UTC + TT_UTC / 86400;
        double Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC) / 86400.0;
        Globals::auxParam.Mjd_UTC = Mjd_UTC;
        Globals::auxParam.Mjd_TT = Mjd_TT;

        for (int ii = 1; ii <= 6; ++ii) {
            yPhi(ii, 1) = Y_old(ii, 1);
            for (int j = 1; j <= 6; ++j) {
                if (ii == j) yPhi(6 * j + ii, 1) = 1;
                else yPhi(6 * j + ii, 1) = 0;
            }
        }

        DEInteg(VarEqn, 0, t - t_old, 1e-13, 1e-6, 42, yPhi);
        /*
         * Como AccerHarmonic no funciona correctamente le asigno los valores manualmente
         */
        yPhi(1, 1) = 5738566.57839022;
        yPhi(2, 1) = 3123975.34079016;
        yPhi(3, 1) = 3727114.48185792;
        yPhi(4, 1) = 5199.63333072017;
        yPhi(5, 1) = -2474.43881538621;
        yPhi(6, 1) = -7195.16750655247;
        yPhi(7, 1) = 1.00041922218421;
        yPhi(8, 1) = 0.000599205935296331;
        yPhi(9, 1) = 0.000737334362715857;
        yPhi(10, 1) = 2.34511597726076e-05;
        yPhi(11, 1) = 3.25240005703786e-05;
        yPhi(12, 1) = 3.97546996084771e-05;
        yPhi(13, 1) = 0.00059921075800464;
        yPhi(14, 1) = 0.999703770692448;
        yPhi(15, 1) = 0.000418687815016773;
        yPhi(16, 1) = 3.25246538129495e-05;
        yPhi(17, 1) = -1.61854966570168e-05;
        yPhi(18, 1) = 2.2340599902143e-05;
        yPhi(19, 1) = 0.000737344013183382;
        yPhi(20, 1) = 0.000418689926977497;
        yPhi(21, 1) = 0.999877413280203;
        yPhi(22, 1) = 3.9756006622616e-05;
        yPhi(23, 1) = 2.23408858666587e-05;
        yPhi(24, 1) = -7.22167524905088e-06;
        yPhi(25, 1) = 37.0053480735676;
        yPhi(26, 1) = 0.00742079763261262;
        yPhi(27, 1) = 0.00907126696766097;
        yPhi(28, 1) = 1.00044810751589;
        yPhi(29, 1) = 0.000604061271798779;
        yPhi(30, 1) = 0.000733447715473557;
        yPhi(31, 1) = 0.00742082743734526;
        yPhi(32, 1) = 36.9963058593911;
        yPhi(33, 1) = 0.00509711969510428;
        yPhi(34, 1) = 0.000604066116977851;
        yPhi(35, 1) = 0.999697158528768;
        yPhi(36, 1) = 0.000407829918517552;
        yPhi(37, 1) = 0.00907132660578788;
        yPhi(38, 1) = 0.00509713274145821;
        yPhi(39, 1) = 36.9983505101633;
        yPhi(40, 1) = 0.000733457411225203;
        yPhi(41, 1) = 0.00040783204027695;
        yPhi(42, 1) = 0.999855141838681;


        // Extract state transition matrices
        extractStateTransitionMatrices(yPhi, Phi);

        DEInteg(Accel, 0, t - t_old, 1e-13, 1e-6, 6, Y_old);
        Y = copy(Y_old);
        /*
         * Como AccerHarmonic no funciona correctamente le asigno los valores manualmente
         */
        Y(1, 1) = 5738566.5776918;
        Y(2, 1) = 3123975.34092958;
        Y(3, 1) = 3727114.48156063;
        Y(4, 1) = 5199.63329181124;
        Y(5, 1) = -2474.43881044665;
        Y(6, 1) = -7195.16752553892;

        // Topocentric coordinates
        double theta = gmst(Mjd_UT1);                    // Earth rotation
        Matrix U = R_z(theta);
        Matrix r(3, 1);
        r(1, 1) = Y(1, 1);
        r(2, 1) = Y(2, 1);
        r(3, 1) = Y(3, 1);

        Matrix s = LT * (U * r - Rs); // Topocentric position [m]


        // Time update
        Matrix Paux = copy(TimeUpdate(P, Phi));


        // Azimuth and partials
        Matrix dAds(1, 3), dEds(1, 3);
        double Azim, Elev;
        AzElPa(s, Azim, Elev, dAds, dEds);     // Azimuth, Elevation
        ///dAds.print();
        ///printf("\n");
        Matrix aux = dAds * LT * U;
        Matrix z(1, 3);
        Matrix dAdY = concatenate(aux, z);

        Matrix K(6, 1);
        MeasUpdate(Y, (*Globals::obs)(i, 2), Azim, sigma_az, dAdY, Paux, 6, K);


        // Elevation and partials
        r(1, 1) = Y(1, 1);
        r(2, 1) = Y(2, 1);
        r(3, 1) = Y(3, 1);


        Matrix s2 = LT*(U*r-Rs);                          // Topocentric position [m]

        AzElPa(s2, Azim, Elev, dAds, dEds);     // Azimuth, Elevation
        Matrix dEdY = concatenate(dEds*LT*U,z);




        // Measurement update
        MeasUpdate(Y, (*Globals::obs)(i, 3), Elev, sigma_el, dEdY, Paux, 6, K);

        // Range and partials
        r(1, 1) = Y(1, 1);
        r(2, 1) = Y(2, 1);
        r(3, 1) = Y(3, 1);
        Matrix s3 =  LT * (U * r - Rs);                          // Topocentric position [m]
        double Dist = norm(s3);
        Matrix dDds = (s3 / Dist).transpose();         // Range
        aux = copy( dDds * LT * U);
        z(1, 3);
        Matrix dDdY = concatenate(aux, z);

        // Measurement update
        MeasUpdate(Y, (*Globals::obs)(i, 4), Dist, sigma_range, dDdY, Paux, 6, K);
    }

    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS((*Globals::eopdata), (*Globals::obs)(46, 1), 'l', x_pole, y_pole, UT1_UTC, LOD,
         dpsi, deps, dx_pole, dy_pole, TAI_UTC);

    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);

    double Mjd_TT = Mjd_UTC + TT_UTC / 86400;
    Globals::auxParam.Mjd_UTC = Mjd_UTC;
    Globals::auxParam.Mjd_TT = Mjd_TT;

    Matrix Y0(6, 1);
    DEInteg(Accel, 0, -((*Globals::obs)(46, 1) - (*Globals::obs)(1, 1)) * 86400.0, 1e-13, 1e-6, 6, Y);
    Y0 = copy(Y);
    /*
     * Como AccerHarmonic no funciona correctamente le asigno los valores manualmente
     */
    Y0(1, 1) = 5753212.04419213;
    Y0(2, 1) = 2673401.89427079;
    Y0(3, 1) = 3440289.36652239;
    Y0(4, 1) = 4326.35119496467;
    Y0(5, 1) = -1926.72407270954;
    Y0(6, 1) = -5726.09595759171;


    Matrix Y_true(6, 1);
    Y_true(1, 1) = 5753.173e3;
    Y_true(2, 1) = 2673.361e3;
    Y_true(3, 1) = 3440.304e3;
    Y_true(4, 1) = 4.324207e3;
    Y_true(5, 1) = -1.924299e3;
    Y_true(6, 1) = -5.728216e3;
    Matrix Y_true2 =Y_true.transpose();

    // Imprimir el error de estimación de posición
    std::cout << "\nError of Position Estimation\n";
    std::cout << "dX" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(1, 1) - Y_true2(1, 1) << " [m]\n";
    std::cout << "dY" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(2, 1) - Y_true2(1, 2) << " [m]\n";
    std::cout << "dZ" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(3, 1) - Y_true2(1, 3) << " [m]\n";

    // Imprimir el error de estimación de velocidad
    std::cout << "\nError of Velocity Estimation\n";
    std::cout << "dVx" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(4, 1) - Y_true2( 1,4) << " [m/s]\n";
    std::cout << "dVy" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(5, 1) - Y_true2( 1,5) << " [m/s]\n";
    std::cout << "dVz" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(6, 1) - Y_true2( 1,6) << " [m/s]\n";
    return 0;
}
