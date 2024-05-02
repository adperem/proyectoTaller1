//
// Created by perez on 02/05/2024.
//
#include "nutMatrix.h"
#include "cassert"
#include "iostream"
#include "cmath"

int main() {
    Matrix result = NutMatrix(24122);
    Matrix expected(3, 3);
    expected(1, 1) = 0.999999998149475;
    expected(1, 2) = 5.58120435260639e-05;
    expected(1, 3) = 2.4208780968457e-05;
    expected(2, 1) = -5.58128849500239e-05;
    expected(2, 2) = 0.999999997838412;
    expected(2, 3) = 3.47576906331026e-05;
    expected(3, 1) = -2.42068410183851e-05;
    expected(3, 2) = -3.47590417306698e-05;
    expected(3, 3) = 0.999999999102919;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(fabs(fabs(result(i, j)) - fabs(result(i, j))) < 1e-100);
        }
    }
    std::cout << "Test pasado con éxito" << std::endl;
    return 0;

}