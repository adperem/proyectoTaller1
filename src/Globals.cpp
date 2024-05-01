//
// Created by adperem on 24/04/2024.
//
/*
#include "Globals.h"


Matrix *Globals::eopdata;

void Globals::eop19620101(int c){
    Globals::eopdata = new Matrix(13,c);

    File *fid = fopen("../data/eop19620101.txt","r");
    if (fid == NULL){
        printf("Error!!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<= 0; i++){
        fscanf(fid,"%i %d %d %i %f %f %f %f %f %f %f %f %i",
               &((*Globals::eopdata).setElement(1,i)));
    }

    fid.close()


}
 */