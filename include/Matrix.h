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

    // Método estático para calcular la norma de la matriz
    static double norm(const Matrix& mat);

    // Método estático para calcular el producto escalar entre dos matrices
    static double dot(const Matrix& mat1, const Matrix& mat2);

    // Sobrecarga del operador de suma (+)
    Matrix operator+(const Matrix& other) const;

     // Sobrecarga del operador de suma (-)
    Matrix operator-(const Matrix& other) const;

    // Sobrecarga del operador de multiplicación (*)
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double multiplicando) const;

    // Sobrecarga del operador de multiplicación (/)
    Matrix operator/(const Matrix& other) const;
    Matrix operator/(double divisor) const;

    // Método estático para dividir una matriz por un número
    static Matrix divide(const Matrix& mat, double divisor);

    // Método estático para multiplicar una matriz por un número
    static Matrix multiply(const Matrix& mat, double factor);






};


#endif //PROYECTOTALLER1_MATRIX_H