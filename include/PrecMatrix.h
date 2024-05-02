//
// Created by perez on 02/05/2024.
//

#ifndef PROYECTOTALLER1_PRECMATRIX_H
#define PROYECTOTALLER1_PRECMATRIX_H
#include "Matrix.h"
#include "SAT_Const.h"
#include "R_z.h"
#include "R_y.h"
//--------------------------------------------------------------------------
//
// PrecMatrix.m
//
// Purpose:
//
//   Precession transformation of equatorial coordinates
//
// Input:
//   Mjd_1     Epoch given (Modified Julian Date TT)
//   MjD_2     Epoch to precess to (Modified Julian Date TT)
//
// Output:
//   PrecMat   Precession transformation matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix PrecMatrix (double Mjd_1,double Mjd_2);
#endif //PROYECTOTALLER1_PRECMATRIX_H

