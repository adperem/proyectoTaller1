//
// Created by perez on 02/05/2024.
//
#include "NutAngles.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {
    double deps, dpsi; // Declara las variables antes de usarlas
    NutAngles(2459246, dpsi, deps); // Llama a la función NutAngles

    // Realiza la aserción
    assert(fabs(dpsi)- 8.23714216989103e-05 < 1e-10);
    assert(fabs(deps -  9.14097460043146e-06) < 1e-10);

    std::cout<< "Test pasados con éxito"<< std::endl;

    return 0;
}
