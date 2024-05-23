//
// Created by adperem on 08/05/2024.
//

#include "G_AccelHarmonic.h"
Matrix G_AccelHarmonic( Matrix r, Matrix U, double n_max, double m_max ){
    double d = 1.0;   // Position increment [m]

    Matrix G(3,3);
    Matrix dr(3,1);

    // Gradient
    for (int i = 1; i <= 3 ; i++) {
        // Set offset in i-th component of the position vector
        dr(3, 1);
        dr(i, 1) = d;
        // Acceleration difference
        Matrix aux1 = AccelHarmonic ( r+dr/2.0,U, n_max, m_max );
        aux1.print();
        printf("\n");printf("\n");
        //(r+dr/2.0).print();
        Matrix aux2 = AccelHarmonic ( r-dr/2.0,U, n_max, m_max );
        aux2.print();
        printf("\n");printf("\n");
        //(r-dr/2.0).print();
        Matrix da = AccelHarmonic ( r+dr/2.0,U, n_max, m_max ) - AccelHarmonic ( r-dr/2.0,U, n_max, m_max );
        da.print();
        printf("\n");
        // Derivative with respect to i-th axis

        for (int row = 1; row <= 3; row++) {
            G(row, i) = da(row, 1) / d;
        }

    }
    //G.print();
    return G;


}