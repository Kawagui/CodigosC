#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// linha = naipe e coluna = valor
// 1=espadas, 2=copas, 3= ouros, 4=paus
int B[4][13]={
	{1,2,3,4,5,6,7,8,9,10,11,12,13},
	{1,2,3,4,5,6,7,8,9,10,11,12,13},
	{1,2,3,4,5,6,7,8,9,10,11,12,13},
	{1,2,3,4,5,6,7,8,9,10,11,12,13},
};

int main(){
	int i, j, c, x;
	printf("Quantas cartas quer receber?\n");
	scanf("%d", &x);
	for (c=1;c<=x;c++){
		srand(time(NULL));
		j = 1 + (rand()%3);
		i = 1 + (rand()%12);
		if (i == 1){
    	printf("Você recebeu Ás");
		} else {
    		if (i == 11){
      			printf("Você recebeu Valete");
    		} else {
    			if (i == 12){
      				printf("Você recebeu Rainha");
    			} else {
      				if (i == 13){
    					printf("Você recebeu Rei");
  					} else {
    					printf("Você recebeu %d", B[j][i]);
  					}
				}
			}
		}
		if (j == 1){
    		printf(" de espadas\n");
		} else {
    		if (j == 2){
      			printf(" de copas\n");
    		} else {
      			if (j == 3){
        			printf(" de paus\n");
       			} else {
        		printf(" de ouros\n");
      			}
      		}
    	}
	}
return 0;
}
