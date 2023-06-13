#include <stdio.h>
#include <stdlib.h>
//variáveis globais
int M=0, m=0;
float x;
//rotinas para * ou / de unidades de tempo
int m60(float x){
  return (x*60);
}
int d60(float x){
  return (x/60);
}
int m24(float x){
  return (x*24);
}
int d24(float x){
  return (x/24);
}
//rotina de conversão de tempo
void Tempo(int y){
  float h[4];
  if (y==5){
    goto fim;
  } else { do{
      printf("Digite o número:");
      scanf("%f", &h[y]);
  } while (h[y]<0);
    if (y==1){
      h[2]=d60(h[1]);
      h[3]=d60(h[2]);
      h[4]=d24(h[3]);
    } else {
      if (y==2){
        h[1]=m60(h[2]);
        h[3]=d60(h[2]);
        h[4]=d24(h[3]);
      } else {
        if (y==3){
          h[2]=m60(h[3]);
          h[1]=m60(h[2]);
          h[4]=d24(h[3]);
        } else {
          h[3]=m24(h[4]);
          h[2]=m60(h[3]);
          h[1]=m60(h[2]);
        }
      }
    }
    printf("Escolha em que quer converter:\n 1-Segundo\n 2-Minuto\n 3-Hora\n 4-Dia\n 5-Sair\n");
    scanf("%d", &M);
    if (M==5){
      goto fim;
  }
    printf("%.2f\n", h[M]);}
  fim:
  printf("----------------------------------------------------------------------------------------------------------------\n");
}
//incio do programa principal
int main(){
  inicio:
  do {
	printf("Escolha o que quer converter:\n 1-Tempo\n 2-Temperatura\n 3-Volume\n 4-Velocidade\n 5-Densidade\n 6-Sair\n\n");
  scanf("%d", &m);
  switch (m){
    case 1:
      do {
        printf("Escolha o que quer converter:\n 1-Segundo\n 2-Minuto\n 3-Hora\n 4-Dia\n 5-Sair\n");
        scanf("%d", &m);
        while (m<1 || m>5){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Tempo(m);} while(m!=5);
    break;
    case 2:
      printf("b\n");
      goto inicio;
    break;
    case 3:
      printf("c\n");
      goto inicio;
    break;
    case 4:
      printf("d\n");
      goto inicio;
    break;
    case 5:
      printf("e\n");
      goto inicio;
    break;
    case 6:
      printf("\nEncerrando\n\n");
    break;
    default:
      printf("Selecione um número da lista\n");
      goto inicio;
    break;
}
} while (m!=6);
	return 0;
}
