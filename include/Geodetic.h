#ifndef PROYECTOTALLER1_GEODETIC_H
#define PROYECTOTALLER1_GEODETIC_H
#include "Matrix.h"
#include "SAT_Const.h"
#include <stdexcept>
#include <cmath>
//--------------------------------------------------------------------------
//
// Geodetic.m
//
// Purpose:
//   geodetic coordinates (Longitude [rad], latitude [rad], altitude [m])
//   from given position vector (r [m])
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calcula las coordenadas geodésicas (longitud, latitud y altura) a partir de las coordenadas cartesianas.
 * @param r Vector de posición en coordenadas cartesianas.
 * @param lon Longitud geodésica resultante en radianes.
 * @param lat Latitud geodésica resultante en radianes.
 * @param h Altura geodésica resultante en metros.
 * Created by perez on 01/05/2024.
 */
void Geodetic(Matrix r, double& lon, double& lat, double& h);
#endif //PROYECTOTALLER1_GEODETIC_H
