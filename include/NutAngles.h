#ifndef PROYECTOTALLER1_NUTANGLES_H
#define PROYECTOTALLER1_NUTANGLES_H
#include "SAT_Const.h"
#include "Matrix.h"
//--------------------------------------------------------------------------
//
// NutAngles.m
//
// Purpose:
//   Nutation in longitude and obliquity
//
// Input:
//   Mjd_TT     Modified Julian Date (Terrestrial Time)
//
// Output:
//   dpsi,deps  Nutation Angles
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Computes the nutation angles.
 * @param Mjd_TT Modified Julian Date (Terrestrial Time).
 * @param dpsi Nutation in longitude in arcseconds.
 * @param deps Nutation in obliquity in arcseconds.
 *
 * This function computes the nutation in longitude and nutation in obliquity
 * based on the input Modified Julian Date (Terrestrial Time).
 * It uses a series of coefficients stored in a matrix to perform the calculations.
 * Created by perez on 01/05/2024.
 */
void NutAngles (double Mjd_TT, double& dpsi, double& deps);
#endif //PROYECTOTALLER1_NUTANGLES_H
