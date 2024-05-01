//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include "Matrix.h" // Asegúrate de incluir el archivo de encabezado correcto
#include "Geodetic.h"

int main() {
    // Crear una matriz de prueba
    Matrix r(1, 3);
    r(1, 1) = 6371000.0; // X
    r(1, 2) = 0.0;       // Y
    r(1, 3) = 0.0;       // Z

    // Variables para almacenar los resultados
    double lon, lat, h;

    // Llamar a la función Geodetic
    try {
        Geodetic(r, lon, lat, h);

        // Imprimir los resultados
        std::cout << "Longitude: " << lon << std::endl;
        std::cout << "Latitude: " << lat << std::endl;
        std::cout << "Altitude: " << h << std::endl;
        std::cout << "El test ha pasado con exito" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
