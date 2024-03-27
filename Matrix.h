//
// Created by adperem on 27/03/2024.
//

#ifndef PROYECTOTALLER1_MATRIX_H
#define PROYECTOTALLER1_MATRIX_H

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    // Constructor
    Matrix(int rows, int cols);

    // Función para obtener el número de filas
    int numRows() const;

    // Función para obtener el número de columnas
    int numCols() const;

    // Función para obtener un elemento de la matriz
    double getElement(int row, int col) const;

    // Función para establecer un elemento de la matriz
    void setElement(int row, int col, double value);

    // Sobrecarga del operador de suma (+)
    Matrix operator+(const Matrix& other) const;

    // Sobrecarga del operador de multiplicación (*)
    Matrix operator*(const Matrix& other) const;
};


#endif //PROYECTOTALLER1_MATRIX_H
