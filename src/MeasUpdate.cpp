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



    K = P*G.transpose()*(1.0/(Inv_W+G*P*G.transpose())(1,1));


    Matrix aux = K*(z-g);
    x = x+aux  ;

    // Covariance update
    P = (identity(n)-K*G)*P;
}




