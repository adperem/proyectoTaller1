//
// Created by adperem on 16/05/2024.
//
#include "VarEqn.h"
#include "cassert"
#include "cmath"
#include "iostream"
#include "Globals.h"

int main() {
    Globals::eop19620101();
    Globals::CnmSnm();
    //Globals::ObsLoad();


    Matrix yPhi(1, 42);
    yPhi(1, 1) = 0.765516788149002;
    yPhi(1, 2) = 0.795199901137063;
    yPhi(1, 3) = 0.186872604554379;
    yPhi(1, 4) = 0.489764395788231;
    yPhi(1, 5) = 0.445586200710899;
    yPhi(1, 6) = 0.646313010111265;
    yPhi(1, 7) = 0.709364830858073;
    yPhi(1, 8) = 0.754686681982361;
    yPhi(1, 9) = 0.276025076998578;
    yPhi(1, 10) = 0.679702676853675;
    yPhi(1, 11) = 0.655098003973841;
    yPhi(1, 12) = 0.162611735194631;
    yPhi(1, 13) = 0.118997681558377;
    yPhi(1, 14) = 0.498364051982143;
    yPhi(1, 15) = 0.959743958516081;
    yPhi(1, 16) = 0.340385726666133;
    yPhi(1, 17) = 0.585267750979777;
    yPhi(1, 18) = 0.223811939491137;
    yPhi(1, 19) = 0.751267059305653;
    yPhi(1, 20) = 0.255095115459269;
    yPhi(1, 21) = 0.505957051665142;
    yPhi(1, 22) = 0.699076722656686;
    yPhi(1, 23) = 0.890903252535798;
    yPhi(1, 24) = 0.959291425205444;
    yPhi(1, 25) = 0.547215529963803;
    yPhi(1, 26) = 0.138624442828679;
    yPhi(1, 27) = 0.149294005559057;
    yPhi(1, 28) = 0.257508254123736;
    yPhi(1, 29) = 0.840717255983663;
    yPhi(1, 30) = 0.254282178971531;
    yPhi(1, 31) = 0.814284826068816;
    yPhi(1, 32) = 0.243524968724989;
    yPhi(1, 33) = 0.929263623187228;
    yPhi(1, 34) = 0.349983765984809;
    yPhi(1, 35) = 0.196595250431208;
    yPhi(1, 36) = 0.251083857976031;
    yPhi(1, 37) = 0.616044676146639;
    yPhi(1, 38) = 0.473288848902729;
    yPhi(1, 39) = 0.351659507062997;
    yPhi(1, 40) = 0.830828627896291;
    yPhi(1, 41) = 0.585264091152724;
    yPhi(1, 42) = 0.54972360829114;


    Matrix resutl = VarEqn(3, yPhi);
    Matrix expected(1, 42);
    expected(1, 1) = 0.489764395788231;
    expected(1, 2) = 0.445586200710899;
    expected(1, 3) = 0.646313010111265;
    expected(1, 4) = 6.76332555411903e+143;
    expected(1, 5) = -4.16080772991263e+143;
    expected(1, 6) = 2.73998077760563e+143;
    expected(1, 7) = 0.679702676853675;
    expected(1, 8) = 0.655098003973841;
    expected(1, 9) = 0.162611735194631;
    expected(1, 11) = -1.06039386711736e+145;
    expected(1, 11) = -4.06164561353207e+145;
    expected(1, 11) = -1.53318098108999e+146;
    expected(1, 11) = 0.340385726666133;
    expected(1, 11) = 0.585267750979777;
    expected(1, 11) = 0.223811939491137;
    expected(1, 11) = -2.90036827922322e+145;
    expected(1, 11) = 4.64703664684067e+145;
    expected(1, 11) = -4.78888390110459e+145;
    expected(1, 11) = 0.699076722656686;
    expected(1, 21) = 0.890903252535798;
    expected(1, 21) = 0.959291425205444;
    expected(1, 21) = 2.84586293530507e+145;
    expected(1, 21) = -1.21335394860935e+146;
    expected(1, 21) = -1.29960715483428e+146;
    expected(1, 21) = 0.257508254123736;
    expected(1, 21) = 0.840717255983663;
    expected(1, 21) = 0.254282178971531;
    expected(1, 21) = 2.41951348150868e+145;
    expected(1, 21) = -9.51206501053821e+145;
    expected(1, 31) = -9.18459253318278e+145;
    expected(1, 31) = 0.349983765984809;
    expected(1, 31) = 0.196595250431208;
    expected(1, 31) = 0.251083857976031;
    expected(1, 34) = 3.32119713381145e+145;
    expected(1, 35) = -1.36335312418333e+146;
    expected(1, 36) = -1.38907005189619e+146;
    expected(1, 37) = 0.830828627896291;
    expected(1, 38) = 0.585264091152724;
    expected(1, 39) = 0.54972360829114;
    expected(1, 40) = 4.06937238877196e+144;
    expected(1, 41) = -6.14925883169389e+145;
    expected(1, 42) = -1.22301543783734e+146;
    for (int i = 1; i <= 42; ++i) {
        std::cout<< resutl(i,1 ) <<" , "<< expected(1, i)<<std::endl;
        assert(fabs(resutl(i,1 ) - expected(1, i)) < 1e-10);

    }
    std::cout << "Test testVarEqn passed" << std::endl;


}