#include <stdio.h>
#include <stdlib.h>
int calFat(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}
void permu (float x){
	return (calFat(x))
}
void arranjo (float x,p){
	return (calFat(x)/calFat(x-p))
}
void combi (float x,p){
    return (calFat(x)/calFat(p)(calFat(x-p)))
}
void prob

int main() {
    int M = -1; 
	float N= -1, R, r, P= -1, n= -1, p= -1;
    while (M!=5){
        while (M<0 || M>5){  
            printf("Selecione uma expressão:\n1-Permutação simples\n2-Arranjo simples\n3-Combinação simples\n4-Probabilidade\n5-Sair\n");
            scanf("%d", &M);
        }
	    switch(M){
		    case 1:
			    while (N<0){
			        printf("Digite o valor de N ");
			        scanf("%f",&N);
                }
			    R=permu(N);
			    printf("\n%f possibilidades", R)
    		break;
		    case 2:
                while (N<0){
			        printf("Digite o valor de N ");
			        scanf("%f",&N);
			    }
                while (P<0){
			        printf("Digite o valor de P ");
			        scanf("%f",&P);
			    }
                R=arranjo(N,P);
    			printf("\n%f possibilidades", R)
            break;
            case 3:
			    while (N<0){
			        printf("Digite o valor de N ");
			        scanf("%f",&N);
			    }
                while (P<0){
			        printf("Digite o valor de P ");
			        scanf("%f",&P);
			    }    
                R=combi(N,P);
			    printf("\n%f possibilidades", R)
            break;
            case 4: //verificar qual caso de probabilidade
                M=-1;
                while (M<1 || M>4){
                    printf("Qual o tipo de probabilidade?\n1-Permutação simples\n2-Arranjo simples\n3-Combinação simples\n4-Sair\n");
                    scanf("%d", &M);
                }
                switch(M){
		            case 1:
			            while (N<0){
			                printf("Digite o valor de N para todas as possibilidades");
			                scanf("%f",&N);
                        }
			            R=permu(N);
                        while (n<0){
			                printf("Digite o valor de n para o campo de possibilidades");
			                scanf("%f",&n);
                        }
			            r=permu(n);
    		        break;
		            case 2:
                        while (N<0){
		    	            printf("Digite o valor de N ");
			                scanf("%f",&N);
			            }
                        while (P<0){
			                printf("Digite o valor de P ");
			                scanf("%f",&P);
			            }
                        R=arranjo(N,P);
                        while (n<0){
			                printf("Digite o valor de n para o campo de possibilidades");
			                scanf("%f",&n);
                        }
                        while (p<0){
			                printf("Digite o valor de p para o campo de possibilidades");
			                scanf("%f",&p);
                        }
			            r=arranjo(n,p);
                    break;
                    case 3:
			            while (N<0){
			                printf("Digite o valor de N ");
			                scanf("%f",&N);
			            }
                        while (P<0){
			                printf("Digite o valor de P ");
			                scanf("%f",&P);
			            }    
                        R=combi(N,P);
                        while (n<0){
			                printf("Digite o valor de n para o campo de possibilidades");
			                scanf("%f",&n);
                        }
                        while (p<0){
			                printf("Digite o valor de p para o campo de possibilidades");
			                scanf("%f",&p);
                        }
                        r=combi(n,p);
                    break;
                printf("A probabilidade é de %f/%f", r, R);
            break;
	        }
    }
    return 0;
}
