//
// Created by perez on 01/05/2024.
//

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
void NutAngles (double Mjd_TT, double& dpsi, double& deps);
#endif //PROYECTOTALLER1_NUTANGLES_H
