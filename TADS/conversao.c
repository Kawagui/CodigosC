#include <stdio.h>
#include <stdlib.h>
#include <float.h>
//variáveis globais
int M=0, m=0, ME=0, me=0, f=0, y; //M e m para menu de medida 1, ME e me para menu de medida 2, f como flag para conversão com 2 medidas distintas
long double a, b, c; //variáveis de apoio para medida1/medida2 c<-a/b
char s[4][5]={"seg","min","hora","dia"}, V[7][5]={"kL","L","mL","m^3","dm^3","cm^3","mm^3"}, D[4][3]={"km","m","cm","mm"};
//rotina de conversão de Tempo
void Tempo(int y){
  long double h[4]; //armazenar os valores
  if (m!=4){
    do{
      printf("Digite um valor em %s: ",s[y]);
      scanf("%15Lf", &h[y]);
    } while (h[y]<0);
    if (y==0){
      h[1]=h[0]/60;//min<-seg
      h[2]=h[1]/60;//hora<-min
      h[3]=h[2]/24;//dia<-hora
    } else {
      if (y==1){
        h[0]=60*h[1];//seg<-min
        h[2]=h[1]/60;//hora<-min
        h[3]=h[2]/24;//dia<-hora
      } else {
        if (y==2){
          h[1]=60*h[2];//min<-hora
          h[0]=60*h[1];//seg<-min
          h[3]=h[2]/24;//dia<-hora
        } else {
          h[2]=24*h[3];//hora<-dia
          h[1]=60*h[2];//min<-hora
          h[0]=60*h[1];//seg<-min
        }      
      }
    }
    printf("Escolha em que quer converter:\n 0-Segundo\n 1-Minuto\n 2-Hora\n 3-Dia\n 4-Sair\n");
    scanf("%d", &M);
    while (M<0 || M>4){
      printf("Digite um número da lista\n");
      scanf("%d", &M);
    }
    if (M!=4 && f==0){
      printf("%.2Lf %s\n", h[M], s[M]);
    } else {
      if (f==1){
        b=h[M];
      }
    }
      printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//rotina de conversão de Temperatura
void Temperatura (int y){
  long double temp[3]; //armazenar os valores
  char C[3][4]={"°C","°F","K"};
  if (m!=3){
      printf("Digite um valor em %s: ",C[y]);
      scanf("%7Lf", &temp[y]);
    if (y==0){
      temp[1]=temp[0]*9/5+32;//°F<-°C
      temp[2]=temp[0]+273;//K<-°C
    } else {
      if (y==1){
        temp[0]=(temp[1]-32)*5/9;//°C<-°F
        temp[2]=temp[0]+273;//K<-°C
      } else {
        temp[0]=temp[2]-273;//°C<-K
        temp[1]=temp[0]*9/5+32;//°F<-°C
      }      
    }
    printf("Escolha em que quer converter:\n 0-Celsius\n 1-Fahrenheit\n 2-Kelvin\n 3-Sair\n");
    scanf("%d", &M);
    while (M<0 || M>3){
      printf("Digite um número da lista\n");
      scanf("%d", &M);
    }
    if (M!=4){
      printf("%.2Lf %s\n", temp[M], C[M]);
    } 
      printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//rotina de conversão de Volume
void Volume (int y){
  long double Vol[7]; //armazenar os valores
  if (m!=7){
    do{
      printf("Digite um valor em %s: ",V[y]);
      scanf("%15Lf", &Vol[y]);
    } while (Vol[y]<0);
    if (y==0){
      Vol[1]=Vol[0]*1000;//L<-kL
      Vol[2]=Vol[1]*1000;//mL<-L
      Vol[4]=Vol[1];//dm^3<-L
      Vol[3]=Vol[0];//m^3<-kL
      Vol[5]=Vol[2];//cm^3<-mL
      Vol[6]=Vol[5]*1000;//mm^3<-cm^3
    } else {
      if (y==1){
        Vol[0]=Vol[1]/1000;//kL<-L
        Vol[2]=Vol[1]*1000;//mL<-L
        Vol[4]=Vol[1];//dm^3<-L
        Vol[3]=Vol[0];//m^3<-kL
        Vol[5]=Vol[2];//cm^3<-mL
        Vol[6]=Vol[5]*1000;//mm^3<-cm^3
      } else {
        if(y==2){
          Vol[1]=Vol[2]/1000;//L<-mL
          Vol[0]=Vol[1]/1000;//kL<-L
          Vol[4]=Vol[1];//dm^3<-L
          Vol[3]=Vol[0];//m^3<-kL
          Vol[5]=Vol[2];//cm^3<-mL
          Vol[6]=Vol[5]*1000;//mm^3<-cm^3
        } else {
          if(y==3){
            Vol[0]=Vol[3];//kL<-m^3
            Vol[1]=Vol[0]*1000;//L<-kL
            Vol[2]=Vol[1]*1000;//mL<-L
            Vol[4]=Vol[1];//dm^3<-L
            Vol[5]=Vol[2];//cm^3<-mL
            Vol[6]=Vol[5]*1000;//mm^3<-cm^3
          } else {
            if(y==4){
              Vol[1]=Vol[4];//L<-dm^3
              Vol[0]=Vol[1]/1000;//kL<-L
              Vol[2]=Vol[1]*1000;//mL<-L
              Vol[3]=Vol[0];//m^3<-kL
              Vol[5]=Vol[2];//cm^3<-mL
              Vol[6]=Vol[5]*1000;//mm^3<-cm^3
            } else {
              if(y==5){
                Vol[2]=Vol[5];//mL<-cm^3
                Vol[1]=Vol[2]/1000;//L<-mL
                Vol[0]=Vol[1]/1000;//kL<-L
                Vol[4]=Vol[1];//dm^3<-L
                Vol[3]=Vol[0];//m^3<-kL
                Vol[6]=Vol[5]*1000;//mm^3<-cm^3
              } else {
                Vol[5]=Vol[6]/1000;//cm^3<-mm^3
                Vol[2]=Vol[5];//mL<-cm^3
                Vol[1]=Vol[2]/1000;//L<-mL
                Vol[0]=Vol[1]/1000;//kL<-L
                Vol[4]=Vol[1];//dm^3<-L
                Vol[3]=Vol[0];//m^3<-kL
              }
            }
          }
        }
      }     
    }
    printf("Escolha em que quer converter:\n 0-Quilolitro\n 1-Litro\n 2-Mililitro\n 3-Metro cúbico\n 4-Decímetro cúbico\n 5-Centímetro cúbico\n 6-Milímetro cúbico\n 7-Sair\n");
    scanf("%d", &M);
    while (M<0 || M>7){
      printf("Digite um número da lista\n");
      scanf("%d", &M);
    }
    if (M!=7){
      printf("%.2Lf %s\n", Vol[M], V[M]);
    } 
      printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//rotina de conversão de volume para densidade
void subVolume (int y){
  long double Vol[4]; //armazenar os valores
  char subV[4][5]={"L","mL","dm^3","mm^3"};
  if (y!=4){
    do{
      printf("Digite um valor em %s: ",subV[y]);
      scanf("%15Lf", &Vol[y]);
    } while (Vol[y]<0);
    if (y==0){
      Vol[1]=Vol[0]*1000;//mL<-L
      Vol[2]=Vol[0];//dm^3<-L
      Vol[3]=Vol[1]*1000;//mm^3<-mL
    } else {
      if (y==1){
        Vol[3]=Vol[1]*1000;//mm^3<-mL
        Vol[0]=Vol[1]/1000;//L<-mL
        Vol[2]=Vol[0];//dm^3<-L
      } else {
        if(y==2){
          Vol[0]=Vol[2];//L<-dm^3
          Vol[1]=Vol[0]*1000;//mL<-L
          Vol[3]=Vol[1]*1000;//mm^3<-mL
        } else {
          Vol[1]=Vol[3]/1000;//mL<-mm^3
          Vol[0]=Vol[1]/1000;//L<-mL
          Vol[2]=Vol[0];//dm^3<-L
        }
      }     
    }
    printf("Escolha em que quer converter:\n 0-Litro\n 1-Mililitro\n 2-Decímetro cúbico\n 3-Milímetro cúbico\n 4-Sair\n");
    scanf("%d", &M);
    while (M<0 || M>4){
      printf("Digite um número da lista\n");
      scanf("%d", &M);
    }
    if (M!=4){
      b=Vol[M];
    } else {
      printf("\nSaindo\n");
      printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
    }
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//rotina de conversão de Distância
void Distancia (int y){
  long double dis[4]; //armazenar os valores
  if (y!=4){
      printf("Digite um valor em %s: ", D[y]);
      scanf("%15Lf", &dis[y]);
    if (y==0){
      dis[1]=dis[0]*1000;//m<-km
      dis[2]=dis[1]*100;//cm<-m
      dis[3]=dis[2]*10;//mm<-cm
    } else {
      if (y==1){
        dis[0]=dis[1]/1000;//km<-m
        dis[2]=dis[1]*100;//cm<-m
        dis[3]=dis[2]*10;//mm<-cm
      } else {
        if (y==2){
          dis[1]=dis[2]/100;//m<-cm
          dis[0]=dis[1]/1000;//km<-m
          dis[3]=dis[2]*10;//mm<-cm
        } else {
          dis[2]=dis[3]/10;//cm<-mm
          dis[1]=dis[2]/100;//m<-cm
          dis[0]=dis[1]/1000;//km<-m
        }
      }      
    }
    printf("Escolha em que quer converter:\n 0-Quilômetro\n 1-Metro\n 2-Centímetro\n 3-Milímetro\n 4-Sair\n");
    scanf("%d", &ME);
    while (ME<0 || ME>3){
      printf("Digite um número da lista\n");
      scanf("%d", &ME);
    }
    if (ME!=4){
      a=dis[ME];
    } 
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//rotina de divisão de velocidade 
void DivV (long double x, long double y){
  c=x/y;
  printf("%.2Lf %s/%s\n", c, D[ME], s[M]);
}
//rotina de divisão de densidade
void DivD (long double x, long double y){
  char G[3][3]={"kg","g","mg"}, subV[4][5]={"L","mL","dm^3","mm^3"};
  c=x/y;
  printf("%.2Lf %s/%s\n", c, G[ME], subV[M]);
}
//rotina de conversão de Massa
void Massa (int y){
  char G[3][3]={"kg","g","mg"};
  long double Mas[4];
  if (y!=3){
      printf("Digite um valor em %s: ", G[y]);
      scanf("%15Lf", &Mas[y]);
    if (y==0){
      Mas[1]=Mas[0]*1000;//g<-kg
      Mas[2]=Mas[1]*1000;//mg<-g
    } else {
      if (y==1){
        Mas[0]=Mas[1]/1000;//kg<-g
        Mas[2]=Mas[1]*1000;//mg<-g
      } else {
        Mas[1]=Mas[2]/1000;//g<-mg
        Mas[0]=Mas[1]/1000;//kg<-g
      }      
    }
    printf("Escolha em que quer converter:\n 0-Quilograma\n 1-Grama\n 2-Miligrama\n 3-Sair\n");
    scanf("%d", &ME);
    while (ME<0 || ME>3){
      printf("Digite um número da lista\n");
      scanf("%d", &ME);
    }
    if (ME!=3){
      a=Mas[ME];
    } 
  } else {
    printf("\nSaindo\n");
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
  }
}
//incio do programa principal
int main(){
  f=0, M=0, m=0, me=0, ME=0;
  do {
	printf("Escolha o que quer converter:\n 1-Tempo\n 2-Temperatura\n 3-Volume\n 4-Velocidade\n 5-Densidade\n 6-Sair\n\n");
  scanf("%d", &m);
  switch (m){
    case 1: //tempo
      do {
        printf("Escolha a medida que quer converter:\n 0-Segundo\n 1-Minuto\n 2-Hora\n 3-Dia\n 4-Sair\n");
        scanf("%d", &m);
        while (m<0 || m>4){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Tempo(m);} while(m!=4);
    break;
    case 2: //temperatura
      while (m!=3){
        printf("Escolha a medida que quer converter:\n 0-Celsius\n 1-Fahrenheit\n 2-Kelvin\n 3-Sair\n");
        scanf("%d", &m);
        while (m<0 || m>3){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Temperatura(m);
      }
    break;
    case 3: //Volume
      while (m!=7){
        printf("Escolha a medida que quer converter:\n 0-Quilolitro\n 1-Litro\n 2-Mililitro\n 3-Metro cúbico\n 4-Decímetro cúbico\n 5-Centímetro cúbico\n 6-Milímetro cúbico\n 7-Sair\n");
        scanf("%d", &m);
        while (m<0 || m>7){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Volume(m);
      }
    break;
    case 4: //Velocidade
      f=1;
      m=0;
      if (me!=4){
        printf("Escolha a medida de distância que quer converter:\n 0-Quilômetro\n 1-Metro\n 2-Centímetro\n 3-Milímetro\n 4-Sair\n");
        scanf("%d", &me);
        while (me<0 || me>4){
          printf("Digite um número da lista\n");
          scanf("%d", &me);
        }
        Distancia(me);
      }
      if (m!=4 && me!=4){
        printf("Escolha a medida de tempo que quer converter:\n 0-Segundo\n 1-Minuto\n 2-Hora\n 3-Dia\n 4-Sair\n");
        scanf("%d", &m);
        while (m<0 || m>4){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Tempo(m);
      }
      if (m!=4 && me!=4){
        DivV(a,b);
      }
    break;
    case 5: //Densidade Kg,G,Mg/L,Ml,Dc^3,Mm^3 1,2,4,6
      if (m!=3){
        printf("Escolha a medida de massa que quer converter:\n 0-Quilograma\n 1-Grama\n 2-Miligrama\n 3-Sair\n");
        scanf("%d", &m);
        while (m<0 || m>3){
          printf("Digite um número da lista\n");
          scanf("%d", &m);
        }
        Massa(m);
      }
      if (me!=4 && m!=3){
        printf("Escolha a medida de volume que quer converter:\n 0-Litro\n 1-Mililitro\n 2-Decímetro cúbico\n 3-Milímetro cúbico\n 4-Sair\n");
        scanf("%d", &me);
        while (me<0 || me>4){
          printf("Digite um número da lista\n");
          scanf("%d", &me);
        }
        subVolume(me);
      }
      if (me!=4 && m!=3){
        DivD(a,b);
      }
    break;
    case 6:
      printf("\nEncerrando\n\n\n");
    break;
    default:
      printf("Selecione um número da lista\n\n");
    break;
}
} while (m!=6);
	return 0;
}
