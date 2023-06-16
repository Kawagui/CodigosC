#include <stdio.h>
float a[4]; //a[0] calor, a[1] massa, a[2] calor sensivel, a[3] temperatura
void massa(){
    printf("\nDigite o valor da massa em gramas: ");
    scanf("%f",&a[1]);
}
void energia(){
    printf("\nDigite o valor da energia em calorias: ");
    scanf("%f",&a[0]);
}
void temperatura(){
    printf("\nDigite o valor da variação de temperatura em Celsius: ");
    scanf("%f",&a[3]);
}
void coeficiente(){
    printf("\nDigite o valor do coeficiente de calor sensível em caloria / grama * Celsius: ");
    scanf("%f",&a[2]);
}
int main (){
    int i;
    printf("\n");
    scanf("%d",&i);
    switch(i){
      case 0:
        massa();
        temperatura();
        coeficiente();
        a[i]=a[1]*a[2]*a[3];
        printf("%.0f calorias", a[i]);
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
}
  return 0;
}
