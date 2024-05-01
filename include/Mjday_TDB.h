//
// Created by perez on 01/05/2024.
//

#ifndef PROYECTOTALLER1_MJDAY_TDB_H
#define PROYECTOTALLER1_MJDAY_TDB_H
//--------------------------------------------------------------------------
//
// Mjday_TDB: Computes the Modified Julian Date for barycentric dynamical
//            time
//
//  Inputs:
//    Mjd_TT      - Modified julian date (TT)
//
//  Output:
//    Mjd_TDB     - Modified julian date (TDB)
//
// Reference:
// Vallado D. A; Fundamentals of Astrodynamics and Applications; McGraw-Hill;
// New York; 3rd edition(2007).
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double Mjday_TDB(double Mjd_TT);

#endif //PROYECTOTALLER1_MJDAY_TDB_H