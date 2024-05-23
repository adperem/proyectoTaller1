#include "doubler.h"
/**
 * @file doubler.h
 * @brief Header file containing the declaration of the doubler function.
 *
 */
/**
* @brief Function to perform orbital trajectory calculations.
* @param cc1 Constant parameter.
* @param cc2 Constant parameter.
* @param magrsite1 Magnitude of position vector of the first site.
* @param magrsite2 Magnitude of position vector of the second site.
* @param magr1in Magnitude of position vector of the first point.
* @param magr2in Magnitude of position vector of the second point.
* @param los1 Matrix representing line of sight for the first point.
* @param los2 Matrix representing line of sight for the second point.
* @param los3 Matrix representing line of sight for the third point.
* @param rsite1 Magnitude of the position vector for the first site.
* @param rsite2 Magnitude of the position vector for the second site.
* @param rsite3 Matrix representing the position vector for the third site.
* @param t1 Time parameter for the first point.
* @param t3 Time parameter for the third point.
* @param direct Character flag indicating direction.
* @param r2 Output parameter for the position vector of the second point.
* @param r3 Output parameter for the position vector of the third point.
* @param f1 Output parameter for the calculated value f1.
* @param f2 Output parameter for the calculated value f2.
* @param q1 Output parameter for the calculated value q1.
* @param magr1 Output parameter for the magnitude of the position vector of the first point.
* @param magr2 Output parameter for the magnitude of the position vector of the second point.
* @param a Output parameter for the semi-major axis.
* @param deltae32 Output parameter for the calculated value deltae32.
 * Created by adperem on 02/05/2024.
*/

void doubler(double cc1, double cc2, double magrsite1, double magrsite2, double magr1in, double magr2in,
             Matrix los1, Matrix los2, Matrix los3, double rsite1, double rsite2, Matrix rsite3, double t1,
             double t3, char direct, Matrix &r2, Matrix &r3, double &f1, double &f2, double &q1, double &magr1,
             double &magr2, double &a, double &deltae32) {

    double rho1 = (-cc1 + sqrt(pow(cc1, 2.0) - 4.0 * (pow(magrsite1, 2.0) - pow(magr1in, 2.0)))) / 2.0;
    double rho2 = (-cc2 + sqrt(pow(cc2, 2.0) - 4.0 * (pow(magrsite2, 2.0) - pow(magr2in, 2.0)))) / 2.0;

    Matrix r1 = los1 * rho1 + rsite1;
    r2 = los2 * rho2 + rsite2;

    magr1 = norm(r1);
    magr2 = norm(r2);

    Matrix w(0, 0);
    if (direct == 'y') {
        w = cross(r1, r2) / (magr1 * magr2);
    } else {
        w = (cross(r1, r2) / (magr1 * magr2)) * -1.0;
    }


    double rho3 = -dot(rsite3, w) / dot(los3, w);
    r3 = los3 * rho3 + rsite3;
    double magr3 = norm(r3);

    double cosdv21 = dot(r2, r1) / (magr2 * magr1);
    double sindv21 = norm(cross(r2, r1)) / (magr2 * magr1);
    double dv21 = atan2(sindv21, cosdv21);

    double cosdv31 = dot(r3, r1) / (magr3 * magr1);
    double sindv31 = sqrt(1.0 - cosdv31 * cosdv31);
    double dv31 = atan2(sindv31, cosdv31);

    double cosdv32 = dot(r3, r2) / (magr3 * magr2);
    double sindv32 = norm(cross(r3, r2)) / (magr3 * magr2);
    double dv32 = atan2(sindv32, cosdv32);

    double c1;
    double c3;
    double p;
    if (dv31 > M_PI) {
        c1 = (magr2 * sindv32) / (magr1 * sindv31);
        c3 = (magr2 * sindv21) / (magr3 * sindv31);
        p = (c1 * magr1 + c3 * magr3 - magr2) / (c1 + c3 - 1.0);
    } else {
        c1 = (magr1 * sindv31) / (magr2 * sindv32);
        c3 = (magr1 * sindv21) / (magr3 * sindv32);
        p = (c3 * magr3 - c1 * magr2 + magr1) / (-c1 + c3 + 1.0);
    }

    double ecosv1 = p / magr1 - 1.0;
    double ecosv2 = p / magr2 - 1.0;
    double ecosv3 = p / magr3 - 1.0;

    double esinv2;
    if (dv21 != M_PI) {
        esinv2 = (-cosdv21 * ecosv2 + ecosv1) / sindv21;
    } else {
        esinv2 = (cosdv32 * ecosv2 - ecosv3) / sindv31;
    }

    double e = sqrt(ecosv2 * ecosv2 + esinv2 * esinv2);
    a = p / (1.0 - (e * e));

    double deltam12;
    double n;
    double deltam32;
    if (e * e < 0.99) {
        n = sqrt(SAT_Const::GM_Earth / a * a * a);

        double s = magr2 / p * sqrt(1.0 - e * e) * esinv2;
        double c = magr2 / p * (e * e + ecosv2);

        double sinde32 = magr3 / sqrt(a * p) * sindv32 - magr3 / p * (1.0 - cosdv32) * s;
        double cosde32 = 1.0 - magr2 * magr3 / (a * p) * (1 - cosdv32);
        deltae32 = atan2(sinde32, cosde32);

        double sinde21 = magr1 / sqrt(a * p) * sindv21 + magr1 / p * (1.0 - cosdv21) * s;
        double cosde21 = 1.0 - magr2 * magr1 / (a * p) * (1.0 - cosdv21);
        double deltae21 = atan2(sinde21, cosde21);

        deltam32 = deltae32 + 2.0 * s * (sin(deltae32 / 2.0)) * (sin(deltae32 / 2.0)) - c * sin(deltae32);
        deltam12 = -deltae21 + 2.0 * s * (sin(deltae21 / 2.0)) * (sin(deltae21 / 2.0)) + c * sin(deltae21);
    } else{
        n = sqrt(SAT_Const::GM_Earth/(-pow(a, 3.0)));

        double s = magr2/p*sqrt(e*e-1.0)*esinv2;
        double c = magr2/p*(e*e+ecosv2);

        double sindh32 = magr3/sqrt(-a*p)*sindv32-magr3/p*(1.0-cosdv32)*s;
        double sindh21 = magr1/sqrt(-a*p)*sindv21+magr1/p*(1.0-cosdv21)*s;

        double deltah32 = log( sindh32 + sqrt(sindh32*sindh32 +1.0) );
        double deltah21 = log( sindh21 + sqrt(sindh21*sindh21 +1.0) );

        deltam32 = -deltah32+2.0*s*(sinh(deltah32/2.0))*(sinh(deltah32/2.0))+c*sinh(deltah32);
        deltam12 = deltah21+2.0*s*(sinh(deltah21/2.0))*(sinh(deltah21/2.0))-c*sinh(deltah21);

        deltae32=deltah32;
    }

    f1 = t1-deltam12/n;
    f2 = t3-deltam32/n;

    q1 = sqrt(f1*f1+f2*f2);
}
