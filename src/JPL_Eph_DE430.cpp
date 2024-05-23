//
// Created by adperem on 15/05/2024.
//
#include "JPL_Eph_DE430.h"
#include "Globals.h"

// Función para encontrar el índice de la primera fila donde se cumple la condición
int findFirstMatchingIndex(const Matrix &PC, double JD) {
    int rows = PC.numRows();

    for (int i = 1; i <= rows; ++i) {
        if (PC(i, 1) <= JD && JD <= PC(i, 2)) {
            return i;
        }
    }

    throw std::out_of_range("No matching index found.");
}


Matrix extraer(Matrix m, int inic, int fin) {
    Matrix aux(1, fin - inic);

    for (int i = inic, j = 1; j <= fin - inic; ++i, j++) {
        aux(1, j) = m(1, i);
    }

    return aux;
}

void
JPL_Eph_DE430(double Mjd_TDB, Matrix &r_Mercury, Matrix &r_Venus, Matrix &r_Earth, Matrix &r_Mars, Matrix &r_Jupiter,
              Matrix &r_Saturn, Matrix &r_Uranus, Matrix &r_Neptune, Matrix &r_Pluto, Matrix &r_Moon, Matrix &r_Sun) {

    Matrix PC = *Globals::PC;


    double JD = Mjd_TDB + 2400000.5;
    int i = findFirstMatchingIndex(PC, JD);
    Matrix PCtemp = PC.getRow(i); // es un vector fila
    PCtemp.print();

    double t1 = PCtemp(1, 1) - 2400000.5; // MJD at start of interval

    double dt = Mjd_TDB - t1;

    Matrix temp(1, 4);
    temp(1, 1) = 231;
    temp(1, 2) = 244;
    temp(1, 3) = 257;
    temp(1, 4) = 270;


    Matrix Cx_Earth = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Earth = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Earth = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    temp = temp + 39;
    Matrix Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);

    Cx_Earth = concatenate(Cx_Earth, Cx);
    Cy_Earth = concatenate(Cy_Earth, Cy);
    Cz_Earth = concatenate(Cz_Earth, Cz);

    double j = 0.0;
    double Mjd0 = 0.0;
    if (0.0 <= dt && dt <= 16.0) {
        j = 0.0;
        Mjd0 = t1;
    } else if (16.0 < dt && dt <= 32.0) {
        j = 1.0;
        Mjd0 = t1 + 16.0 * j;
    }

    r_Earth = Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0 + 16, extraer(Cx_Earth, 13 * j + 1, 13 * j + 13),
                     extraer(Cy_Earth, 13 * j + 1, 13 * j + 13),
                     extraer(Cz_Earth, 13 * j + 1, 13 * j + 13)).transpose() * 1e3;

    temp(1, 4);
    temp(1, 1) = 441;
    temp(1, 2) = 454;
    temp(1, 3) = 467;
    temp(1, 4) = 480;
    Matrix Cx_Moon = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Moon = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Moon = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    for (int i = 1; i <= 7; ++i) {
        temp = temp + 39;
        Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
        Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
        Cz = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
        Cx_Moon = concatenate(Cx_Moon, Cx);
        Cy_Moon = concatenate(Cy_Moon, Cy);
        Cz_Moon = concatenate(Cz_Moon, Cz);
    }
    if (0 <= dt && dt <= 4) {
        j = 0;
        Mjd0 = t1;
    } else if (4 < dt && dt <= 8) {
        j = 1;
        Mjd0 = t1 + 4 * j;
    } else if (8 < dt && dt <= 12) {
        j = 2;
        Mjd0 = t1 + 4 * j;
    } else if (12 < dt && dt <= 16) {
        j = 3;
        Mjd0 = t1 + 4 * j;
    } else if (16 < dt && dt <= 20) {
        j = 4;
        Mjd0 = t1 + 4 * j;
    } else if (20 < dt && dt <= 24) {
        j = 5;
        Mjd0 = t1 + 4 * j;
    } else if (24 < dt && dt <= 28) {
        j = 6;
        Mjd0 = t1 + 4 * j;
    } else if (28 < dt && dt <= 32) {
        j = 7;
        Mjd0 = t1 + 4 * j;
    }

    r_Moon = Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0 + 4, extraer(Cx_Moon, 13 * j + 1, 13 * j + 13),
                    extraer(Cy_Moon, 13 * j + 1, 13 * j + 13), extraer(Cz_Moon, 13 * j + 1, 13 * j + 13)).transpose() *
             1e3;

    temp(1, 4);
    temp(1, 1) = 753;
    temp(1, 2) = 764;
    temp(1, 3) = 775;
    temp(1, 4) = 786;
    Matrix Cx_Sun = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Sun = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Sun = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    temp = temp + 33;
    Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Cz = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    Cx_Sun = concatenate(Cx_Sun, Cx);
    Cy_Sun = concatenate(Cy_Sun, Cy);
    Cz_Sun = concatenate(Cz_Sun, Cz);
    if (0 <= dt && dt <= 16) {
        j = 0;
        Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1;
        Mjd0 = t1 + 16 * j;
    }
    r_Sun = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0 + 16, extraer(Cx_Sun, 11 * j + 1, 11 * j + 11),
                   extraer(Cy_Sun, 11 * j + 1, 11 * j + 11), extraer(Cz_Sun, 11 * j + 1, 11 * j + 11)).transpose() *
            1e3;

    temp(1, 4);
    temp(1, 1) = 753;
    temp(1, 2) = 764;
    temp(1, 3) = 775;
    temp(1, 4) = 786;
    Matrix Cx_Mercury = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Mercury = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Mercury = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    for (int i = 1; i <= 3; ++i) {
        temp = temp + 42;
        Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
        Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
        Cz = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
        Cx_Mercury = concatenate(Cx_Mercury, Cx);
        Cy_Mercury = concatenate(Cy_Mercury, Cy);
        Cz_Mercury = concatenate(Cz_Mercury, Cz);
    }
    if (0 <= dt && dt <= 8) {
        j = 0;
        Mjd0 = t1;
    } else if (8 < dt && dt <= 16) {
        j = 1;
        Mjd0 = t1 + 8 * j;
    } else if (16 < dt && dt <= 24) {
        j = 2;
        Mjd0 = t1 + 8 * j;
    } else if (24 < dt && dt <= 32) {
        j = 3;
        Mjd0 = t1 + 8 * j;
    }
    r_Mercury = Cheb3D(Mjd_TDB, 14, Mjd0, Mjd0 + 8, extraer(Cx_Mercury, 14 * j + 1, 14 * j + 14),
                       extraer(Cy_Mercury, 14 * j + 1, 14 * j + 14),
                       extraer(Cz_Mercury, 14 * j + 1, 14 * j + 14)).transpose() * 1e3;

    temp(1, 4);
    temp(1, 1) = 171;
    temp(1, 2) = 181;
    temp(1, 3) = 191;
    temp(1, 4) = 201;
    Matrix Cx_Venus = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Venus = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Venus = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    temp = temp + 30;
    Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Cz = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    Cx_Venus = concatenate(Cx_Venus, Cx);
    Cy_Venus = concatenate(Cy_Venus, Cy);
    Cz_Venus = concatenate(Cz_Venus, Cz);
    if (0 <= dt && dt <= 16) {
        j = 0;
        Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1;
        Mjd0 = t1 + 16 * j;
    }
    r_Venus = Cheb3D(Mjd_TDB, 10, Mjd0, Mjd0 + 16, extraer(Cx_Venus, 10 * j + 1, 10 * j + 10),
                     extraer(Cy_Venus, 10 * j + 1, 10 * j + 10),
                     extraer(Cz_Venus, 10 * j + 1, 10 * j + 10)).transpose() * 1e3;

    temp(1, 4);
    temp(1, 1) = 309;
    temp(1, 2) = 320;
    temp(1, 3) = 331;
    temp(1, 4) = 342;
    Matrix Cx_Mars = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Mars = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Mars = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Mars = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0 + 32, extraer(Cx_Mars, 11 * j + 1, 11 * j + 11),
                    extraer(Cy_Mars, 11 * j + 1, 11 * j + 11), extraer(Cz_Mars, 11 * j + 1, 11 * j + 11)).transpose() *
             1e3;


    temp(1, 4);
    temp(1, 1) = 342;
    temp(1, 2) = 350;
    temp(1, 3) = 358;
    temp(1, 4) = 366;
    Matrix Cx_Jupiter = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Jupiter = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Jupiter = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Jupiter = Cheb3D(Mjd_TDB, 8, Mjd0, Mjd0 + 32, extraer(Cx_Jupiter, 8 * j + 1, 8 * j + 8),
                       extraer(Cy_Jupiter, 8 * j + 1, 8 * j + 8),
                       extraer(Cz_Jupiter, 8 * j + 1, 8 * j + 8)).transpose() * 1e3;


    temp(1, 4);
    temp(1, 1) = 366;
    temp(1, 2) = 373;
    temp(1, 3) = 380;
    temp(1, 4) = 387;
    Matrix Cx_Saturn = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Saturn = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Saturn = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Saturn = Cheb3D(Mjd_TDB, 7, Mjd0, Mjd0 + 32, extraer(Cx_Saturn, 7 * j + 1, 7 * j + 7),
                      extraer(Cy_Saturn, 7 * j + 1, 7 * j + 7), extraer(Cz_Saturn, 7 * j + 1, 7 * j + 7)).transpose() *
               1e3;

    temp(1, 4);
    temp(1, 1) = 378;
    temp(1, 2) = 393;
    temp(1, 3) = 399;
    temp(1, 4) = 405;
    Matrix Cx_Uranus = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Uranus = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Uranus = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Uranus = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32, extraer(Cx_Uranus, 6 * j + 1, 6 * j + 6),
                      extraer(Cy_Uranus, 6 * j + 1, 6 * j + 6), extraer(Cz_Uranus, 6 * j + 1, 6 * j + 6)).transpose() *
               1e3;

    temp(1, 4);
    temp(1, 1) = 405;
    temp(1, 2) = 411;
    temp(1, 3) = 417;
    temp(1, 4) = 423;
    Matrix Cx_Neptune = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Neptune = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Neptune = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Neptune = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32, extraer(Cx_Neptune, 6 * j + 1, 6 * j + 6),
                       extraer(Cy_Neptune, 6 * j + 1, 6 * j + 6),
                       extraer(Cz_Neptune, 6 * j + 1, 6 * j + 6)).transpose() * 1e3;

    temp(1, 4);
    temp(1, 1) = 423;
    temp(1, 2) = 429;
    temp(1, 3) = 435;
    temp(1, 4) = 441;
    Matrix Cx_Pluto = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Pluto = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
    Matrix Cz_Pluto = extraer(PCtemp, temp(1, 3), temp(1, 4) - 1);
    j = 0;
    Mjd0 = t1;
    r_Pluto = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0 + 32, extraer(Cx_Pluto, 6 * j + 1, 6 * j + 6.0),
                     extraer(Cy_Pluto, 6.0 * j + 1, 6.0 * j + 6), extraer(Cz_Pluto, 6.0 * j + 1.0, 6.0 * j + 6.0)).transpose() *
              1e3;

    /*
     * no hacia falta implementar esto
    temp(1, 3);
    for (int j = 819, i = 1; j <= 839; j = j + 10, i++) {
        temp(1, i) = j;
    }
    Matrix Cx_Nutations = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
    Matrix Cy_Nutations = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);

    for (int i = 0; i < 3; ++i) {
        temp = temp + 20;
        Cx = extraer(PCtemp, temp(1, 1), temp(1, 2) - 1);
        Cy = extraer(PCtemp, temp(1, 2), temp(1, 3) - 1);
        Cx_Nutations = concatenate(Cx_Nutations, Cx);
        Cy_Nutations = concatenate(Cy_Nutations, Cy);
    }
    if (0 <= dt && dt <= 8) {
        j = 0;
        Mjd0 = t1;
    } else if (8 < dt && dt <= 16) {
        j = 1;
        Mjd0 = t1 + 8 * j;
    } else if (16 < dt && dt <= 24) {
        j = 2;
        Mjd0 = t1 + 8 * j;
    } else if (24 < dt && dt <= 32) {
        j = 3;
        Mjd0 = t1 + 8 * j;
    }

    Nutations = Cheb3D(Mjd_TDB, 10, Mjd0, Mjd0+8, Cx_Nutations(10*j+1:10*j+10),...
    Cy_Nutations(10*j+1:10*j+10),zeros(10,1))';
    */

    double EMRAT = 81.30056907419062; // DE430
    double EMRAT1 = 1.0 / (1.0 + EMRAT);
    r_Earth = (r_Moon * EMRAT1) - r_Earth;

    r_Mercury = (r_Earth * -1.0) + r_Mercury;
    r_Mercury = (r_Earth * -1.0) + r_Mercury;
    r_Venus = (r_Earth * -1.0) + r_Venus;
    r_Mars = (r_Earth * -1.0) + r_Mars;
    r_Jupiter = (r_Earth * -1.0) + r_Jupiter;
    r_Saturn = (r_Earth * -1.0) + r_Saturn;
    r_Uranus = (r_Earth * -1.0) + r_Uranus;
    r_Neptune = (r_Earth * -1.0) + r_Neptune;
    r_Pluto = (r_Earth * -1.0) + r_Pluto;
    r_Sun = (r_Earth * -1.0) + r_Sun;


}
