#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char num[13][3] = {
    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};
char nai[4][8] = {
    "Espadas", "Copas", "Ouros", "Paus"
};
int main() {
    int c = 2, x, a;
    printf("O baralho está completo. Deseja retirar alguma carta?\n");
    printf("Quantas cartas quer receber?\n");
    scanf("%d", &x);
    printf("\n");
    srand(time(NULL));
    int Rnai[x], Rnum[x]; // Vetores para armazenar as cartas retiradas
    for (c = 0; c < x; c++) {
        int j, i, r = 1;
        while (r==1) {
            j = (rand() % 4);
            i = (rand() % 13);
            r = 0;
            // Verificar se a carta já foi retirada anteriormente
            for (a = 0; a < c; a++) {
                if (Rnai[a] == j && Rnum[a] == i) {
                    r = 1; // Marcar a carta como repetida
                    break; // Sair do loop interno
                }
            }
        }
        Rnai[c] = j;
        Rnum[c] = i;
        printf("Você recebeu %s de %s\n", num[i], nai[j]);
    }
    printf("\n");
    return 0;
}
