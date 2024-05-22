//
// Created by perez on 19/05/2024.
//
#include "Accel.h"
#include "assert.h"
#include "cmath"
#include "Globals.h"
int main() {
    Globals::eop19620101();
    Globals::PCLoad();
    double x = 0;
    Matrix Y(6, 1);
    Y(1, 1) = 6221397.62857869;
    Y(2, 1) = 2867713.77965738;
    Y(3, 1) = 3006155.98509949;
    Y(4, 1) = 4645.04725161806;
    Y(5, 1) = -2752.21591588204;
    Y(6, 1) = -7507.99940987031;
    Matrix result = Accel(x, Y);

    Matrix expected(6, 1);
    expected(1, 1) = 4645.04725161806;
    expected(2, 1) = -2752.21591588204;
    expected(3, 1) = -7507.99940987031;
    expected(4, 1) = -5.92414951314006;
    expected(5, 1) = -2.73076669788113;
    expected(6, 1) = -2.86933570556259;

    for (int i = 1; i <=6; ++i) {
        assert(std::abs(result(i, 1) - expected(i, 1)) < 1e-10);
        std::cout << "Error" << std::endl;
    }
    std::cout << "Test passed" << std::endl;

    return 0;
}
