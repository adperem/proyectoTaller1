//
// Created by perez on 01/05/2024.
//

#ifndef PROYECTOTALLER1_POSITION_H
#define PROYECTOTALLER1_POSITION_H
#include "Matrix.h"
#include "SAT_Const.h"
#include "cmath"
//--------------------------------------------------------------------------
//
// Position.m
//
// Purpose:
//   Position vector (r [m]) from geodetic coordinates (Longitude [rad],
//   latitude [rad], altitude [m])
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix Position(double lon, double lat, double h);
#endif //PROYECTOTALLER1_POSITION_H
