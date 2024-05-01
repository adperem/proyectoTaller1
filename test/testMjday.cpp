//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include <cassert>
#include "Mjday.h" // Suponiendo que este es el nombre del archivo que contiene la función Mjday

int main() {
    // Definir valores de entrada para la función
    double yr = 2024;
    double mon = 4;
    double day = 11;
    double hr = 12;
    double min = 30;
    double sec = 15;

    // Calcular el Modified Julian Date (Mjd) usando la función Mjday
    double expected_Mjd = Mjday(yr, mon, day, hr, min, sec);


    double expected_Mjd_manual = 60411.5210000;

    // Verificar si los valores son iguales usando assert
    assert(fabs(expected_Mjd -expected_Mjd_manual) < 1e-5 );

    // Si assert no falla, imprimir un mensaje de éxito
    std::cout << "Test passed: Mjd matches expected value." << std::endl;

    return 0;
}
