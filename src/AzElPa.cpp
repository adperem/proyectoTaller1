/**
 * @brief Calcula los ángulos de acimut y elevación a partir de un vector de posición.
 *
 * @param s Vector de posición del objeto observado (matriz de 1x3).
 * @param Az Ángulo de acimut resultante (en radianes).
 * @param El Ángulo de elevación resultante (en radianes).
 * @param dAds Derivadas del ángulo de acimut respecto al vector de posición (matriz de 1x3).
 * @param dEds Derivadas del ángulo de elevación respecto al vector de posición (matriz de 1x3).
 */
#include <cstdio>
#include <iostream>
#include "AzElPa.h"
void AzElPa(Matrix s, double &Az, double &El, Matrix &dAds, Matrix &dEds){
    double pi2 = 2.0*M_PI;
    double rho = sqrt(s(1,1)*s(1,1)*s(2,1)*s(2,1));

    // Angles
    Az = atan2(s(1,1),s(2,1));

    if (Az<0.0) {
        Az = Az + pi2;
    }

    El = atan ( s(3,1) / rho );

    // Partials

    dAds = Matrix(1,3);
    dAds(1,1) = s(2,1)/(rho*rho);
    dAds(1,2) = -s(1,1)/(rho*rho);
    dAds(1,3) = 0.0;

    dEds = Matrix(1,3);
    dEds.setElement(1,1,-s(1,1)*s(3,1)/rho);
    dEds.setElement(1,2,-s(2,1)*s(3,1)/rho);
    dEds.setElement(1,3,rho);
    dEds = dEds / dot(s,s);

}