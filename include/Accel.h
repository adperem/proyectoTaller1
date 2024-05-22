//
// Created by perez on 19/05/2024.
//

#ifndef PROYECTOTALLER1_ACCEL_H
#define PROYECTOTALLER1_ACCEL_H
#include "Matrix.h"
#include "IERS.h"
#include "Globals.h"
#include "timediff.h"
#include "SAT_Const.h"
#include "PrecMatrix.h"
#include "nutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "Mjday_TDB.h"
#include "JPL_Eph_DE430.h"
#include "AccelHarmonic.h"
#include "AccelPointMass.h"
//--------------------------------------------------------------------------
//
// Accel.m
//
// Purpose:
//   Computes the acceleration of an Earth orbiting satellite due to
//    - the Earth's harmonic gravity field,
//    - the gravitational perturbations of the Sun and Moon
//    - the solar radiation pressure and
//    - the atmospheric drag
//
// Inputs:
//   Mjd_TT      Terrestrial Time (Modified Julian Date)
//   Y           Satellite state vector in the ICRF/EME2000 system
//
// Output:
//   dY		    Acceleration (a=d^2r/dt^2) in the ICRF/EME2000 system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix Accel(double x, Matrix Y);
#endif //PROYECTOTALLER1_ACCEL_H
