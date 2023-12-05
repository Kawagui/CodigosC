//Algoritmo de implementação de alocação dinâmica no contexto de compactação de uma matriz de incidência de um grafo qualquer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Todas as variáveis usadas, informações de cada uma têm no documento
int TAML=0, TAMC=0, i, j, k, **Matriz, **CopyM, *CdUpL;
float tempo, area;
//Ler número de arestas e vértices de um grafo para alocar espaço necessário para a matriz
void lerTAM() {
    do{
    printf("Defina o número de vértices do grafo (limite de 100000):\nDefina o numero de vertices do grafo (limite de 100000): ");
    scanf("%d", &TAML);
    } while (TAML<=1 || TAML>=100000);
    do{
    printf("\nAgora defina o número de arestas e que seja maior ou igual ao número de vértices (%d):\nAgora defina o numero de arestas e que seja maior ou igual ao numero de vertices (%d): ", TAML, TAML);
    scanf("%d", &TAMC);
    } while (TAML>TAMC || TAMC>=100000);
    Matriz = (int **)malloc(TAML * sizeof(int *));
    CopyM = (int **)malloc(TAML * sizeof(int*));
    CdUpL = (int *)malloc(TAML * sizeof(int *));
    for(i=0;i<TAML;i++){
        CdUpL[i] = 0;
        Matriz[i] = (int *)malloc(TAMC * sizeof(int *));
        CopyM[i] = (int *)malloc(TAMC * sizeof(int *));
    }
}
//Preenche a matriz com 0 para depois aleatoriamente inserir 1, ainda mantendo as características de uma matriz de incidência, podendo representar grafos com laço
void Gerador(){
    for(i=0;i<TAML;i++){
        for(j=0;j<TAMC;j++){
            CopyM[i][j] = Matriz[i][j] = 0;
        }
    }
    srand(time(NULL));
    for(i=0;i<TAMC;i++){
        int v1, v2;
        v1 = rand() % TAML;
        v2 = rand() % TAML;
        CopyM[v1][i] = Matriz[v1][i] = 1;
        CopyM[v2][i] = Matriz[v2][i] = 1;
    }
    for(i=0;i<TAML;i++){
        for(j=0;j<TAMC;j++){
            if (CopyM[i][j]==1){
                CdUpL[i]++;
            }
        }
    }
}
//Menu para optar se a matriz gerada será imprimida ou não, se ela for muito grande será imprimida em arquivo CSV
void Print(){
    area=TAMC*TAML;
    printf("\nFoi gerada uma matriz %d X %d de área %f\nGostaria de a imprimir? Digite 1 para sim ou qualquer dígito para não.\nFoi gerada uma matriz %d X %d de area %f\nGostaria de a imprimir? Digite 1 para sim ou qualquer digito para nao. ", TAML, TAMC, area, TAML, TAMC, area);
    scanf("%d", &j);
    if (j==1){
        if (i>=100){
            printf("\nPor ter uma área superior a 100 ela será imprimida em um arquivo CSV\nPor ter uma area superior a 100 ela vai ser imprimida em um arquivo CSV\n");
            FILE *arquivo;
            arquivo = fopen("MatrizIncidenciaEsparsa.csv", "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.");
            } else {
                for (i=0;i<TAML;i++){
                    for(j=0;j<TAMC;j++){
                        fprintf(arquivo, "%d", Matriz[i][j]);
                        if (j<TAMC-1) {
                            fprintf(arquivo, ",");
                        }
                    }
                    fprintf(arquivo, "\n");
                }       
                fclose(arquivo);
            }
        } else {
            printf("\nFoi gerada a seguinte matriz:\n");
            for(i=0;i<TAML;i++){
                for(j=0;j<TAMC;j++){
                    printf("[%d] ", CopyM[i][j]);
                }
                printf("\n");
            }
        }
        
    }
    printf("\n");
}
//Compactar a matriz usando alocação dinâmica (realloc) e imprimir sua forma compactada
void compactarMatriz() {
    for (int i = 0; i < TAML; i++) {
        CopyM[i] = (int*)realloc(CopyM[i], CdUpL[i] * sizeof(int));
        k=0;
        for (int j = 0; j < TAMC; j++) {
            if (Matriz[i][j] != 0) {
                CopyM[i][k]=j;
                k++;
            }
        }
        printf("V%d incide em A: ", i);
        for (int k = 0; k < CdUpL[i]; k++) {
            printf("[%d] -> ", CopyM[i][k]);
        }
        printf("NULL\n");
    }
}
// Liberar memória alocada
void Liberar(){
    for (int i = 0; i < TAML; i++) {
        free(Matriz[i]);
        free(CopyM[i]);
    }
    free(Matriz);
    free(CopyM);
}
//Cronometrar tempo utilizado por uma função
void Cronometro(void (*funcao)()) {
    // Registra o tempo de início
	tempo = 0.0;
    clock_t start = clock();
    // Chama a função que executa a ação
    funcao();
    // Registra o tempo de término
    clock_t end = clock();
    // Calcula a diferença de tempo em milissegundos
    tempo = ((float)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    // Exibe o tempo de execução para a ação
}

int main() {
    lerTAM();
    Cronometro(Gerador);
    printf("\nO tempo decorrido para gerar a matriz foi de %.5f ms\n", tempo);
    Cronometro(Print);
    printf("\nO tempo decorrido para imprimir a matriz de incidência foi de %.5f ms\n", tempo);
    Cronometro(compactarMatriz);
    printf("\nO tempo decorrido para imprimir a nova matriz foi de %.5f ms\n", tempo);
    printf("\nEncerrando o programa...\n\n");
    return 0;
}
