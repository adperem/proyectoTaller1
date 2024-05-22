//
// Created by perez on 02/05/2024.
//
#include "NutAngles.h"
#include <cassert>
#include <iostream>
#include <cmath>



int main() {
    double deps, dpsi; // Declara las variables antes de usarlas
    NutAngles(4.974611085861109e+04, dpsi, deps); // Llama a la función NutAngles

    // Realiza la aserción
    assert(fabs(dpsi- 6.230692866336197e-05 < 1e-15));
    assert(fabs(deps + 3.511084590138603e-05) < 1e-15);

    std::cout<< "Test pasados con éxito"<< std::endl;

    return 0;
}
