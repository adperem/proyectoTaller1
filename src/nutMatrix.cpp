//
// Created by perez on 02/05/2024.
//
#include "nutMatrix.h"
Matrix NutMatrix (double Mjd_TT){
    // Mean obliquity of the ecliptic
    double eps = MeanObliquity (Mjd_TT);

    // Nutation in longitude and obliquity
    double dpsi, deps;
    NutAngles (Mjd_TT,dpsi, deps);

    // Transformation from mean to true equator and equinox
    Matrix NutMat = R_x(-eps-deps)*R_z(-dpsi)*R_x(+eps);
    return NutMat;
}



