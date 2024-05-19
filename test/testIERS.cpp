//
// Created by perez on 01/05/2024.
//
#include <iostream>
#include "IERS.h"
#include "Globals.h"
#include "assert.h"

int main() {

    Globals::eop19620101();

    // Supongamos que Mjd_UTC es un valor de tiempo de ejemplo
    double Mjd_UTC = 4.974611015046295e+04;

    // Variables para almacenar los resultados de la función
    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC;

    // Test de la versión de interpolación lineal ('l')
    char interp = 'l';
    try {
        IERS(*Globals::eopdata, Mjd_UTC, interp, x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);

        assert(abs(x_pole + 5.593861831521886e-07) < 1e-10);
        assert(abs(y_pole - 2.335544384403725e-06) < 1e-10);
        assert(abs(UT1_UTC - 0.325764698106523) < 1e-10);
        assert(abs(LOD - 0.002726686357638) < 1e-10);
        assert(abs(dpsi + 1.168819606404215e-07) < 1e-10);
        assert(abs(deps + 0.005112926678243) < 1e-10);
        assert(abs(dx_pole + 8.417641506705226e-10) < 1e-10);
        assert(abs(dy_pole + 1.566188801213420e-09) < 1e-10);
        assert(abs(TAI_UTC - 29) < 1e-10);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test de la versión sin interpolación ('n')

    /* No se llama*/
    /*
    interp = 'n';
    try {
        IERS(*Globals::eopdata, Mjd_UTC, interp, x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);

        assert(abs(x_pole+5.593861831521886e-07)<1e-10);
        assert(abs(y_pole-2.335544384403725e-06)<1e-10);
        assert(abs(UT1_UTC-0.325764698106523)<1e-10);
        assert(abs(LOD-0.002726686357638)<1e-10);
        assert(abs(dpsi+1.168819606404215e-07)<1e-10);
        assert(abs(deps+0.005112926678243)<1e-10);
        assert(abs(dx_pole+8.417641506705226e-10)<1e-10);
        assert(abs(dy_pole+1.566188801213420e-09)<1e-10);
        assert(abs(TAI_UTC-29)<1e-10);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    */
    return 0;
}
