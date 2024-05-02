//
// Created by perez on 02/05/2024.
//
#include "gmst.h"
#include "cassert"
#include "cmath"
#include "iostream"
int main(){

    double result = gmst(24122);
    double expected = 1.2487;
    assert(fabs(result - expected)<1e-4);
    std::cout << "Test pasado con éxito" << std::endl;
}