//
// Created by perez on 02/05/2024.
//
#include "GHAMatrix.h"
Matrix GHAMatrix (double Mjd_UT1){
    Matrix GHAmat = R_z( gast(Mjd_UT1) );
    return GHAmat;
}