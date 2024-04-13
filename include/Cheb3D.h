//
// Created by perez on 13/04/2024.
//

#ifndef PROYECTOTALLER1_CHEB3D_H
#define PROYECTOTALLER1_CHEB3D_H
#include <stdexcept>
#include "Matrix.h"
//--------------------------------------------------------------------------
//
// Chebyshev approximation of 3-dimensional vectors
//
// Inputs:
//     N       Number of coefficients
//     Ta      Begin interval
//     Tb      End interval
//     Cx      Coefficients of Chebyshev polyomial (x-coordinate)
//     Cy      Coefficients of Chebyshev polyomial (y-coordinate)
//     Cz      Coefficients of Chebyshev polyomial (z-coordinate)
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------

Matrix Cheb3D(double t, int N, double Ta, double Tb, Matrix Cx, Matrix Cy, Matrix Cz);
#endif //PROYECTOTALLER1_CHEB3D_H
