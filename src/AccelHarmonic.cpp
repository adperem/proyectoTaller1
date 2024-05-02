//
// Created by perez on 02/05/2024.
//
#include "AccelHarmonic.h"
/*
double AccelHarmonic(Matrix r,Matrix E,double n_max,double m_max){
    double r_ref = 6378.1363e3;   // Earth's radius [m]; GGM03S
    double gm    = 398600.4415e9; // [m^3/s^2]; GGM03S

                                        // Body-fixed position
    Matrix r_bf = E * r;

    // Auxiliary quantities
    double d = norm(r_bf);                     // distance
    double latgc = asin(r_bf(1,3)/d);
    double lon = atan2(r_bf(1,2),r_bf(1,1));

    Matrix pnm(0,0), dpnm(0,0);
    Legendre(n_max,m_max,latgc,pnm,dpnm);
    double dUdr = 0;
    double dUdlatgc = 0;
    double dUdlon = 0;
    double q3 = 0, q2 = q3, q1 = q2;
    for (int n = 0; n < n_max; ++n) {
        double b1 = (-gm/ pow(d,2))*pow((r_ref/d),n)*(n+1);
        double b2 =  (gm/d)*pow((r_ref/d),n);
        double b3 =  (gm/d)*pow((r_ref/d),n);
        for (int m = 0; m < m_max ; ++m) {
            q1 = q1 + pnm(n+1,m+1)*(Cnm(n+1,m+1)*cos(m*lon)+Snm(n+1,m+1)*sin(m*lon));
            q2 = q2 + dpnm(n+1,m+1)*(Cnm(n+1,m+1)*cos(m*lon)+Snm(n+1,m+1)*sin(m*lon));
            q3 = q3 + m*pnm(n+1,m+1)*(Snm(n+1,m+1)*cos(m*lon)-Cnm(n+1,m+1)*sin(m*lon));
        }
    }
}*/