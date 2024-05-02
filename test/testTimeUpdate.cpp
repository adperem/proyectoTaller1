//
// Created by perez on 02/05/2024.
//
#include "TimeUpdate.h"
#include <cassert>
#include <iostream>
#include <cmath>
int main(){
    Matrix Phi(2,2);
    Phi(1,1) = 1;
    Phi(1,2) = 0.1;
    Phi(2,1) = 0;
    Phi(2,2) = 1;

    Matrix P(2,2);
    Phi(1,1) = 1;
    Phi(1,2) = 0;
    Phi(2,1) = 0;
    Phi(2,2) = 1;

    Matrix result(2,2);
    result(1,1) = 3.0100;
    result(1,2) = 0;
    result(2,1) = 0;
    result(2,2) = 1;


    Matrix P_updated = TimeUpdate(P, Phi,5);
    P_updated.print();
    return 0;

}
