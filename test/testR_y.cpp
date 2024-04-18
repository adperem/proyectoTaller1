//
// Created by adperem on 18/04/2024.
//
#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "R_y.h"

int main() {
    // Definir el ángulo para la rotación
    double angle = M_PI / 3.0; // Rotación de 60 grados (en radianes)

    // Calcular la matriz de rotación
    Matrix rot_mat = R_y(angle);

    // Crear la matriz de rotación esperada
    Matrix expected_rot_mat(3, 3);
    expected_rot_mat.setElement(1, 1, cos(angle));
    expected_rot_mat.setElement(1, 2, 0.0);
    expected_rot_mat.setElement(1, 3, -sin(angle));
    expected_rot_mat.setElement(2, 1, 0.0);
    expected_rot_mat.setElement(2, 2, 1.0);
    expected_rot_mat.setElement(2, 3, 0.0);
    expected_rot_mat.setElement(3, 1, sin(angle));
    expected_rot_mat.setElement(3, 2, 0.0);
    expected_rot_mat.setElement(3, 3, cos(angle));

    // Verificar si las matrices son iguales
    if (rot_mat.equals(expected_rot_mat)) {
        std::cout << "La matriz de rotación obtenida es correcta." << std::endl;
    } else {
        std::cout << "Error: La matriz de rotación obtenida es incorrecta." << std::endl;
    }

    return 0;
}
