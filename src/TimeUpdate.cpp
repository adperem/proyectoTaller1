//
// Created by perez on 02/05/2024.
//
#include "TimeUpdate.h"

Matrix TimeUpdate(Matrix P, Matrix Phi, double Qdt) {
    Matrix P_updated = Phi * P * Phi.transpose() + Qdt;
    return P_updated;
}
