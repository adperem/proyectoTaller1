//
// Created by perez on 17/05/2024.
//

#ifndef PROYECTOTALLER1_DEINTEG_H
#define PROYECTOTALLER1_DEINTEG_H
#include "Matrix.h"
#include "cmath"
#include "sign_.h"
//----------------------------------------------------------------------------
//
// Purpose:
//   Numerical integration methods for ordinaray differential equations
//
//   This module provides implemenation of the variable order variable
//   stepsize multistep method of Shampine & Gordon.
//
// Last modified:   2015/08/25   M. Mahooti
//
// Reference:
//
//   Shampine, Gordon: "Computer solution of Ordinary Differential Equations",
//   Freeman and Comp., San Francisco (1975).
//
//----------------------------------------------------------------------------
void
DEInteg(Matrix (*func)(double, Matrix), double t, double tout, double relerr, double abserr, double n_eqn, Matrix& y);
#endif //PROYECTOTALLER1_DEINTEG_H
