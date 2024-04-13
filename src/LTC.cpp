#include "LTC.h"
Matrix LTC(double lon,double lat){
    Matrix M = R_y(-1.0 * lat) * R_z(lon);
    // Intercambiar filas para ajustar la convención de orientación
    for (int j = 0; j < 3; ++j) {
        double Aux = M.getElement(1, j);
        M.setElement(1, j, M.getElement(2, j));
        M.setElement(2, j, M.getElement(3, j));
        M.setElement(3, j, Aux);
    }
    return M;
}