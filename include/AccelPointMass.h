//
// Created by perez on 13/04/2024.
//

#ifndef PROYECTOTALLER1_ACCELPOINTMASS_H
#define PROYECTOTALLER1_ACCELPOINTMASS_H
#include "Matrix.h"
#include <math.h>
//--------------------------------------------------------------------------
//
// AccelPointMass: Computes the perturbational acceleration due to a point
//				  mass
//
// Inputs:
//   r           Satellite position vector
//   s           Point mass position vector
//   GM          Gravitational coefficient of point mass
//
// Output:
//   a    		Acceleration (a=d^2r/dt^2)
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------
Matrix AccelPointMass(Matrix r, Matrix s, double GM);
#endif //PROYECTOTALLER1_ACCELPOINTMASS_H
