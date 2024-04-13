#include <stdexcept>
#include "Matrix.h"
//--------------------------------------------------------------------------
//
// Chebyshev approximation of 3-dimensional vectors
//
// Inputs:
//     N       Number of coefficients
//     Ta      Begin interval
//     Tb      End interval
//     Cx      Coefficients of Chebyshev polyomial (x-coordinate)
//     Cy      Coefficients of Chebyshev polyomial (y-coordinate)
//     Cz      Coefficients of Chebyshev polyomial (z-coordinate)
//
// Last modified:   2018/01/27   M. Mahooti
//
//--------------------------------------------------------------------------

Matrix Cheb3D(double t, int N, double Ta, double Tb, Matrix Cx, Matrix Cy, Matrix Cz){
    // Check validity
    if (t < Ta || t > Tb) {
        throw std::invalid_argument("ERROR: Tiempo fuera de rango en Cheb3D::Value\n");
    }

    // Clenshaw algorithm
    double tau = (2 * t - Ta - Tb) / (Tb - Ta);

    Matrix f1(1,3);
    Matrix f2(1,3);

    for (int i = N; i >= 2; i--) {
        Matrix old_f1 = f1;
        Matrix aux(1,3);
        aux.setElement(1,1,Cx.getElement(1,i));
        aux.setElement(1,2,Cy.getElement(1,i));
        aux.setElement(1,3,Cz.getElement(1,i));
        f1 = (f1*tau*2) - f2 + aux;
        f2 = old_f1;
    }

    Matrix aux(1,3);
    aux.setElement(1,1,Cx.getElement(1,1));
    aux.setElement(1,2,Cy.getElement(1,1));
    aux.setElement(1,3,Cz.getElement(1,1));
    Matrix ChebApp = (f1 * tau) - f2 + aux;



}




