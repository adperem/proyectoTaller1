//
// Created by adperem on 08/05/2024.
//
#include "VarEqn.h"


Matrix VarEqn(double x, Matrix yPhi){
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;
    IERS(Globals::eopdata , Globals::auxParam.Mjd_UTC,'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);

    double UT1_TAI,  UTC_GPS,  UT1_GPS,  TT_UTC, GPS_UTC;
    timediff( UT1_UTC,  TAI_UTC,  UT1_TAI,  UTC_GPS,  UT1_GPS,  TT_UTC, GPS_UTC);
    double Mjd_UT1 = Globals::auxParam.Mjd_TT + (UT1_UTC-TT_UTC)/86400.0;

    // Transformation matrix
    Matrix P = PrecMatrix(SAT_Const::MJD_J2000,Globals::auxParam.Mjd_TT + x/86400);
    Matrix N = NutMatrix(Globals::auxParam.Mjd_TT + x/86400);
    Matrix T = N * P;
    Matrix E = PoleMatrix(x_pole,y_pole) * GHAMatrix(Mjd_UT1) * T;

    // State vector components
    Matrix r(1, 3);
    for (int i = 1; i <= 3; ++i) {
        r(1, i) = yPhi(i, 1);
    }

    Matrix v(1, 3);
    for (int i = 1; i <= 3; ++i) {
        v(1, i) = yPhi(i + 3, 1);
    }
    Matrix Phi(6, 6);

    // State transition matrix
    for (int j = 1; j <= 6; ++j) {
        for (int i = 1; i <= 6; ++i) {
            Phi(i, j) = yPhi(6 * (j - 1) + i, 1);
        }
    }

    // Acceleration and gradient
    Matrix a = AccelHarmonic ( r, E, Globals::auxParam.n, Globals::auxParam.m );
    Matrix G = G_AccelHarmonic ( r, E, Globals::auxParam.n, Globals::auxParam.m );

    // Time derivative of state transition matrix
    Matrix yPhip = Matrix(42,1);
    Matrix dfdy = Matrix(6,6);

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            dfdy(i, j) = 0.0;                      // dv/dr(i,j)
            dfdy(i + 3, j) = G(i, j);              // da/dr(i,j)
            if (i == j) {
                dfdy(i, j + 3) = 1;
            } else {
                dfdy(i, j + 3) = 0;                // dv/dv(i,j)
            }
            dfdy(i + 3, j + 3) = 0.0;              // da/dv(i,j)
        }
    }
    Matrix Phip = dfdy*Phi;
    for (int i = 1; i <= 3; ++i) {
        yPhip(i,1) = v(i,1);    // dr/dt(i)
        yPhip(i + 3,1) = a(i,1);    // dv/dt(i)
    }
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            yPhip(6*j+i,1) = Phip(i,j);     // dPhi/dt(i,j)
        }
    }
    return yPhip;
}

