#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cmath>
#include "Matrix.h"
#include "Cheb3D.h"

int main() {
    try {
        // Definir los parámetros
        double t = 4.974611199287850e+04;
        int N = 13;
        double Ta = 49744.0;
        double Tb = 49760.0;

        // Definir las matrices de coeficientes Cx, Cy, Cz
        Matrix Cx(1, 13);
        Cx(1, 1) = -103506598.421090;
        Cx(1, 2) = -14927175.9535129;
        Cx(1, 3) = 512386.261705712;
        Cx(1, 4) = 11989.7464659321;
        Cx(1, 5) = -231.321791175806;
        Cx(1, 6) = -3.01145680139332;
        Cx(1, 7) = 0.0557108554642511;
        Cx(1, 8) = 0.000160763608359754;
        Cx(1, 9) = 4.59304599038190e-05;
        Cx(1, 10) = 2.65245498743318e-06;
        Cx(1, 11) = -2.69798189927076e-06;
        Cx(1, 12) = 5.19937618744697e-07;
        Cx(1, 13) = 5.42165920618080e-08;


        Matrix Cy(1, 13);
        Cy(1, 1) = 96607067.3707606;
        Cy(1, 2) = -13337710.4674864;
        Cy(1, 3) = -474105.009264048;
        Cy(1, 4) = 11293.5192596881;
        Cy(1, 5) = 193.380285507684;
        Cy(1, 6) = -3.43928289232978;
        Cy(1, 7) = -0.0344227898113099;
        Cy(1, 8) = 0.00107593031980365;
        Cy(1, 9) = 4.63124437216978e-06;
        Cy(1, 10) = -1.24347116253730e-05;
        Cy(1, 11) = 2.21298188012278e-06;
        Cy(1, 12) = 1.39759592836155e-07;
        Cy(1, 13) = -1.68301628426181e-07;


        Matrix Cz(1, 13);
        Cz(1, 1) = 41887005.1061263;
        Cz(1, 2) = -5782554.14940129;
        Cz(1, 3) = -205553.618975101;
        Cz(1, 4) = 4896.48746963361;
        Cz(1, 5) = 83.8420287547238;
        Cz(1, 6) = -1.49161452214215;
        Cz(1, 7) = -0.0148800126199174;
        Cz(1, 8) = 0.000502341000673383;
        Cz(1, 9) = -2.65374413641448e-06;
        Cz(1, 10) = -6.64088213358266e-06;
        Cz(1, 11) = 1.33131703155108e-06;
        Cz(1, 12) = 4.77273410670398e-08;
        Cz(1, 13) = -9.29357771479359e-08;



        // Calcular el valor de Cheb3D
        Matrix result = Cheb3D(t, N, Ta, Tb, Cx, Cy, Cz);
        Matrix expected(1, 3);
        expected(1, 1) = -9.246987516899471e+07;
        expected(1, 2) = 1.063908284562656e+08;
        expected(1, 3) = 4.612874685964671e+07;
        result.print();
        expected.print();
        for (int i = 1; i <= 3; ++i) {
            assert(fabs(result(1, i) - expected(1, i)) < 1e-6);
        }

        std::cout << "El valor de Cheb3D calculado es correcto." << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1; // Devolver un código de error
    }

    return 0;
}
