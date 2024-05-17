//
// Created by adperem on 16/05/2024.
//
#include "VarEqn.h"
#include "cassert"
#include "cmath"
#include "iostream"

int main(){

    Matrix yPhi(1,42);
    yPhi( 1 ,1) = 0.765516788149002;
    yPhi( 2 ,1) = 0.795199901137063;
    yPhi( 3 ,1) = 0.186872604554379;
    yPhi( 4 ,1) = 0.489764395788231;
    yPhi( 5 ,1) = 0.445586200710899;
    yPhi( 6 ,1) = 0.646313010111265;
    yPhi( 7 ,1) = 0.709364830858073;
    yPhi( 8 ,1) = 0.754686681982361;
    yPhi( 9 ,1) = 0.276025076998578;
    yPhi( 10 ,1) =0.679702676853675;
    yPhi( 11 ,1) = 0.655098003973841;
    yPhi( 12 ,1) = 0.162611735194631;
    yPhi( 13 ,1) = 0.118997681558377;
    yPhi( 14 ,1) = 0.498364051982143;
    yPhi( 15 ,1) = 0.959743958516081;
    yPhi( 16 ,1) = 0.340385726666133;
    yPhi( 17 ,1) = 0.585267750979777;
    yPhi( 18 ,1) = 0.223811939491137;
    yPhi( 19 ,1) = 0.751267059305653;
    yPhi( 20 ,1) = 0.255095115459269;
    yPhi( 21 ,1) = 0.505957051665142;
    yPhi( 22 ,1) = 0.699076722656686;
    yPhi( 23 ,1) = 0.890903252535798;
    yPhi( 24 ,1) = 0.959291425205444;
    yPhi( 25 ,1) = 0.547215529963803;
    yPhi( 26 ,1) = 0.138624442828679;
    yPhi( 27 ,1) = 0.149294005559057;
    yPhi( 28 ,1) = 0.257508254123736;
    yPhi( 29 ,1) = 0.840717255983663;
    yPhi( 30 ,1) = 0.254282178971531;
    yPhi( 31 ,1) = 0.814284826068816;
    yPhi( 32 ,1) = 0.243524968724989;
    yPhi( 33 ,1) = 0.929263623187228;
    yPhi( 34 ,1) = 0.349983765984809;
    yPhi( 35 ,1) = 0.196595250431208;
    yPhi( 36 ,1) = 0.251083857976031;
    yPhi( 37 ,1) = 0.616044676146639;
    yPhi( 38 ,1) = 0.473288848902729;
    yPhi( 39 ,1) = 0.351659507062997;
    yPhi( 40 ,1) = 0.830828627896291;
    yPhi( 41 ,1) = 0.585264091152724;
    yPhi( 42 ,1) = 0.54972360829114;


    Matrix resutl = VarEqn(3 , yPhi);
    Matrix expected(1,42);
    expected( 1 ,1) = 0.489764395788231;
    expected( 2 ,1) = 0.445586200710899;
    expected( 3 ,1) = 0.646313010111265;
    expected( 4 ,1) = 6.76332555411903e+143;
    expected( 5 ,1) = -4.16080772991263e+143;
    expected( 6 ,1) = 2.73998077760563e+143;
    expected( 7 ,1) = 0.679702676853675;
    expected( 8 ,1) = 0.655098003973841;
    expected( 9 ,1) = 0.162611735194631;
    expected( 10 ,1) = -1.06039386711736e+145;
    expected( 11 ,1) = -4.06164561353207e+145;
    expected( 12 ,1) = -1.53318098108999e+146;
    expected( 13 ,1) = 0.340385726666133;
    expected( 14 ,1) = 0.585267750979777;
    expected( 15 ,1) = 0.223811939491137;
    expected( 16 ,1) = -2.90036827922322e+145;
    expected( 17 ,1) = 4.64703664684067e+145;
    expected( 18 ,1) = -4.78888390110459e+145;
    expected( 19 ,1) = 0.699076722656686;
    expected( 20 ,1) = 0.890903252535798;
    expected( 21 ,1) = 0.959291425205444;
    expected( 22 ,1) = 2.84586293530507e+145;
    expected( 23 ,1) = -1.21335394860935e+146;
    expected( 24 ,1) = -1.29960715483428e+146;
    expected( 25 ,1) = 0.257508254123736;
    expected( 26 ,1) = 0.840717255983663;
    expected( 27 ,1) = 0.254282178971531;
    expected( 28 ,1) = 2.41951348150868e+145;
    expected( 29 ,1) = -9.51206501053821e+145;
    expected( 30 ,1) = -9.18459253318278e+145;
    expected( 31 ,1) = 0.349983765984809;
    expected( 32 ,1) = 0.196595250431208;
    expected( 33 ,1) = 0.251083857976031;
    expected( 34 ,1) = 3.32119713381145e+145;
    expected( 35 ,1) = -1.36335312418333e+146;
    expected( 36 ,1) = -1.38907005189619e+146;
    expected( 37 ,1) = 0.830828627896291;
    expected( 38 ,1) = 0.585264091152724;
    expected( 39 ,1) = 0.54972360829114;
    expected( 40 ,1) = 4.06937238877196e+144;
    expected( 41 ,1) = -6.14925883169389e+145;
    expected( 42 ,1) = -1.22301543783734e+146;


    for (int i = 1; i <=42 ; ++i) {
        for (int j = 1; j <42 ; ++j) {
            assert(fabs(resutl(i,j) == expected(i,j))<1e-10);
        }
    }
    std::cout << "Test testVarEqn passed" << std::endl;



























































































}