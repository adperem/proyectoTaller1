//
// Created by adperem on 27/03/2024.
//
#include <iostream>

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
        return data[row][col];
    }

    // Función para establecer un elemento de la matriz
    void setElement(int row, int col, double value) {
        data[row][col] = value;
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
};
