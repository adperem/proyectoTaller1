//
// Created by adperem on 24/04/2024.
//
#include "Globals.h"



void Globals::eop19620101(){
    Globals::eopdata(21413,13);

    std::ifstream file("eop19620101.txt");
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
    }

    // Leer los datos del archivo y almacenarlos en la matriz
    for (int i = 1; i <= 21413; ++i) {
        for (int j = 1; j <= 13; ++j) {
            double value;
            file >> value;
            eopdata(i, j) = value;
        }
    }

    file.close();
}
