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
/**
 * @brief Computes the nutation matrix.
 * @param Mjd_TT Modified Julian Date (Terrestrial Time).
 * @return The nutation matrix.
 *
 * This function computes the nutation matrix based on the input Modified Julian Date (Terrestrial Time).
 * It calculates the mean obliquity of the ecliptic, nutation in longitude, and nutation in obliquity
 * using other functions. Then it performs a series of transformations to obtain the nutation matrix.
 * Created by perez on 02/05/2024.
 */
Matrix NutMatrix (double Mjd_TT);
#endif //PROYECTOTALLER1_NUTMATRIX_H
