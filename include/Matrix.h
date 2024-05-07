//
// Created by adperem on 27/03/2024.
//

#ifndef PROYECTOTALLER1_MATRIX_H
#define PROYECTOTALLER1_MATRIX_H

class Matrix {
private:
    int rows;
    int cols;
    double **data;

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

    // Devuelve la columna
    Matrix getColumn(int column);

    // Devuelve la fila
    Matrix getRow(int row);

    //Muestra la matriz por pantall
    void print() const;

    // Método estático para calcular la norma de la matriz
    friend double norm(const Matrix &mat);

    // Método estático para calcular el producto escalar entre dos matrices
    friend double dot(const Matrix &mat1, const Matrix &mat2);

    // Método estático para dividir una matriz por un número
    friend Matrix divide(const Matrix &mat, double divisor);

    // Método estático para multiplicar una matriz por un número
    friend Matrix multiply(const Matrix &mat, double factor);

    // Método  para comparar si dos matrices son iguales
    bool equals(Matrix mat);

    // Sobrecarga del operador de suma (+)
    Matrix operator+(const Matrix &other) const;

    // Sobrecarga del operador de suma (+)
    Matrix operator+(const double &other) const;

    // Sobrecarga del operador de suma (-)
    Matrix operator-(const Matrix other) const;

    // Sobrecarga del operador de multiplicación (*)
    Matrix operator*(const Matrix &other) const;

    Matrix operator*(double multiplicando) const;
    //TODO: Hacerla funcion amiga

    // Sobrecarga del operador de multiplicación (/)
    Matrix operator/(const Matrix &other) const;

    Matrix operator/(double divisor) const;

    // Sobrecarga del operador de igual (=)
    bool operator==(const Matrix other) const;

    // Sobrecarga del operador de parentesis () para acceder
    double operator()(int i, int j) const;

    // Sobrecarga del operador de parentesis () para modificar
    double &operator()(int i, int j);

    // Método para concatenar dos matrices horizontalmente
    friend Matrix concatenate(const Matrix &mat1, const Matrix &mat2);

    // Función para calcular la inversa de una matriz
    friend Matrix inverse(const Matrix &mat);

    // Método para calcular la transpuesta de la matriz
    Matrix transpose() const;

    // Crear una matriz identidad del mismo tamaño que mat
    friend Matrix identity(double tam);

    // Método para hacer una copia de la matriz
    Matrix copy() const;

    // Método para el producto cruzado
    friend Matrix cross(const Matrix& mat1, const Matrix& mat2);



};

double norm(const Matrix &mat);

double dot(const Matrix &mat1, const Matrix &mat2);

Matrix divide(const Matrix &mat, double divisor);

Matrix multiply(const Matrix &mat, double factor);

Matrix concatenate(const Matrix &mat1, const Matrix &mat2);

Matrix inverse(const Matrix &mat);

Matrix identity(double tam);

Matrix cross(const Matrix& mat1, const Matrix& mat2);
#endif //PROYECTOTALLER1_MATRIX_H
