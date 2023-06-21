#include <stdio.h>
#define limite 10 //tamanho máximo de linha e coluna de uma matriz
    // Multiplicação de matrizes
void multiM(int m1[limite][limite], int m2[limite][limite], int r[limite][limite], int L1, int C1, int L2, int C2) {
    int i, j, k;
    for (i = 0; i < L1; i++) {
        for (j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (k = 0; k < C1; k++) {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
void printM(int mat[limite][limite], int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int m1[limite][limite], m2[limite][limite], r[limite][limite];
    int L1, C1, L2, C2, i, j;
    printf("Digite o número de linhas e colunas da primeira matriz:\n");
    scanf("%d %d", &L1, &C1);
    printf("Digite os elementos da primeira matriz:\n");
    for (i = 0; i < L1; i++) {
        for (j = 0; j < C1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }
    printf("Digite o número de linhas e colunas da segunda matriz:\n");
    scanf("%d %d", &L2, &C2);
    printf("Digite os elementos da segunda matriz:\n");
    for (i = 0; i < L2; i++) {
        for (j = 0; j < C2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }
    if (C1 != L2) {
        printf("O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
        return 1;
    }
    multiM(m1, m2, r, L1, C1, L2, C2);
    printf("A matriz resultante é:\n");
    printMatrix(r, L1, C2);
    return 0;
}
