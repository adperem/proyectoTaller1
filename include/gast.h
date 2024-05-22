#ifndef PROYECTOTALLER1_GAST_H
#define PROYECTOTALLER1_GAST_H
#include "gmst.h"
#include "EqnEquinox.h"
#include <cmath>
//--------------------------------------------------------------------------
//
// GAST.m
//
// Purpose:
//   Greenwich Apparent Sidereal Time
//
// Input:
//   Mjd_UT1   Modified Julian Date UT1
//
// Output:
//   gstime    GAST in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calcula el Tiempo Sideral Medio Greenwich (GAST) para un momento dado en Tiempo Universal (UT1).
 * @param Mjd_UT1 Fecha y hora en Tiempo Universal (UT1) en formato modificado de días de juliano.
 * @return El Tiempo Sideral Medio Greenwich (GAST) en radianes.
 * Created by perez on 02/05/2024.
 */
double gast (double Mjd_UT1);
#endif //PROYECTOTALLER1_GAST_H
