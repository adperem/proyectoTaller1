//
// Created by perez on 02/05/2024.
//
#include "PrecMatrix.h"
#include "cassert"
#include "iostream"
#include "cmath"

int main(){
    Matrix result = PrecMatrix(24122,24122);
    Matrix expected = identity(3);

    assert(result==expected);
    std::cout << "Test pasado con éxito" << std::endl;
    return 0;
}
