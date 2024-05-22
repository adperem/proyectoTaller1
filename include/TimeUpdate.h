#ifndef PROYECTOTALLER1_TIMEUPDATE_H
#define PROYECTOTALLER1_TIMEUPDATE_H
#include "Matrix.h"
#include <iostream>
/**
 * @brief Realiza el paso de actualización de tiempo en el filtro de Kalman.
 * @param P La matriz de covarianza.
 * @param Phi La matriz de transición de estado.
 * @param Qdt La matriz de ruido de proceso multiplicada por el paso de tiempo.
 * @return La matriz de covarianza actualizada.
 * Created by perez on 02/05/2024.
 */
Matrix TimeUpdate(Matrix P, Matrix Phi, double Qdt = 0.0);
#endif //PROYECTOTALLER1_TIMEUPDATE_H
