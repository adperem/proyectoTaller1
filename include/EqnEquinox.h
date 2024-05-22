#ifndef PROYECTOTALLER1_EQNEQUINOX_H
#define PROYECTOTALLER1_EQNEQUINOX_H
#include "MeanObliquity.h"
#include "NutAngles.h"
#include <cmath>
//--------------------------------------------------------------------------
//
// EqnEquinox.m
//
// Purpose:
//   Computation of the equation of the equinoxes
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
//
// Output:
//    EqE      Equation of the equinoxes
//
// Notes:
//   The equation of the equinoxes dpsi*cos(eps) is the right ascension of
//   the mean equinox referred to the true equator and equinox and is equal
//   to the difference between apparent and mean sidereal time.
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calcula la ecuación de los equinoccios.
 * @param Mjd_TT Fecha y tiempo (Tiempo Terrestre Modificado).
 * @return La ecuación de los equinoccios.
 * Created by perez on 02/05/2024.
 */
double EqnEquinox (double Mjd_TT);
#endif //PROYECTOTALLER1_EQNEQUINOX_H
