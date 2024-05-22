#ifndef PROYECTOTALLER1_MEANOBLIQUITY_H
#define PROYECTOTALLER1_MEANOBLIQUITY_H
#include "SAT_Const.h"
//--------------------------------------------------------------------------
//
// MeanObliquity.m
//
// Purpose:
//   Computes the mean obliquity of the ecliptic
//
// Input:
//   Mjd_TT    Modified Julian Date (Terrestrial Time)
//
// Output:
//   MOblq     Mean obliquity of the ecliptic [rad]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calcula la oblicuidad media de la eclíptica para una fecha dada en tiempo terrestre modificado (TT).
 * @param Mjd_TT Fecha en Tiempo Terrestre Modificado (TT).
 * @return La oblicuidad media de la eclíptica en radianes.
 * Created by perez on 01/05/2024.
 */
double MeanObliquity(double Mjd_TT);
#endif //PROYECTOTALLER1_MEANOBLIQUITY_H
