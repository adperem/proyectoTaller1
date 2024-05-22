#ifndef PROYECTOTALLER1_MATRIX_H
#define PROYECTOTALLER1_MATRIX_H

/**
 * @class Matrix
 * @brief Represents a mathematical matrix.

 */
/**
 * @class Matrix
 * @brief Clase que representa una matriz.
 * Created by adperem on 27/03/2024.
 */
class Matrix {
private:
    int rows; /**< Número de filas de la matriz. */
    int cols; /**< Número de columnas de la matriz. */
    double **data; /**< Datos de la matriz almacenados. */

public:
    /**
     * @brief Constructor de la clase Matrix.
     * @param rows Número de filas de la matriz.
     * @param cols Número de columnas de la matriz.
     */
    Matrix(int rows, int cols);

    /**
     * @brief Destructor de la clase Matrix.
     */
    ~Matrix();

    /**
     * @brief Devuelve el número de filas de la matriz.
     * @return El número de filas.
     */
    int numRows() const;

    /**
      * @brief Devuelve el número de columnas de la matriz.
      * @return El número de columnas.
      */
    int numCols() const;

    /**
     * @brief Obtiene un elemento específico de la matriz.
     * @param row Índice de la fila.
     * @param col Índice de la columna.
     * @return El valor del elemento en la posición (row, col).
     */
    double getElement(int row, int col) const;

    /**
     * @brief Establece un valor para un elemento específico de la matriz.
     * @param row Índice de la fila.
     * @param col Índice de la columna.
     * @param value Valor a establecer en la posición (row, col).
     */
    void setElement(int row, int col, double value);

    /**
     * @brief Obtiene una columna específica de la matriz.
     * @param column Índice de la columna a obtener.
     * @return Una nueva matriz que representa la columna especificada.
     */
    Matrix getColumn(int column);

    /**
    * @brief Obtiene una fila específica de la matriz.
    * @param row Índice de la fila a obtener.
    * @return Una nueva matriz que representa la fila especificada.
    */
    Matrix getRow(int row);

    /**
     * @brief Muestra la matriz por consola.
     */
    void print() const;

    /**
     * @brief Calcula la norma de la matriz.
     * @param mat La matriz para la que se calcula la norma.
     * @return La norma de la matriz.
     */
    friend double norm(const Matrix &mat);

    /**
     * @brief Calcula el producto escalar entre dos matrices.
     * @param mat1 La primera matriz.
     * @param mat2 La segunda matriz.
     * @return El producto escalar entre las dos matrices.
     */
    friend double dot(const Matrix &mat1, const Matrix &mat2);

    /**
     * @brief Multiplica una matriz por un número.
     * @param mat La matriz a multiplicar.
     * @param factor El número por el cual se multiplica la matriz.
     * @return La matriz multiplicada por el factor.
     */
    friend Matrix divide(const Matrix &mat, double divisor);

    /**
     * @brief Multiplica una matriz por un número.
     * @param mat La matriz a multiplicar.
     * @param factor El número por el cual se multiplica la matriz.
     * @return La matriz multiplicada por el factor.
     */
    friend Matrix multiply(const Matrix &mat, double factor);

    /**
     * @brief Compara si dos matrices son iguales.
     * @param mat La matriz con la cual se compara.
     * @return true si las matrices son iguales, false en caso contrario.
     */
    bool equals(Matrix mat);

    /**
     * @brief Sobrecarga del operador de suma (+).
     * @param other La segunda matriz a sumar.
     * @return La matriz resultante de la suma.
     */
    Matrix operator+(const Matrix &other) const;

    /**
     * @brief Sobrecarga del operador de suma (+).
     * @param other El número a sumar a cada elemento de la matriz.
     * @return La matriz resultante de la suma.
     */
    Matrix operator+(const double &other) const;

    /**
     * @brief Sobrecarga del operador de resta (-).
     * @param other La segunda matriz a restar.
     * @return La matriz resultante de la resta.
     */
    Matrix operator-(const Matrix other) const;

    /**
     * @brief Sobrecarga del operador de multiplicación (*).
     * @param other La segunda matriz a multiplicar.
     * @return La matriz resultante de la multiplicación.
     */
    Matrix operator*(const Matrix &other) const;

    /**
     * @brief Sobrecarga del operador de multiplicación (*).
     * @param other El número a multiplicar a cada elemento de la matriz.
     * @return La matriz resultante de la multiplicación.
     */
    Matrix operator*(double multiplicando) const;

    /**
     * @brief Sobrecarga del operador de división (/).
     * @param other La segunda matriz a dividir.
     * @return La matriz resultante de la división.
     */
    Matrix operator/(const Matrix &other) const;

    /**
     * @brief Sobrecarga del operador de división (/).
     * @param divisor El número por el cual se divide cada elemento de la matriz.
     * @return La matriz resultante de la división.
     */
    Matrix operator/(double divisor) const;

    /**
      * @brief Sobrecarga del operador de igualdad (==).
      * @param other La segunda matriz con la cual se compara.
      * @return true si las matrices son iguales, false en caso contrario.
      */
    bool operator==(const Matrix other) const;

    /**
     * @brief Sobrecarga del operador de paréntesis () para acceso de elementos.
     * @param i Índice de la fila.
     * @param j Índice de la columna.
     * @return El valor del elemento en la posición (i, j).
     */
    double operator()(int i, int j) const;

    /**
     * @brief Sobrecarga del operador de paréntesis () para modificación de elementos.
     * @param i Índice de la fila.
     * @param j Índice de la columna.
     * @return Una referencia al valor del elemento en la posición (i, j).
     */
    double &operator()(int i, int j);

    /**
     * @brief Concatena dos matrices horizontalmente.
     * @param mat1 La primera matriz.
     * @param mat2 La segunda matriz.
     * @return La matriz resultante de la concatenación horizontal.
     */
    friend Matrix concatenate(const Matrix &mat1, const Matrix &mat2);

    /**
     * @brief Calcula la inversa de una matriz.
     * @return La matriz inversa.
     */
    friend Matrix inverse(const Matrix &mat);

    /**
     * @brief Calcula la transpuesta de una matriz.
     * @return La matriz transpuesta.
     */
    Matrix transpose() const;

    /**
     * @brief Crea una matriz identidad del mismo tamaño que la matriz dada.
     * @param tam Tamaño de la matriz identidad.
     * @return La matriz identidad del tamaño especificado.
     */
    friend Matrix identity(double tam);

    /**
     * @brief Calcula el producto cruzado entre dos vectores de 3 dimensiones.
     * @param mat1 Primer vector.
     * @param mat2 Segundo vector.
     * @return El vector resultado del producto cruzado.
     */
    friend Matrix cross(const Matrix &mat1, const Matrix &mat2);

    /**
     * @brief Copia los elementos de una matriz en otra.
     * @param original La matriz original.
     * @return Una copia de la matriz original.
     */
    friend Matrix copy(const Matrix &original);


};

double norm(const Matrix &mat);

double dot(const Matrix &mat1, const Matrix &mat2);

Matrix divide(const Matrix &mat, double divisor);

Matrix multiply(const Matrix &mat, double factor);

Matrix concatenate(const Matrix &mat1, const Matrix &mat2);

Matrix inverse(const Matrix &mat);

Matrix identity(double tam);

Matrix cross(const Matrix &mat1, const Matrix &mat2);

Matrix copy(const Matrix &original);

#endif //PROYECTOTALLER1_MATRIX_H
