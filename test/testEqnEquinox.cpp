//
// Created by perez on 02/05/2024.
//
#include "EqnEquinox.h"
#include "cmath"
#include "cassert"
#include "iostream"
int main(){

    double result = EqnEquinox(24122);
    double expected = -5.58120435604911e-05;

    assert(fabs(fabs(result)- fabs(expected))<1e-10);
    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}
