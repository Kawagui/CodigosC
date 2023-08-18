#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <stdlib.h>
int TAM, i, res;
void defineTAM (int x){		//rotina para definir valor de TAM
	printf("Defina um valor para TAM: ");
	scanf("%d",&TAM);
}
void preencheFor(int x){		//rotina para preencher vetor TAM usando for
	int v[x];
	for (i=0;i<x;i++){
		v[i]=rand()%1001;	
	}
}
void preenchewhile(int x){		//rotina para preencher vetor TAM usando while
	int v[x], i=0;
	while (i<x){
		v[i]=rand()%1001;
		i++;
	}
}
float maiorFor(int x){			//rotina que detecta o maior valor usando for
	double time_spentF = 0.0;
 
    clock_t begin = clock();	//inicia a cronometragem
	res=v[0];
	printf("\nO maior valor atual é %d do vetor de tamanho %d\n", res, x);
 	for (i=1;i<x;i++){
 		v[i]=rand() % 1001;	
 		if(v[i]>res){
 			res=v[i];
 			printf("Agora o maior valor é %d do vetor de tamanho %d\n", res, x);
		}
	}
	clock_t end = clock();		//termina a cronometragem
	time_spentF += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %.5f seconds (for)", time_spentF);
	return res;
}
float maiorWhile(int x){		//rotina que detecta o maior valor usando while
	double time_spentW = 0.0;
 
    clock_t begin = clock();	//inicia a cronometragem
	res=v[0];
	printf("\nO maior valor atual é %d do vetor de tamanho %d\n", res, x);
	while (i<x){
		v[i]=rand() % 1001;	
 		if(v[i]>res){
 			res=v[i];
 			printf("Agora o maior valor é %d do vetor de tamanho %d\n", res, x);
		}
		i++;
	}
	clock_t end = clock();		//termina a cronometragem
	time_spentW += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %.5f seconds (while)", time_spentW);
	return res;
void escreverMaior (int x){
	printf("%d\n", x);
}

// função principal para encontrar o tempo de execução de um programa em C
int main()
{
    // para armazenar o tempo de execução do código
    double time_spent = 0.0;
 
    clock_t begin = clock();
	
	defineTAM(TAM);
	int v[TAM];
	srand(time(NULL));
	preencheFor(TAM);
 	maiorFor(TAM);
 	maiorWhile(TAM);
 	escreverMaior(res);
 	
    clock_t end = clock();
 
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %.5f seconds (main)", time_spent);
 
    return 0;
}
