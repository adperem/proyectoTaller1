//
// Created by perez on 13/04/2024.
//

#ifndef PROYECTOTALLER1_LTC_H
#define PROYECTOTALLER1_LTC_H
#include "Matrix.h"
#include "R_y.h"
#include "R_z.h"

//--------------------------------------------------------------------------
//
// LTC.m
//
// Purpose:
//   Transformation from Greenwich meridian system to
//   local tangent coordinates
//
// Inputs:
//   lon      -Geodetic East longitude [rad]
//   lat      -Geodetic latitude [rad]
//
// Output:
//   M        -Rotation matrix from the Earth equator and Greenwich meridian
//             to the local tangent (East-North-Zenith) coordinate system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix LTC(double lon,double lat);
#endif //PROYECTOTALLER1_LTC_H
