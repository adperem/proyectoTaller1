//
// Created by perez on 02/05/2024.
//

#ifndef PROYECTOTALLER1_GHAMATRIX_H
#define PROYECTOTALLER1_GHAMATRIX_H
#include "R_z.h"
#include "gast.h"
//--------------------------------------------------------------------------
//
// GHAMatrix.m
//
// Purpose:
//   Transformation from true equator and equinox to Earth equator and
//   Greenwich meridian system
//
// Input:
//   Mjd_UT1   Modified Julian Date UT1
//
// Output:
//   GHAmat    Greenwich Hour Angle matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix GHAMatrix (double Mjd_UT1);
#endif //PROYECTOTALLER1_GHAMATRIX_H
