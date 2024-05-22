#ifndef PROYECTOTALLER1_POLEMATRIX_H
#define PROYECTOTALLER1_POLEMATRIX_H
#include "Matrix.h"
#include "R_x.h"
#include "R_y.h"
//--------------------------------------------------------------------------
//
// PoleMatrix.m
//
// Purpose:
//   Transformation from pseudo Earth-fixed to Earth-fixed coordinates
//   for a given date
//
// Input:
//   Pole coordinte(xp,yp)
//
// Output:
//   PoleMat   Pole matrix
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------

/**
 * @brief Trasnforma de .
 * @param xp Desplazamiento de la coordenada del polo en la dirección y (segundos de arco).
 * @param yp Desplazamiento de la coordenada del polo en la dirección x (segundos de arco).
 * @return La matriz del polo.
 * Created by perez on 02/05/2024.
 */

Matrix PoleMatrix(double xp,double yp);
#endif //PROYECTOTALLER1_POLEMATRIX_H
