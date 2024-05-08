//
// Created by perez on 03/05/2024.
//
#include "cmath"
#include "cassert"
#include "iostream"
#include "elements.h"

int main() {
    Matrix m1(1, 6);
    for (int i = 1; i <= 6; ++i) {
        m1(1, i) = i;
    }
    double p, a, e, i, Omega, omega, M;
    elements(m1, p, a, e, i, Omega, omega, M);

    assert(fabs(p - ) < 1e-10);
    assert(fabs(a - ) < 1e-10);
    assert(fabs(e - ) < 1e-10);
    assert(fabs(i - ) < 1e-10);
    assert(fabs(Omega - ) < 1e-10);
    assert(fabs(omega - ) < 1e-10);
    assert(fabs(M - ) < 1e-10);

    std::cout << "Tests pasados con éxito" << std::endl;
    return 0;
}