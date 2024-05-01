//
// Created by perez on 01/05/2024.
//
#include "Geodetic.h"
//--------------------------------------------------------------------------
//
// Geodetic.m
//
// Purpose:
//   geodetic coordinates (Longitude [rad], latitude [rad], altitude [m])
//   from given position vector (r [m])
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void Geodetic(Matrix r, double& lon, double& lat, double& h){
    double R_equ = SAT_Const::R_Earth;
    double f = SAT_Const::f_Earth;

    double epsRequ = M_E*R_equ;        // Convergence criterion
    double e2      = f*(2.0-f);        // Square of eccentricity

    double X = r(1,1);                   // Cartesian coordinates
    double Y = r(1,2);
    double Z = r(1,3);
    double rho2 = X*X + Y*Y;

    // Check validity of input data
    if (norm(r)==0.0) {
        throw std::runtime_error("invalid input in Geodetic constructor\n");
        lon = 0.0;
        lat = 0.0;
        h = SAT_Const::R_Earth * -1;
    }

    // Iteration
    double dZ = e2*Z;

    double ZdZ;
    double Nh;
    double SinPhi;
    double N;
    double dZ_new;
    while(1){
        ZdZ    =  Z + dZ;
        Nh     =  sqrt ( rho2 + ZdZ*ZdZ );
        SinPhi =  ZdZ / Nh;                    // Sine of geodetic latitude
        N      =  R_equ / sqrt(1.0-e2*SinPhi*SinPhi);
        dZ_new =  N*e2*SinPhi;
        if ( abs(dZ-dZ_new) < epsRequ ){
            break;
        }
        dZ = dZ_new;
    }

    // Longitude, latitude, altitude
    lon = atan2 ( Y, X );
    lat = atan2 ( ZdZ, sqrt(rho2) );
    h   = Nh - N;
}