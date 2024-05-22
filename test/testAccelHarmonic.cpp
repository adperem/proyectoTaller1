//
// Created by perez on 17/05/2024.
//
#include "AccelHarmonic.h"
#include "Globals.h"
#include "assert.h"
int main() {
    Globals::CnmSnm();

    Matrix r(3, 1);
    r(1, 1) = 6221397.62857869;
    r(2, 1) = 2867713.77965738;
    r(3, 1) = 3006155.98509949;

    Matrix E(3, 3);
    E(1, 1) = -0.978185453896254;
    E(1, 2) = 0.207733066362260;
    E(1, 3) = -0.000436950239569363;
    E(2, 1) = -0.207733028352522 ;
    E(2, 2) = -0.978185550768511;
    E(2, 3) = -0.000131145697267082;
    E(3, 1) = -0.000454661708585098;
    E(3, 2) = -3.75158169026289e-05;
    E(3, 3) = 0.999999895937642;

    int n_max = 20;
    int m_max = 20;
    Matrix result = AccelHarmonic(r, E, n_max, m_max);

    Matrix expected(3, 1);
    expected(1, 1) = -5.92414856522541;
    expected(2, 1) = -2.73076679296887;
    expected(3, 1) = -2.86933544780688;

    for (int i = 1; i <= 3; ++i) {
        assert(fabs(result(i, 1) - expected(i, 1)) < 1e-6);
    }
    printf("Test pasado con extito");
    return 0;
}
