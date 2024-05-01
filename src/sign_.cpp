//
// Created by perez on 02/05/2024.
//
#include "sign_.h"

// sign: returns absolute value of a with sign of b
double singn_(double a, double b){
    double result;
    if (b>=0.0){
        result = abs(a);
    }
    else {
        result = -abs(a);
    }
    return result;
}


