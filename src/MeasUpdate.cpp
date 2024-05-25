//
// Created by perez on 02/05/2024.
//
#include <cstdio>
#include "MeasUpdate.h"

void MeasUpdate(Matrix& x, double z, double g, double s, Matrix G, Matrix& P, double n, Matrix &K){
    double m = 1;
    Matrix Inv_W (m, m);

    for (int i = 1; i <= m ; ++i) {
        Inv_W(i,i) = s*s;    // Inverse weight (measurement covariance)
    }

    // Kalman gain


    Matrix Kaux = P*G.transpose()*(1.0/(Inv_W+G*P*G.transpose())(1,1));

    K(1,1) = Kaux(1,1);
    K(2,1) = Kaux(2,1);
    K(3,1) = Kaux(3,1);
    K(4,1) = Kaux(4,1);
    K(5,1) = Kaux(5,1);
    K(6,1) = Kaux(6,1);


    Matrix aux = K*(z-g);

    x = x+aux;


    // Covariance update
    P = (identity(n)-K*G)*P;


}




