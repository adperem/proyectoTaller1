//
// Created by perez on 02/05/2024.
//
#include "timediff.h"
#include "cmath"
#include "cassert"
#include "iostream"
int main() {
    double UT1_UTC = 0.0;
    double TAI_UTC = 0.0;
    double UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC;

    // Llama a la función timediff
    timediff(UT1_UTC, TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);

    // Verifica los resultados con aserciones
    assert(fabs(UT1_TAI - UT1_UTC + TAI_UTC) < 1e-6);  // UT1_TAI = UT1_UTC - TAI_UTC
    assert(fabs(UTC_GPS - TAI_UTC - 19.0) < 1e-6);      // UTC_GPS = UTC_TAI - GPS_TAI
    assert(fabs(UT1_GPS - UT1_UTC + TAI_UTC - 19.0) < 1e-6);  // UT1_GPS = UT1_TAI - GPS_TAI
    assert(fabs(TT_UTC - 32.184 + TAI_UTC) < 1e-6);     // TT_UTC = TT_TAI - UTC_TAI
    assert(fabs(GPS_UTC + TAI_UTC) < 1e-6);             // GPS_UTC = GPS_TAI - UTC_TAI

    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}