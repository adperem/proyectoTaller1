//
// Created by perez on 02/05/2024.
//
#include <iostream>
#include "sign_.h"
#include "cassert"

int main() {
    assert(singn_(1, -1) < 0);
    assert(singn_(1, 1) > 0);
    std::cout << "Test pasado con éxito" << std::endl;

}