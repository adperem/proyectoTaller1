#include <iostream>
#include <cassert>
#include <stdexcept>
#include "Matrix.h"
#include "Cheb3D.h"

int main() {
    try {
        // Definir los parámetros
        double t = 0.5; // Tiempo
        int N = 3; // Orden del polinomio de Chebyshev
        double Ta = 0.0; // Extremo inferior del intervalo
        double Tb = 1.0; // Extremo superior del intervalo

        // Definir las matrices de coeficientes Cx, Cy, Cz
        Matrix Cx(1, N + 1);
        Cx.setElement(1, 1, 0.0);
        Cx.setElement(1, 2, 1.0);
        Cx.setElement(1, 3, 2.0);
        Cx.setElement(1, 4, 3.0);

        Matrix Cy(1, N + 1);
        Cy.setElement(1, 1, 0.0);
        Cy.setElement(1, 2, 4.0);
        Cy.setElement(1, 3, 5.0);
        Cy.setElement(1, 4, 6.0);

        Matrix Cz(1, N + 1);
        Cz.setElement(1, 1, 0.0);
        Cz.setElement(1, 2, 7.0);
        Cz.setElement(1, 3, 8.0);
        Cz.setElement(1, 4, 9.0);

        // Calcular el valor de Cheb3D
        Matrix result = Cheb3D(t, N, Ta, Tb, Cx, Cy, Cz);

        // Calcular el valor esperado manualmente
        double tau = (2 * t - Ta - Tb) / (Tb - Ta);
        Matrix expected_result(1, 3);
        expected_result.setElement(1, 1, 10.5 * tau * tau * tau + 4.0 * tau * tau + 1.0 * tau); // Coeficientes de Cx, Cy, Cz respectivamente
        expected_result.setElement(1, 2, 12.5 * tau * tau * tau + 5.0 * tau * tau + 2.0 * tau);
        expected_result.setElement(1, 3, 14.5 * tau * tau * tau + 6.0 * tau * tau + 3.0 * tau);

        // Verificar si los resultados son iguales
        assert(result.equals(expected_result) && "Error: El valor de Cheb3D calculado es incorrecto.");

        std::cout << "El valor de Cheb3D calculado es correcto." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Devolver un código de error
    }

    return 0;
}
