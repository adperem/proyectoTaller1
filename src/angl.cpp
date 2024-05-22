/**
 * @brief Calcula el ángulo entre dos vectores.
 *
 * @param vec1 Primer vector (matriz de 3x1).
 * @param vec2 Segundo vector (matriz de 3x1).
 * @return Ángulo entre los dos vectores en radianes.
 */
#include "angl.h"
double angl (Matrix vec1,Matrix vec2){

    double small     = 0.00000001;
    double undefined = 999999.1;

    double magv1 = norm(vec1);
    double magv2 = norm(vec2);

    double temp;
    double theta;

    if (magv1 * magv2 > small * small) {
        temp = dot(vec1, vec2) / (magv1 * magv2);
        if (std::fabs(temp) > 1.0) {
            temp = std::copysign(1.0, temp); // std::copysign devuelve el valor absoluto de su primer argumento, con el signo del segundo argumento
        }

        theta = std::acos(temp);
    } else {
        theta = undefined;
    }

    return theta;
}


