//
// Created by adperem on 24/04/2024.
//

#ifndef PROYECTOTALLER1_GLOBALS_H
#define PROYECTOTALLER1_GLOBALS_H

#include "Matrix.h"
#include <iostream>
#include <fstream>

class Globals{
public:
    static Matrix *eopdata;

    static void eop19620101(int c);
};

#endif //PROYECTOTALLER1_GLOBALS_H
