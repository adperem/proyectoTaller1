#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

class Matrix
{
private:
    double** data;
public:
    int numRows,numColumns;
    Matrix(int rows, int columns);
    
};

Matrix::Matrix(int rows, int columns)
{
    numRows = rows;
    numColumns = columns;

    int **data = (int **)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) data[i] = (int *)malloc(columns * sizeof(int));

}
