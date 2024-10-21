#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <float.h>
// Problemas a resolver: Tempo, Busca binária, contadores, DevC++
//Todas as principais variáveis usadas, informações de cada uma têm no documento
int TAM, i, j, r, k, x, *vBase, *R, *vBubble, *vInsert, *vSelect, *vHeap, *vRadix, *vMerge, *vQuick, *vShell, M= -1, CT, CC;
typedef struct {
    int chave;
    int campoDaEstrutura[1];
} Registro1;
typedef struct {
    int chave;
    int campoDaEstrutura[1000];
} Registro1000;
/* long double tempo;
struct timespec (nome variável);
clock_gettime (CLOCK_MONOTONIC, &tiInsert);
			sortInsert(vInsert, TAM);
			clock_gettime (CLOCK_MONOTONIC, &tfInsert);
			tempo = tfInsert.tv_nsec - tiInsert.tv_nsec;
			printVetor(vInsert, TAM);
			printf("\nTempo: %.0Lf ns\n", tempo); */
// Cronometrar tempo de cada função de ordenação
void Crono(long double tempo, void *fun, REGISTRO *reg, int TAM){
    struct timespec x, y;
    clock_gettime (CLOCK_MONOTONIC, &x);
    fun(*reg, TAM);
    clock_gettime (CLOCK_MONOTONIC, &y);
    tempo = y.tv_nsec - x.tv_nsec;
}

//Troca de valores entre variáveis de qualquer distância utilizado pelo Heap e Select
void Troca(int *a, int *b) {
    int x;
    x = *a;
    *a = *b;
    *b = x;
}
//Bubble sort
void bubble (int vet[], int TAM){
    clock_t start = clock();		
    for (j = 0; j < TAM - 1; j++ ){
	    for (i = 0; i < TAM - 1; i++ ){
            CC++;
		    if(vet[i] > vet[i + 1]){
		        CT++;
                Troca(&vet[i], &vet[i+1]);          
		    }   
	    }
    }
}
//Insert sort
void insert (int *vet, int tam){        
    for (i=1; i<tam; i++){
	    x=vet[i];
        j=i-1;
        CC++;
        while (x<vet[j] && j>=0){
            CT++;
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=x;
    }
}
//Select sort
void selecta (int *vet, int TAM){ 	 
    for (i=0; i<TAM-1; i++){
        x = i;
	    for (j=i+1; j<TAM; j++){
            CC++;
            if (vet[j] < vet[x])
	        x = j;
	    }
        CT++;
        Troca(&vet[x], &vet[i]);
    }
}
//sort quick
void quick(int *vet, int esq, int dir){  	
    k = esq;         
    for(i=esq+1;i<=dir;i++){        
        j = i;
        CC++;
        if(vet[j] < vet[k]){     
            x = vet[j];               
            while(j > k){           
                CT++;
                vet[j] = vet[j-1];      
                j--;                    
            }
            CT++;
            vet[j] = x;               
            k++;                    
        }
    }
    if(k-1 >= esq){              
        quick(vet,esq,k-1);      
    }
    if(k+1 <= dir){              
        quick(vet,k+1,dir);      
    }
 }
//Merge sort
void mergeSort(int *vetor, int Inicio, int Fim) {  	
    int metadeTamanho, *vetorTemp;
    if(Inicio==Fim) return;
    metadeTamanho = (Inicio+Fim )/2;
    mergeSort(vetor, Inicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, Fim);
    i=Inicio;
    j=metadeTamanho+1;
    k=0;
    vetorTemp = (int *) malloc(sizeof(int) * (Fim - Inicio + 1));
    while(i < metadeTamanho + 1 || j  < Fim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } else {
            if (j == Fim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } else {
                CC++;
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } else {
                    CT++;
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for(i = Inicio; i <= Fim; i++) {
        vetor[i] = vetorTemp[i - Inicio];
    }
    free(vetorTemp);
}
//Shell sort
void shellSort(int *vet, int size) {  
    k = 1;
    while(k < size) {
        k = 3*k+1;
    }
    while ( k > 1) {
        k /= 3;
        for(i = k; i < size; i++) {
            x = vet[i];
            j = i - k;
            CC++;
            while (j >= 0 && x < vet[j]) {
                CT++;
                vet [j + k] = vet[j];
                j -= k;
            }
            CT++;
            vet [j + k] = x;
        }
    }
}
//ordenação dos nós do heap máximo
void maxHeapify(int arr[], int n, int i) {		
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    CC++;
    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;
    CC++;
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;
    if (maior != i) {
        CT++;
        Troca(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}
//Heap sort
void heapSort(int *arr, int n) {
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (i = n - 1; i >= 0; i--) {
        CT++;
        Troca(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}
// Função para encontrar o maior elemento no array utilizado pelo Radix sort
int encontrarMaior(int *arr, int n) {
    x = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > x) {
            x = arr[i];
        }
    }
    return x;
}