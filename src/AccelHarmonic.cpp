/**
 * @brief Calcula la aceleración debido al campo gravitatorio armónico de la Tierra.
 *
 * @param r Posición del satélite en coordenadas inerciales (matriz de 3x1).
 * @param E Matriz de transformación del sistema de coordenadas inerciales al sistema de coordenadas fijas en la Tierra.
 * @param n_max Orden máximo del desarrollo armónico.
 * @param m_max Grado máximo del desarrollo armónico.
 * @return Matriz que contiene la aceleración del satélite en coordenadas inerciales (matriz de 3x1).
 *
 * Created by perez on 02/05/2024.
 */
#include "AccelHarmonic.h"
#include "Globals.h"

Matrix AccelHarmonic(Matrix r, Matrix E, int n_max, int m_max) {

    double r_ref = 6378.1363e3;   // Earth's radius [m]; GGM03S
    double gm = 398600.4415e9; // [m^3/s^2]; GGM03S

    // Body-fixed position
    Matrix r_bf = E * r;


    // Auxiliary quantities
    double d = norm(r_bf);                     // distance
    double latgc = asin(r_bf(3, 1) / d);
    double lon = atan2(r_bf(2, 1), r_bf(1, 1));

    Matrix pnm(n_max+1, m_max+1), dpnm(n_max+1, m_max+1);
    Legendre(n_max, m_max, latgc, pnm, dpnm);

    double dUdr = 0.0;
    double dUdlatgc = 0.0;
    double dUdlon = 0.0;
    double q1 = 0.0;
    double q2 = 0.0;
    double q3 = 0.0;

    double b1 = 0.0;
    double b2 = 0.0;
    double b3 = 0.0;
    double ax = 0.0;
    double ay = 0.0;
    double az = 0.0;
    double r2xy= 0.0;
    for (int n = 0; n <= n_max; n++) {
        b1 = (-gm / pow(d, 2)) * pow((r_ref / d), n) * (n + 1);
        b2 = (gm / d) * pow((r_ref / d), n);
        b3 = (gm / d) * pow((r_ref / d), n);

        for (int m = 0; m <= m_max; m++) {

            q1 = q1 + pnm(n + 1, m + 1) *
                      ((*Globals::Cnm)(n + 1, m + 1) * cos(m * lon) + (*Globals::Snm)(n + 1, m + 1) * sin(m * lon));
            q2 = q2 + dpnm(n + 1, m + 1) *
                      ((*Globals::Cnm)(n + 1, m + 1) * cos(m * lon) + (*Globals::Snm)(n + 1, m + 1) * sin(m * lon));
            q3 = q3 + m * pnm(n + 1, m + 1) *
                      ((*Globals::Snm)(n + 1, m + 1) * cos(m * lon) - (*Globals::Cnm)(n + 1, m + 1) * sin(m * lon));
        }
        dUdr = dUdr + q1 * b1;
        dUdlatgc = dUdlatgc + q2 * b2;
        dUdlon = dUdlon + q3 * b3;
        q3 = 0.0;
        q2 = q3;
        q1 = q2;
    }
    // Body-fixed acceleration

    r2xy = pow(r_bf(1,1), 2) + pow(r_bf(2,1), 2);

    ax = (1.0 / d * dUdr - r_bf(3,1) / ((d*d) * sqrt(r2xy)) * dUdlatgc) * r_bf(1,1) - (1.0 / r2xy * dUdlon) * r_bf(2,1);
    ay = (1.0 / d * dUdr - r_bf(3,1) / ((d*d) * sqrt(r2xy)) * dUdlatgc) * r_bf(2,1) + (1.0 / r2xy * dUdlon) * r_bf(1,1);
    az = 1.0 / d * dUdr * r_bf(3,1) + sqrt(r2xy) / (d*d) * dUdlatgc;

    Matrix a_bf(3,1);
    a_bf(1,1) = ax;
    a_bf(2,1) = ay;
    a_bf(3,1) = az;



    // Inertial acceleration
    return E.transpose()*a_bf;
}