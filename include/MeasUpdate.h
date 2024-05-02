//
// Created by perez on 02/05/2024.
//

#ifndef PROYECTOTALLER1_MEASUPDATE_H
#define PROYECTOTALLER1_MEASUPDATE_H
#include "Matrix.h"
/*
 * z es un vector
 * s es un vector
 */
void MeasUpdate(Matrix& x, Matrix z, Matrix g, Matrix s, Matrix G, Matrix& P, double n, Matrix &K);
#endif //PROYECTOTALLER1_MEASUPDATE_H
