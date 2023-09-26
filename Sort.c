#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TAM, i, j, r; 
/*
void bubble (int vet, int TAM){		//sort bubble
int i,j; 
for (int j = 0; j < TAM - 2; j++ ){
	for (i = 0; i < TAM - 2; i++ ){
		if(vet[i] > vet[i + 1]){
        vet[i] = vet[i+1];
        vet[i+1] = vet[i]-vet[i+1];
        vet[i] = vet[i]-vet[i+1];        
		}   
	}
}  
}

void insert (int vet, int tam){  	//sort insert
int i, j, x;
for (i=2; i<=tam; i++){
	x = vet[i];
	j=i-1;
	vet[0] = x; 
	while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}

void select (int vet, int tam){ 	//sort select 
    int i, j, min, x;
    for (i=1; i<=n-1; i++){
        min = i;
	for (j=i+1; j<=n; j++){
            if (vet[j] < vet[min])
	        min = j;
	}
	x = vet[min];
	vet[min] = vet[i];
	vet[i] = x;
    }
}

void quick(int vet[], int esq, int dir){  	//sort quick
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {  	//sort merge
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void shellSort(int *vet, int size) {  //sort shell
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}
	
void maxHeapify(int arr[], int n, int i) {		//sort heap *Precisa fazer uma rotina para trocar variável
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        trocar(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}
	
// Função para encontrar o maior elemento no array		//sort radix
int encontrarMaior(int arr[], int n) {
    int maior = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Função para realizar a ordenação Radix Sort
void radixSort(int arr[], int n) {
    int maior = encontrarMaior(arr, n);
    int exp;
    
    for (exp = 1; maior / exp > 0; exp *= 10) {
        int saida[n]; // Array de saída
        int contador[10] = {0}; // Inicializa o contador de dígitos

        // Conta a ocorrência de cada dígito
        for (int i = 0; i < n; i++) {
            contador[(arr[i] / exp) % 10]++;
        }

        // Atualiza o contador para indicar a posição correta de cada dígito
        for (int i = 1; i < 10; i++) {
            contador[i] += contador[i - 1];
        }

        // Cria o array de saída a partir do array original
        for (int i = n - 1; i >= 0; i--) {
            saida[contador[(arr[i] / exp) % 10] - 1] = arr[i];
            contador[(arr[i] / exp) % 10]--;
        }

        // Copia o array de saída de volta para o array original
        for (int i = 0; i < n; i++) {
            arr[i] = saida[i];
        }
    }
}

void lerTAM(){
	printf("Defina o tamanho do vetor: ");
	scanf("%d",&TAM);
}
*/
void imprimirVetor(int vet[],int TAM){
	for (i=0;i<TAM;i++){
		printf ("%d ",vet[TAM]);
	}	
}

int main (){
	//lerTAM();
	printf("Defina o tamanho do vetor: ");
	scanf("%d",&TAM);
	int vetBase[TAM], R[TAM];		//vetor base
	srand(time(NULL));
	for (i=0;i<TAM;i++) {
		while (r==1){
			r=0;
			vetBase[i]= (rand() % 10);
			R[vetBase[i]]=1;
			for (j=0;j<i;j++){
				if (R[vetBase[i]]==1){
					r=1;
					break;
				}
			}
		}
	}
	for (i=0;i<TAM;i++){
		printf ("%d ",vetBase[TAM]);
	}
    
            
	return 0;
}
