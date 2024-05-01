#include <iostream>
#include <cassert>
#include "Position.h"
#include "cmath"

int main() {
    Matrix sol(1,3);

    sol=Position(2*M_PI, 2*M_PI, 3);

    assert(fabs(sol(1,1)) - 6378139.3 < 1e-10 &&
           fabs(sol(1,2)) - 1.56219357565219e-09 < 1e-10 &&
           fabs(sol(1,3)) - 1.55173566315757e-09 < 1e-10);

    sol(1,3);

    sol=Position(2*M_PI, 2*M_PI, 3);

    assert(fabs(sol(1,1)) - 6378139.3 < 1e-10 &&
           fabs(sol(1,2)) - 1.56219357565219e-09 < 1e-10 &&
           fabs(sol(1,3)) - 1.55173566315757e-09 < 1e-10);

    std::cout << "Test pasado con éxito" << std::endl;
    return 0;

}
