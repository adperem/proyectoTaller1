//
// Created by perez on 02/05/2024.
//
#include "PoleMatrix.h"
Matrix PoleMatrix(double xp,double yp){
    Matrix PoleMat = R_y(-xp) * R_x(-yp);
    return PoleMat;
}


