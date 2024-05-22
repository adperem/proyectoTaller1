#ifndef PROYECTOTALLER1_UNIT_H
#define PROYECTOTALLER1_UNIT_H
#include "Matrix.h"
//--------------------------------------------------------------------------
//
//  unit.m
//
//  this function calculates a unit vector given the original vector. if a
//  zero vector is input, the vector is set to zero.
//
//  input:
//    vec         - vector
//
//  output:
//    outvec      - unit vector
//
//--------------------------------------------------------------------------
/**
 * @brief Normaliza un vector para obtener su versión unitaria.
 * @param vec El vector a normalizar.
 * @return El vector unitario.
 * Created by perez on 02/05/2024.
 */
Matrix unit(Matrix vec);
#endif //PROYECTOTALLER1_UNIT_H
