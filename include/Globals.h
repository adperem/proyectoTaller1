//
// Created by adperem on 24/04/2024.
//

#ifndef PROYECTOTALLER1_GLOBALS_H
#define PROYECTOTALLER1_GLOBALS_H

#include "Matrix.h"
#include "SAT_Const.h"
#include <iostream>
#include <fstream>

struct AuxParam {
    double Mjd_UTC = 4.974611128472211e+04;
    int n = 20, m = 20;
    bool sun = true, moon = true, planets = true;
    double Mjd_TT;
};

class Globals {
public:
    static AuxParam auxParam;
    static Matrix *eopdata;
    static Matrix *Cnm;
    static Matrix *Snm;
    static Matrix *PC;
    static Matrix *obs;


    static void eop19620101();

    static void CnmSnm();

    static void PCLoad();
    static void ObsLoad();

    static void GEO(int c);

};

#endif //PROYECTOTALLER1_GLOBALS_H
