//
// Created by perez on 13/04/2024.
//

#ifndef PROYECTOTALLER1_ECCANOM_H
#define PROYECTOTALLER1_ECCANOM_H
#include <cmath>
#include <stdexcept>
#include "Matrix.h"
#include <stdexcept>
//--------------------------------------------------------------------------
//
// Purpose:
//   Computes the eccentric anomaly for elliptic orbits
//
// Inputs:
//   M         Mean anomaly in [rad]
//   e         Eccentricity of the orbit [0,1]
//
// Output:
//             Eccentric anomaly in [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double EccAnom(double M, double e);

#endif //PROYECTOTALLER1_ECCANOM_H
