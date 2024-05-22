//
// Created by perez on 22/05/2024.
//
#include "MeasUpdate.h"

int main() {
    Matrix x(6, 1);
    x(1, 1) = 5738566.57769180;
    x(2, 1) = 3123975.34092958;
    x(3, 1) = 3727114.48156063;
    x(4, 1) = 5199.63329181125;
    x(5, 1) = -2474.43881044665;
    x(6, 1) = -7195.16752553892;
    Matrix G(1, 3);
    G(1, 1) = 9.59123748602946e-08;
    G(1, 2) = 2.16050345227544e-07;
    G(1, 3) = -3.27382770920699e-07;
    Matrix P(3, 3);
    P(1, 1) = 1.00000000000000;
    P(1, 2) = 2.00000000000000;
    P(1, 3) = 3.00000000000000;
    P(2, 1) = 2.00000000000000;
    P(2, 2) = 4.00000000000000;
    P(2, 3) = 5.00000000000000;
    P(3, 1) = 3.00000000000000;
    P(3, 2) = 5.00000000000000;
    P(3, 3) = 6.00000000000000;

    double z = 1.055908489493301;
    double n;
    Matrix K(6, 1);




    MeasUpdate(x, z, 1.058929953815132, 3.909537524467298e-04, G, P, 6,K);


    Matrix Kexpected(6, 1);
    Kexpected(1, 1) = 582691.206464978;
    Kexpected(2, 1) = 1312775.30841890;
    Kexpected(3, 1) = -1989454.89979415;
    Kexpected(4, 1) = 190.367307408249;
    Kexpected(5, 1) = 433.242659443716;
    Kexpected(6, 1) = -660.433799219898;



















}