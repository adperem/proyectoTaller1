#include "AccelPointMass.h"
Matrix AccelPointMass(Matrix r, Matrix s, double GM){

    // Relative position vector of satellite w.r.t. point mass 
    Matrix d = r - s;
    double aux = pow((Matrix::norm(d)),3);
    double aux2 = pow(Matrix::norm(s),3);
    Matrix aux3 = Matrix::divide(d,aux);
    Matrix aux4 = Matrix::divide(s,aux2);

    // Acceleration
    Matrix a =  ( aux3 + aux4 )*-GM ;
    return a;
}


