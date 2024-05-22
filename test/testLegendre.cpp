//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "Legendre.h"

int main() {
    double fi = 0.413090752583063;
    double n = 3;
    double m = 3;

    Matrix pnm(0, 0);
    Matrix dpnm(0, 0);

    Legendre(n, m, fi, pnm, dpnm);
    pnm.print();

    Matrix pnmExpected(4, 4);
    Matrix dpnmExpected(4, 4);

    pnmExpected(1, 1) = 1;
    pnmExpected(1, 2) = 0.695317963011515;
    pnmExpected(1, 3) = -0.577501372399094;
    pnmExpected(1, 4) = -1.16525861472322;
    pnmExpected(2, 1) = 0;
    pnmExpected(2, 2) = 1.58635838646679;
    pnmExpected(2, 3) = 1.42399719193790;
    pnmExpected(2, 4) = -0.288205823728229;
    pnmExpected(3, 1) = 0;
    pnmExpected(3, 2) = 0;
    pnmExpected(3, 3) = 1.62441502154780;
    pnmExpected(3, 4) = 1.72531675052923;
    pnmExpected(4, 1) = 0;
    pnmExpected(4, 2) = 0;
    pnmExpected(4, 3) = 0;
    pnmExpected(4, 4) = 1.60698222588979;

    dpnmExpected(1, 1) =0;
    dpnmExpected(1, 2) =1.58635838646679;
    dpnmExpected(1, 3) =2.46643548627185;
    dpnmExpected(1, 4) =-0.705957209032674;
    dpnmExpected(2, 1) =0;
    dpnmExpected(2, 2) =-0.695317963011515;
    dpnmExpected(2, 3) =2.62467673998379;
    dpnmExpected(2, 4) =0;
    dpnmExpected(3, 1) =0;
    dpnmExpected(3, 2) =0;
    dpnmExpected(3, 3) =-1.42399719193790;
    dpnmExpected(3, 4) =2.42383665852906;
    dpnmExpected(4, 1) =0;
    dpnmExpected(4, 2) =0;
    dpnmExpected(4, 3) =0;
    dpnmExpected(4, 4) =-2.11307284173668;

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            assert(abs(pnm(i, j) - pnmExpected(i, j)) < 1e-10);
            assert(abs(dpnm(i, j) - dpnmExpected(i, j)) < 1e-10);
        }
    }

    std::cout << "Test passed successfully!" << std::endl;

    return 0;

}

