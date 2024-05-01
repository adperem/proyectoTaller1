//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "Legendre.h"

int main() {
    double fi = M_PI / 4.0; // Ángulo en radianes
    double n = 3; // Grado del polinomio Legendre
    double m = 2; // Orden del polinomio Legendre

    Matrix pnm(0,0);
    Matrix dpnm(0,0);

    Legendre(n, m, fi, pnm, dpnm);

    // Verificación de algunos valores esperados
    assert(fabs(pnm(1, 1) - 1.0) < 1e-10); // Primer elemento de pnm debe ser 1
    assert(fabs(dpnm(1, 1) - 0.0) < 1e-10); // Primer elemento de dpnm debe ser 0
    assert(fabs(pnm(2, 2) - sqrt(3) * cos(fi)) < 1e-10); // Elemento (2, 2) de pnm
    assert(fabs(dpnm(2, 2) + sqrt(3) * sin(fi)) < 1e-10); // Elemento (2, 2) de dpnm

    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}

