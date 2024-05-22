/**
 * @brief Evalúa una interpolación de Chebyshev 3D en un punto dado.
 *
 * @param t Tiempo en el que se evalúa la interpolación.
 * @param N Orden de la interpolación.
 * @param Ta Tiempo inicial de la interpolación.
 * @param Tb Tiempo final de la interpolación.
 * @param Cx Coeficientes de Chebyshev para la dimensión x.
 * @param Cy Coeficientes de Chebyshev para la dimensión y.
 * @param Cz Coeficientes de Chebyshev para la dimensión z.
 * @return Matriz que contiene las coordenadas x, y, z evaluadas en el tiempo t.
 * @throw std::invalid_argument Si el tiempo t está fuera del rango [Ta, Tb].
 */
#include <stdexcept>
#include "Cheb3D.h"

Matrix Cheb3D(double t, int N, double Ta, double Tb, Matrix Cx, Matrix Cy, Matrix Cz) {
    // Check validity
    if (t < Ta || t > Tb) {
        throw std::invalid_argument("ERROR: Tiempo fuera de rango en Cheb3D::Value\n");
    }

    // Clenshaw algorithm
    double tau = (2 * t - Ta - Tb) / (Tb - Ta);

    Matrix f1(1, 3);
    Matrix f2(1, 3);

    for (int i = N; i >= 2; i--) {
        Matrix old_f1 = f1;
        Matrix aux(1, 3);
        aux.setElement(1, 1, Cx.getElement(1, i));
        aux.setElement(1, 2, Cy.getElement(1, i));
        aux.setElement(1, 3, Cz.getElement(1, i));
        f1 = (f1 * tau * 2) - f2 + aux;
        f2 = old_f1;
    }

    Matrix aux(1, 3);
    aux.setElement(1, 1, Cx.getElement(1, 1));
    aux.setElement(1, 2, Cy.getElement(1, 1));
    aux.setElement(1, 3, Cz.getElement(1, 1));
    Matrix ChebApp = (f1 * tau) - f2 + aux;

    return ChebApp;
}
