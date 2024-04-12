//
// Created by adperem on 27/03/2024.
//
#include <iostream>
#include <math.h>

class Matrix {
private:
    int rows;
    int cols;
    double **data;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Reservar memoria para los datos de la matriz
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
        }

        // Inicializar la matriz con ceros
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0.0;
            }
        }
    }

    // Función para obtener el número de filas
    int numRows() const {
        return rows;
    }

    // Función para obtener el número de columnas
    int numCols() const {
        return cols;
    }

    // Función para obtener un elemento de la matriz
    double getElement(int row, int col) const {
        return data[row-1][col-1];
    }

    // Función para establecer un elemento de la matriz
    void setElement(int row, int col, double value) {
        data[row-1][col-1] = value;
    }

    // Método estático para calcular la norma de la matriz
    static double norm(const Matrix& mat) {
        double suma_cuadrados = 0.0;

        // Calcular la suma de los cuadrados de todos los elementos de la matriz
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                double elemento = mat.data[i][j];
                suma_cuadrados += elemento * elemento;
            }
        }

        // Calcular la raíz cuadrada de la suma de los cuadrados
        double norma = sqrt(suma_cuadrados);
        return norma;
    }

    // Método estático para calcular el producto escalar entre dos matrices
    static double dot(const Matrix& mat1, const Matrix& mat2) {
        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para calcular el producto escalar.");
        }

        double resultado = 0.0;

        // Calcular el producto escalar sumando el producto de los elementos correspondientes
        for (int i = 0; i < mat1.rows; ++i) {
            for (int j = 0; j < mat1.cols; ++j) {
                resultado += mat1.data[i][j] * mat2.data[i][j];
            }
        }

        return resultado;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Las matrices deben tener la misma dimensión para sumarse.");
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Las matrices deben tener la misma dimensión para restarse.");
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarse.");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix operator*(double multiplicando) const {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * multiplicando;
            }
        }

        return result;
    }

    Matrix operator/(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarse.");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] / other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix operator/(double divisor) const {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / divisor;
            }
        }

        return result;
    }

    // Método estático para dividir una matriz por un número
    static Matrix divide(const Matrix& mat, double divisor) {
        Matrix resultado(mat.rows, mat.cols);

        // Dividir cada elemento de la matriz por el divisor
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                resultado.data[i][j] = mat.data[i][j] / divisor;
            }
        }

        return resultado;
    }

    // Método estático para multiplicar una matriz por un número
    static Matrix multiply(const Matrix& mat, double factor) {
        Matrix resultado(mat.rows, mat.cols);

        // Multiplicar cada elemento de la matriz por el factor
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                resultado.data[i][j] = mat.data[i][j] * factor;
            }
        }

        return resultado;
    }


};