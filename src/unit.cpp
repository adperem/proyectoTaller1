//
// Created by perez on 02/05/2024.
//
#include "unit.h"
Matrix unit(Matrix vec) {

    double small = 0.000001;
    double magv = norm(vec);
    Matrix outvec(1, vec.numCols());
    if (magv > small) {
        for (int i = 1; i <= 3; i++) {
            outvec(1, i) = vec(1, i) / magv;
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            outvec(1,i) = 0.0;
        }
    }
    return outvec;
}


