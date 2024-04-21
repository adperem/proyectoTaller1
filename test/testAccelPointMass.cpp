//
// Created by perez on 21/04/2024.
//
#include <iostream>
#include <cassert>
#include "Matrix.h"
#include "AccelPointMass.h"

int main() {
    // Definir las matrices de posición relativa y de posición del punto masivo
    Matrix r(3, 1);
    r.setElement(1, 1, 1.0);
    r.setElement(2, 1, 2.0);
    r.setElement(3, 1, 3.0);

    Matrix s(3, 1);
    s.setElement(1, 1, 4.0);
    s.setElement(2, 1, 5.0);
    s.setElement(3, 1, 6.0);

    // Definir la constante GM
    double GM = 10.0;

    // Calcular la aceleración utilizando la función AccelPointMass
    Matrix a = AccelPointMass(r, s, GM);

    // Calcular la aceleración esperada manualmente
    Matrix d = r - s;
    double norm_d = norm(d);
    double norm_s_cubed = pow(norm(s), 3);
    Matrix expected_a = ((d / pow(norm_d, 3)) + (s / norm_s_cubed)) * (-GM);

    // Verificar si las matrices de aceleración son iguales
    assert(a.equals(expected_a) && "Error: La aceleración calculada es incorrecta.");

    std::cout << "La aceleración calculada es correcta." << std::endl;

    return 0;
}
