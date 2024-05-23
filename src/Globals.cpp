//
// Created by adperem on 24/04/2024.
//
#include <sstream>
#include "Globals.h"
#include "Mjday.h"

Matrix *Globals::eopdata;
Matrix *Globals::Cnm;
Matrix *Globals::Snm;
Matrix *Globals::PC;
AuxParam Globals::auxParam;
Matrix *Globals::obs;


void Globals::eop19620101(){
    Globals::eopdata = new Matrix( 13,21413);

    FILE *fp3 = fopen("../data/eop19620101.txt", "r");
    if(fp3==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }
    for(int i=1; i<=21413; i++){
        fscanf(fp3,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
               &((*Globals::eopdata)(1,i)), &((*Globals::eopdata)(2,i)), &((*Globals::eopdata)(3,i)), &((*Globals::eopdata)(4,i)), &((*Globals::eopdata)(5,i)),
               &((*Globals::eopdata)(6,i)), &((*Globals::eopdata)(7,i)), &((*Globals::eopdata)(8,i)), &((*Globals::eopdata)(9,i)), &((*Globals::eopdata)(10,i)),
               &((*Globals::eopdata)(11,i)), &((*Globals::eopdata)(12,i)), &((*Globals::eopdata)(13,i)));
    }
    fclose(fp3);
}

void Globals::CnmSnm() {
    double dummy;
    Globals::Cnm = new Matrix(181,181);
    Globals::Snm = new Matrix(181,181);
    FILE *fp4 = fopen("../data/GGM03S.txt", "r");
    if (fp4==NULL) {
        std::cerr << "Error al abrir el archivo GGM03S.txt" << std::endl;
    }
    for (int n = 0; n <= 180; ++n) {
        for (int m = 0; m <= n; ++m) {
            fscanf(fp4,"%lf %lf %lf %lf %lf %lf",
                   &dummy, &dummy, &((*Globals::Cnm)(n + 1, m + 1)), &((*Globals::Snm)(n + 1, m + 1)), &dummy, &dummy);

        }
    }
    fclose(fp4);
}

void Globals::PCLoad() {
    Globals::PC = new Matrix(2285, 1020);

    std::ifstream file("../data/DE430Coeff.txt");
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo DE430Coeff.txt" << std::endl;
    }

    // Leer los datos del archivo y almacenarlos en la matriz
    for (int i = 1; i <= 2285; ++i) {
        for (int j = 1; j <= 1020; ++j) {
            double value;
            file >> value;
            (*Globals::PC)(i, j) = value;
        }
    }

    file.close();
}

void Globals::ObsLoad() {
    std::ifstream file("../data/GEOS3.txt");
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo GEOS3.txt"<< std::endl;
        return;
    }

    std::string line;
    for (int i = 1; i <= 46; ++i) {
        if (!std::getline(file, line)) {
            break;
        }

        std::istringstream iss(line);
        int Y, M, D, h, m;
        double s, az, el, Dist;
        std::string temp;

        temp = line.substr(0, 4);
        Y = std::stoi(temp);
        temp = line.substr(5, 2);
        M = std::stoi(temp);
        temp = line.substr(8, 2);
        D = std::stoi(temp);
        temp = line.substr(12, 2);
        h = std::stoi(temp);
        temp = line.substr(15, 2);
        m = std::stoi(temp);
        temp = line.substr(18, 6);
        s = std::stod(temp);
        temp = line.substr(25, 8);
        az = std::stod(temp);
        temp = line.substr(35, 7);
        el = std::stod(temp);
        temp = line.substr(44, 10);
        Dist = std::stod(temp);

        (*Globals::obs)(i, 1) = Mjday(Y, M, D, h, m, s);
        (*Globals::obs)(i, 2) = SAT_Const::Rad * az;
        (*Globals::obs)(i, 3) = SAT_Const::Rad * el;
        (*Globals::obs)(i, 4) = 1e3*Dist;
    }
    file.close();
}



