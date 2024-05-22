#ifndef PROYECTOTALLER1_VAREQN_H
#define PROYECTOTALLER1_VAREQN_H
#include "Matrix.h"
#include "Globals.h"
#include "IERS.h"
#include "timediff.h"
#include "SAT_Const.h"
#include "PrecMatrix.h"
#include "nutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "AccelHarmonic.h"
#include "G_AccelHarmonic.h"
//------------------------------------------------------------------------------
//
// VarEqn.m
//
// Purpose:
//   Computes the variational equations, i.e. the derivative of the state vector
//   and the state transition matrix
//
// Input:
//   x           Time since epoch in [s]
//   yPhi        (6+36)-dim vector comprising the state vector (y) and the
//               state transition matrix (Phi) in column wise storage order
//
// Output:
//   yPhip       Derivative of yPhi
//
// Last modified:   2015/08/12   M. Mahooti
//
//------------------------------------------------------------------------------
/**
 * @brief Calcula la derivada temporal del vector de estado y la matriz de transición de estado.
 * @param x El tiempo en segundos desde el comienzo del día TT (Tiempo Terrestre).
 * @param yPhi El vector de estado y la matriz de transición de estado concatenados.
 * @return La derivada temporal del vector de estado y la matriz de transición de estado concatenados.
 * Created by adperem on 08/05/2024.
 */
Matrix VarEqn(double x, Matrix yPhi);
#endif //PROYECTOTALLER1_VAREQN_H
