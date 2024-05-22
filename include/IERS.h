//
//
//
#ifndef PROYECTOTALLER1_IERS_H
#define PROYECTOTALLER1_IERS_H
#include "Matrix.h"
//--------------------------------------------------------------------------
//
// IERS: Management of IERS time and polar motion data
//
// Last modified:   2018/02/01   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calcula los parámetros de rotación de la Tierra según los datos del IERS.
 *
 * @param eop Matriz de datos del IERS.
 * @param Mjd_UTC Fecha modificada de Julio (UTC).
 * @param interp Tipo de interpolación ('l' para lineal, 'n' para ningún).
 * @param x_pole Coordenada x del polo de rotación [rad].
 * @param y_pole Coordenada y del polo de rotación [rad].
 * @param UT1_UTC Diferencia de tiempo UT1-UTC [s].
 * @param LOD Longitud del día [s].
 * @param dpsi Diferencia en la longitud de la precesión [rad].
 * @param deps Diferencia en la oblicuidad de la eclíptica [rad].
 * @param dx_pole Tasa de cambio de la coordenada x del polo [rad/día].
 * @param dy_pole Tasa de cambio de la coordenada y del polo [rad/día].
 * @param TAI_UTC Diferencia de tiempo TAI-UTC [s].
 * Created by perez on 01/05/2024.
 */
void IERS(Matrix eop, double Mjd_UTC, char interp,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC);
/**
 * @brief Calcula los parámetros de rotación de la Tierra según los datos del IERS.
 *
 * @param eop Matriz de datos del IERS.
 * @param Mjd_UTC Fecha modificada de Julio (UTC).
 * @param x_pole Coordenada x del polo de rotación [rad].
 * @param y_pole Coordenada y del polo de rotación [rad].
 * @param UT1_UTC Diferencia de tiempo UT1-UTC [s].
 * @param LOD Longitud del día [s].
 * @param dpsi Diferencia en la longitud de la precesión [rad].
 * @param deps Diferencia en la oblicuidad de la eclíptica [rad].
 * @param dx_pole Tasa de cambio de la coordenada x del polo [rad/día].
 * @param dy_pole Tasa de cambio de la coordenada y del polo [rad/día].
 * @param TAI_UTC Diferencia de tiempo TAI-UTC [s].
 * Created by perez on 01/05/2024.
 */
void IERS(Matrix eop, double Mjd_UTC,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC);
#endif //PROYECTOTALLER1_IERS_H
