//
// Created by adperem on 27/03/2024.
//
#include <iostream>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    // Reservar memoria para los datos de la matriz
    data = new double *[rows];
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
    return data[row - 1][col - 1];
}

// Función para establecer un elemento de la matriz
void Matrix::setElement(int row, int col, double value) {
    data[row - 1][col - 1] = value;
}

// Devuelve la columna
Matrix Matrix::getColumn(int column) {
    Matrix aux(this->rows, 1);
    for (int i = 1; i <= this->rows; i++) {
        aux(i, 1) = this->getElement(i, column);
    }
    return aux;
}

// Devuelve la fila
Matrix Matrix::getRow(int row) {
    Matrix aux(1, this->cols);
    for (int i = 1; i <= this->cols; i++) {
        aux(1, 1) = this->getElement(row, i);
    }
    return aux;
}

// Método estático para calcular la norma de la matriz
double norm(const Matrix &mat) {
	//TODO:Lanzar excepcion si no tiene una fila
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
double dot(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        throw std::invalid_argument(
                "Las matrices deben tener las mismas dimensiones para calcular el producto escalar.");
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

Matrix Matrix::operator+(const Matrix &other) const {
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

Matrix Matrix::operator+(const double &other) const {
    Matrix result(this->numRows(), this->cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = this->data[i][j] + other;
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

Matrix Matrix::operator*(const Matrix &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument(
                "El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarse.");
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

Matrix Matrix::operator/(const Matrix &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument(
                "El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarse.");
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
double &Matrix::operator()(int i, int j) {
    if (i < 1 || i > rows || j < 1 || j > cols) {
        throw std::out_of_range("Index out of range.");
    }
    return data[i - 1][j - 1];
}

// Método estático para dividir una matriz por un número
Matrix divide(const Matrix &mat, double divisor) {
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
Matrix multiply(const Matrix &mat, double factor) {
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
                std::cout << "Los elementos en la posición (" << i << "," << j << ") son diferentes" << std::endl;
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
            std::cout << this->getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// Función para calcular la inversa de una matriz
Matrix inverse(const Matrix &mat) {
    // Verificar si la matriz es cuadrada
    if (mat.numRows() != mat.numCols()) {
        throw std::invalid_argument("La matriz debe ser cuadrada para calcular su inversa.");
    }

    // Crear una matriz identidad del mismo tamaño que mat
    Matrix identity(mat.numRows(), mat.numCols());
    for (int i = 1; i <= mat.numRows(); ++i) {
        for (int j = 1; j <= mat.numCols(); ++j) {
            identity(i, j) = (i == j) ? 1.0 : 0.0;
        }
    }

    // Realizar eliminación gaussiana para obtener la matriz inversa
    Matrix augmented = mat;
    augmented = concatenate(augmented, identity);

    // Realizar eliminación gaussiana
    for (int i = 1; i <= augmented.numRows(); ++i) {
        // Encontrar el pivote
        double pivot = augmented(i, i);

        // Si el pivote es cero, intercambiar filas
        if (pivot == 0.0) {
            throw std::invalid_argument("La matriz no tiene inversa.");
        }

        // Normalizar la fila para hacer el pivote 1
        for (int j = 1; j <= augmented.numCols(); ++j) {
            augmented(i, j) /= pivot;
        }

        // Eliminar elementos por debajo del pivote
        for (int k = 1; k <= augmented.numRows(); ++k) {
            if (k != i) {
                double factor = augmented(k, i);
                for (int j = 1; j <= augmented.numCols(); ++j) {
                    augmented(k, j) -= factor * augmented(i, j);
                }
            }
        }
    }

    // Extraer la matriz inversa de la parte derecha de la matriz aumentada
    Matrix inverseMat(mat.numRows(), mat.numCols());
    for (int i = 1; i <= mat.numRows(); ++i) {
        for (int j = 1; j <= mat.numCols(); ++j) {
            inverseMat(i, j) = augmented(i, j + mat.numCols());
        }
    }

    return inverseMat;
}

// Método para concatenar dos matrices horizontalmente
Matrix concatenate(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.numRows() != mat2.numRows()) {
        throw std::invalid_argument("Las matrices deben tener el mismo número de filas para concatenarse.");
    }

    int newCols = mat1.numCols() + mat2.numCols();
    Matrix result(mat1.numRows(), newCols);

    // Copiar los elementos de la primera matriz
    for (int i = 1; i <= mat1.numRows(); ++i) {
        for (int j = 1; j <= mat1.numCols(); ++j) {
            result(i, j) = mat1(i, j);
        }
    }

    // Copiar los elementos de la segunda matriz
    for (int i = 1; i <= mat2.numRows(); ++i) {
        for (int j = 1; j <= mat2.numCols(); ++j) {
            result(i, j + mat1.numCols()) = mat2(i, j);
        }
    }

    return result;
}

// Método para calcular la transpuesta de la matriz
Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }

    return transposed;
}

// Crear una matriz identidad del mismo tamaño que mat
Matrix identity(double tam) {
    Matrix ident(tam, tam);
    for (int i = 1; i <= tam; ++i) {
        for (int j = 1; j <= tam; ++j) {
            ident(i, j) = (i == j) ? 1.0 : 0.0;
        }
    }
    return ident;
}


Matrix cross(const Matrix& mat1, const Matrix& mat2) {
    // Comprobación de que ambas matrices son vectores de 3 dimensiones
    if (mat1.numCols() != 3 || mat2.numCols() != 3 || mat1.numRows() != 1 || mat2.numRows() != 1) {
        std::cerr << "Error: Ambas matrices deben ser vectores de 3 dimensiones." << std::endl;
        exit(1);
    }

    // Obtiene los valores de los vectores
    double x1 = mat1(1, 1), y1 = mat1(1, 2), z1 = mat1(1, 3);
    double x2 = mat2(1, 1), y2 = mat2(1, 2), z2 = mat2(1, 3);

    // Calcula los componentes del producto cruzado
    double x = y1 * z2 - z1 * y2;
    double y = z1 * x2 - x1 * z2;
    double z = x1 * y2 - y1 * x2;

    // Crea y devuelve la matriz resultado
    Matrix result(1, 3);
    result(1, 1) = x;
    result(1, 2) = y;
    result(1, 3) = z;
    return result;
}

Matrix copyMatrix(const Matrix &original) {
    int numRows = original.numRows();
    int numCols = original.numCols();

    // Crear una nueva matriz para almacenar la copia
    Matrix copy(numRows, numCols);

    // Copiar los elementos de la matriz original a la copia
    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numCols; ++j) {
            copy(i, j) = original(i, j);
        }
    }

    return copy;
}
