//
// Created by adperem on 22/05/2024.
//
#include "G_AccelHarmonic.h"
#include "assert.h"

int main() {
    Globals::CnmSnm();

    Matrix r(3, 1);
    r(1, 1) = 5542555.93722861;
    r(2, 1) = 3213514.86734920;
    r(3, 1) = 3990892.97587685;

    Matrix U(3, 3);
    U(1, 1) = -0.976675972331716;
    U(1, 2) = 0.214718082511189;
    U(1, 3) = -0.000436019054674645;
    U(2, 1) = -0.214718043811152;
    U(2, 2) = -0.976676068937815;
    U(2, 3) = -0.000134261271504216;
    U(3, 1) = -0.000454677699074514;
    U(3, 2) = -3.75085994087200e-05;
    U(3, 3) = 0.999999895930642;

    int n_max = 20;
    int m_max = 20;
    Matrix result = G_AccelHarmonic(r, U, n_max, m_max);
    Matrix expected(3, 3);
    expected(1, 1) = 20357959754e-07;
    expected(1, 2) = 0.0;
    expected(1, 3) = 0.0;
    expected(2, 1) = 8.676515932393158e-07;
    expected(2, 2) = 0.0;
    expected(2, 3) = 0.0;
    expected(3, 1) = 1.081693540072592e-06;
    expected(3, 2) = 0.0;
    expected(3, 3) = 0.0;
    result.print();
    for (int i = 1; i <= 3; ++i) {

        assert(fabs(result(i, 1) - expected(i, 1)) < 1e-8);
    }


}
