#include <math.h>
#include "R_y.h"

Matrix R_y(double angle) {
    double C = cos(angle);
    double S = sin(angle);
    Matrix rotmat(3, 3);

    rotmat.setElement(1, 1, C); rotmat.setElement(1, 2, 0.0); rotmat.setElement(1, 3, -1.0 * S);
    rotmat.setElement(2, 1, 0.0); rotmat.setElement(2, 2, 1.0); rotmat.setElement(2, 3, 0.0);
    rotmat.setElement(3, 1, S); rotmat.setElement(3, 2, 0.0); rotmat.setElement(3, 3, C);

    return rotmat;
}