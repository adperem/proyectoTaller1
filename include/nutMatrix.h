//
// Created by perez on 02/05/2024.
//

#ifndef PROYECTOTALLER1_NUTMATRIX_H
#define PROYECTOTALLER1_NUTMATRIX_H
#include "Matrix.h"
#include "MeanObliquity.h"
#include "NutAngles.h"
#include "R_z.h"
#include "R_y.h"
#include "R_x.h"
//--------------------------------------------------------------------------
//
// NutMatrix.m
//
// Purpose:
//   Transformation from mean to true equator and equinox
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
//
// Output:
//   NutMat    Nutation matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix NutMatrix (double Mjd_TT);
#endif //PROYECTOTALLER1_NUTMATRIX_H
