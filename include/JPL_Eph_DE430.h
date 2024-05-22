#ifndef PROYECTOTALLER1_JPL_EPH_DE430_H
#define PROYECTOTALLER1_JPL_EPH_DE430_H
#include "Matrix.h"
#include "Cheb3D.h"
//--------------------------------------------------------------------------
//
// JPL_Eph_DE430: Computes the sun, moon, and nine major planets' equatorial
//                position using JPL Ephemerides
//
// Inputs:
//   Mjd_TDB         Modified julian date of TDB
//
// Output:
//   r_Earth(solar system barycenter (SSB)),r_Mars,r_Mercury,r_Venus,
//   r_Jupiter,r_Saturn,r_Uranus,r_Neptune,r_Pluto,r_Moon,
//   r_Sun(geocentric equatorial position ([m]) referred to the
//   International Celestial Reference Frame (ICRF))
//
// Notes: Light-time is already taken into account
//
// Last modified:   2018/01/11   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Computes the JPL Ephemeris DE430.
 *
 * @param Mjd_TDB Modified Julian Date.
 * @param r_Mercury Position vector of Mercury.
 * @param r_Venus Position vector of Venus.
 * @param r_Earth Position vector of Earth.
 * @param r_Mars Position vector of Mars.
 * @param r_Jupiter Position vector of Jupiter.
 * @param r_Saturn Position vector of Saturn.
 * @param r_Uranus Position vector of Uranus.
 * @param r_Neptune Position vector of Neptune.
 * @param r_Pluto Position vector of Pluto.
 * @param r_Moon Position vector of the Moon.
 * @param r_Sun Position vector of the Sun.
 * Created by adperem on 15/05/2024.
 */
void JPL_Eph_DE430(double Mjd_TDB, Matrix &r_Mercury, Matrix &r_Venus, Matrix &r_Earth, Matrix &r_Mars, Matrix &r_Jupiter,
                   Matrix &r_Saturn, Matrix &r_Uranus, Matrix &r_Neptune, Matrix &r_Pluto, Matrix &r_Moon, Matrix &r_Sun);
#endif //PROYECTOTALLER1_JPL_EPH_DE430_H
