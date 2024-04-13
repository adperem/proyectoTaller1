#include "angl.h"
double angl (Matrix vec1,Matrix vec2){

    double small     = 0.00000001;
    double undefined = 999999.1;

    double magv1 = Matrix::norm(vec1);
    double magv2 = Matrix::norm(vec2);

    double temp;
    double theta;

    if (magv1 * magv2 > small * small) {
        temp = Matrix::dot(vec1, vec2) / (magv1 * magv2);
        if (std::fabs(temp) > 1.0) {
            temp = std::copysign(1.0, temp); // std::copysign devuelve el valor absoluto de su primer argumento, con el signo del segundo argumento
        }

        theta = std::acos(temp);
    } else {
        theta = undefined;
    }

    return theta;
}


