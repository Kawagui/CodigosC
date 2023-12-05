//Implementação de algoritmos de ordenação e de busca binária
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Problemas a resolver: Tempo, Busca binária, contadores, DevC++
//Todas as principais variáveis usadas, informações de cada uma têm no documento
int TAM, i, j, r, k, x, *vBase, *R, *vBubble, *vInsert, *vSelect, *vHeap, *vRadix, *vMerge, *vQuick, *vShell, *vBinary, M= -1, CT, CC;
float tempo;
//Troca de valores entre variáveis de qualquer distância utilizado pelo Heap e Select
void Troca(int *a, int *b) {
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
//Radix Sort
void radixSort(int *arr, int n) {
    x = encontrarMaior(arr, n); 
    for (k = 1; x / k > 0; k *= 10) {
        int saida[n]; // Array de saída
        int contador[10] = {0}; // Inicializa o contador de dígitos
        // Conta a ocorrência de cada dígito
        for (int i = 0; i < n; i++) {
            contador[(arr[i] / k) % 10]++;
        }
        // Atualiza o contador para indicar a posição correta de cada dígito
        for (int i = 1; i < 10; i++) {
            contador[i] += contador[i - 1];
        }
        // Cria o array de saída a partir do array original
        for (int i = n - 1; i >= 0; i--) {
            saida[contador[(arr[i] / k) % 10] - 1] = arr[i];
            contador[(arr[i] / k) % 10]--;
            CT++;
        }
        // Copia o array de saída de volta para o array original
        for (int i = 0; i < n; i++) {
            arr[i] = saida[i];
        }
    }
}
//Binary search
void BuscaBinaria(int *vetor, int inicio, int fim, int alvo){
    CT++;
    // Índice representando o meio do sub-vetor begin->end 
    i = (inicio + fim) / 2;
    // Ponto de parada. Item não está no vetor 
    if (inicio > fim) {
        printf("\nDado %d não encontrado na lista\nDado %d nao encontrado na lista", alvo, alvo); 
        return;
    }
    CC++;
    // Item encontrado 
    if (vetor[i] == alvo) {  
        printf("\nDado %d encontrado na posição %d da lista\nDado %d encontrado na posicao %d da lista", alvo, i, alvo, i);
        return;
    }
    CC++;
    // Item está no sub-vetor à direita 
    if (vetor[i] < alvo) {  
        return BuscaBinaria (vetor, i + 1, fim, alvo);
    // vetor[i] > alvo. Item está no sub-vetor à esquerda
    } else {   
        return BuscaBinaria (vetor, inicio, i - 1, alvo);
    }
} 
//Definir TAM
void lerTAM(){
	printf("Defina o tamanho do vetor: ");
	scanf("%d",&TAM);
	vBase = (int *)malloc(TAM * sizeof(int));
	R = (int *)malloc(TAM * sizeof(int));
    vBubble = (int *)malloc(TAM * sizeof(int));
    vInsert = (int *)malloc(TAM * sizeof(int));
    vSelect = (int *)malloc(TAM * sizeof(int));
    vShell = (int *)malloc(TAM * sizeof(int));
    vMerge = (int *)malloc(TAM * sizeof(int));
    vQuick = (int *)malloc(TAM * sizeof(int));
    vHeap = (int *)malloc(TAM * sizeof(int));
    vRadix = (int *)malloc(TAM * sizeof(int));
    vBinary = (int *)malloc(TAM * sizeof(int));
}
//Preencher vetor com elementos aleatórios
void gerarVetor(int vet[], int TAM){
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        do {
        x=rand()%TAM;
        } while(R[x]==1);
        vet[i]=x;
        R[x]=1;
    }
}
//Imprimir vetor
void imprimirVetor(int vet[], int TAM){
	printf("\n");
	for (i=0;i<TAM;i++){
		printf ("[%d] ",vet[i]);
	}	
}
//Copiar conteúdo de um vetor a outro
void copiarVetor(int vCopy[], int TAM){
    for (i=0;i<TAM;i++){
		vBubble[i]=vCopy[i];
        vInsert[i]=vCopy[i];
        vSelect[i]=vCopy[i];
        vHeap[i]=vCopy[i];
        vShell[i]=vCopy[i];
        vQuick[i]=vCopy[i];
        vMerge[i]=vCopy[i];
        vRadix[i]=vCopy[i];
        vBinary[i]=3*vCopy[i];
	}
}
//Menu principal
void Case(){
    printf("\nDeseja continuar?\n 1-Sim\n 2-Não / Nao\n");
    scanf("%d", &M);
    switch (M){
        case 1:
            M=-1, CC=0, CT=0, tempo=0.0;
            //Menu para selecionar o tipo de sort
            printf("\nSelecione um algoritmo de sort ou search:\n1-Bubble\n2-Insert\n3-Select\n4-Quick\n5-Merge\n6-Shell\n7-Heap\n8-Radix\n9-Binary search\n10-Sair\n");
            scanf("%d", &M);
            copiarVetor(vBase, TAM);
	        switch(M){
                //Bubble
		        case 1:{
                    clock_t start1 = clock();
			        bubble(vBubble, TAM);
                    clock_t end1 = clock();
                    tempo = ((float)(end1 - start1)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
			        imprimirVetor(vBubble, TAM);
                    Case();
    			    break;
                }
                //Insert
    		    case 2:{
			        clock_t start2 = clock();
                    insert(vInsert, TAM);
                    clock_t end2 = clock();
                    tempo = ((float)(end2 - start2)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
		            imprimirVetor(vInsert, TAM);
                    Case();
   			        break;
                }
                //Select
		        case 3:{
                    clock_t start3 = clock();
	        	    selecta(vSelect, TAM);
                    clock_t end3 = clock();
                    tempo = ((float)(end3 - start3)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
                    imprimirVetor(vSelect, TAM);
                    Case();
    		        break;
                }
                //Quick
    		    case 4:{
                    clock_t start4 = clock();
                    quick(vQuick, 0, TAM-1);
                    clock_t end4 = clock();
                    tempo = ((float)(end4 - start4)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
		    	    imprimirVetor(vQuick, TAM);
                    Case();
            		break;
                }
                //Merge
    	        case 5:{
		            clock_t start5 = clock();
                    mergeSort(vMerge, 0, TAM-1);
                    clock_t end5 = clock();
                    tempo = ((float)(end5 - start5)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
	        	    imprimirVetor(vMerge, TAM);
                    Case();
    		        break;
                }
                //Shell
   		        case 6:{  	
		            clock_t start6 = clock();
                    shellSort(vShell, TAM);
                    clock_t end6 = clock();
                    tempo = ((float)(end6 - start6)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
		            imprimirVetor(vShell, TAM);
                    Case();
    		        break;
                }
                //Heap
    		    case 7:{
                    clock_t start7 = clock();
			        heapSort(vHeap, TAM);
                    clock_t end7 = clock();
                    tempo = ((float)(end7 - start7)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
		            imprimirVetor(vHeap, TAM);
                    Case();
			        break;
                }
                //Radix
    		    case 8:{
			        clock_t start8 = clock();
                    radixSort(vRadix, TAM);
                    clock_t end8 = clock();
                    tempo = ((float)(end8 - start8)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("Para ordenar este vetor precisou comparar %d vezes e trocar %d vezes: ", CC, CT);
		    	    imprimirVetor(vRadix, TAM);
                    Case();
			        break;
                }
                //Binary
                case 9:{
                    clock_t start9 = clock();
                    radixSort(vBinary, TAM);
                    clock_t end9 = clock();
                    tempo = ((float)(end9 - start9)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para ordenar foi de %.5f ms\n", tempo);
                    printf("\nQual dado deseja buscar? ");
                    scanf("%d", &x);
                    tempo=0.0, CC=0, CT=0;
                    clock_t start10 = clock();
                    BuscaBinaria(vBinary, 0, TAM-1, x);
                    clock_t end10 = clock();
                    tempo = ((float)(end10 - start10)) / CLOCKS_PER_SEC * 1000.0;
                    printf("\nO tempo decorrido para buscar foi de %.5f ms", tempo);
                    printf("\nPara buscar neste vetor precisou comparar %d vezes e iterar %d vezes: ", CC, CT);
                    imprimirVetor(vBinary, TAM);
                    Case();
                    break;
                }
                //Encerrar o programa
    		    default:{
                    printf("Encerrando\n");
    			    break;
                }
            }
            break;
        //Encerrar o programa
        default:{
            printf("\nEncerrando\n");
            break;
        }
    }
}

int main (){
    lerTAM();
    printf("Foi gerado o vetor: ");
    gerarVetor(vBase, TAM);
    imprimirVetor(vBase, TAM);
    Case();	
	return 0;
}
