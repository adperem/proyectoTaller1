//
// Created by adperem on 18/04/2024.
//
#include <cassert>
#include "Frac.h"
void test(){
    // Casos de prueba
    double testCases[] = {3.14, 5.67, -2.5, 0.0, 1.0};
    double expectedResults[] = {0.14, 0.67, 0.5, 0.0, 0.0};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    // Ejecutar las pruebas
    for (int i = 0; i < numTestCases; ++i) {
        double result = Frac(testCases[i]);
        assert(std::fabs(result - expectedResults[i]) < 0.0001); // Comparación con tolerancia
        std::cout << "Test " << i+1 << " passed." << std::endl;
    }

    std::cout << "All tests passed successfully!" << std::endl;

}