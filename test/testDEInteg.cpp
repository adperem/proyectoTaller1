//
// Created by perez on 23/05/2024.
//
#include "DEInteg.h"
#include "Accel.h"
#include "Globals.h"
#include "assert.h"


int main() {
    Globals::ObsLoad();
    double Mjd0 = 49746.1097222222;
    Matrix Y0_apr(6, 1);
    Y0_apr(1, 1) = 6221397.62857869;
    Y0_apr(2, 1) = 2867713.77965738;
    Y0_apr(3, 1) = 3006155.98509949;
    Y0_apr(4, 1) = 4645.04725161806;
    Y0_apr(5, 1) = -2752.21591588204;
    Y0_apr(6, 1) = -7507.99940987031;

    Matrix Y(6, 1);

    DEInteg(Accel, 0, -((*Globals::obs)(9, 1) - Mjd0) * 86400.0, 1e-13, 1e-6, 6, Y0_apr, Y);

    Matrix expected(6, 1);
    expected(1, 1) = 6221397.61448549;
    expected(2, 1) = 2867713.78800767;
    expected(3, 1) = 3006156.00787896;
    expected(4, 1) = 4645.04726959209;
    expected(5, 1) = -2752.21590759682;
    expected(6, 1) = -7507.99940116467;

    for (int i = 1; i <= 6 ; ++i) {
        assert(fabs(expected(1, 1)-Y(1, 1))< 1e-10);
    }
    printf("test pasado con exito");


    return 0;
}