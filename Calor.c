#include <stdio.h>
#include <stdlib.h>
float a[4]; //a[0] calor, a[1] massa, a[2] calor sensivel, a[3] temperatura
char m[4][5]={{"cal"},{"g"},{"/"},{"°C"}};
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
void calor(){
    printf("\nDigite o valor do calor específico da substância em calorias / gramas * graus Celsius: ");
    scanf("%f",&a[2]);
}
int main (){
    int i;
    printf("Qual valor você quer descobrir?\n 0-Energia\n 1-Massa\n 2-Calor específico\n 3-Variação de temperatura\n");
    scanf("%d",&i);
    switch(i){
      case 0:
        massa();
        temperatura();
        coeficiente();
        a[i]=a[1]*a[2]*a[3];
        printf("%.0f %s", a[i], m[i]);
        break;
      case 1:
        energia();
        temperatura();
        coeficiente();
        a[i]=a[0]/(a[2]*a[3]);
        printf("%.0f %s", a[i], m[i]);
        break;
      case 2:
        massa();
        temperatura();
        energia();
        a[i]=a[0]/(a[1]*a[3]);
        printf("%.0f %s%s%s*%s", a[i], m[0], m[i], m[1], m[3]);
        break;
      case 3:
        massa();
        energia();
        coeficiente();
        a[i]=a[0]/(a[2]*a[1]);
        printf("%.0f %s", a[i], m[i]);
        break;
}
  printf("\n");
  return 0;
}
