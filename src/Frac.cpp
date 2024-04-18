#include "Frac.h"
//--------------------------------------------------------------------------
//
//  Fractional part of a number (y=x-[x])
//
// Last modified:   2015/08/12   M. Mahooti
//
//--------------------------------------------------------------------------
double Frac(double x) {
    return x - std::floor(x);
}
