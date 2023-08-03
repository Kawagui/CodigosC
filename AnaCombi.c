#include <stdio.h>
#include <stdlib.h>
float N= -1, P= -1, n= -1, p= -1, r, R,y, x;
int M= -1;
int calFat(float n) {
    if (n == 0) {
        return 1;
    } else {
    	return (n * calFat(n - 1));
    }
}
int permu (float x){
	return (calFat(x));
}
int arranjo (float x, float p){
	return (calFat(x)/calFat(x-p));
}
int combi (float x,float p){
    return (calFat(x)/(calFat(p)*calFat(x-p)));
}
void LerN(){
	while (N<0){
		printf("Digite o valor de N: ");
		scanf("%f",&N);
    }
}
void LerP(){
	while (P<0){	
		printf("Digite o valor de P: ");
		scanf("%f",&P);
	}
}
void WriteR(){
	printf("%.0f possibilidades\n\n", R);
	N= -1, M= -1, P= -1;
}
void Lern(){
	while (n<0){
		printf("\nDigite o valor de n para o campo de possibilidades: ");
		scanf("%f",&n);
    }
}
void Lerp(){
	while (p<0){
		printf("\nDigite o valor de p para o campo de possibilidades: ");
		scanf("%f",&p);
    }
}
void Writer(){
	printf("A probabilidade é de %.0f/%.0f\n", r, R);
	N= -1, M= -1, P= -1, n= -1, p= -1;
}
int main() {
    while (M!=5){
        while (M<0 || M>5){  
            printf("Selecione uma expressão:\n 1-Permutação simples\n 2-Arranjo simples\n 3-Combinação simples\n 4-Probabilidade\n 5-Sair\n");
            scanf("%d", &M);
        }
	    switch(M){
		    case 1:  //permutação simples
			    LerN();
			    R=permu(N);
			    WriteR();
    			break;
		    case 2: //arranjo simples
                LerN();
                LerP();
                R=arranjo(N,P);
    			WriteR();
            break;
            case 3: //combinação simples
			   	LerN();
                LerP();   
                R=combi(N,P);
			    WriteR();
            break;
            case 4: //verificar qual caso de probabilidade
                M=-1;
                while (M<1 || M>4){
                    printf("Qual o tipo de probabilidade?\n1-Permutação simples\n2-Arranjo simples\n3-Combinação simples\n4-Sair\n");
                    scanf("%d", &M);
                }
                switch(M){
		            case 1:
			            LerN();
			            R=permu(N);
                        Lern();
			            r=permu(n);
    		        break;
		            case 2:
                        LerN();
                		LerP();
                        R=arranjo(N,P);
                        Lern();
                		Lerp();
			            r=arranjo(n,p);
                    break;
                    case 3:
			            LerN();
                		LerP();
                        R=combi(N,P);
                        Lern();
                		Lerp();
                        r=combi(n,p);
                    break;
				}
                Writer();
            break;
            case 5: //permutação com repetição
			   	//(n!/n1!*n2!*n3!*...nk!) k = número de repetições diferentes
            break;
            case 6: //arranjo com repetição
			   	//(n^k)
            break;
            case 7: //combinação com repetição
			   	//(n+k-1)!/(k!*(n-1)!)
            break;
	    }
    }
    return 0;
}
