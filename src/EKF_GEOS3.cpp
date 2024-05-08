//
// Created by adperem on 24/04/2024.
//
#include <fstream>
#include "EKF_GEOS3.h"
#include "Globals.h"

//--------------------------------------------------------------------------
//
//  Initial Orbit Determination using Gauss and Extended Kalman Filter methods
//
// References:
//   O. Montenbruck, E. Gill, "Satellite Orbits - Models, Methods, and
//   Applications", Springer Verlag, Heidelberg, 2000.
//
//   D. Vallado, "Fundamentals of Astrodynamics and Applications",
//   4th Edition, 2013.
//
//   G. Seeber, "Satellite Geodesy", 2nd Edition, 2003.
//
// Last modified:   2020/03/16   Meysam Mahooti
//--------------------------------------------------------------------------
int main() {
    Matrix Cnm = Matrix(181, 181);
    Matrix Snm = Matrix(181, 181);
    std::ifstream fid("GGM03S.txt");
    if (!fid.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo GGM03S.txt");
    }
    for (int n = 0; n <= 180; ++n) {
        for (int m = 0; m <= n; ++m) {
            int n_read, m_read;
            float temp[4];
            fid >> n_read >> m_read >> temp[0] >> temp[1] >> temp[2] >> temp[3];
            Cnm(n + 1, m + 1) = temp[2];
            Snm(n + 1, m + 1) = temp[3];
        }
    }

    // Model parameters
    auxParam = {0, 0, 0};

    // read Earth orientation parameters
    std::ifstream fid_eop("eop19620101.txt");
    //  ----------------------------------------------------------------------------------------------------
    // |  Date    MJD      x         y       UT1-UTC      LOD       dPsi    dEpsilon     dX        dY    DAT
    // |(0h UTC)           "         "          s          s          "        "          "         "     s
    //  ----------------------------------------------------------------------------------------------------
    if (!fid_eop.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo eop19620101.txt");
    }
    // Leer datos de eop19620101.txt y almacenarlos en eopdata
    while (!fid_eop.eof()) {
        Matrix eopdata(1,13);
        for (int i = 0; i < 13; ++i) {
            // Leer el siguiente valor y almacenarlo en la fila actual
            fid_eop >> row[i];
        }
        eopdata.push_back(row);
    }
    fid_eop.close();

}
