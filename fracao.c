#include <stdio.h>
int MDC(int a, int b) {
    if (b == 0) {
        return a;
    }
    return MDC(b, a % b);
}
void conversor(double decimal) {
    const int MAX_DENOMINADOR = 1000000;
    int numerador = decimal * MAX_DENOMINADOR;
    int denominador = MAX_DENOMINADOR;
    int divisor = MDC(numerador, denominador);
    numerador /= divisor;
    denominador /= divisor;
    printf("O número %.7f é aproximadamente %d/%d\n", decimal, numerador, denominador);
}
int main() {
    double n;
    printf("Digite um número decimal: ");
    scanf("%lf", &n);
    conversor(n);
    return 0;
}
