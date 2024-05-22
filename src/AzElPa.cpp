/**
 * @brief Calcula los ángulos de acimut y elevación a partir de un vector de posición.
 *
 * @param s Vector de posición del objeto observado (matriz de 1x3).
 * @param Az Ángulo de acimut resultante (en radianes).
 * @param El Ángulo de elevación resultante (en radianes).
 * @param dAds Derivadas del ángulo de acimut respecto al vector de posición (matriz de 1x3).
 * @param dEds Derivadas del ángulo de elevación respecto al vector de posición (matriz de 1x3).
 */
#include "AzElPa.h"
void AzElPa(Matrix s, double &Az, double &El, Matrix &dAds, Matrix &dEds){
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
    dEds = dEds / dot(s,s);

}