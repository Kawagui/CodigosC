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
    int c = 2, x=0, a, R[4][13], j , i, t=52;
	for (j=0; j<4;j++){
		for (i=0;i<13;i++){
			R[j][i]=0;
		}
	}
	while (x!=1 && x!=2){
    	printf("O baralho está completo. Deseja retirar alguma carta?\n1-Sim\n2-Não\n");
		scanf("%d", &x);
	}
	if (x==1){
		printf("Quantas cartas quer remover?\n");
		scanf("%d", &x);
		for (c = 0; c < x; c++) {
			printf("Quais cartas quer remover?\nSelecione um naipe e depois digite um número de 0(A) a 12(K)\n0-Espadas\n1-Copas\n2-Ouros\n3-Paus\n");
			scanf("%d %d", &j, &i);
			R[j][i]=1;
		}
		t-=x;
		printf("Restam %d cartas no baralho\n", t);
	}
    printf("Quantas cartas quer receber?\n");
    scanf("%d", &x);
    printf("\n");
    srand(time(NULL));
    int Rnai[x], Rnum[x]; // Vetores para armazenar as cartas retiradas
    for (c = 0; c < x; c++) {
        int r = 1, B=1;
        while (r==1 || B==1) {
            j = (rand() % 4);
            i = (rand() % 13);
            r = 0;
			B=0;
            // Verificar se a carta já foi removida anteriormente
            for (a = 0; a < c; a++) {
                if (R[j][i] == 1) {
                    B = 1; // Marcar a carta como repetida
                    break; // Sair do loop interno
                }
            }
			// Verificar se a carta já foi retirada anteriormente
			for (a = 0; a < c; a++) {
                if (Rnai[a] == j && Rnum[a] == i) {
                    r = 1; // Marcar a carta como repetida
                    break; // Sair do loop interno
                }
            }
        }
        Rnai[c] = j; //Marca como repetida
        Rnum[c] = i;
        printf("Você recebeu %s de %s\n", num[i], nai[j]);
    }
    printf("\n");
    return 0;
}
