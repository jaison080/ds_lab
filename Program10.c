#include <stdio.h>
#define MAX_TERMS 100
struct Sparse_matrix
{
    int row;
    int col;
    int value;
};
struct Sparse_matrix sparse1[MAX_TERMS];
struct Sparse_matrix transposeSparse[MAX_TERMS];
int SIZE;
const int MATRIX_ROWS, MATRIX_COLS;
int matrix[100][100];
int transpose[100][100];

void printMatrix(int printMatrix[100][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d", printMatrix[i][j]);
        }
        printf("\n");
    }
}

void printSparseMatrix(struct Sparse_matrix sparse[100])
{
    int i;
    printf("\n");
    printf("ROW  COLUMN  VALUE");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

void convertToSparseMatrix()
{
    sparse1[0].row = MATRIX_ROWS;
    sparse1[0].col = MATRIX_COLS;
    int i, j, k = 1;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            if (matrix[i][j])
            {
                sparse1[k].row = i + 1;
                sparse1[k].col = j + 1;
                sparse1[k].value = matrix[i][j];
                k++;
            }
        }
    }
    SIZE = k;
    sparse1[0].value = k - 1;
}

void transposeSparseMatrix()
{
    transposeSparse[0].row = MATRIX_COLS; 
    transposeSparse[0].col = MATRIX_ROWS;
    transposeSparse[0].value = sparse1[0].value; 
    int i, j, k = 1, min_col;
    for (i = 1; i <= MATRIX_COLS; i++)
    {
        for (j = 1; j <= SIZE; j++)
        {
            if (sparse1[j].col == i)
            {
                transposeSparse[k].row = sparse1[j].col;
                transposeSparse[k].col = sparse1[j].row;
                transposeSparse[k].value = sparse1[j].value;
                k++;
            }
        }
    }
}

void convertSparseToNormal()
{
    int i, j;
    for (i = 0; i < MATRIX_COLS; i++)
        for (j = 0; j < MATRIX_ROWS; j++)
            transpose[i][j] = 0;
    for (i = 1; i < SIZE; i++)
    {
        transpose[transposeSparse[i].row - 1][transposeSparse[i].col - 1] = transposeSparse[i].value;
    }
}

int main()
{
    int i, j;
    printf("\nEnter matrix dimensions\n");
    scanf("%d %d", &MATRIX_ROWS, &MATRIX_COLS);
    printf("\nEnter matrix\n");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &matrix[i][j]);
    convertToSparseMatrix();
    printf("\n\nSPARSE MATRIX");
    printSparseMatrix(sparse1);
    printf("\n\nTRANSPOSE OF SPARSE MATRIX ");
    transposeSparseMatrix();
    printSparseMatrix(transposeSparse);
    printf("\n\nTRANSPOSE OF INPUT MATRIX\n");
    convertSparseToNormal();
    printMatrix(transpose, MATRIX_COLS, MATRIX_ROWS);
    return 0;
}