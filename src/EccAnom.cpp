#include "EccAnom.h"
/**
 * @brief Function to calculate the eccentric anomaly given mean anomaly and eccentricity.
 * @param M Mean anomaly.
 * @param e Eccentricity.
 * @return Eccentric anomaly.
 */
double EccAnom(double M, double e) {
    int maxit = 15;
    int i = 1;

    // Starting value
    M = fmod(M, 2.0 * M_PI);

    double E;
    if (e < 0.8) {
        E = M;
    } else {
        E = M_PI;
    }

    double f = E - e * sin(E) - M;
    E = E - f / (1.0 - e * cos(E));

    // Iteration
    while (abs(f) > 1e2*M_E){
        f = E - e*sin(E) - M;
        E = E - f / ( 1.0 - e*cos(E) );
        i = i+1;
        if (i==maxit) {
            throw std::runtime_error("convergence problems in EccAnom");
        }
    }
    return E;
}
