#include "AccelPointMass.h"
/**
 * @brief Calcula la aceleración debida a una masa puntual
 *
 * @param r Vector de posición del satélite en coordenadas inerciales (matriz de 3x1).
 * @param s Vector de posición de la masa puntual en coordenadas inerciales (matriz de 3x1).
 * @param GM Constante gravitacional de la masa puntual [m^3/s^2].
 * @return Matriz que contiene la aceleración del satélite debida a la masa puntual (matriz de 3x1).
 */
Matrix AccelPointMass(Matrix r, Matrix s, double GM){

    // Relative position vector of satellite w.r.t. point mass 
    Matrix d = r - s;
    double aux = pow((norm(d)),3);
    double aux2 = pow(norm(s),3);
    Matrix aux3 = divide(d,aux);
    Matrix aux4 = divide(s,aux2);

    // Acceleration
    Matrix a =  ( aux3 + aux4 )*-GM ;
    return a;
}


