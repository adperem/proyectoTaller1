//
// Created by adperem on 15/05/2024.
//
#include "JPL_Eph_DE430.h"
// Función para encontrar el índice de la primera fila donde se cumple la condición
int findIndex(const Matrix &PC, double JD) {
    int numRows = PC.numRows();

    for (int i = 1; i <= numRows; ++i) {
        if (PC(i, 1) <= JD && JD <= PC(i, 2)) {
            return i; // Devolver el índice de la primera fila donde se cumple la condición
        }
    }

    return -1; // Devolver -1 si no se encuentra ninguna fila que cumpla la condición
}

Matrix concatenar( Matrix m1, Matrix m2){
    Matrix aux = copyMatrix(m1);
    m1(1,m1.numCols()+m2.numCols());
    for (int j = 1; j <= aux.numCols() ; ++j) {
        m1(1,j) = aux(1,j);
    }
    for (int j = aux.numCols()+1; j <= m2.numCols()+aux.numCols(); ++j) {
        m1(1,j) = aux(1,j);
    }
    return m1;
}

Matrix extraer( Matrix m, int inic, int fin){
    Matrix aux(1,fin-inic);

    for (int i = inic, j = 0; i <= fin; ++i, j++) {
        aux(1,j) = m(1,i);
    }

    return aux;
}

void JPL_Eph_DE430 (double Mjd_TDB, Matrix& r_Mercury, Matrix& r_Venus, Matrix& r_Earth, Matrix& r_Mars, Matrix& r_Jupiter, Matrix& r_Saturn, Matrix& r_Uranus, Matrix&
                    r_Neptune, Matrix& r_Pluto, Matrix& r_Moon, Matrix& r_Sun){

    //global PC  /* Carga la variable globa */
    Matrix PC(0,0);

    double JD = Mjd_TDB + 2400000.5;
    int i = findIndex(PC, JD);
    Matrix PCtemp = PC.getRow(i); // es un vector fila

    double t1 = PCtemp(1,1)-2400000.5; // MJD at start of interval

    double dt = Mjd_TDB - t1;

    Matrix temp(1,3);
    for (int j = 231,i = 1; j <=270 ; j=j+13, i++) {
        temp(1,i)=j;
    }

    Matrix Cx_Earth = extraer(PCtemp,temp(1,1), temp(1,2)-1);
    Matrix Cy_Earth = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Earth = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    temp = temp+39;
    Matrix Cx = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz = extraer(PCtemp,temp(1,3),temp(1,4)-1);

    Cx_Earth = concatenar(Cx_Earth,Cx);
    Cy_Earth = concatenar(Cy_Earth,Cy);
    Cz_Earth = concatenar(Cz_Earth,Cz);

    double j= 0.0;
    double Mjd0= 0.0;
    if (0.0 <= dt && dt <= 16.0) {
        j = 0.0;
        Mjd0 = t1;
    } else if (16.0 < dt && dt <= 32.0) {
        j = 1.0;
        Mjd0 = t1 + 16.0 * j;
    }

    r_Earth = Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0+16,extraer(Cx_Earth,13*j+1,13*j+13),
                  extraer(Cy_Earth,13*j+1,13*j+13), extraer(Cz_Earth,13*j+1,13*j+13)).transpose()*1e3;

    temp(1,3);
    for (int j = 441,i = 1; j <=480 ; j=j+13, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Moon = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Moon = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Moon = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    for (int i = 1; i <=7 ; ++i) {
        temp = temp+39;
        Cx = extraer(PCtemp,temp(1,1),temp(1,2)-1);
        Cy = extraer(PCtemp,temp(1,2),temp(1,3)-1);
        Cz = extraer(PCtemp,temp(1,3),temp(1,4)-1);
        Cx_Moon = concatenar(Cx_Moon,Cx);
        Cy_Moon = concatenar(Cy_Moon,Cy);
        Cz_Moon = concatenar(Cz_Moon,Cz);
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

    r_Moon =Cheb3D(Mjd_TDB, 13, Mjd0, Mjd0+4, extraer(Cx_Moon,13*j+1,13*j+13),
                   extraer(Cy_Moon,13*j+1,13*j+13), extraer(Cz_Moon,13*j+1,13*j+13)).transpose()*1e3;

    temp(1,3);
    for (int j = 753,i = 1; j <=786 ; j=j+11, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Sun = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Sun = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Sun = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    temp = temp+33;
    Cx = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Cy = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Cz = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    Cx_Sun = concatenar(Cx_Sun,Cx);
    Cy_Sun = concatenar(Cy_Sun,Cy);
    Cz_Sun = concatenar(Cz_Sun,Cz);
    if (0 <= dt && dt <= 16) {
        j = 0;
        Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1;
        Mjd0 = t1 + 16 * j;
    }
    r_Sun = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0+16, extraer(Cx_Sun,11*j+1,11*j+11),
            extraer(Cy_Sun,11*j+1,11*j+11), extraer(Cz_Sun,11*j+1,11*j+11)).transpose()*1e3;

    temp(1,3);
    for (int j = 3,i = 1; j <=45 ; j=j+14, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Mercury = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Mercury = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Mercury = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    for (int i = 1; i <=3 ; ++i) {
        temp = temp+42;
        Cx = extraer(PCtemp,temp(1,1),temp(1,2)-1);
        Cy = extraer(PCtemp,temp(1,2),temp(1,3)-1);
        Cz = extraer(PCtemp,temp(1,3),temp(1,4)-1);
        Cx_Mercury = concatenar(Cx_Mercury,Cx);
        Cy_Mercury = concatenar(Cy_Mercury,Cy);
        Cz_Mercury = concatenar(Cz_Mercury,Cz);
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
    r_Mercury = Cheb3D(Mjd_TDB, 14, Mjd0, Mjd0+8, extraer(Cx_Mercury,14*j+1,14*j+14),
               extraer(Cy_Mercury,14*j+1,14*j+14), extraer(Cz_Mercury,14*j+1,14*j+14)).transpose()*1e3;

    temp(1,3);
    for (int j = 171,i = 1; j <=201 ; j=j+10, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Venus = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Venus = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Venus = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    temp = temp+30;
    Cx = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Cy = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Cz = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    Cx_Venus = concatenar(Cx_Venus,Cx);
    Cy_Venus = concatenar(Cy_Venus,Cy);
    Cz_Venus = concatenar(Cz_Venus,Cz);
    if (0 <= dt && dt <= 16) {
        j = 0;
        Mjd0 = t1;
    } else if (16 < dt && dt <= 32) {
        j = 1;
        Mjd0 = t1 + 16 * j;
    }
    r_Venus = Cheb3D(Mjd_TDB, 10, Mjd0, Mjd0+16, extraer(Cx_Venus,10*j+1,10*j+10),
             extraer(Cy_Venus,10*j+1,10*j+10), extraer(Cz_Venus,10*j+1,10*j+10)).transpose()*1e3;

    temp(1,3);
    for (int j = 309,i = 1; j <=342 ; j=j+11, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Mars = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Mars = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Mars = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    j=0;
    Mjd0 = t1;
    r_Mars = Cheb3D(Mjd_TDB, 11, Mjd0, Mjd0+32, extraer(Cx_Mars,11*j+1,11*j+11),
            extraer(Cy_Mars,11*j+1,11*j+11), extraer(Cz_Mars,11*j+1,11*j+11)).transpose()*1e3;


    temp(1,3);
    for (int j = 342,i = 1; j <=366 ; j=j+88, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Jupiter = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Jupiter = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Jupiter = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    j=0;
    Mjd0 = t1;
    r_Jupiter = Cheb3D(Mjd_TDB, 8, Mjd0, Mjd0+32, extraer(Cx_Jupiter,8*j+1,8*j+8),
            extraer(Cy_Jupiter,8*j+1,8*j+8), extraer(Cz_Jupiter,8*j+1,8*j+8)).transpose()*1e3;


    temp(1,3);
    for (int j = 366,i = 1; j <=387 ; j=j+7, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Saturn = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Saturn = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Saturn = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    j=0;
    Mjd0 = t1;
    r_Saturn = Cheb3D(Mjd_TDB, 7, Mjd0, Mjd0+32, extraer(Cx_Saturn,7*j+1,7*j+7),
          extraer(Cy_Saturn,7*j+1,7*j+7), extraer(Cz_Saturn,7*j+1,7*j+7)).transpose()*1e3;

    for (int j = 387,i = 1; j <=405 ; j=j+6, i++) {
        temp(1,i)=j;
    }
    Matrix Cx_Uranus = extraer(PCtemp,temp(1,1),temp(1,2)-1);
    Matrix Cy_Uranus = extraer(PCtemp,temp(1,2),temp(1,3)-1);
    Matrix Cz_Uranus = extraer(PCtemp,temp(1,3),temp(1,4)-1);
    j=0;
    Mjd0 = t1;
    r_Uranus = Cheb3D(Mjd_TDB, 6, Mjd0, Mjd0+32, extraer(Cx_Uranus,6*j+1,6*j+6),
      extraer(Cy_Uranus,6*j+1,6*j+6), extraer(Cz_Uranus,6*j+1,6*j+6)).transpose()*1e3;

}
