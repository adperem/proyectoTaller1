#include "Matrix.h"
#include <cmath>
#ifndef PROYECTOTALLER1_LEGENDRE_H
#define PROYECTOTALLER1_LEGENDRE_H
/**
 * @brief Calculates the associated Legendre polynomials and their derivatives.
 * @param n Degree of the Legendre polynomial.
 * @param m Order of the Legendre polynomial.
 * @param fi Angle in radians.
 * @param pnm Output matrix containing the Legendre polynomials.
 * @param dpnm Output matrix containing the derivatives of the Legendre polynomials.
 * Created by perez on 01/05/2024.
 */
void Legendre(double n,double m, double  fi, Matrix &pnm, Matrix& dpnm);
#endif //PROYECTOTALLER1_LEGENDRE_H
