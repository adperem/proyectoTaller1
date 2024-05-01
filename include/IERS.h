//
// Created by perez on 01/05/2024.
//
#ifndef PROYECTOTALLER1_IERS_H
#define PROYECTOTALLER1_IERS_H
#include "Matrix.h"
//--------------------------------------------------------------------------
//
// IERS: Management of IERS time and polar motion data
//
// Last modified:   2018/02/01   M. Mahooti
//
//--------------------------------------------------------------------------
void IERS(Matrix eop, double Mjd_UTC, char interp,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC);
void IERS(Matrix eop, double Mjd_UTC,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC);
#endif //PROYECTOTALLER1_IERS_H
