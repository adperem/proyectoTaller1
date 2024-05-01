//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include "Matrix.h"
#include "IERS.h"

int main() {
    // Crear una matriz de datos de ejemplo (supongamos que tiene 13 filas y 10 columnas)
    Matrix eop(13, 10);eop(4,3) = 59000;
    // Llenar la matriz eop con algunos datos de ejemplo

    // Supongamos que Mjd_UTC es un valor de tiempo de ejemplo
    double Mjd_UTC = 59000.5;

    // Variables para almacenar los resultados de la función
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;

    // Test de la versión de interpolación lineal ('l')
    char interp = 'l';
    try {
        IERS(eop, Mjd_UTC, interp, x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
        // Imprimir los resultados
        std::cout << "Resultados de la interpolación lineal ('l'):" << std::endl;
        std::cout << "x_pole: " << x_pole << std::endl;
        std::cout << "y_pole: " << y_pole << std::endl;
        std::cout << "UT1_UTC: " << UT1_UTC << std::endl;
        std::cout << "LOD: " << LOD << std::endl;
        std::cout << "dpsi: " << dpsi << std::endl;
        std::cout << "deps: " << deps << std::endl;
        std::cout << "dx_pole: " << dx_pole << std::endl;
        std::cout << "dy_pole: " << dy_pole << std::endl;
        std::cout << "TAI_UTC: " << TAI_UTC << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test de la versión sin interpolación ('n')
    interp = 'n';
    try {
        IERS(eop, Mjd_UTC, interp, x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
        // Imprimir los resultados
        std::cout << "\nResultados sin interpolación ('n'):" << std::endl;
        std::cout << "x_pole: " << x_pole << std::endl;
        std::cout << "y_pole: " << y_pole << std::endl;
        std::cout << "UT1_UTC: " << UT1_UTC << std::endl;
        std::cout << "LOD: " << LOD << std::endl;
        std::cout << "dpsi: " << dpsi << std::endl;
        std::cout << "deps: " << deps << std::endl;
        std::cout << "dx_pole: " << dx_pole << std::endl;
        std::cout << "dy_pole: " << dy_pole << std::endl;
        std::cout << "TAI_UTC: " << TAI_UTC << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
