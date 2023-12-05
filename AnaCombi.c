//Programa que realiza operações da análise combinatória: Permutação simples ou circular, Arranjo simples ou com repetição, Combinação simples ou com repetição e probabilidade com as operações citadas anteriormente
#include <stdio.h>		
#include <stdlib.h>
#include <float.h>
#include <time.h>
//Todas as variáveis usadas, informações de cada uma têm no documento
long double r, R, x, tempo, y,  d=0, a=1;		
int M, N= -1, P= -1;
//Fatorial recursivo
long double calFat(int n) {	
    if (n == 1) {
        return 1;
    } else {
    	return (n * calFat(n - 1));
    }
}
//Arranjo com repetição
long double arranRepete (int n, int p){ 	
	x=1;
	for (p;p>0;p--){
		x=x*n;
	}
	return (x);
}
//Combinação com repetição
long double combiRepete (int n, int p){		
	return ((calFat(n+p-1))/(calFat(p)*calFat(n-1)));
}
//Permutação circular
long double permuCircu (int n){		
	return (calFat(n)/n);
}    
//Permutação simples
long double permu (int n){	
	return (calFat(n));
}
//Arranjo simples
long double arranjo (int n, int p){ 	
	return (calFat(n)/calFat(n-p));
}
//Combinação simples
long double combi (int n,int p){	
    return (calFat(n)/(calFat(p)*calFat(n-p)));
}
//Ler variável N
void LerN(){	
	while (N<0||N>1754){
		printf("Digite o valor de N: ");
		scanf("%d",&N);
    }
}
//Ler variável P
void LerP(){ 	
	while (P<0){	
		printf("Digite o valor de P: ");
		scanf("%d",&P);
	}
}
//Escrever variável R
void WriteR(){		
	__mingw_printf("%.0Lf possibilidades\n", R);
}
//Escrever variável r
void Writer(){		
	__mingw_printf("A probabilidade de %.0Lf  /  %.0Lf\n\n", r, R);
}
//Contar os dígitos escrever quantidade
void contagemDigitos(){ 
	while (a<=R){
		a=a*10;
		d++;
	}
	__mingw_printf("Este número possui %.0Lf dígitos\nEste numero possui %.0Lf digitos\n\n", d, d);
	a=1;
	d=0;
}
void trocar (){     //Função de troca de valores entre variáveis
    y = R;
    R = r;
    r = y;
}
//Cronometrar tempo
void Cronometro1(long double (*funcao)(int)) {
    // Registra o tempo de início
	tempo = 0.0;
    clock_t start = clock();
    // Chama a função que executa a ação
    R=funcao(N);
    // Registra o tempo de término
    clock_t end = clock();
    // Calcula a diferença de tempo em milissegundos
    tempo = ((long double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    // Exibe o tempo de execução para a ação
    __mingw_printf("O tempo decorrido foi de %.5Lf ms\n", tempo);
	N=-1, M=-1;
}
void Cronometro2(long double (*funcao)(int, int)) {
    // Registra o tempo de início
	tempo = 0.0;
    clock_t start = clock();
    // Chama a função que executa a ação
    R=funcao(N,P);
    // Registra o tempo de término
    clock_t end = clock();
    // Calcula a diferença de tempo em milissegundos
    tempo = ((long double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    // Exibe o tempo de execução para a ação
    __mingw_printf("O tempo decorrido foi de %.5Lf ms\n", tempo);
	P=-1, N=-1, M=-1;
}
//Declaração das rotinas de menu
void CaseMain();
void CaseProb();
//Menu inicial do programa para seleção de expressão
void CaseMain(){
	printf("Selecione uma expressão / Selecione uma expressao (limite do fatorial 1754):\n1-Permutação simples / Permutacao simples\n2-Arranjo simples\n3-Combinação simples / Combinacao simples\n4-Probabilidade\n5-Permutação circular / Permutacao circular\n6-Arranjo com repetição / Arranjo com repeticao (até 18^18)\n7-Combinação com repetição / Combinacao com repeticao\n8-Sair\n\n");
        scanf("%d", &M);
	    switch(M){
			//permutação simples
		    case 1:{
			    LerN();
				Cronometro1(permu);
			    WriteR();
				contagemDigitos();
				CaseMain();
    			break;
			}
			//arranjo simples
		    case 2:{
                LerN();
                LerP();
				Cronometro2(arranjo);
    			WriteR();
				contagemDigitos();
				CaseMain();
            break;
			}
			//combinação simples
            case 3:{
			   	LerN();
                LerP();  
				Cronometro2(combi);
			    WriteR();
				contagemDigitos();
				CaseMain();  
            break;
			}
			//menu para probabilidade de cada operação
            case 4:{
            	CaseProb();
            	break;  
			}
			//permutação circular
            case 5:{
			   	LerN();
				Cronometro1(permuCircu);
			   	WriteR();
				contagemDigitos();
				CaseMain();
            break;
			}
			//arranjo com repetição
            case 6:{
            	LerN();
            	LerP();
				Cronometro2(arranRepete);
			   	WriteR();
				contagemDigitos();
				CaseMain();
            break;
			}
			//combinação com repetição
            case 7:{
            	LerN();
            	LerP();
				Cronometro2(combiRepete);
			   	WriteR();
				contagemDigitos();
				CaseMain();
            break;
			}
			//encerrar o programa
            default:{	
            	printf("Encerrando\n");
            break;
			}
	    }
}
//Menu para selecionar a probabilidade a partir de uma operação
void CaseProb(){	
    printf("Qual o tipo de probabilidade (limite do fatorial 1754)?\n1-Permutação simples / Permutacao simples\n2-Arranjo simples\n3-Combinação simples / Combinacao simples\n4-Permutação circular / Permutacao circular\n5-Arranjo com repetição / Arranjo com repeticao (até 18^18)\n6-Combinação com repetição / Combinacao com repeticao\n7-Sair\n\n");
    scanf("%d", &M); 
    switch(M){ 
		//permutação simples
		case 1:{
    		LerN();
			Cronometro1(permu);
			r=R;
    		LerN();
			Cronometro1(permu);
			trocar();
			Writer();
			CaseMain();
    		break;
		}
		//arranjo simples
		case 2:{
    		LerN();
    		LerP();
			Cronometro2(arranjo);
			r=R;
    		LerN();
    		LerP();
			Cronometro2(arranjo);
			trocar();
			Writer();
			CaseMain();
        	break;
		}
		//combinação simples
    	case 3:{	
			LerN();
        	LerP();
			Cronometro2(combi);
			r=R;
			LerN();
        	LerP();
			Cronometro2(combi);
			trocar();
        	Writer();
        	CaseMain();
    		break;
		}
		//permutação circular
    	case 4:{
			LerN();
			Cronometro1(permuCircu);
			r=R;
        	LerN();
			Cronometro1(permuCircu);
			trocar();
			Writer();
			CaseMain();
        	break;
		}
		//arranjo com repetição
    	case 5:{
			LerN();
		    LerP();
			Cronometro2(arranRepete);
			r=R;
			LerN();
    	    LerP();
			Cronometro2(arranRepete);
			trocar();
			Writer();
			CaseMain();
    	    break;
		}
		//combinação com repetição
    	case 6:{	
			LerN();
    	    LerP();
			Cronometro2(combiRepete);
			r=R;
			LerN();
    	    LerP();
			Cronometro2(combiRepete);
			trocar();
    	    Writer();
    	    CaseMain();
    	    break;
		}
		//sair
    	default:{
			printf("Saindo\n\n");			            
    	    break;
		}
	}
}
int main() {
    CaseMain();
    return 0;
}
