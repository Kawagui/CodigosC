//Algoritmos de estrutura de dados do tipo lista pilha e fila circular
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
//Todas as variáveis usadas, informações de cada uma têm no documento
int TAM, topo, inicio, fim, *Pilha, *Fila, M, i, j, s;
//Iniciar/criar pilha
void initializeStack(){    
    Pilha = (int *)malloc(TAM * sizeof(int));
    topo = -1;
    printf("\nFoi criada uma pilha de tamanho %d!", TAM);
}
//Verificar se a pilha está vazia
int isStackEmpty(){      
    return topo == -1;
}
//Verificar se está cheia
int isStackFull(){       
    return topo == TAM - 1;
}
//Imprimir pilha
void printStack(){ 
    if (isStackEmpty()){
        printf("\nErro: A pilha está vazia.");
         
    } else {
        printf("\nConteúdo da pilha: ");
        for (i = 0; i <= topo; i++){
            printf("[%d] ", Pilha[i]);
        }
        printf("\n");
    }
}
//Adicionar valor(es) na pilha
void push(){       
    if (isStackFull()){  
        printf("\nErro: A pilha está cheia.");
    }else{
        printf("\nDigite quantos dados serão adicionados à pilha, se for maior que 1 será preenchida com valores aleatórios... ");
        scanf("%d", &s);
        if (s==1){
            printf("\nDigite o dado a ser adicionado... ");
            scanf("%d", &s);
            printf("\nAdicionando o dado [%d] à pilha.", s);
            Pilha[topo + 1] = s;
            topo++;
            printStack();
            if(isStackFull()){
                printf("\nA pilha agora está cheia!");
            }
        } else {
            srand(time(NULL));
            for (j=0; j<s; j++){
                topo++;
                Pilha[topo] = rand() % 10000;
                printf("\nAdicionando o dado [%d] à pilha.", Pilha[topo]);
                printStack();
                if(isStackFull()){
                    printf("\nA pilha agora está cheia!");
                    break;
                }
            }
        }
    }
}
//Retirar valor(es) da pilha
void pop(){     //Função para desempilhar um elemento da pilha
    if (isStackEmpty()){
        printf("\nErro: A pilha está vazia.");
    }else{
        printf("\nDigite quantos dados serão removidos da pilha... ");
        scanf("%d",&s);
        for (j=0;j<s;j++){
            printf("\nRemovendo o dado [%d] da pilha.", Pilha[topo]);
            topo--;
            if(isStackEmpty()){
                printf("\nA pilha agora está vazia!");
                break;
            } else {
                printStack();
            }
        }
    }
}
//Iniciar/criar fila circular
void  initializeQueue(){
    Fila = (int *)malloc(TAM * sizeof(int));
    inicio = -1;
    fim = -1;
    printf("\nFoi criada uma fila circular de tamanho %d!", TAM);
    }
//Verificar se a fila está vazia
int isQueueEmpty(){
    return (inicio == -1 && fim == -1);
}
//Verificar se está cheia
int isQueueFull(){
    return ((fim + 1) % TAM == inicio);
}
//Imprimir a fila
void printQueue() {
    if (isQueueEmpty()) {
    printf("\nErro: A fila está vazia.");     
    } else {
        printf("\nConteúdo da fila: ");
        for (i = inicio; i <= fim; i++) {
            printf("[%d] ", Fila[i]);
        }       
        printf("\n");
    }
}
//Adicionar valor(es) a fila
void enqueue(){
    if (isQueueFull()){
        printf("\nErro: A fila está cheia.");
    }else {
        printf("\nDigite quantos dados serão adicionados à fila,se for maior que 1 será preenchido com valores aleatórios... ");
        scanf("%d", &s);
        if (s==1){
        	if (isQueueEmpty()){
        	    inicio = 0;
        	    fim = 0;
         	} else {
         	    fim = (fim + 1) % TAM;
         	}
        	printf("\nDigite o dado a ser adicionado... ");
            scanf("%d", &s);
            Fila[fim] = s;
            printf("\nAdicionando o dado [%d] à fila.", s);
            printQueue();
            if(isQueueFull()){
                printf("\nA fila agora está cheia!");
            }
		}else{
        	for (j=0;j<s;j++){
        	    if (isQueueEmpty()){
        	        inicio = 0;
        	        fim = 0;
         	   	} else {
         	    	fim = (fim + 1) % TAM;
         	   	}
         	   	Fila[fim] = rand() % 10000;
         	   	printf("\nAdicionando o dado [%d] à fila.", Fila[fim]);
            	if(isQueueFull()){
                	printf("\nA fila agora está cheia!");
                	printQueue();
                	break;
            	}
            	printQueue();
        	}
        }
    }     
}
//Remover valor(es)
void dequeue(){
    if (isQueueEmpty()){
        printf("Erro: A fila está vazia.\n");
    }else {
        printf("\nDigite quantos dados serão removidos da fila... ");
        scanf("%d",&s);
        for (j = 0; j < s; j++){
            if (inicio == fim){
                printf("\nRemovendo o dado [%d] da fila.", Fila[inicio]);
                inicio = fim = -1;
                printf("\nA fila agora está vazia!");
                break;
            }else{
                printf("\nRemovendo o dado [%d] da fila.", Fila[inicio]);
                inicio = (inicio + 1) % TAM;
                printQueue();
            }
        }   
    }  
}
//Imprimir dados sobre o topo
void printTopo() {
    if (isStackEmpty()){
        printf("\nErro: A pilha está vazia.");
    } else {
        printf("\nO topo é %d e nele contém o dado [%d].", topo, Pilha[topo]);
    } 
}
//Imprimir dados sobre início e fim
void printInicioEFim(){
    if (isQueueEmpty()){
        printf("\nErro: A fila está vazia.");
    } else {
        printf("\nO início é %d e nele contém o dado [%d]\nO fim é %d e nele contém o dado [%d].", inicio, Fila[inicio], fim, Fila[fim]);
    }  
}
//Buscar dado na Pilha
void searchStack(){
	if (isQueueEmpty()){
        printf("\nErro: A fila está vazia.");
    } else {
    	printf("\nQual é o dado a ser buscado? ");
    	scanf("%d",&s);
    	for (i = 0; i < topo+1; i++){
        	if(Pilha[i]==s){
            	printf("Dado [%d] encontrado na posição %d da lista.", s, i);
            	break;
        	}
    	}
    	if(i==topo+1){
        	printf("\nDado não encontrado!");
    	}
    }
}
//Buscar dado na fila
void searchQueue(){
	if (isQueueEmpty()){
        printf("Erro: A fila está vazia.\n");
    }else {
    	printf("\nQual é o dado a ser buscado? ");
    	scanf("%d",&s);
    	for (i = inicio; i < fim+1; i++){
        	if(Fila[i]==s){
            	printf("Dado [%d] encontrado na posição %d da lista.", s, i);
            	break;
        	}
    	}
    	if(i==fim+1){
        	printf("\nDado não encontrado!");
    	}
    }
}
//Definir TAM das listas
void lerTAM(){
    printf("Defina o tamanho da estrutura: ");
    scanf("%d", &TAM);
}
//Declarando as funções de menu pilha, fila e principal
void CasePilha();
void CaseFila();
void CaseMain();
//Menu de opções da pilha
void CasePilha(){
    printf("\nO que deseja fazer com a pilha?\n 1-Adicionar(Push)\n 2-Remover(Pop)\n 3-Buscar dado\n 4-Mostrar topo da pilha\n 5-Sair da pilha\n 6-Encerrar o programa\n");
    scanf("%d", &M);
    switch (M){
        case 1:
        push();
        CasePilha();
        break;
        case 2:
        pop();
        CasePilha();
        break;
        case 3:
        searchStack();
        CasePilha();
        break;
        case 4:
        printTopo();
        CasePilha();
        break;
        case 5:
        free(Pilha);
        printf("Limpando e deletando a pilha!");
		CaseMain();
        break;
        default:
        M=5;
        printf("\nEncerrando o programa");
        break;
    }
}
//Menu de opções do início
void CaseMain(){
    printf("\nDeseja mexer com qual estrutura?\n 1-Pilha estática\n 2-Fila circular estática\n 3-Encerrar o programa\n");
    scanf("%d", &M);
    switch (M){
        case 1:
        initializeStack();
        CasePilha();
        break;
        case 2:
         initializeQueue();
        CaseFila();
        break;
        default:
        printf("\nEncerrando ");
        break;
    }
}
//Menu de opções da fila
void CaseFila(){
    printf("\nO que deseja fazer com a fila?\n 1-Adicionar\n 2-Remover\n 3-Buscar dado\n 4-Mostrar início e fim da fila\n 5-Sair da fila\n 6-Encerrar o programa\n");
    scanf("%d", &M);
    switch (M){
        case 1:
        enqueue();
        CaseFila();
        break;
        case 2:
        dequeue();
        CaseFila();
        break;
        case 3:
        searchQueue();
        CaseFila();
        break;
        case 4:
        printInicioEFim();
        CaseFila();
        case 5:
        free(Fila);
        printf("Limpando e deletando a fila!");
        CaseMain();
        break;
        default:
        M=5;
        printf("\nEncerrando o programa");
        break;
    }
}
//Programa principal
int main(){
    lerTAM();
    CaseMain();
    return 0;
}
