#include <stdio.h>		//Programa que realiza operações da análise combinatória: Permutação simples ou circular, Arranjo simples ou com repetição, Combinação simples ou com repetição e probabilidade com as operações citadas anteriormente
#include <stdlib.h>
#include <float.h>
long double N= -1, P= -1, n= -1, p= -1, r, R, y, x;		//N e P para o caso 1 montando a operação, n e p para o caso 2 montando a operação, R para resultado do caso 1, r para resultado do caso 2, x e y para parâmetros, 
int M= -1;		//M para selecionar no menu
long double calFat(long double n) {	//Fatorial recursivo em rotina
    if (n == 1) {
        return 1;
    } else {
    	return (n * calFat(n - 1));
    }
}
long double potencia(long double x, long double y){		//Rotina para realizar exponenciação
	int z = 1;
	for (y;y>0;y--){
		z=z*x;
	}
	return (z);
}
long double arranrepete (long double x, long double p){ 	//Arranjo com repetição
	return (potencia(x,p));
}
long double combirepete (long double x, long double p){		//Combinação com repetição
	return ((calFat(x+p-1))/(calFat(p)*calFat(x-1)));
}
long double permucircu (long double x){		//Permutação circular
	return (calFat(x)/x);
}    
long double permu (long double x){	//Permutação simples
	return (calFat(x));
}
long double arranjo (long double x, long double p){ 	//Arranjo simples
	return (calFat(x)/calFat(x-p));
}
long double combi (long double x,long double p){	//Combinação simples
    return (calFat(x)/(calFat(p)*calFat(x-p)));
}
void LerN(){	//Ler variável N
	while (N<0){
		printf("Digite o valor de N: ");
		scanf("%Lf",&N);
    }
}
void LerP(){ 	//Ler variável P
	while (P<0){	
		printf("Digite o valor de P: ");
		scanf("%Lf",&P);
	}
}
void WriteR(){		//Escrever variável R
	printf("%.0Lf possibilidades\n\n", R);
	N= -1, M= -1, P= -1;
}
void Lern(){	//Ler variável n
	while (n<0){
		printf("\nDigite o valor de n para o campo de possibilidades: ");
		scanf("%Lf",&n);
    }
}
void Lerp(){	//Ler variável p
	while (p<0){
		printf("\nDigite o valor de p para o campo de possibilidades: ");
		scanf("%Lf",&p);
    }
}
void Writer(){		//Escrever variável r
	printf("A probabilidade é de %.0Lf/%.0Lf\n\n", r, R);
	N= -1, M= -1, P= -1, n= -1, p= -1;
}
int main() {
    while (M!=8){
        while (M<0 || M>8){  	//Menu para selecionar a operação
            printf("Selecione uma expressão:\n1-Permutação simples\n2-Arranjo simples\n3-Combinação simples\n4-Probabilidade\n5-Permutação circular\n6-Arranjo com repetição\n7-Combinação com repetição\n8-Sair\n\n");
            scanf("%d", &M);
        }
	    switch(M){
		    case 1:  	//permutação simples
			    LerN();
			    R=permu(N);
			    WriteR();
    			break;
		    case 2: 	//arranjo simples
                LerN();
                LerP();
                R=arranjo(N,P);
    			WriteR();
            break;
            case 3: 	//combinação simples
			   	LerN();
                LerP();   
                R=combi(N,P);
			    WriteR();
            break;
            case 4: 	//verificar qual caso de probabilidade
                M=-1;
                while (M<1 || M>7){		//Menu para selecionar a probabilidade a partir de uma operação
                    printf("Qual o tipo de probabilidade?\n1-Permutação simples\n2-Arranjo simples\n3-Combinação simples\n4-Permutação circular\n5-Arranjo com repetição\n6-Combinação com repetição\n7-Sair\n\n");
                    scanf("%d", &M);
                }
                switch(M){ 
		            case 1:		//Probabilidade de permutação simples
			            LerN();
			            R=permu(N);
                        Lern();
			            r=permu(n);
			            Writer();
    		        break;
		            case 2:		//Probabilidade de arranjo simples
                        LerN();
                		LerP();
                        R=arranjo(N,P);
                        Lern();
                		Lerp();
			            r=arranjo(n,p);
			            Writer();
                    break;
                    case 3:		//Probabilidade de combinação simples
			            LerN();
                		LerP();
                        R=combi(N,P);
                        Lern();
                		Lerp();
                        r=combi(n,p);
                        Writer();
                    break;
                    case 4:		//Probabilidade de permutação circular
			            LerN();
			            R=permucircu(N);
                        Lern();
			            r=permucircu(n);
			            Writer();
                    break;
                    case 5:		//Probabilidade de arranjo com repetição
			            LerN();
                		LerP();
                        R=arranrepete(N,P);
                        Lern();
                		Lerp();
			            r=arranrepete(n,p);
			            Writer();
                    break;
                    case 6: 	//Probabilidade de combinação com repetição
			            LerN();
                		LerP();
                        R=combirepete(N,P);
                        Lern();
                		Lerp();
                        r=combirepete(n,p);
                        Writer();
                    break;
                    case 7: //sair
			            printf("Saindo\n\n");
			            M=-1;
                    break;
				} 
            break;
            case 5: 	//permutação circular
			   	LerN();
				R=permucircu(N);
			   	WriteR();
            break;
            case 6: 	//arranjo com repetição
            	LerN();
            	LerP();
			   	R=arranrepete(N,P);	
			   	WriteR();
            break;
            case 7: 	//combinação com repetição
            	LerN();
            	LerP();
			   	R=combirepete(N,P);
			   	WriteR();
            break;
            case 8:		//encerrar o programa
            	printf("Encerrando\n");
            break;
	    }
    }
    return 0;
}
