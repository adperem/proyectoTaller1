#ifndef PROYECTOTALLER1_TIMEDIFF_H
#define PROYECTOTALLER1_TIMEDIFF_H
//--------------------------------------------------------------------------
//
// Time differences [s]
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
/**
 * @brief Calculates various time differences.
 * @param UT1_UTC The UT1-UTC time difference [s].
 * @param TAI_UTC The TAI-UTC time difference [s].
 * @param UT1_TAI Output parameter for the UT1-TAI time difference [s].
 * @param UTC_GPS Output parameter for the UTC-GPS time difference [s].
 * @param UT1_GPS Output parameter for the UT1-GPS time difference [s].
 * @param TT_UTC Output parameter for the TT-UTC time difference [s].
 * @param GPS_UTC Output parameter for the GPS-UTC time difference [s].
 *
 * This function calculates various time differences based on input parameters:
 * - UT1-UTC time difference [s]
 * - TAI-UTC time difference [s]
 * The function then calculates and assigns the following time differences to the output parameters:
 * - UT1-TAI time difference [s]
 * - UTC-GPS time difference [s]
 * - UT1-GPS time difference [s]
 * - TT-UTC time difference [s]
 * - GPS-UTC time difference [s]
 * Created by perez on 02/05/2024.
 */
void timediff(double UT1_UTC, double TAI_UTC, double &UT1_TAI, double &UTC_GPS, double &UT1_GPS, double &TT_UTC,
              double &GPS_UTC);
#endif //PROYECTOTALLER1_TIMEDIFF_H
