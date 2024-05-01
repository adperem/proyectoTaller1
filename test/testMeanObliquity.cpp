//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "MeanObliquity.h"
#include "SAT_Const.h"

int main() {
    double Mjd_TT = 2451545.0; // Modificado Julian Date (TT)

    // Valor esperado calculado externamente
    double expected_MeanObliquity = 0.39666;

    double result = MeanObliquity(Mjd_TT);

    // Verificación del resultado con una tolerancia de 1e-9
    assert(fabs(result - expected_MeanObliquity) < 1e-6);

    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}
