//
// Created by perez on 01/05/2024.
//
#include <cmath>
#include "NutAngles.h"
void NutAngles (double Mjd_TT, double& dpsi, double& deps){

    double T  = (Mjd_TT-SAT_Const::MJD_J2000)/36525;
    double T2 = T*T;
    double T3 = T2*T;
    double rev = 360*3600; // arcsec/revolution
    double N_coeff = 106;
    Matrix C(106,9);
    // l  l' F  D Om    dpsi    *T     deps     *T
    C(1, 0) = 0; C(1, 1) =  0; C(1, 2) =  0; C(1, 3) =  0; C(1, 4) =  1; C(1, 5) = -1719960; C(1, 6) = -1742; C(1, 7) =   920250; C(1, 8) =    89; //1
    C(2, 0) = 0; C(2, 1) =  0; C(2, 2) =  0; C(2, 3) =  0; C(2, 4) =  2; C(2, 5) =    20620; C(2, 6) =     2; C(2, 7) =    -8950; C(2, 8) =     5; //2
    C(3, 0) = -2; C(3, 1) =  0; C(3, 2) =  2; C(3, 3) =  0; C(3, 4) =  1; C(3, 5) =      460; C(3, 6) =     0; C(3, 7) =     -240; C(3, 8) =     0; //3
    C(4, 0) = 2; C(4, 1) =  0; C(4, 2) = -2; C(4, 3) =  0; C(4, 4) =  0; C(4, 5) =      110; C(4, 6) =     0; C(4, 7) =        0; C(4, 8) =     0; //4
    C(5, 0) = -2; C(5, 1) =  0; C(5, 2) =  2; C(5, 3) =  0; C(5, 4) =  2; C(5, 5) =      -30; C(5, 6) =     0; C(5, 7) =       10; C(5, 8) =     0; //5
    C(6, 0) = 1; C(6, 1) = -1; C(6, 2) =  0; C(6, 3) = -1; C(6, 4) =  0; C(6, 5) =      -30; C(6, 6) =     0; C(6, 7) =        0; C(6, 8) =     0; //6
    C(7, 0) = 0; C(7, 1) = -2; C(7, 2) =  2; C(7, 3) = -2; C(7, 4) =  1; C(7, 5) =      -20; C(7, 6) =     0; C(7, 7) =       10; C(7, 8) =     0; //7
    C(8, 0) = 2; C(8, 1) =  0; C(8, 2) = -2; C(8, 3) =  0; C(8, 4) =  1; C(8, 5) =       10; C(8, 6) =     0; C(8, 7) =        0; C(8, 8) =     0; //8
    C(9, 0) = 0; C(9, 1) =  0; C(9, 2) =  2; C(9, 3) = -2; C(9, 4) =  2; C(9, 5) =  -131870; C(9, 6) =   -16; C(9, 7) =    57360; C(9, 8) =   -31; //9
    C(10, 0) = 0; C(10, 1) =  1; C(10, 2) =  0; C(10, 3) =  0; C(10, 4) =  0; C(10, 5) =    14260; C(10, 6) =   -34; C(10, 7) =      540; C(10, 8) =    -1; //10
    C(11, 0) = 0; C(11, 1) =  1; C(11, 2) =  2; C(11, 3) = -2; C(11, 4) =  2; C(11, 5) =    -5170; C(11, 6) =    12; C(11, 7) =     2240; C(11, 8) =    -6; //11
    C(12, 0) = 0; C(12, 1) = -1; C(12, 2) =  2; C(12, 3) = -2; C(12, 4) =  2; C(12, 5) =     2170; C(12, 6) =    -5; C(12, 7) =     -950; C(12, 8) =     3; //12
    C(13, 0) = 0; C(13, 1) =  0; C(13, 2) =  2; C(13, 3) = -2; C(13, 4) =  1; C(13, 5) =     1290; C(13, 6) =     1; C(13, 7) =     -700; C(13, 8) =     0; //13
    C(14, 0) = 2; C(14, 1) =  0; C(14, 2) =  0; C(14, 3) = -2; C(14, 4) =  0; C(14, 5) =      480; C(14, 6) =     0; C(14, 7) =       10; C(14, 8) =     0; //14
    C(15, 0) = 0; C(15, 1) =  0; C(15, 2) =  2; C(15, 3) = -2; C(15, 4) =  0; C(15, 5) =     -220; C(15, 6) =     0; C(15, 7) =        0; C(15, 8) =     0; //15
    C(16, 0) = 0; C(16, 1) =  2; C(16, 2) =  0; C(16, 3) =  0; C(16, 4) =  0; C(16, 5) =      170; C(16, 6) =    -1; C(16, 7) =        0; C(16, 8) =     0; //16
    C(17, 0) = 0; C(17, 1) =  1; C(17, 2) =  0; C(17, 3) =  0; C(17, 4) =  1; C(17, 5) =     -150; C(17, 6) =     0; C(17, 7) =       90; C(17, 8) =     0; //17
    C(18, 0) = 0; C(18, 1) =  2; C(18, 2) =  2; C(18, 3) = -2; C(18, 4) =  2; C(18, 5) =     -160; C(18, 6) =     1; C(18, 7) =       70; C(18, 8) =     0; //18
    C(19, 0) = 0; C(19, 1) = -1; C(19, 2) =  0; C(19, 3) =  0; C(19, 4) =  1; C(19, 5) =     -120; C(19, 6) =     0; C(19, 7) =       60; C(19, 8) =     0; //19
    C(20, 0) = -2; C(20, 1) =  0; C(20, 2) =  0; C(20, 3) =  2; C(20, 4) =  1; C(20, 5) =      -60; C(20, 6) =     0; C(20, 7) =       30; C(20, 8) =     0; //20
    C(21, 0) = 0; C(21, 1) = -1; C(21, 2) =  2; C(21, 3) = -2; C(21, 4) =  1; C(21, 5) =      -50; C(21, 6) =     0; C(21, 7) =       30; C(21, 8) =     0; //21
    C(22, 0) = 2; C(22, 1) =  0; C(22, 2) =  0; C(22, 3) = -2; C(22, 4) =  1; C(22, 5) =       40; C(22, 6) =     0; C(22, 7) =      -20; C(22, 8) =     0; //22
    C(23, 0) = 0; C(23, 1) =  1; C(23, 2) =  2; C(23, 3) = -2; C(23, 4) =  1; C(23, 5) =       40; C(23, 6) =     0; C(23, 7) =      -20; C(23, 8) =     0; //23
    C(24, 0) = 1; C(24, 1) =  0; C(24, 2) =  0; C(24, 3) = -1; C(24, 4) =  0; C(24, 5) =      -40; C(24, 6) =     0; C(24, 7) =        0; C(24, 8) =     0; //24
    C(25, 0) = 2; C(25, 1) =  1; C(25, 2) =  0; C(25, 3) = -2; C(25, 4) =  0; C(25, 5) =       10; C(25, 6) =     0; C(25, 7) =        0; C(25, 8) =     0; //25
    C(26, 0) = 0; C(26, 1) =  0; C(26, 2) = -2; C(26, 3) =  2; C(26, 4) =  1; C(26, 5) =       10; C(26, 6) =     0; C(26, 7) =        0; C(26, 8) =     0; //26
    C(27, 0) = 0; C(27, 1) =  1; C(27, 2) = -2; C(27, 3) =  2; C(27, 4) =  0; C(27, 5) =      -10; C(27, 6) =     0; C(27, 7) =        0; C(27, 8) =     0; //27
    C(28, 0) = 0; C(28, 1) =  1; C(28, 2) =  0; C(28, 3) =  0; C(28, 4) =  2; C(28, 5) =       10; C(28, 6) =     0; C(28, 7) =        0; C(28, 8) =     0; //28
    C(29, 0) = -1; C(29, 1) =  0; C(29, 2) =  0; C(29, 3) =  1; C(29, 4) =  1; C(29, 5) =       10; C(29, 6) =     0; C(29, 7) =        0; C(29, 8) =     0; //29
    C(30, 0) = 0; C(30, 1) =  1; C(30, 2) =  2; C(30, 3) = -2; C(30, 4) =  0; C(30, 5) =      -10; C(30, 6) =     0; C(30, 7) =        0; C(30, 8) =     0; //30
    C(31, 0) = 0; C(31, 1) =  0; C(31, 2) =  2; C(31, 3) =  0; C(31, 4) =  2; C(31, 5) =   -22740; C(31, 6) =    -2; C(31, 7) =     9770; C(31, 8) =    -5; //31
    C(32, 0) = 1; C(32, 1) =  0; C(32, 2) =  0; C(32, 3) =  0; C(32, 4) =  0; C(32, 5) =     7120; C(32, 6) =     1; C(32, 7) =      -70; C(32, 8) =     0; //32
    C(33, 0) = 0; C(33, 1) =  0; C(33, 2) =  2; C(33, 3) =  0; C(33, 4) =  1; C(33, 5) =    -3860; C(33, 6) =    -4; C(33, 7) =     2000; C(33, 8) =     0; //33
    C(34, 0) = 1; C(34, 1) =  0; C(34, 2) =  2; C(34, 3) =  0; C(34, 4) =  2; C(34, 5) =    -3010; C(34, 6) =     0; C(34, 7) =     1290; C(34, 8) =    -1; //34
    C(35, 0) = 1; C(35, 1) =  0; C(35, 2) =  0; C(35, 3) = -2; C(35, 4) =  0; C(35, 5) =    -1580; C(35, 6) =     0; C(35, 7) =      -10; C(35, 8) =     0; //35
    C(36, 0) = -1; C(36, 1) =  0; C(36, 2) =  2; C(36, 3) =  0; C(36, 4) =  2; C(36, 5) =     1230; C(36, 6) =     0; C(36, 7) =     -530; C(36, 8) =     0; //36
    C(37, 0) = 0; C(37, 1) =  0; C(37, 2) =  0; C(37, 3) =  2; C(37, 4) =  0; C(37, 5) =      630; C(37, 6) =     0; C(37, 7) =      -20; C(37, 8) =     0; //37
    C(38, 0) = 1; C(38, 1) =  0; C(38, 2) =  0; C(38, 3) =  0; C(38, 4) =  1; C(38, 5) =      630; C(38, 6) =     1; C(38, 7) =     -330; C(38, 8) =     0; //38
    C(39, 0) = -1; C(39, 1) =  0; C(39, 2) =  0; C(39, 3) =  0; C(39, 4) =  1; C(39, 5) =     -580; C(39, 6) =    -1; C(39, 7) =      320; C(39, 8) =     0; //39
    C(40, 0) = -1; C(40, 1) =  0; C(40, 2) =  2; C(40, 3) =  2; C(40, 4) =  2; C(40, 5) =     -590; C(40, 6) =     0; C(40, 7) =      260; C(40, 8) =     0; //40
    C(41, 0) = 1; C(41, 1) =  0; C(41, 2) =  2; C(41, 3) =  0; C(41, 4) =  1; C(41, 5) =     -510; C(41, 6) =     0; C(41, 7) =      270; C(41, 8) =     0; //41
    C(42, 0) = 0; C(42, 1) =  0; C(42, 2) =  2; C(42, 3) =  2; C(42, 4) =  2; C(42, 5) =     -380; C(42, 6) =     0; C(42, 7) =      160; C(42, 8) =     0; //42
    C(43, 0) = 2; C(43, 1) =  0; C(43, 2) =  0; C(43, 3) =  0; C(43, 4) =  0; C(43, 5) =      290; C(43, 6) =     0; C(43, 7) =      -10; C(43, 8) =     0; //43
    C(44, 0) = 1; C(44, 1) =  0; C(44, 2) =  2; C(44, 3) = -2; C(44, 4) =  2; C(44, 5) =      290; C(44, 6) =     0; C(44, 7) =     -120; C(44, 8) =     0; //44
    C(45, 0) = 2; C(45, 1) =  0; C(45, 2) =  2; C(45, 3) =  0; C(45, 4) =  2; C(45, 5) =     -310; C(45, 6) =     0; C(45, 7) =      130; C(45, 8) =     0; //45
    C(46, 0) = 0; C(46, 1) =  0; C(46, 2) =  2; C(46, 3) =  0; C(46, 4) =  0; C(46, 5) =      260; C(46, 6) =     0; C(46, 7) =      -10; C(46, 8) =     0; //46
    C(47, 0) = -1; C(47, 1) =  0; C(47, 2) =  2; C(47, 3) =  0; C(47, 4) =  1; C(47, 5) =      210; C(47, 6) =     0; C(47, 7) =     -100; C(47, 8) =     0; //47
    C(48, 0) = -1; C(48, 1) =  0; C(48, 2) =  0; C(48, 3) =  2; C(48, 4) =  1; C(48, 5) =      160; C(48, 6) =     0; C(48, 7) =      -80; C(48, 8) =     0; //48
    C(49, 0) = 1; C(49, 1) =  0; C(49, 2) =  0; C(49, 3) = -2; C(49, 4) =  1; C(49, 5) =     -130; C(49, 6) =     0; C(49, 7) =       70; C(49, 8) =     0; //49
    C(50, 0) = -1; C(50, 1) =  0; C(50, 2) =  2; C(50, 3) =  2; C(50, 4) =  1; C(50, 5) =     -100; C(50, 6) =     0; C(50, 7) =       50; C(50, 8) =     0; //50
    C(51, 0) = 1; C(51, 1) =  1; C(51, 2) =  0; C(51, 3) = -2; C(51, 4) =  0; C(51, 5) =      -70; C(51, 6) =     0; C(51, 7) =        0; C(51, 8) =     0; //51
    C(52, 0) = 0; C(52, 1) =  1; C(52, 2) =  2; C(52, 3) =  0; C(52, 4) =  2; C(52, 5) =       70; C(52, 6) =     0; C(52, 7) =      -30; C(52, 8) =     0; //52
    C(53, 0) = 0; C(53, 1) = -1; C(53, 2) =  2; C(53, 3) =  0; C(53, 4) =  2; C(53, 5) =      -70; C(53, 6) =     0; C(53, 7) =       30; C(53, 8) =     0; //53
    C(54, 0) = 1; C(54, 1) =  0; C(54, 2) =  2; C(54, 3) =  2; C(54, 4) =  2; C(54, 5) =      -80; C(54, 6) =     0; C(54, 7) =       30; C(54, 8) =     0; //54
    C(55, 0) = 1; C(55, 1) =  0; C(55, 2) =  0; C(55, 3) =  2; C(55, 4) =  0; C(55, 5) =       60; C(55, 6) =     0; C(55, 7) =        0; C(55, 8) =     0; //55
    C(56, 0) = 2; C(56, 1) =  0; C(56, 2) =  2; C(56, 3) = -2; C(56, 4) =  2; C(56, 5) =       60; C(56, 6) =     0; C(56, 7) =      -30; C(56, 8) =     0; //56
    C(57, 0) = 0; C(57, 1) =  0; C(57, 2) =  0; C(57, 3) =  2; C(57, 4) =  1; C(57, 5) =      -60; C(57, 6) =     0; C(57, 7) =       30; C(57, 8) =     0; //57
    C(58, 0) = 0; C(58, 1) =  0; C(58, 2) =  2; C(58, 3) =  2; C(58, 4) =  1; C(58, 5) =      -70; C(58, 6) =     0; C(58, 7) =       30; C(58, 8) =     0; //58
    C(59, 0) = 1; C(59, 1) =  0; C(59, 2) =  2; C(59, 3) = -2; C(59, 4) =  1; C(59, 5) =       60; C(59, 6) =     0; C(59, 7) =      -30; C(59, 8) =     0; //59
    C(60, 0) = 0; C(60, 1) =  0; C(60, 2) =  0; C(60, 3) = -2; C(60, 4) =  1; C(60, 5) =      -50; C(60, 6) =     0; C(60, 7) =       30; C(60, 8) =     0; //60
    C(61, 0) = 1; C(61, 1) = -1; C(61, 2) =  0; C(61, 3) =  0; C(61, 4) =  0; C(61, 5) =       50; C(61, 6) =     0; C(61, 7) =        0; C(61, 8) =     0; //61
    C(62, 0) = 2; C(62, 1) =  0; C(62, 2) =  2; C(62, 3) =  0; C(62, 4) =  1; C(62, 5) =      -50; C(62, 6) =     0; C(62, 7) =       30; C(62, 8) =     0; //62
    C(63, 0) = 0; C(63, 1) =  1; C(63, 2) =  0; C(63, 3) = -2; C(63, 4) =  0; C(63, 5) =      -40; C(63, 6) =     0; C(63, 7) =        0; C(63, 8) =     0; //63
    C(64, 0) = 1; C(64, 1) =  0; C(64, 2) = -2; C(64, 3) =  0; C(64, 4) =  0; C(64, 5) =       40; C(64, 6) =     0; C(64, 7) =        0; C(64, 8) =     0; //64
    C(65, 0) = 0; C(65, 1) =  0; C(65, 2) =  0; C(65, 3) =  1; C(65, 4) =  0; C(65, 5) =      -40; C(65, 6) =     0; C(65, 7) =        0; C(65, 8) =     0; //65
    C(66, 0) = 1; C(66, 1) =  1; C(66, 2) =  0; C(66, 3) =  0; C(66, 4) =  0; C(66, 5) =      -30; C(66, 6) =     0; C(66, 7) =        0; C(66, 8) =     0; //66
    C(67, 0) = 1; C(67, 1) =  0; C(67, 2) =  2; C(67, 3) =  0; C(67, 4) =  0; C(67, 5) =       30; C(67, 6) =     0; C(67, 7) =        0; C(67, 8) =     0; //67
    C(68, 0) = 1; C(68, 1) = -1; C(68, 2) =  2; C(68, 3) =  0; C(68, 4) =  2; C(68, 5) =      -30; C(68, 6) =     0; C(68, 7) =       10; C(68, 8) =     0; //68
    C(69, 0) = -1; C(69, 1) = -1; C(69, 2) =  2; C(69, 3) =  2; C(69, 4) =  2; C(69, 5) =      -30; C(69, 6) =     0; C(69, 7) =       10; C(69, 8) =     0; //69
    C(70, 0) = -2; C(70, 1) =  0; C(70, 2) =  0; C(70, 3) =  0; C(70, 4) =  1; C(70, 5) =      -20; C(70, 6) =     0; C(70, 7) =       10; C(70, 8) =     0; //70
    C(71, 0) = 3; C(71, 1) =  0; C(71, 2) =  2; C(71, 3) =  0; C(71, 4) =  2; C(71, 5) =      -30; C(71, 6) =     0; C(71, 7) =       10; C(71, 8) =     0; //71
    C(72, 0) = 0; C(72, 1) = -1; C(72, 2) =  2; C(72, 3) =  2; C(72, 4) =  2; C(72, 5) =      -30; C(72, 6) =     0; C(72, 7) =       10; C(72, 8) =     0; //72
    C(73, 0) = 1; C(73, 1) =  1; C(73, 2) =  2; C(73, 3) =  0; C(73, 4) =  2; C(73, 5) =       20; C(73, 6) =     0; C(73, 7) =      -10; C(73, 8) =     0; //73
    C(74, 0) = -1; C(74, 1) =  0; C(74, 2) =  2; C(74, 3) = -2; C(74, 4) =  1; C(74, 5) =      -20; C(74, 6) =     0; C(74, 7) =       10; C(74, 8) =     0; //74
    C(75, 0) = 2; C(75, 1) =  0; C(75, 2) =  0; C(75, 3) =  0; C(75, 4) =  1; C(75, 5) =       20; C(75, 6) =     0; C(75, 7) =      -10; C(75, 8) =     0; //75
    C(76, 0) = 1; C(76, 1) =  0; C(76, 2) =  0; C(76, 3) =  0; C(76, 4) =  2; C(76, 5) =      -20; C(76, 6) =     0; C(76, 7) =       10; C(76, 8) =     0; //76
    C(77, 0) = 3; C(77, 1) =  0; C(77, 2) =  0; C(77, 3) =  0; C(77, 4) =  0; C(77, 5) =       20; C(77, 6) =     0; C(77, 7) =        0; C(77, 8) =     0; //77
    C(78, 0) = 0; C(78, 1) =  0; C(78, 2) =  2; C(78, 3) =  1; C(78, 4) =  2; C(78, 5) =       20; C(78, 6) =     0; C(78, 7) =      -10; C(78, 8) =     0; //78
    C(79, 0) = -1; C(79, 1) =  0; C(79, 2) =  0; C(79, 3) =  0; C(79, 4) =  2; C(79, 5) =       10; C(79, 6) =     0; C(79, 7) =      -10; C(79, 8) =     0; //79
    C(80, 0) = 1; C(80, 1) =  0; C(80, 2) =  0; C(80, 3) = -4; C(80, 4) =  0; C(80, 5) =      -10; C(80, 6) =     0; C(80, 7) =        0; C(80, 8) =     0; //80
    C(81, 0) = -2; C(81, 1) =  0; C(81, 2) =  2; C(81, 3) =  2; C(81, 4) =  2; C(81, 5) =       10; C(81, 6) =     0; C(81, 7) =      -10; C(81, 8) =     0; //81
    C(82, 0) = -1; C(82, 1) =  0; C(82, 2) =  2; C(82, 3) =  4; C(82, 4) =  2; C(82, 5) =      -20; C(82, 6) =     0; C(82, 7) =       10; C(82, 8) =     0; //82
    C(83, 0) = 2; C(83, 1) =  0; C(83, 2) =  0; C(83, 3) = -4; C(83, 4) =  0; C(83, 5) =      -10; C(83, 6) =     0; C(83, 7) =        0; C(83, 8) =     0; //83
    C(84, 0) = 1; C(84, 1) =  1; C(84, 2) =  2; C(84, 3) = -2; C(84, 4) =  2; C(84, 5) =       10; C(84, 6) =     0; C(84, 7) =      -10; C(84, 8) =     0; //84
    C(85, 0) = 1; C(85, 1) =  0; C(85, 2) =  2; C(85, 3) =  2; C(85, 4) =  1; C(85, 5) =      -10; C(85, 6) =     0; C(85, 7) =       10; C(85, 8) =     0; //85
    C(86, 0) = -2; C(86, 1) =  0; C(86, 2) =  2; C(86, 3) =  4; C(86, 4) =  2; C(86, 5) =      -10; C(86, 6) =     0; C(86, 7) =       10; C(86, 8) =     0; //86
    C(87, 0) = -1; C(87, 1) =  0; C(87, 2) =  4; C(87, 3) =  0; C(87, 4) =  2; C(87, 5) =       10; C(87, 6) =     0; C(87, 7) =        0; C(87, 8) =     0; //87
    C(88, 0) = 1; C(88, 1) = -1; C(88, 2) =  0; C(88, 3) = -2; C(88, 4) =  0; C(88, 5) =       10; C(88, 6) =     0; C(88, 7) =        0; C(88, 8) =     0; //88
    C(89, 0) = 2; C(89, 1) =  0; C(89, 2) =  2; C(89, 3) = -2; C(89, 4) =  1; C(89, 5) =       10; C(89, 6) =     0; C(89, 7) =      -10; C(89, 8) =     0; //89
    C(90, 0) = 2; C(90, 1) =  0; C(90, 2) =  2; C(90, 3) =  2; C(90, 4) =  2; C(90, 5) =      -10; C(90, 6) =     0; C(90, 7) =        0; C(90, 8) =     0; //90
    C(91, 0) = 1; C(91, 1) =  0; C(91, 2) =  0; C(91, 3) =  2; C(91, 4) =  1; C(91, 5) =      -10; C(91, 6) =     0; C(91, 7) =        0; C(91, 8) =     0; //91
    C(92, 0) = 0; C(92, 1) =  0; C(92, 2) =  4; C(92, 3) = -2; C(92, 4) =  2; C(92, 5) =       10; C(92, 6) =     0; C(92, 7) =        0; C(92, 8) =     0; //92
    C(93, 0) = 3; C(93, 1) =  0; C(93, 2) =  2; C(93, 3) = -2; C(93, 4) =  2; C(93, 5) =       10; C(93, 6) =     0; C(93, 7) =        0; C(93, 8) =     0; //93
    C(94, 0) = 1; C(94, 1) =  0; C(94, 2) =  2; C(94, 3) = -2; C(94, 4) =  0; C(94, 5) =      -10; C(94, 6) =     0; C(94, 7) =        0; C(94, 8) =     0; //94
    C(95, 0) = 0; C(95, 1) =  1; C(95, 2) =  2; C(95, 3) =  0; C(95, 4) =  1; C(95, 5) =       10; C(95, 6) =     0; C(95, 7) =        0; C(95, 8) =     0; //95
    C(96, 0) = -1; C(96, 1) = -1; C(96, 2) =  0; C(96, 3) =  2; C(96, 4) =  1; C(96, 5) =       10; C(96, 6) =     0; C(96, 7) =        0; C(96, 8) =     0; //96
    C(97, 0) = 0; C(97, 1) =  0; C(97, 2) = -2; C(97, 3) =  0; C(97, 4) =  1; C(97, 5) =      -10; C(97, 6) =     0; C(97, 7) =        0; C(97, 8) =     0; //97
    C(98, 0) = 0; C(98, 1) =  0; C(98, 2) =  2; C(98, 3) = -1; C(98, 4) =  2; C(98, 5) =      -10; C(98, 6) =     0; C(98, 7) =        0; C(98, 8) =     0; //98
    C(99, 0) = 0; C(99, 1) =  1; C(99, 2) =  0; C(99, 3) =  2; C(99, 4) =  0; C(99, 5) =      -10; C(99, 6) =     0; C(99, 7) =        0; C(99, 8) =     0; //99
    C(100, 0) = 1; C(100, 1) =  0; C(100, 2) = -2; C(100, 3) = -2; C(100, 4) =  0; C(100, 5) =      -10; C(100, 6) =     0; C(100, 7) =        0; C(100, 8) =     0; //100
    C(101, 0) = 0; C(101, 1) = -1; C(101, 2) =  2; C(101, 3) =  0; C(101, 4) =  1; C(101, 5) =      -10; C(101, 6) =     0; C(101, 7) =        0; C(101, 8) =     0; //101
    C(102, 0) = 1; C(102, 1) =  1; C(102, 2) =  0; C(102, 3) = -2; C(102, 4) =  1; C(102, 5) =      -10; C(102, 6) =     0; C(102, 7) =        0; C(102, 8) =     0; //102
    C(103, 0) = 1; C(103, 1) =  0; C(103, 2) = -2; C(103, 3) =  2; C(103, 4) =  0; C(103, 5) =      -10; C(103, 6) =     0; C(103, 7) =        0; C(103, 8) =     0; //103
    C(104, 0) = 2; C(104, 1) =  0; C(104, 2) =  0; C(104, 3) =  2; C(104, 4) =  0; C(104, 5) =       10; C(104, 6) =     0; C(104, 7) =        0; C(104, 8) =     0; //104
    C(105, 0) = 0; C(105, 1) =  0; C(105, 2) =  2; C(105, 3) =  4; C(105, 4) =  2; C(105, 5) =      -10; C(105, 6) =     0; C(105, 7) =        0; C(105, 8) =     0; //105
    C(106, 0) = 0; C(106, 1) =  1; C(106, 2) =  0; C(106, 3) =  1; C(106, 4) =  0; C(106, 5) =       10; C(106, 6) =     0; C(106, 7) =        0; C(106, 8) =     0; //106

    // Mean arguments of luni-solar motion
    //   l   mean anomaly of the Moon
    //   l'  mean anomaly of the Sun
    //   F   mean argument of latitude
    //   D   mean longitude elongation of the Moon from the Sun
                                                                                                                                                    //   Om  mean longitude of the ascending node
    double l  = fmod(  485866.733 + (1325.0*rev +  715922.633)*T
         + 31.310*T2 + 0.064*T3, rev );
    double lp = fmod ( 1287099.804 + (  99.0*rev + 1292581.224)*T
         -  0.577*T2 - 0.012*T3, rev );
    double F  = fmod (  335778.877 + (1342.0*rev +  295263.137)*T
         - 13.257*T2 + 0.011*T3, rev );
    double D  = fmod ( 1072261.307 + (1236.0*rev + 1105601.328)*T
         -  6.891*T2 + 0.019*T3, rev );
    double Om = fmod (  450160.280 - (   5.0*rev +  482890.539)*T
         +  7.455*T2 + 0.008*T3, rev );

    // Nutation in longitude and obliquity [rad]

    dpsi = 0;
    deps = 0;

    for (int i = 1; i < N_coeff; ++i) {
        double arg = (C(i,1) * l + C(i,2) * lp + C(i,3) * F + C(i,4) * D + C(i,5) * Om) / SAT_Const::Arcs;
        dpsi += (C(i,5) + C(i,6) * T) * sin(arg);
        deps += (C(i,7) + C(i,8) * T) * cos(arg);
    }

    dpsi = 1.0e-5 * dpsi/SAT_Const::Arcs;
    deps = 1.0e-5 * deps/SAT_Const::Arcs;
}