//
// Created by adperem on 08/05/2024.
//

#include "G_AccelHarmonic.h"
Matrix G_AccelHarmonic( Matrix r, Matrix U, double n_max, double m_max ){/*
    double d = 1.0;   // Position increment [m]

    Matrix G(3,3);
    Matrix dr(3,1);

    // Gradient
    for (int i = 1; i <= 3 ; ++i) {
        // Set offset in i-th component of the position vector
        dr(3, 1);
        dr(i, 1) = d;
        // Acceleration difference
        Matrix da = AccelHarmonic ( r+dr/2,U, n_max, m_max ) - AccelHarmonic ( r-dr/2,U, n_max, m_max );
        // Derivative with respect to i-th axis
        G(:,i) = da/d;
        for (int j = 1; j <= G.numRows(); ++j) {
            G(j, i) = da_dd(j); // Suponiendo que 'da_dd' es el vector de derivadas de 'a' respecto a 'd'
        }
    }

*/
}