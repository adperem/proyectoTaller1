//
// Created by perez on 02/05/2024.
//
#include "MeasUpdate.h"

void MeasUpdate(Matrix& x, Matrix z, Matrix g, Matrix s, Matrix G, Matrix& P, double n, Matrix &K){
    double m = z.numCols();
    Matrix Inv_W (m, m);

    for (int i = 1; i <= m ; ++i) {
        Inv_W(i,i) = s(1,i)*s(1,i);    // Inverse weight (measurement covariance)
    }

    // Kalman gain
    K = P*G.transpose()*inverse(Inv_W+G*P*G.transpose());

    // State update
    x = x + K*(z-g);

    // Covariance update
    P = (identity(n)-K*G)*P;
}




