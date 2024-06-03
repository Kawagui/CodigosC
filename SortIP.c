#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

int TAM, i, j, x, *vBase, *R, *vSelect, *vQ, *vInsert, M;
long double tempo;
struct timespec tiSelect;
struct timespec tfSelect;
struct timespec tiQ;
struct timespec tfQ;
struct timespec tiInsert;
struct timespec tfInsert;

void Troca(int *a, int *b){
	x=*a;
	*a=*b;
	*b=x;
}

void sortInsert (int *vet, int tam){        
    for (i=1; i<tam; i++){
	    x=vet[i];
        j=i-1;
        while (x<vet[j] && j>=0){
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=x;
    }
}

void sortSelect(int *vet, int TAM){
	for(i=0;i<TAM-1;i++){
		x=i;
		for(j=i+1; j<TAM; j++){
			if(vet[j]<vet[x]){
				x=j;
			}
		}
		Troca(&vet[x], &vet[i]);
	}
}

void lerTAM(){
	do{
		printf("Defina o tamanho do array: ");
		scanf("%d", &TAM);
	} while (TAM<=0);
	vBase = (int *)malloc(TAM * sizeof(int));
	R = (int *)malloc(TAM * sizeof(int));
	vSelect = (int *)malloc(TAM * sizeof(int));
	vInsert  = (int *)malloc(TAM * sizeof(int));
	vQ = (int *)malloc(TAM * sizeof(int));
}

void gerarVetor(int vet[], int TAM){
	srand(time(NULL));
	printf("de semente %li: \n", (time(NULL)));
	for(i=0;i<TAM;i++){
		do{
			x=rand()%TAM;
		} while(R[x]==1);
		vet[i]=x;
		R[x]=1;
	}
}

void printVetor(int vet[], int TAM){
	printf("\n");
	for(i=0;i<TAM;i++){
		printf("[%d] ", vet[i]);
	}
}

void copiarVetor(int vCopy[], int TAM){
	for(i=0;i<TAM;i++){
		vSelect[i]=vCopy[i];
		vInsert[i]=vCopy[i];
		vQ[i]=vCopy[i];
	}
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void liberar(){
    free(vBase);
    free(R);
    free(vSelect);
    free(vInsert);
    free(vQ);
}

int main (){
	lerTAM();
	printf("Foi gerado um array ");
	gerarVetor(vBase, TAM);
	printf("Último valor do array: [%d]\n", vBase[TAM-1]);
	copiarVetor(vBase, TAM);
	back:
	printf("Escolha o algoritmo de ordenação:\n 1-Insert\n 2-Select\n 3-Q\n");
	scanf("%d", &M);
	switch(M){
		case 1:
			clock_gettime (CLOCK_MONOTONIC, &tiInsert);
			sortInsert(vInsert, TAM);
			clock_gettime (CLOCK_MONOTONIC, &tfInsert);
			tempo = tfInsert.tv_nsec - tiInsert.tv_nsec;
			printVetor(vInsert, TAM);
			printf("\nTempo: %.0Lf ns\n", tempo);
			goto back;
			break;
		case 2:
			clock_gettime (CLOCK_MONOTONIC, &tiSelect);
			sortSelect(vSelect, TAM);
			clock_gettime (CLOCK_MONOTONIC, &tfSelect);
			tempo = tfSelect.tv_nsec - tiSelect.tv_nsec;
			printVetor(vSelect, TAM);
			printf("\nTempo: %.0Lf ns\n", tempo);
			goto back;
			break;
		case 3:
			clock_gettime (CLOCK_MONOTONIC, &tiQ);
			qsort(vQ, TAM, sizeof(int), cmpfunc);
			clock_gettime (CLOCK_MONOTONIC, &tfQ);
			tempo = tfQ.tv_nsec - tiQ.tv_nsec;
			printVetor(vQ, TAM);
			printf("\nTempo: %.0Lf ns\n", tempo);
			goto back;
			break;
		default:
			printf("Nada acontece...\n");
			liberar();
			break;
	}
	return 0;
}
