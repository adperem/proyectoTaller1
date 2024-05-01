//
// Created by perez on 02/05/2024.
//
#include "PoleMatrix.h"
#include "cassert"
#include "iostream"

int main() {
    Matrix matrix = PoleMatrix(30, 75);
    Matrix esperada(3, 3);
    esperada(1, 1) = 0.154251;
    esperada(1, 2) = 0.383141;
    esperada(1, 3) = -0.910719;
    esperada(2, 1) = 0;
    esperada(2, 2) = 0.921751;
    esperada(2, 3) = 0.387782;
    esperada(3, 1) = 0.988032;
    esperada(3, 2) = -0.0598159;
    esperada(3, 3) = 0.142181;

    for (int i = 1; i <= matrix.numRows(); i++) {
        for (int j = 1; j <= matrix.numCols(); j++) {
            assert(matrix(i,j) == esperada(i,j));
        }
    }
    std::cout << "Test pasado con éxito" << std::endl;
}