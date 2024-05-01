//
// Created by adperem on 27/03/2024.
//
#include <iostream>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
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
int Matrix::numRows() const {
    return rows;
}

// Función para obtener el número de columnas
int Matrix::numCols() const {
    return cols;
}

// Función para obtener un elemento de la matriz
double Matrix::getElement(int row, int col) const {
    return data[row-1][col-1];
}

// Función para establecer un elemento de la matriz
void Matrix::setElement(int row, int col, double value) {
    data[row-1][col-1] = value;
}

// Devuelve la columna
Matrix Matrix::getColumn(int column) {
    Matrix aux(this->rows,1);
    for (int i = 1; i <= this->rows; i++){
        aux(i,1) = this->getElement(i,column);
    }
    return aux;
}

// Devuelve la fila
Matrix Matrix::getRow(int row) {
    Matrix aux(1,this->cols);
    for (int i = 1; i <= this->cols; i++){
        aux(1,1) = this->getElement(row,i);
    }
    return aux;
}

// Método estático para calcular la norma de la matriz
double norm(const Matrix& mat) {
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
double dot(const Matrix& mat1, const Matrix& mat2) {
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

Matrix Matrix::operator+(const Matrix& other) const {
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

Matrix Matrix::operator-(const Matrix other) const {
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

Matrix Matrix::operator*(const Matrix& other) const {
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

Matrix Matrix::operator*(double multiplicando) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * multiplicando;
        }
    }

    return result;
}

Matrix Matrix::operator/(const Matrix& other) const {
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

Matrix Matrix::operator/(double divisor) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / divisor;
        }
    }

    return result;
}
bool Matrix::operator==(const Matrix other) const {
    if (rows != other.rows || cols != other.cols) {
        return false; // Las matrices tienen diferentes dimensiones
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (getElement(i, j) != other.getElement(i, j)) {
                return false; // Los elementos en la posición (i, j) son diferentes
            }
        }
    }
    return true; // Todas las posiciones coinciden
}

double Matrix::operator()(int i, int j) const {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Index out of range.");
    }
    return data[i - 1][j - 1];
}

// Overload operator() to access and modify elements directly
double&  Matrix::operator()(int i, int j) {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Index out of range.");
    }
    return data[i - 1][j - 1];
}

// Método estático para dividir una matriz por un número
 Matrix divide(const Matrix& mat, double divisor) {
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
 Matrix multiply(const Matrix& mat, double factor) {
    Matrix resultado(mat.rows, mat.cols);

    // Multiplicar cada elemento de la matriz por el factor
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            resultado.data[i][j] = mat.data[i][j] * factor;
        }
    }

    return resultado;
}

// Método para comparar si dos matrices son iguales
bool Matrix::equals(Matrix mat) {
    if (rows != mat.rows || cols != mat.cols) {
        return false; // Las matrices tienen diferentes dimensiones
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (getElement(i, j) != mat.getElement(i, j)) {
                std::cout<< "Los elementos en la posición ("<<i<<","<< j<<") son diferentes"<<std::endl;
                return false; // Los elementos en la posición (i, j) son diferentes
            }
        }
    }
    return true; // Todas las posiciones coinciden
}

// Método para imprimir la matriz por pantalla
void Matrix::print() const {
    for (int i = 1; i <= this->rows; i++) {
        for (int j = 1; j <= this->cols; j++) {
            std::cout << this->getElement(i,j) << " ";
        }
        std::cout << std::endl;
    }
}


