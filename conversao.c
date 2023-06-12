#include <stdio.h>
#include <stdlib.h>
int m=0, M=0;
//int dec (int x){
//  printf("");
//}
//int hex (int x){
//}
int main(){
  inicio:
	printf("Escolha o que quer converter:\n 1-Tempo\n 2-Temperatura\n 3-Volume\n 4-Velocidade\n 5-Densidade\n 6-Sair\n");
  scanf("%d", &m);
  switch (m){
    case 1:
      printf("Escolha o que quer converter:\n 1-Segundo\n 2-Minuto\n 3-Hora\n 4-Dia\n 5-Sair\n");
      scanf("%d", &m);
      printf("Escolha em que quer converter:\n 1-Segundo\n 2-Minuto\n 3-Hora\n 4-Dia\n 5-Sair\n");
      switch (m){
        case 1:
          printf("Escolha o que quer converter:\n 1-Segundo\n 2-Minuto\n 3-Hora\n 4-Dia\n 5-Sair\n");
          scanf("%d", &m);
          goto inicio;
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
          printf("f\n");
          goto inicio;
        break;
        default:
          printf("Selecione um número da lista\n");
          goto inicio;
        break;
}
      goto inicio;
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
      printf("f\n");
      goto inicio;
    break;
    default:
      printf("Selecione um número da lista\n");
      goto inicio;
    break;
}
	return 0;
}
