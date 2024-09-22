//IAA-EP1: Buscar menor e maior valor e suas posições em uma matriz quadrada N de potência de 2 usando divisão e conquista
#include <stdio.h>
#include <stdlib.h>

//Declaração das variáveis globais para menor e maior valor e suas posições
int Min, Max, MinL, MinC, MaxL, MaxC;

void inicializarGlobais(int M, int L, int C) { //Inicializar as variáveis globais
    Min=M, Max=M, MinL=L, MinC=C, MaxL=L, MaxC=C;
}

//Divisão da matriz com parâmetros a matriz, início da linha(IL) e da coluna(IC), final da linha(FL) e da coluna(FC)
void Dividir(int** M, int IL, int IC, int FL, int FC) { //Se iguais menor linha, se mesma linha menor coluna
    if(IL==FL && IC==FC){ //Verificar se formou a menor matriz possível (1x1)
        int Temp=M[IL][IC]; //Auxiliar para passar por toda matriz
        
        if(Min==Temp && IL==MinL && IC<MinC){ //Verificar se encontrou um valor tão pequeno quanto o menor encontrado
            MinC=IC; //Salvar posição do valor de menor coluna
        } else {
            if(Min==Temp && IL<MinL){ MinL=IL, MinC=IC; //Salvar posição do valor de menor linha
            } else {
                if(Temp<Min){ //Verificar se achou um valor menor do que o valor salvo
                    Min=Temp, MinL=IL, MinC=IC; //Se sim atualiza o menor valor e sua posição
                }
            }
        }
        
        if(Max==Temp && IL==MaxL && IC<MaxC){ //Verificar se encontrou um valor tão grnade quanto o maior encontrado
            MaxC=IC; //Salvar posição do valor de menor coluna
        } else {
            if(Max==Temp && IL<MaxL){ MaxL=IL, MaxC=IC; //Salvar posição do valor de menor linha
            } else {
                if(Temp>Max){ //Verificar se achou um valor maior do que o valor salvo
                    Max=Temp, MaxL=IL, MaxC=IC; //Se sim atualiza o maior valor e sua posição
                }
            }
        }

        return;
    }

    //Obter a metade da linha(ML) e da coluna(MC)
    int ML=(IL+FL)/2; int MC=(IC+FC)/2;

    Dividir(M, IL, IC, ML, MC);//Buscar no 1º quadrante
    if(MC+1<=FC){ //Verificar não ultrapassou o tamanho da matriz
        Dividir(M, IL, MC+1, ML, FC); //Buscar no 2º quadrante
    }
    if(ML+1<=FL){ //Verificar não ultrapassou o tamanho da matriz
        Dividir(M, ML+1, IC, FL, MC); //Buscar no 3º quadrante
    }
    if(ML+1<=FL && MC+1<=FC){ //Verificar não ultrapassou o tamanho da matriz
        Dividir(M, ML+1, MC+ 1, FL, FC); //Buscar no 4º quadrante
    }
} //Fim Dividir

int main(int argc, char *argv[]) { //Início do main
    int N, i, j, **M;

    if(argc!=4){ //4 argumentos = nome do programa, N(tamanho da matriz), arquivo de entrada(conteúdo da matriz), nome e formato do arquivo de saída(apresentar menor e maior e suas posições)
        printf("Número de argumentos inesperado %d, precisa de 4 argumentos.\n", argc); //Encerrar o programa se não receber argumentos suficientes
        return 1;
    }

    N=atoi(argv[1]); //Mudança de tipo string para int para representar o tamanho da matriz contida no arquivo
    if(N<=0){
        printf("Tamanho da matriz deve ser um número inteiro positivo.\n"); //Encerrar se receber um número negativo
        return 1;
    }

    M=(int**)malloc(N*sizeof(int*)); //Criar a matriz dinamicamente
    for(int i=0;i<N;i++) 
        M[i]=(int*)malloc(N*sizeof(int));
    
    FILE *FileIn=fopen(argv[2], "r"); //Criar poteiro do arquivo de entrada
    if(!FileIn){ //Verificar se conseguiu abrir o arquivo no modo de leitura
        perror("Erro ao abrir o arquivo.\n"); //Se não, encerra o programa
        for(i=0;i<N;i++) //Liberar a memória alocada
            if(M[i]!=NULL) free(M[i]);
        if(M!=NULL) free(M);
        return 1;
    }

    for(i=0;i<N;i++){ //Passar conteúdo do arquivo para a matriz
        for(j=0;j<N;j++){
            if (fscanf(FileIn, "%d", &M[i][j])!=1){ //Verificar se a passagem foi bem sucedida
                printf("Erro ao ler arquivo.\n"); //Se não for, encerra o programa
                fclose(FileIn); //Fechar arquivo de entrada
                for(i=0;i<N;i++) //Liberar memória alocada
                    if(M[i]!=NULL) free(M[i]);
                if(M!=NULL) free(M);
                return 1;
            }
        }
    }
    fclose(FileIn); //Fechar arquivo de entrada

    inicializarGlobais(M[0][0], 0, 0); //Inicializar variáveis globais a partir do 1º valor da matriz

    Dividir(M, 0, 0, N-1, N-1); //Início da divisão e conquista

    FILE *FileOut=fopen(argv[3], "w"); //Criar ponteiro do arquivo de saída
    if(!FileOut){ //Verificar se conseguiu abrir o arquivo no modo de escrita
        perror("Erro ao abrir o arquivo de saída"); //Se não, encerra o programa
        for(i=0;i<N;i++) //Liberar memória alocada
            if(M[i]!=NULL) free(M[i]);
        if(M!=NULL)free(M);
        return 1;
    }

    fprintf(FileOut, "min = %d; pos = (%d, %d)\nmax = %d; pos = (%d, %d)\n", Min, MinL, MinC, Max, MaxL, MaxC); //Gravar conteúdo no arquivo de saída
    
    fclose(FileOut); //Fechar arquivo de saída

    for(i=0;i<N;i++) //Liberar memória alocada
        if(M[i]!=NULL) free(M[i]);
    if(M!=NULL) free(M);

    return 0; //Fim do main
}

