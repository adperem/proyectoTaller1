//
// Created by perez on 02/05/2024.
//
#include "gast.h"
#include <iostream>
#include <cassert>
#include <cmath>
int main(){
    double result = gast(24122);
    double expected = 1.24865632134115;

    assert(fabs(result-expected)<1e-15);
    std::cout << "Test pasado con éxito" << std::endl;

}