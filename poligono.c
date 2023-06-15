#include <stdio.h>
int main (){
  float  N=0, d, ai, ae, S;
  while (N<=2){
    printf("Insira um número de lados para um polígono regular: ");
    scanf("%d", &N);
  }
  d=N*(N-3)/2;
  S=(N-2)*180;
  ai=S/N;
  ae=180-ai;
  printf("\nO polígono de %.0f lados possui:\n%.0f diagonais\n%.2f=ângulo interno\n%.2f=ângulo externo\n%.0f=soma dos ângulos internos", N,d,ai,ae,S);
return 0;
}
