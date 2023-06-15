#include <stdio.h>

int calcularFatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

int main() {
    int N = -1;

    while (N<0){  
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &N);
    }
  
    int R = calcularFatorial(N);
    
    printf("O fatorial de %d é %d\n", N, R);

    return 0;
}
