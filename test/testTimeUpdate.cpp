//
// Created by m2erez on 02/05/2024.
//
#include "TimeUpdate.h"
#include <cassert>
#include <iostream>
#include <cmath>
int main(){
    Matrix m1(2,2);
    m1(1,1) = 1;
    m1(1,2) = 0.1;
    m1(2,1) = 4;
    m1(2,2) = 5;

    Matrix m2(2,2);
    m2(1,1) = 1;
    m2(1,2) = 6;
    m2(2,1) = 7;
    m2(2,2) = 8;

    Matrix result(2,2);
    result(1,1) =205.6000;
    result(1,2) = 415.8000;
    result(2,1) = 283.2000;
    result(2,2) = 598.6000;
    



    Matrix m2_updated = TimeUpdate(m1, m2);

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            assert(fabs(result(i,j) - m2_updated(i,j))<1e-13);
        }
    }

    std::cout << "Test pasado con éxito" << std::endl;

    return 0;

}
