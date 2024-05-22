#ifndef PROYECTOTALLER1_MEASUPDATE_H
#define PROYECTOTALLER1_MEASUPDATE_H
#include "Matrix.h"
/**
 * @brief Actualiza el estado y la covarianza del filtro de Kalman extendido utilizando una medición.
 * @param x Estado estimado del sistema.
 * @param z Medición.
 * @param g Predicción de la medición.
 * @param s Desviación estándar de la medición.
 * @param G Matriz de sensibilidad de la medición.
 * @param P Covarianza estimada del estado.
 * @param n Número de filas de la matriz de covarianza.
 * @param K Ganancia de Kalman.
 * Created by perez on 02/05/2024.
 */
void MeasUpdate(Matrix& x, double z, double g, double s, Matrix G, Matrix& P, double n, Matrix &K);
#endif //PROYECTOTALLER1_MEASUPDATE_H
