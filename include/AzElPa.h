//
// Created by perez on 13/04/2024.
//

#ifndef PROYECTOTALLER1_AZELPA_H
#define PROYECTOTALLER1_AZELPA_H

#include "Matrix.h"
#include <math.h>

//--------------------------------------------------------------------------
//
// Purpose:
//  Computes azimuth, elevation and partials from local tangent coordinates
//
// Input:
//   s      Topocentric local tangent coordinates (East-North-Zenith frame)
//
// Outputs:
//   A      Azimuth [rad]
//   E      Elevation [rad]
//   dAds   Partials of azimuth w.r.t. s
//   dEds   Partials of elevation w.r.t. s
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
void AzElPa(Matrix s, double &Az, double &El, Matrix &dAds, Matrix &dEds);

#endif //PROYECTOTALLER1_AZELPA_H
