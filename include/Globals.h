//
// Created by adperem on 24/04/2024.
//

#ifndef PROYECTOTALLER1_GLOBALS_H
#define PROYECTOTALLER1_GLOBALS_H

#include "Matrix.h"
#include <iostream>
#include <fstream>

struct AuxParam {
    double Mjd_UTC,Mjd_TT;
    int n;
    int m;
};

class Globals{
public:
    static AuxParam auxParam;
    static Matrix eopdata;
    static Matrix Cnm;
    static Matrix Snm;


    static void eop19620101(int c);
    static void GEO(int c);
};

#endif //PROYECTOTALLER1_GLOBALS_H
