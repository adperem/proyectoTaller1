//
// Created by perez on 03/05/2024.
//
#include "cmath"
#include "cassert"
#include "iostream"
#include "elements.h"

int main() {
    Matrix y(3, 2);
    y(1, 1) = 6221397.62857869;
    y(1, 2) = 4645.04725161806;
    y(2, 1) = 2867713.77965738;
    y(2, 2) = -2752.21591588204;
    y(3, 1) = 3006155.98509949;
    y(3, 2) = -7507.99940987031;


    double p, a, e, i, Omega, omega, M;
    elements(y, p, a, e, i, Omega, omega, M);

    printf("%5.20lf", fabs(Omega - 3.356710766508286));
    assert(fabs(p - 1.200169359721398e+07) < 1e-7);
    assert(fabs(a - 1.894392266071454e+07) < 1e-7);
    assert(fabs(e - 0.605361104987026) < 1e-7);
    assert(fabs(i - 2.026562955350169) < 1e-7);
    assert(fabs(Omega - 3.356710766508286) < 1e-7);
    assert(fabs(omega - 2.737572897725617) < 1e-7);
    assert(fabs(M - 6.271446933419666) < 1e-7);

    std::cout << "Tests pasados con éxito" << std::endl;
    return 0;
}