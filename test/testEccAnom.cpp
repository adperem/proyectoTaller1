//
// Created by perez on 21/04/2024.
//
#include <iostream>
#include <cassert>
#include <cmath>
#include "EccAnom.h"

int main() {
    try {
        // Definir los parámetros
        double M = 1.5; // Anomalía media
        double e = 0.5; // Excentricidad

        // Calcular la anomalía excéntrica
        double E = EccAnom(M, e);

        // Calcular el valor esperado manualmente
        double expected_E = 1.9622; // Valor esperado para M=1.5 y e=0.5 (puede variar dependiendo de la precisión requerida)

        // Verificar si los resultados son iguales con una tolerancia de 1e-6
        assert(std::abs(E - expected_E) < 1e-1 && "Error: La anomalía excéntrica calculada es incorrecta.");

        std::cout << "La anomalía excéntrica calculada es correcta." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Devolver un código de error
    }

    return 0;
}
