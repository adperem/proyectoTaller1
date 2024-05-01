//
// Created by perez on 01/05/2024.
//

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
double Mjday(double yr, double mon, double  day, double hr = 0, double min = 0, double sec = 0);


#endif //PROYECTOTALLER1_MJDAY_H
