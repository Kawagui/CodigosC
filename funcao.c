#include <stdio.h>
#include <cmath>
int i, j;
float a,b,c, M[2][5];
//linha 1 para função linear e linha 2 para função quadrática. M[0][0] para raiz, M[0][1] para tangente entre a reta e o eixo x, M[0][2] para ler um X e M[0][3] para escrever Y
//M[1][0] e M[1][1] para as raízes, M[1][2] para discriminate, M[1][3] para ler X, M[1][4] para escrever Y
void func (){
    printf("Determine o valor de a:");
	scanf("%f",&a);
	printf("Determine o valor de b:");
	scanf("%f",&b);
	printf("Determine o valor de c:");
	scanf("%f",&c);
  if (a==0) {
		M[0][0]=c, M[0][1]=b, i=0;
	} else {
		M[1][2]=(b*b)-4*a*c, i=1;
		if(M[1][2]>0){
			M[1][0]=(-b+sqrt(M[2][2]))/2*a;
			M[1][1]=(-b-sqrt(M[2][2]))/2*a;
	  } else {
      if (M[1][2]==0){
		    M[1][0]=-b+d/(2*a);
		    M[1][1]=-b+d/(2*a);
	    } 
    }
  }
}
int main () {
	printf("Monte uma função de 1º grau ou de 2º grau mediante ao seguinte modelo a*x^2+b*x+c\n");
	func;
	if (i==0){
    printf("Você montou uma equação de 1º grau, o quê quer descobrir?\n 1-Raiz\n 2-Tangente\n 3-Um valor de y\n");
    scanf("%d",&j);
    if (j==3) {
      printf("Digite um valor para x: ");
      scanf("%f",&M[i][j-1]);
      M[i][j]=b*M[i][j-1]+c;
      printf("\n%.2f", M[i][j]);
    } else {
      printf("\n%.2f", M[i][j-1]);
    }
  } else {
    printf("Você montou uma equação de 2º grau, o quê quer descobrir?\n 1-Raízes\n 2-Discriminate\n 3-Um valor de y\n");
    scanf("%d",&j);
    if (j==3) {
      printf("Digite um valor para x: ");
      scanf("%f",&M[i][j]);
      M[i][j+1]=a*M[i][j]*M[i][j]+b*M[i][j]+c;
      printf("\n%.2f", M[i][j+1]);
    } else {
      if (j==1){
        printf("\n%.2f e %.2f", M[i][j-1],M[i][j]);
      } else {
      printf("\n%.2f", M[i][j]);
      }
    }
  }
	return 0;
}
