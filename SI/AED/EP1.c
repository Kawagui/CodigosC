/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2024                           **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Luís Guilherme Hitoshi Kanazawa        14747868   <turma> 02  **/
/**                                                                 **/
/*********************************************************************/

/*
A Maratona de Programacao que voce gerenciara tem um numero fixo de problemas definido na constante PROBLEMAS.
Os problemas da maratona serao numerados de 0 (zero) ate PROBLEMAS-1.
Havera uma lista ligada ordenada pela classificacao dos times, como discutido ao longo do enunciado.
*/

#include <stdlib.h>
#include <stdio.h>

#define false 0 // false possui valor 0
#define true 1 // true possui valor 1

#define PROBLEMAS 10 // Número de problemas 0 a 9

typedef int bool; // Definir tipo bool como um tipo int

/*
A estrutura TIME foi projetada para armazenar as informacoes de cada time participante da Maratona de Programacao.
Ela e composta por quatro campos:
   id – identificador numerico do time, comecando por 1 (um);
   resolvidos – arranjo booleano com tamanho igual ao numero de problemas da maratona,
   	que contera o valor true}, caso o Time tenha resolvido (corretamente) o problema e false}, caso contrario;
   tentativas – arranjo de inteiros com tamanho igual ao numero de problemas da maratona,
   	que contera o numero de tentativas (submissoes) do respectivo problema que o time fez ate conseguir resolver o problema; e
   minutos – arranjo de inteiros com tamanho igual ao numero de problemas da maratona,
   	que contera o numero de minutos passados desde o inicio da maratona ate o momento em que o time submeteu a solucao correta do respectivo problema.
    	Para os problemas em que o time nao submeteu uma solucao correta, o valor 0 (zero) deve ser armazenado na respectiva posicao do arranjo.
*/
typedef struct {
	int id; // Primary Key do time(1 a n, onde n representa a quantidade de times da maratona) 
	bool resolvidos[PROBLEMAS]; // Vetor que contém 0(false) ou 1(true) associado a cada problema
	int tentativas[PROBLEMAS]; // Vetor que contém tentativas de cada problema
	int minutos[PROBLEMAS]; // Vetor que contém o tempo decorrido de resolução bem sucedida de cada problema (0 se não resolveu)
} TIME; // Tamanho de 124 bytes - id(4), bool=int{(4*nº de Problemas[10])}*3(número de vetores)

/*
A estrutura ELEMENTO foi projetada para armazenar cada elemento da lista duplamente ligada, ordenada, com no cabeca e nao circular
	que voce gerenciara. Esta estrutura e composta por tres campos:
   time (chave) – ponteiro (ou referencia) para o time participante da maratona;
   ant – ponteiro (ou referencia) para o elemento anterior da lista ligada; e
   prox – ponteiro (ou referencia) para o elemento seguinte da lista ligada.
*/
typedef struct aux{ // Ponteiro para apontar o time associado a este ponteiro, para o próximo elemento da lista, e para o elemento anterior da lista
	TIME* time;
	struct aux* ant;
	struct aux* prox;
} ELEMENTO, *PONT; // ELEMENTO tem tamanho de 24 bytes - 3*tamanho de ponteiro(8); PONT tem tamanho de 8 bytes - tamanho de ponteiro(8)

/*
A estrutura  MARATONA foi projetada para representar a Maratona de Programacao. Esta estrutura e composta por dois campos:
   cabeca – ponteiro (ou referencia) para o no cabeca da lista duplamente ligada;
   numTimes – campo do tipo inteiro contendo o numero de times que estao participando da maratona.
*/
typedef struct {
	PONT cabeca; // Ponto de referência para a lista
	int numTimes; // Quantos times estão participando
} MARATONA; // Tamanho de 16 bytes - tamanho de PONT(8) + tamanho de int(4) + 4 bytes vazios ("memória desperdiçada")
/*Estes bytes vazios servem para alinhar o endereço da struct em um múltiplo de 8 (maior tamanho 
dentre os elementos da struct é o PONT) para assim em um vetor do tipo MARATONA o próximo elemento
ser concatenado em um endereço múltiplo de 8*/

/*
Funcao usada em testes da correcao automatica
   NAO APAGAR OU MODIFICAR 
*/
void print123(){

}

/*
Funcao que recebe o endereco de um TIME e, se esse endereco for igual a NULL, retorna -1.
Caso contrario, calcula e retorna a penalidade total (em minutos) recebida pelo time.
A penalidade total de um time e dada pela soma dos minutos que o time levou para resolver cada problema
(estes valores sao armazenados no arranjo minutos), considerando apenas os problemas efetivamente resolvidos,
mais 20 minutos de penalizacao para cada submissao incorreta, considerando, novamente, apenas os problemas que o time conseguiu resolver.
Por exemplo, se o time conseguiu resolver o problema numero 3 apenas na quinta tentativa e a tentativa correta ocorreu no minuto 110,
havera uma penalizacao de 80 minutos referentes as tentativas incorretas, mais 110 minutos referentes ao tempo que o time levou para resolver esse problema.
Assim, havera uma penalidade de 190 minutos referente ao problema de numero 3 (a penalidade total do time corresponde a soma das penalidades do time para todos os problemas da maratona).
Destaca-se que problemas nao resolvidos corretamente tem penalidade igual a zero.
*/
int calcularPenalidade(TIME* time){
	if(time==NULL) return -1; // Verificar se o parâmetro passado existe
    int cont=0; // Guardar a penalidade total
    for(int i=0;i<PROBLEMAS;i++){
        if(time->resolvidos[i]==true){ // Buscar por problemas já resolvidos
            cont+=time->minutos[i]+20*(time->tentativas[i]-1); // Penalidade total vai se acumulando com o tempo de resolução + número de submissões erradas(tentativas-1, ao acertar a submissão incrementa uma tentativa ao problema relacionado) * 20
        }
    }
	return cont;
}

/*
Funcao que recebe o endereco de um TIME e, se esse endereco for igual a NULL, retorna -1.
Caso contrario, calcula e retorna o numero total de problemas resolvidos pelo respectivo time
(o arranjo resolvidos armazena, para cada problema, se ele foi ou nao resolvido).
*/
int calcularProblemasResolvidosDoTime(TIME* time){
    if(time==NULL) return -1; // Verificar se o parâmetro passado existe
    int cont=0; // Guardar quantos problemas o time resolveu
    for(int i=0;i<PROBLEMAS;i++){
        if(time->resolvidos[i]==true){ // Buscar por problemas já resolvidos
            cont++; // Incrementar o contador quando encontrar um problema resolvido
        }
    }
	return cont;
}

/*
Funcao que recebe o endereco de uma MARATONA e, se esse endereco for igual a NULL, retorna -1.
Caso contrario, calcula e retorna o numero total de problemas que nenhum time ainda conseguiu resolver.
Isto e, se a maratona tem 10 problemas e ha tres problemas que nenhum time resolveu, devera retornar 3.
*/
int calcularProblemasNaoResolvidos(MARATONA* mar){
    if(mar==NULL) return -1; // Verificar se o parâmetro passado existe
    int cont=PROBLEMAS; // A maratona se inicia com nenhum problema resolvido
	int i=0, j=0; // Índice(i) para percorrer o vetor resolvidos
	PONT posicao; // Inicializar um ponteiro para buscar por resolvidos==FALSE em cada problema de cada time
	while(i<PROBLEMAS){ // Passar por todos os problemas
		posicao=mar->cabeca->prox; // Começar a busca de resolvidos[i]==TRUE na lista pelo próximo da cabeça
		while(posicao!=NULL){ // Verificar se passou por todos os elementos da lista
			if(posicao->time->resolvidos[i]==false){ // Verificar se o atual time resolveu o problema i
				posicao=posicao->prox; // Passar para o próximo time da lista
			} else {
				cont--; // Caso encontrar decrementar problemas não resolvidos
				break; // Parar a busca para o problema i
			}
		}
		i++; // Passar para o próximo problema
    }
	return cont;
}

/*
Funcao que recebe cinco parametros: mar - endereco de uma MARATONA, id – identificador de um time,
	problema – identificador de um problema, tempo – tempo, em minutos, da submissao,
 	acerto – parametro booleano que indica se o problema foi resolvido corretamente ou nao.
  	Esta funcao devera retornar false caso algum parametro seja invalido, isto e MAR igual a NULL, ou id fora do intervalo
   	que vai de 1 ate o numero de times da respectiva maratona, ou problema fora do intervalo valido dos problemas (que vai de 0 a PROBLEMAS – 1).
     	A funcao tambem devera retornar false caso o respectivo time ja tenha resolvido corretamente o problema
      	cujo numero e dado pelo parametro problema. Isto e, submissoes de problemas ja resolvidos pelo time devem ser ignoradas.
       	Caso contrario, a funcao deve atualizar as seguintes informacoes do time:
(i) aumentar em uma unidade o numero de tentativas de resolucao pelo time para o respectivo problema; 
(ii) caso o time tenha acertado a solucao (parametro acerto = true), (ii.a) atualizar para verdadeiro o respectivo valor do arranjo resolvidos};
(ii.b) atualizar o valor do arranjo minutos}, atualizando o valor correspondente ao problema atual com o tempo passado como parametro;
(ii.c) reposicionar, se necessario, o ELEMENTO correspondente ao time atual na lista duplamente ligada, ordenada, com no cabeca e nao circular.
A lista e ordenada pela classificacao do time na maratona, a qual segue estas regras:
	a lista e ordenada de forma decrescente do time que resolveu mais problemas para o time que resolveu menos problemas
	e tendo como criterio de desempate as penalidades recebidas pelos times
 	(dados dois times que resolveram a mesma quantidade de problemas, ficara na frente da lista [mais para o inicio da lista] aquele com menor penalidade).
Se dois times empatarem nestes dois criterios, deve ficar a frente da lista aquele que ja estava a frente antes da atualizacao
	(isto e, se o time A ja tinha resolvido dois problemas e tinha penalidade 200 e a funcao tratarSubmissao foi chamada para o time B que, agora, resolveu seu segundo problema e ficou com penalidade 200, o time A deve permanecer a frente na classificacao em relacao ao time B [como ja estava antes desta submissao]).
 	Durante a atualizacao da posicao dos elementos da lista ligada preste bastante atencao para atualizar todos os ponteiros necessarios e nao esqueca que a lista e duplamente ligada e possui no cabeca.
*/
bool tratarSubmissao(MARATONA* mar, int id, int problema, int tempo, bool acerto){
	// Retornar FALSE se existe a maratona, ou se id ou problema não estão dentro de seus respectivos intervalos, ou se o time já resolveu
	if(mar==NULL || mar->numTimes-id<0 || mar->numTimes-id>mar->numTimes || PROBLEMAS-1-problema<0 || PROBLEMAS-1-problema>PROBLEMAS-1) return false;
	PONT posicao=mar->cabeca->prox; // Inicializar um ponteiro para buscar pelo time associado ao id
	while(posicao!=NULL){ // Verificar se passou por todos os elementos da lista
		if(posicao->time->id!=id){ // Verificar se o atual time corresponde ao id
			posicao=posicao->prox; // Passar para o próximo time da lista
		} else {
			break; // Parar a busca quando encontrar o time
		}
	}
	if(posicao->time->resolvidos[problema]==true) return false; // Verificar se esse problema já foi resolvido
	posicao->time->tentativas[problema]++; // Aumentar número de tentativas associadas ao problema independete de ter acertado ou não
	if(acerto==false) return true; // Se acertar atribuir tempo a minutos e mudar a flag acerto para true de resolvidos 
	posicao->time->minutos[problema]=tempo;
	posicao->time->resolvidos[problema]=acerto;
	PONT apoio=posicao->ant; // Inicializar um ponteiro de apoio para trocar a posição dos elementos da lista
	while(apoio!=mar->cabeca && calcularProblemasResolvidosDoTime(apoio->time)<calcularProblemasResolvidosDoTime(posicao->time)){
			apoio=apoio->ant; // Buscar o time que mais resolveu problemas do que o time de posição
	}
	while(apoio!=mar->cabeca && calcularProblemasResolvidosDoTime(apoio->time)==calcularProblemasResolvidosDoTime(posicao->time) && calcularPenalidade(apoio->time)>calcularPenalidade(posicao->time)){
			apoio=apoio->ant; // Buscar o time que resolveu a mesma quantidade de problemas que posição e que tenha menor penalidade que posição
	}

	/* A ordenação da lista seguindo os critérios de mais problemas resolvidos e menor penalidade em caso de empate será da seguinte forma:
	Considerando a situação em como a lista fica ao inicializar a maratona:
		NULL<-cabeça<->time1<->time2<->time3<->time4<->time5->NULL
	A atualização dela quando ocorrer tratarSubmissao(&m1, 2, 3, 35, true) ficará assim:
		NULL<-cabeça<->time2<->time1<->time3<->time4<->time5->NULL
	E para isso acontecer é verificado se há time(s) a esquerda de time2 com menos problemas resolvidos.
	Se houver, marco o anterior do time que será ultrapassado, ou seja,
		o time2 será remanejado para ser o próximo elemento da marcação.
	Neste caso a marcação ficou na cabeça da lista,
		então time2 será o próximo elemento da cabeça e terá como próximo o antigo próximo da cabeça(time1),
		e o antigo anterior do time2(time1) vai ter como próximo o antigo próximo do time2(time3)
	De maneira análoga ocorre a aplicação do critério de desempate:
	Se houver time(s) com mesma quantidade de problemas resolvidos e penalidade maior que penalidade do time a ser remanejado
		a marcação continua a ser deslocada a esquerda
	Quando encontrar o time que está a uma colocação acima do time sendo remanejado
		esse processo de troca de ponteiros anteriormente explicado ocorre
	*/

	if(posicao->prox!=NULL) // Verificar se é o último elemento da lista
		posicao->prox->ant=posicao->ant; // Ligar o "buraco" quando um time muda de posição
	posicao->ant->prox=posicao->prox; // Ligar o "buraco" quando um time muda de posição
	posicao->prox=apoio->prox; // Abrir espaço para o time em sua nova posição (ligar com o time a direita)
	if(posicao->prox!=NULL){ // Verificar se é o último elemento da lista 
		posicao->prox->ant=posicao; // Abrir espaço para o time em sua nova posição (ligar com o time a direita)
	} else {
		posicao->prox->ant=NULL;
	}
	posicao->ant=apoio; // Abrir espaço para o time em sua nova posição (ligar com o time a esquerda)
	posicao->ant->prox=posicao; // Abrir espaço para o time em sua nova posição (ligar com o time a esquerda)
	return true;
}

/*
Funcao que recebe como parametro o endereco de uma MARATONA e o numero de times
que participarao da competicao e realiza a inicializacao da maratona.
Isto e, cria a lista duplamente ligada com todos os times e o no cabeca, preenche o valor de todos os campos necessarios
(valores dos times, elementos e da maratona propriamente dita) e retorna true.
Porem, se os parametros recebidos forem invalidos, retorna false}, sem realizar a inicializacao.
Destaca-se que durante a inicializacao, a lista ordenada dos times e criada e, neste momento, o time com id igual a 1 esta em primeiro lugar, com id igual a 2 em segundo e assim por diante (se a competicao acabar sem nenhuma resolucao dos problemas, esta sera a classificacao dos times).
*/
bool inicializarMaratona(MARATONA* mar, int numTimes){
	if (!mar || numTimes < 1) return false; // Verificar validade dos parâmetros
	int x,p;
	ELEMENTO* novoElem;
	TIME* novoTime;
	mar->numTimes = numTimes; // Construtor para o tipo MARATONA
	mar->cabeca = (ELEMENTO*) malloc(sizeof(ELEMENTO)); // Criar cabeça com tamanho de ELEMENTO
	mar->cabeca->ant = NULL;
	mar->cabeca->prox = NULL;
	mar->cabeca->time = NULL;
	for (x=numTimes;x>0;x--){ // Construtor para times
		novoElem = (ELEMENTO*) malloc(sizeof(ELEMENTO)); // Criar elemento com tamanho de ELEMENTO
		novoTime = (TIME*) malloc(sizeof(TIME)); // Criar time com tamanho de TIME
		novoTime->id = x;
		for (p=0;p<PROBLEMAS;p++){
			novoTime->resolvidos[p] = false;
			novoTime->tentativas[p] = 0;
			novoTime->minutos[p] = 0;
		}
		novoElem->time = novoTime; // Vincular cada elemento à lista
		novoElem->prox = mar->cabeca->prox;
		novoElem->ant = mar->cabeca;
		if(mar->cabeca->prox) mar->cabeca->prox->ant = novoElem;
		mar->cabeca->prox = novoElem;
	}
	return true;
}

/*
Funcao que recebe o endereco de uma MARATONA e exibe informacoes basicas dos times de acordo com a ordem de classificacao
(que e a ordem em que os times estao na lista ligada).
*/
void mostrarClassificacao(MARATONA* mar){
	if (mar){ // Verificar parâmetro
		printf("\nClassificacao Atual:\n");
		printf("Time\tProb.\tPenalidadade\n"); // \t para criar um espaçamento (semelhante ao TAB)
		PONT atual = mar->cabeca->prox; // Ponteiro auxiliar para percorrer a lista
		int solucoes, penalidade;
		while (atual){ // atual!=NULL
			solucoes = calcularProblemasResolvidosDoTime(atual->time);
			penalidade = calcularPenalidade(atual->time);
			printf("%4i\t%4i\t%5i\n", atual->time->id, solucoes, penalidade); // %ni mostrar até n primeiros dígitos do int
			atual = atual->prox;
		}
	}
}

/*
Funcao que recebe o endereco de um TIME e exibe informacoes basicas do time
(identificador, numero de problemas resolvidos e penalidade total).
*/
void exibirTime(TIME* t){
	if (t){ // Verificar parâmetro
		printf("Time: %3i; solucoes: %2i; penalidade: %5i\n", t->id, calcularProblemasResolvidosDoTime(t), calcularPenalidade(t));
		int p;
		for (p=0;p<PROBLEMAS;p++){
			printf("\t[%2i: %2i %3i %3i]\n", p, t->resolvidos[p], t->tentativas[p], t->minutos[p]);		
		}
		printf("\n");
	}
}

/*
Funcao que recebe o endereco de uma MARATONA e exibe as informacoes de todos os times (utilizando a funcao exibirTime)
*/
void exibirTodosTimes(MARATONA* mar){
	if (mar){ // Verificar parâmetro
		printf("##### EXIBINDO TODOS OS TIMES #####\n");
		PONT atual = mar->cabeca->prox; // Auxiliar para percorrer lista
		while (atual){
			exibirTime(atual->time);
			atual = atual->prox;
		}
	}
}

/*
Funcao main que realiza ALGUNS testes nas funcoes implementadas
seu EP sera avaliado utilizando um conjunto distinto de testes.
*/   
int main(){
	MARATONA m1;
	inicializarMaratona(&m1, 5);
	printf("Numero de problemas ainda nao resolvidos: %i\n", calcularProblemasNaoResolvidos(&m1));
	mostrarClassificacao(&m1);
	exibirTime(m1.cabeca->prox->time);
	if (!tratarSubmissao(&m1, 2, 3, 25, false)) printf("A funcao retornou false. [PROBLEMA]\n"); // printf irá acontecer se o retorno for inesperado
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 2, 3, 35, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 4, 2, 40, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 4, 40, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 2, 55, false)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 2, 58, false)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 2, 60, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 1, 7, 65, false)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 3, 8, 70, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 1, 8, 75, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 7, 90, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (tratarSubmissao(&m1, 5, 7, 93, true)) printf("A funcao retornou true. [PROBLEMA]\n");
	
	if (!tratarSubmissao(&m1, 1, 1, 95, true)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	if (!tratarSubmissao(&m1, 5, 1, 99, false)) printf("A funcao retornou false. [PROBLEMA]\n");
	mostrarClassificacao(&m1);
	exibirTodosTimes(&m1);
	printf("Numero de problemas ainda nao resolvidos: %i\n", calcularProblemasNaoResolvidos(&m1));
	printf("\nCampeao:\n");
	exibirTime(m1.cabeca->prox->time);
	return 0;
}
