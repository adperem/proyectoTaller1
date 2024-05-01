//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include <cassert>
#include <cmath>
#include "Mjday_TDB.h"

int main() {
    // Fecha de ejemplo en Tiempo Terrestre (TT)
    double Mjd_TT = 2451545.0;

    // Calcular el Modified Julian Date (TDB) usando la función
    double Mjd_TDB = Mjday_TDB(Mjd_TT);

    // Valor esperado para el Modified Julian Date (TDB) en este ejemplo
    double expected_Mjd_TDB = 2451544.9999999;

    // Verificar si el resultado es correcto utilizando assert
    assert(fabs(Mjd_TDB - expected_Mjd_TDB) < 1e-7);

    // Imprimir mensaje si la aserción es exitosa
    std::cout << "Test pasado con éxito: Modified Julian Date (TDB) calculado correctamente." << std::endl;

    return 0;
}
