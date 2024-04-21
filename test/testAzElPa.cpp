//
// Created by perez on 21/04/2024.
//
#include <iostream>
#include <cassert>
#include "AzElPa.h"

int main() {
    // Definir las variables para almacenar azimuth y elevación
    double Az, El;

    // Definir las matrices para almacenar las parciales
    Matrix dAds(1, 3);
    Matrix dEds(1, 3);

    // Definir el vector de posición
    Matrix s(1, 3);
    s.setElement(1, 1, 3.0);
    s.setElement(1, 2, 4.0);
    s.setElement(1, 3, 5.0);

    // Llamar a la función AzElPa para calcular azimuth, elevación y parciales
    AzElPa(Az, El, dAds, dEds, s);

    // Calcular los valores esperados manualmente
    double rho = sqrt(s.getElement(1,1)*s.getElement(1,1)*s.getElement(1,2)*s.getElement(1,2));
    double expected_Az = atan2(s.getElement(1,1),s.getElement(1,2));
    if (expected_Az < 0.0) {
        expected_Az = expected_Az + 2.0 * M_PI;
    }
    double expected_El =  atan ( s.getElement(1,3) / rho );

    Matrix expected_dAds(1, 3);
    expected_dAds.setElement(1, 1, s.getElement(1, 2) / (rho * rho));
    expected_dAds.setElement(1, 2, -s.getElement(1, 1) / (rho * rho));
    expected_dAds.setElement(1, 3, 0.0);

    Matrix expected_dEds(1, 3);
    expected_dEds.setElement(1, 1, -s.getElement(1, 1) * s.getElement(1, 3) / rho);
    expected_dEds.setElement(1, 2, -s.getElement(1, 2) * s.getElement(1, 3) / rho);
    expected_dEds.setElement(1, 3, rho);
    expected_dEds = expected_dEds / dot(s,s);

    // Verificar si los resultados son iguales a los esperados
    assert(fabs(Az - expected_Az) < 1e-10 && "Error: El valor de azimuth calculado es incorrecto.");
    assert(fabs(El - expected_El) < 1e-10 && "Error: El valor de elevación calculado es incorrecto.");
    assert(dAds.equals(expected_dAds) && "Error: Las parciales de azimuth calculadas son incorrectas.");
    assert(dEds.equals(expected_dEds) && "Error: Las parciales de elevación calculadas son incorrectas.");

    std::cout << "Los resultados calculados son correctos." << std::endl;

    return 0;
}