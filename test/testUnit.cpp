//
// Created by perez on 02/05/2024.
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "unit.h"
int main() {
    // Definir un vector de entrada
    Matrix vec(1, 3);
    vec(1, 1) = 3.0;
    vec(1, 2) = 4.0;
    vec(1, 3) = 0.0;

    // Llamar a la función unit
    Matrix outvec = unit(vec);

    // Verificar los resultados con aserciones
    double magv = norm(vec);
    double small = 0.000001;
    if (magv > small) {
        for (int i = 1; i <= 3; i++) {
            assert(fabs(outvec(1, i) - vec(1, i) / magv) < 1e-6); // Verifica si los valores de outvec son correctos
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            assert(fabs(outvec(1, i) - 0.0) < 1e-6); // Verifica si los valores de outvec son correctos
        }
    }

    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}
