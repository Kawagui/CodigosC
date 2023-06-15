#include <stdio.h>
int main (){
  int N=0, d;
  float ai, ae, S;
  while (N<=2){
    printf("Insira um número de lados para um polígono regular: ");
    scanf("%d", &N);
  }
  d=N(N-3)/2;
  S=(N-2)*180;
  ai=S/N;
  ae=180-ai;
  printf("\nO polígono de %d lados possui:\n%d diagonais\n%.2f=ângulo interno\n%,2f=ângulo externo\n%.2f=soma dos ângulos internos", N,d,ai,ae,S);
return 0;
}
