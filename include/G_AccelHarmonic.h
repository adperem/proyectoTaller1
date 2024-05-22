//
// Created by adperem on 08/05/2024.
//

#ifndef PROYECTOTALLER1_G_ACCELHARMONIC_H
#define PROYECTOTALLER1_G_ACCELHARMONIC_H
#include "Matrix.h"
#include "AccelHarmonic.h"
//--------------------------------------------------------------------------
//
// G_AccelHarmonic.m
//
// Purpose:
//   Computes the gradient of the Earth's harmonic gravity field
//
// Inputs:
//   r           Satellite position vector in the true-of-date system
//   U           Transformation matrix to body-fixed system
//   n           Gravity model degree
//   m 			Gravity model order
//
// Output:
//   G    		Gradient (G=da/dr) in the true-of-date system
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix G_AccelHarmonic( Matrix r, Matrix U, double n_max, double m_max );
#endif //PROYECTOTALLER1_G_ACCELHARMONIC_H
