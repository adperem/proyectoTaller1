//
// Created by perez on 01/05/2024.
//

#include <cmath>
#include <iostream>
#include "IERS.h"
#include "SAT_Const.h"

void IERS(Matrix eop, double Mjd_UTC, char interp,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC){
    if (interp =='l'){
        // linear interpolation
        double mjd = (floor(Mjd_UTC));

        int indice = -1;
        for (int i = 1; i < eop.numCols(); i++) {
            if (mjd == fabs(eop(4,i))) {
                indice = i;
                break;
            }
        }
        Matrix preeop = eop.getColumn(indice);
        Matrix nexteop = eop.getColumn(indice+1);

        double mfme = 1440.0*(Mjd_UTC-floor(Mjd_UTC));
        double fixf = mfme/1440.0;
        // Setting of IERS Earth rotation parameters
        // (UT1-UTC [s], TAI-UTC [s], x ["], y ["])

        x_pole  = preeop(5,1)+(nexteop(5,1)-preeop(5,1))*fixf;
        y_pole  = preeop(6,1)+(nexteop(6,1)-preeop(6,1))*fixf;
        UT1_UTC = preeop(7,1)+(nexteop(7,1)-preeop(7,1))*fixf;
        LOD     = preeop(8,1)+(nexteop(8,1)-preeop(8,1))*fixf;
        dpsi    = preeop(9,1)+(nexteop(9,1)-preeop(9,1))*fixf;
        deps    = preeop(10,1)+(nexteop(10,1)-preeop(10,1))*fixf;
        dx_pole = preeop(11,1)+(nexteop(11,1)-preeop(11,1))*fixf;
        dy_pole = preeop(12,1)+(nexteop(12,1)-preeop(12,1))*fixf;
        TAI_UTC = preeop(13,1);

        x_pole  = x_pole/(SAT_Const::Arcs);  // Pole coordinate [rad]
        y_pole  = y_pole/(SAT_Const::Arcs);  // Pole coordinate [rad]
        dpsi    = dpsi/(SAT_Const::Arcs);
        dx_pole = dx_pole/(SAT_Const::Arcs);  // Pole coordinate [rad]
        dy_pole = dy_pole/(SAT_Const::Arcs);  // Pole coordinate [rad]
    }else if(interp =='n'){
        IERS(eop, Mjd_UTC,x_pole,y_pole,UT1_UTC,LOD,
             dpsi,deps,dx_pole,dy_pole,TAI_UTC);
    }else{
        throw std::invalid_argument("invalid value for interp\n");
    }



}
void IERS(Matrix eop, double Mjd_UTC,double& x_pole,double& y_pole,double& UT1_UTC,double& LOD,
          double& dpsi,double& deps,double& dx_pole,double& dy_pole,double& TAI_UTC){
    double mjd = (floor(Mjd_UTC));

    int indice = -1;
    for (int i = 1; i < eop.numCols(); i++) {
        if (mjd == eop(4,i)) {
            indice = i;
            break;
        }
    }
    Matrix preeop = eop.getColumn(indice);
    // Setting of IERS Earth rotation parameters
    // (UT1-UTC [s], TAI-UTC [s], x ["], y ["])
    x_pole  = preeop(5,1)/(SAT_Const::Arcs);  // Pole coordinate [rad]
    y_pole  = preeop(6,1)/(SAT_Const::Arcs);  // Pole coordinate [rad]
    UT1_UTC = preeop(7,1);             // UT1-UTC time difference [s]
    LOD     = preeop(8,1);             // Length of day [s]
    dpsi    = preeop(9,1)/(SAT_Const::Arcs);
    deps    = preeop(10,1)/(SAT_Const::Arcs);
    dx_pole = preeop(11,1)/(SAT_Const::Arcs); // Pole coordinate [rad]
    dy_pole = preeop(12,1)/(SAT_Const::Arcs); // Pole coordinate [rad]
    TAI_UTC = preeop(13,1);            // TAI-UTC time difference [s]
}


