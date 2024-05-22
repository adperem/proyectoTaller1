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
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 6; ++i) {
            Phi.setElement(i + 1, j + 1, yPhi.getElement(6 * j + i + 1, 1));
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
    double nobs = 46;

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

    Matrix Y0_apr(1, 6);
    Y0_apr(1, 1) = 6221397.62857869;
    Y0_apr(1, 2) = 2867713.77965738;
    Y0_apr(1, 3) = 3006155.98509949;
    Y0_apr(1, 4) = 4645.04725161806;
    Y0_apr(1, 5) = -2752.21591588204;
    Y0_apr(1, 6) = -7507.99940987031;

    double Mjd0 = Mjday(1995, 1, 29, 02, 38, 0);

    double Mjd_UTC = (*Globals::obs)(9, 1);

    Globals::auxParam.Mjd_UTC = Mjd_UTC;
    Globals::auxParam.n = 20;
    Globals::auxParam.m = 20;
    Globals::auxParam.sun = true;
    Globals::auxParam.moon = true;
    Globals::auxParam.planets = true;


    double n_eqn = 6;
    Matrix Y(1, 6);
    DEInteg(Accel, 0, -((*Globals::obs)(9, 1) - Mjd0) * 86400.0, 1e-13, 1e-6, 6, Y0_apr, Y);

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

    for (int i = 1; i <= nobs; ++i) {
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

        DEInteg(VarEqn, 0, t - t_old, 1e-13, 1e-6, 42, yPhi, yPhi);
        // Extract state transition matrices
        extractStateTransitionMatrices(yPhi, Phi);

        DEInteg(Accel, 0, t - t_old, 1e-13, 1e-6, 6, Y_old, Y);

        // Topocentric coordinates
        double theta = gmst(Mjd_UT1);                    // Earth rotation
        Matrix U = R_z(theta);
        Matrix r(3, 1);
        r(1, 1) = Y(1, 1);
        r(2, 1) = Y(2, 1);
        r(3, 1) = Y(3, 1);
        Matrix s = LT * (U * r - Rs);                          // Topocentric position [m]

        // Time update
        P = TimeUpdate(P, Phi);

        // Azimuth and partials
        Matrix dAds(1, 3), dEds(1, 3);
        double Azim, Elev;
        AzElPa(s, Azim, Elev, dAds, dEds);     // Azimuth, Elevation
        Matrix aux = dAds * LT * U;
        Matrix z(1, 3);
        Matrix dAdY = concatenate(aux, z);

        // Measurement update
        Matrix K(6, 3);
        MeasUpdate(Y, (*Globals::obs)(i, 2), Azim, sigma_az, dAdY, P, 6, K);

        // Range and partials
        r(1, 1) = Y(1, 1);
        r(2, 1) = Y(2, 1);
        r(3, 1) = Y(3, 1);
        s = LT * (U * r - Rs);                          // Topocentric position [m]
        double Dist = norm(s);
        Matrix dDds = (s / Dist).transpose();         // Range
        aux = dDds * LT * U;
        z(1, 3);
        Matrix dDdY = concatenate(aux, z);

        // Measurement update
        MeasUpdate(Y, (*Globals::obs)(i, 4), Dist, sigma_range, dDdY, P, 6, K);
    }

    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS((*Globals::eopdata), (*Globals::obs)(46, 1), 'l', x_pole, y_pole, UT1_UTC, LOD,
         dpsi, deps, dx_pole, dy_pole, TAI_UTC);

    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);

    double Mjd_TT = Mjd_UTC + TT_UTC / 86400;
    Globals::auxParam.Mjd_UTC = Mjd_UTC;
    Globals::auxParam.Mjd_TT = Mjd_TT;

    Matrix Y0(1, 6);
    DEInteg(Accel, 0, -((*Globals::obs)(46, 1) - (*Globals::obs)(1, 1)) * 86400.0, 1e-13, 1e-6, 6, Y, Y0);

    Matrix Y_true(6, 1);
    Y_true(1, 1) = 5753.173e3;
    Y_true(2, 1) = 2673.361e3;
    Y_true(3, 1) = 3440.304e3;
    Y_true(4, 1) = 4.324207e3;
    Y_true(5, 1) = -1.924299e3;
    Y_true(6, 1) = -5.728216e3;
    Y_true = Y_true.transpose();

    // Imprimir el error de estimación de posición
    std::cout << "\nError of Position Estimation\n";
    std::cout << "dX" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(1, 1) - Y_true(1, 1) << " [m]\n";
    std::cout << "dY" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(2, 1) - Y_true(2, 1) << " [m]\n";
    std::cout << "dZ" << std::setw(10) << std::fixed << std::setprecision(1) << Y0(3, 1) - Y_true(3, 1) << " [m]\n";

    // Imprimir el error de estimación de velocidad
    std::cout << "\nError of Velocity Estimation\n";
    std::cout << "dVx" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(4, 1) - Y_true(4, 1) << " [m/s]\n";
    std::cout << "dVy" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(5, 1) - Y_true(5, 1) << " [m/s]\n";
    std::cout << "dVz" << std::setw(8) << std::fixed << std::setprecision(1) << Y0(6, 1) - Y_true(6, 1) << " [m/s]\n";


}
