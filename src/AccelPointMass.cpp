#include "AccelPointMass.h"
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


