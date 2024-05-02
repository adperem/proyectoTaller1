//
// Created by perez on 02/05/2024.
//
#include "elements.h"

void elements(Matrix y, double& p, double& a, double& e, double& i, double& Omega, double& omega, double& M) {
    double pi2 = 2 * M_PI;

    Matrix r(1, 3);             // Position
    r(1, 1) = y(1, 1);
    r(1, 2) = y(1, 2);
    r(1, 3) = y(1, 3);

    Matrix v(1, 3);              // Velocity
    v(1, 1) = y(1, 4);
    v(1, 2) = y(1, 5);
    v(1, 3) = y(1, 6);

    Matrix h = cross(r, v);                                    // Areal velocity
    double magh = norm(h);
    p = magh * magh /SAT_Const::GM_Earth;
    double H = norm(h);

    Omega = atan2 ( h(1,1), -h(1,2) );                     // Long. ascend. node
    Omega = fmod(Omega, pi2);
    i     = atan2 ( sqrt(h(1,1)*h(1,1)+h(1,2)*h(1,2)), h(1,3) ); // Inclination
    double u= atan2 ( r(1,3)*H, -r(1,1)*h(1,2)+r(1,2)*h(1,1) );    // Arg. of latitude


    double R  = norm(r);                                      // Distance

    a = 1/(2/R-dot(v,v)/SAT_Const::GM_Earth);               // Semi-major axis

    double eCosE = 1-R/a;                                     // e*cos(E)
    double eSinE = dot(r,v)/sqrt(SAT_Const::GM_Earth*a);           // e*sin(E)

    double e2 = eCosE*eCosE +eSinE*eSinE;
    e  = sqrt(e2);                                     // Eccentricity
    double E  = atan2(eSinE,eCosE);                           // Eccentric anomaly

    M  = fmod(E-eSinE,pi2);                             // Mean anomaly

    double nu = atan2(sqrt(1.0-e2)*eSinE, eCosE-e2);          // True anomaly

    omega = fmod(u-nu,pi2);                             // Arg. of perihelion
}