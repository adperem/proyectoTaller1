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
    double Mjd_TT, Mjd_UTC = 4.974611128472211e+04;
    int n = 20, m = 20;
    bool sun = true, moon = true, planets = true;
};
/**
 * @brief Clase que almacena los datos globales necesarios para el cálculo.
 */
class Globals {
public:
    static AuxParam auxParam;
    static Matrix *eopdata;
    static Matrix *Cnm;
    static Matrix *Snm;
    static Matrix *PC;
    static Matrix *obs;

    /**
     * @brief Carga los datos de la matriz eopdata  .
     */
    static void eop19620101();
    /**
     * @brief Carga los datos de las matrices Cnm y Snm  .
     */
    static void CnmSnm();
    /**
     * @brief Carga los datos de la matriz PC  .
     */
    static void PCLoad();
    /**
     * @brief Carga los datos de la matriz obs  .
     */
    static void ObsLoad();

};

#endif //PROYECTOTALLER1_GLOBALS_H
