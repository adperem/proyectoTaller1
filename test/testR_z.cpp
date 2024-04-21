//
// Created by perez on 21/04/2024.
//
#include <cassert>
#include <cmath>
#include <iostream>
#include "Matrix.h"
#include "R_z.h"

int main() {
    // Definir el ángulo para la rotación
    double angle = M_PI / 6.0; // Rotación de 30 grados (en radianes)

    // Calcular la matriz de rotación
    Matrix rot_mat = R_z(angle);

    // Crear la matriz de rotación esperada
    Matrix expected_rot_mat(3, 3);
    expected_rot_mat.setElement(1, 1, cos(angle));
    expected_rot_mat.setElement(1, 2, sin(angle));
    expected_rot_mat.setElement(1, 3, 0.0);
    expected_rot_mat.setElement(2, 1, -sin(angle));
    expected_rot_mat.setElement(2, 2, cos(angle));
    expected_rot_mat.setElement(2, 3, 0.0);
    expected_rot_mat.setElement(3, 1, 0.0);
    expected_rot_mat.setElement(3, 2, 0.0);
    expected_rot_mat.setElement(3, 3, 1.0);

    // Verificar si las matrices son iguales
    assert(rot_mat == expected_rot_mat && "Error: La matriz de rotación obtenida es incorrecta.");

    std::cout << "La matriz de rotación obtenida es correcta." << std::endl;

    return 0;
}
