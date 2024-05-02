//
// Created by perez on 02/05/2024.
//

#ifndef PROYECTOTALLER1_GMST_H
#define PROYECTOTALLER1_GMST_H
#include "cmath"
#include "Frac.h"
//--------------------------------------------------------------------------
//
// Purpose:
//   Greenwich Mean Sidereal Time
//
// Input:
//   Mjd_UT1    Modified Julian Date UT1
//
// Output:
//   gmstime	   GMST in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double gmst(double Mjd_UT1);
#endif //PROYECTOTALLER1_GMST_H
