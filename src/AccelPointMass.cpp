#include "Matrix.h"
#include <math.h>
//--------------------------------------------------------------------------
//
// AccelPointMass: Computes the perturbational acceleration due to a point
//				  mass
//
// Inputs:
//   r           Satellite position vector 
//   s           Point mass position vector
//   GM          Gravitational coefficient of point mass
//
// Output:
//   a    		Acceleration (a=d^2r/dt^2)
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------

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


