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


void AzElPa(double& Az, double& El, Matrix& dAds, Matrix& dEds, Matrix s){
    double pi2 = 2.0*M_PI;
    double rho = sqrt(s.getElement(1,1)*s.getElement(1,1)*s.getElement(1,2)*s.getElement(1,2));

    // Angles
    Az = atan2(s.getElement(1,1),s.getElement(1,2));

    if (Az<0.0) {
        Az = Az + pi2;
    }

    El = atan ( s.getElement(1,3) / rho );

    // Partials
    dAds = Matrix(1,3);
    dAds.setElement(1,1,s.getElement(1,2)/(rho*rho));
    dAds.setElement(1,2,-s.getElement(1,1)/(rho*rho));
    dAds.setElement(1,3,0.0);

    dEds = Matrix(1,3);
    dEds.setElement(1,1,-s.getElement(1,1)*s.getElement(1,3)/rho);
    dEds.setElement(1,2,-s.getElement(1,2)*s.getElement(1,3)/rho);
    dEds.setElement(1,3,rho);
    dEds = dEds / Matrix::dot(s,s);

}








