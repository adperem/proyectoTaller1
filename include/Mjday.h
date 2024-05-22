#ifndef PROYECTOTALLER1_MJDAY_H
#define PROYECTOTALLER1_MJDAY_H
#include "Matrix.h"
#include <cmath>
//--------------------------------------------------------------------------
//  inputs:
//    year        - year
//    mon         - month
//    day         - day
//    hr          - universal time hour
//    min         - universal time min
//    sec         - universal time sec
//
//  output:
//    Mjd         - Modified julian date
//--------------------------------------------------------------------------
/**
 * @brief Calcula el número juliano modificado (MJD) dado un conjunto de componentes de fecha y hora.
 * @param yr Año.
 * @param mon Mes.
 * @param day Día.
 * @param hr Hora.
 * @param min Minuto.
 * @param sec Segundo.
 * @return El número juliano modificado correspondiente a la fecha y hora especificadas.
 * Created by perez on 01/05/2024.
 */
double Mjday(double yr, double mon, double  day, double hr = 0, double min = 0, double sec = 0);


#endif //PROYECTOTALLER1_MJDAY_H
