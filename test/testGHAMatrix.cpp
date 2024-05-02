//
// Created by perez on 02/05/2024.
//
#include "GHAMatrix.h"
#include <iostream>
#include <cmath>
#include <cassert>

int main() {
    Matrix result = GHAMatrix(24122);
    Matrix expected(3, 3);

    expected(1, 1) = 0.316597207739312;
    expected(1, 2) = 0.948560070871461;
    expected(1, 3) = 0;
    expected(2, 1) = -0.948560070871461;
    expected(2, 2) = 0.316597207739312;
    expected(2, 3) = 0;
    expected(3, 1) = 0;
    expected(3, 2) = 0;
    expected(3, 3) = 1;

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            assert(fabs(fabs(result(i, j)) - fabs(expected(i, j))) < 1e-10);
        }
    }
    std::cout << "Test pasado con éxito" << std::endl;
}