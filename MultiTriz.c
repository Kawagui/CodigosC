#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;

    // Multiplicação de matrizes
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int i, j;

    printf("Digite o número de linhas e colunas da primeira matriz:\n");
    scanf("%d %d", &rows1, &cols1);

    printf("Digite os elementos da primeira matriz:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Digite o número de linhas e colunas da segunda matriz:\n");
    scanf("%d %d", &rows2, &cols2);

    printf("Digite os elementos da segunda matriz:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Erro: O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
        return 1;
    }

    multiplyMatrices(m1, m2, result, rows1, cols1, rows2, cols2);

    printf("A matriz resultante é:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}
