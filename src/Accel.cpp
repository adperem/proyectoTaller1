#include "Accel.h"
/**
 * @brief Calcula la aceleración de un satélite en función de varios parámetros astronómicos.
 *
 * @param x Tiempo en segundos desde la época de referencia.
 * @param Y Matriz que contiene las posiciones y velocidades del satélite.
 * @return Matriz que contiene las derivadas de las posiciones y velocidades del satélite.
 * Creado por perez el 19/05/2024.
 */

// Created by perez on 19/05/2024.

Matrix Accel(double x, Matrix Y) {

    double x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;
    //double Mjd_UTC = 59000.5;

    Matrix eopdata = (*Globals::eopdata);
    IERS(eopdata, Globals::auxParam.Mjd_UTC + x / 86400.0, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);

    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    double Mjd_UT1 = Globals::auxParam.Mjd_UTC + (x / 86400.0) + (UT1_UTC / 86400.0);
    double Mjd_TT = Globals::auxParam.Mjd_UTC + (x / 86400.0) + (TT_UTC / 86400.0);

    Matrix P = PrecMatrix(SAT_Const::MJD_J2000, Mjd_TT);
    Matrix N = NutMatrix(Mjd_TT);
    Matrix T = N * P;
    Matrix E = PoleMatrix(x_pole, y_pole) * GHAMatrix(Mjd_UT1) * T;

    double MJD_TDB = Mjday_TDB(Mjd_TT);
    Matrix r_Mercury(0, 0), r_Venus(0, 0), r_Earth(0, 0), r_Mars(0, 0), r_Jupiter(0, 0), r_Saturn(0, 0), r_Uranus(0,
                                                                                                                  0), r_Neptune(
            0, 0), r_Pluto(0, 0), r_Moon(0, 0), r_Sun(0, 0);
    JPL_Eph_DE430(MJD_TDB, r_Mercury, r_Venus, r_Earth, r_Mars, r_Jupiter, r_Saturn, r_Uranus, r_Neptune, r_Pluto,
                  r_Moon, r_Sun);

    // Acceleration due to harmonic gravity field
    Matrix aux(3, 1);
    aux(1, 1) = Y(1, 1);
    aux(2, 1) = Y(2, 1);
    aux(3, 1) = Y(3, 1);
    Matrix a = AccelHarmonic(aux, E, Globals::auxParam.n, Globals::auxParam.m);

    // Luni-solar perturbations
    if (Globals::auxParam.sun) a = a + AccelPointMass(aux, r_Sun, SAT_Const::GM_Sun);


    if (Globals::auxParam.moon) a = a + AccelPointMass(aux, r_Moon, SAT_Const::GM_Moon);

    // Planetary perturbations
    if (Globals::auxParam.planets) {
        a = a + AccelPointMass(aux, r_Mercury, SAT_Const::GM_Mercury);
        a = a + AccelPointMass(aux, r_Venus, SAT_Const::GM_Venus);
        a = a + AccelPointMass(aux, r_Mars, SAT_Const::GM_Mars);
        a = a + AccelPointMass(aux, r_Jupiter, SAT_Const::GM_Jupiter);
        a = a + AccelPointMass(aux, r_Saturn, SAT_Const::GM_Saturn);
        a = a + AccelPointMass(aux, r_Uranus, SAT_Const::GM_Uranus);
        a = a + AccelPointMass(aux, r_Neptune, SAT_Const::GM_Neptune);
        a = a + AccelPointMass(aux, r_Pluto, SAT_Const::GM_Pluto);
    }

    Matrix aux2(3, 1);
    aux2(1, 1) = Y(4, 1);
    aux2(2, 1) = Y(5, 1);
    aux2(3, 1) = Y(6, 1);

    Matrix dY = concatenate(aux2, a);
    return dY;

}


