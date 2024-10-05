#include <stdio.h>
#include <gmp.h>
// Este código utiliza a Série alternada de Leibniz para calcular as 100 primeiras casas decimais de pi através da Fórmula de Machin

// Função para calcular arctg(x) usando a Série de Leibniz
void arctg(mpf_t resultado, mpf_srcptr x, unsigned long precisao) {
    // arctan(x) = sum_{n=0}^{inf} ((-1)^n*x^{2n+1})/(2n+1) => x^1/1 - x^3/3 + x^5/5 - x^7/7 + ...
    mpf_set_default_prec (8192); // Definir 8192 bits de precisão para as variáveis tipo float que serão usadas 
    mpf_t termo;
    mpf_init(termo); // Alocar espaço para termo n da série

    mpf_set_ui(resultado, 0); // Inicializar resultado
    int sinal=0; // Alternar entre somar ou subtrair o termo da série

    for(unsigned long i=1; i<=precisao; i+=2){ // Calcular o somatório de n termos (valor da precisão)
        // Calcular o termo da série: x^i / i que equivale 1/x^i*i para 0<x<1
        mpf_pow_ui(termo, x, i); // termo <- x^i
        mpf_mul_ui(termo, termo, i); // termo <- termo*i
        mpf_ui_div(termo, 1, termo); // termo <- 1/termo

        if(sinal%2==0){ // (-1)^n, se n for par => 1*termo, caso contrário => (-1)*termo
            mpf_add(resultado, resultado, termo); // Somar o termo à série
            sinal=1;
        } else {
            mpf_sub(resultado, resultado, termo); // Subtrair o termo à série
            sinal=0;
        }
    }

    // Limpar e liberar variável temporária alocada
    mpf_clear(termo);
}

int main() {
    mpf_set_default_prec (8192); // Definir 8192 bits de precisão para as variáveis tipo float que serão usadas
    mpf_t pi, arctg_1_5, arctg_1_239, five, twoH;
    mpf_init(pi); // Alocar espaço para conter valor de pi
    mpf_init(arctg_1_5); // Alocar espaço para conter valor de arctan (1/5)
    mpf_init(arctg_1_239); // Alocar espaço para conter valor de arctan (1/239)
    mpf_init(five); // Alocar espaço para conter valor 5
    mpf_init(twoH); // Alocar espaço para conter valor 239
    mpf_set_ui(five, 5); // Inicializar com valor 5
    mpf_set_ui(twoH, 239); // Inicializar com valor 239
    
    unsigned long precision = 1000000; // Definir a precisão (número de termos da série)

    // Calcular arctg(1/5) e arctg(1/239) usando a Série de Leibniz
    arctg(arctg_1_5, five, precision);
    arctg(arctg_1_239, twoH, precision);

    // Fórmula de Machin: pi=16*arctg(1/5) - 4*arctg(1/239)
    mpf_mul_ui(arctg_1_5, arctg_1_5, 16); // arctg_1_5 <- 16*arctg(1/5)
    mpf_mul_ui(arctg_1_239, arctg_1_239, 4); // arctg_1_239 <- 4*arctg(1/239)
    mpf_sub(pi, arctg_1_5, arctg_1_239); // // pi <- 16*arctg(1/5) - 4*arctg(1/239)

    gmp_printf("Imprimindo as 100 primeiras casas de Pi = %.100Ff\n", pi);  // Mostrar os 100 primeiros dígitos de pi obtidos

    // Limpar e liberar as variáveis alocadas
    mpf_clear(pi);
    mpf_clear(arctg_1_5);
    mpf_clear(arctg_1_239);
    mpf_clear(five);
    mpf_clear(twoH);

    return 0;
}
