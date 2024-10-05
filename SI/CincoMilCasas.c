#include <stdio.h>
#include <gmp.h>
// Este código utiliza a Série alternada de Leibniz para calcular mais de 2037 casas decimais de pi através da Fórmula de Takano comparando com a Fórmula de Stormer

/* K. Takano, 1982: pi = 48*arctg(1/49) + 128*arctg(1/57) - 20*arctg(1/239) + 48*arctg(1/110.443)
   F.C.M. Stormer, 1896: pi = 176*arctg(1/57) + 28*arctg(1/239) - 48*arctg(1/682) + 96*arctg(1/12.943) */

// Função para calcular arctg(x) usando a Série de Leibniz
void arctg(mpf_t resultado, mpf_srcptr x, unsigned long precisao){
    // arctg(x) = sum_{n=0}^{inf} ((-1)^n*x^{2n+1})/(2n+1) => x^1/1 - x^3/3 + x^5/5 - x^7/7 + ...
    mpf_set_default_prec (32768); // Definir 32768 bits de precisão para as variáveis tipo float que serão usadas
    mpf_t termo;
    mpf_init(termo); // Alocar espaço para termo n da série

    mpf_set_ui(resultado, 0); // Inicializar resultado
    int sinal=0; // Alternar entre somar ou subtrair o termo da série

    for(unsigned long i=1;i<=precisao;i+=2) { // Calcular o somatório de n termos da série
        // Calcular o termo da série: x^i/i
        mpf_pow_ui(termo, x, i); // termo <- x^i
        mpf_div_ui(termo, termo, i); // termo <- termo/i

        if (sinal%2==0) { // (-1)^n, se n for par => 1*termo, caso contrário => (-1)*termo
            mpf_add(resultado, resultado, termo); // Somar o termo à série
            sinal++;
        } else {
            mpf_sub(resultado, resultado, termo); // Subtrair o termo à série
            sinal--;
        }
    }
    // Limpar e liberar variável temporária alocada
    mpf_clear(termo);
}

int main() {
    mpf_set_default_prec (32768); // Definir 32768 bits de precisão para as variáveis tipo float que serão usadas
    mpf_t piTak, piStor, arctg_1_49, arctg_1_239, arctg_1_57, arctg_1_682, arctg_1_12943, arctg_1_110443, a, b, c, d, e, f;
    mpf_init(piTak); // Alocar espaço para conter valor de pi pela Fórmula de Takano
    mpf_init(arctg_1_49); // Alocar espaço para conter valor de arctg (1/49)
    mpf_init(arctg_1_239); // Alocar espaço para conter valor de arctg (1/239)
    mpf_init(arctg_1_57); // Alocar espaço para conter valor de arctg (1/57)
    mpf_init(arctg_1_110443); // Alocar espaço para conter valor de arctg (1/110.443)
    mpf_init(a); // Alocar espaço para conter valor de 1/49
    mpf_init(b); // Alocar espaço para conter valor de 1/57
    mpf_init(c); // Alocar espaço para conter valor de 1/239
    mpf_init(f); // Alocar espaço para conter valor de 1/110.443
    
    mpf_set_ui(a, 49); // Inicializar com valor 49
    mpf_set_ui(b, 57); // Inicializar com valor 57
    mpf_set_ui(c, 239); // Inicializar com valor 239
    mpf_set_ui(f, 110443); // Inicializar com valor 110.443
    
    mpf_ui_div(a, 1, a); // a<-1/49 
    mpf_ui_div(b, 1, b); // b<-1/57
    mpf_ui_div(c, 1, c); // c<-1/239
    mpf_ui_div(f, 1, f); // f<-1/110443
    
    unsigned long precisao = 500000; // Definir a precisão (número de termos da série)

    arctg(arctg_1_49, a, precisao); // Calcular arctg(1/49) 
    arctg(arctg_1_239, c, precisao); // Calcular arctg(1/239)
    arctg(arctg_1_57, b, precisao); // Calcular arctg(1/57) 
    arctg(arctg_1_110443, f, precisao); // Calcular arctg(1/110.443)

    // Limpar e liberar as variáveis alocadas
    mpf_clear(a);
    mpf_clear(f);

    // K. Takano, 1982: pi = 48*arctg(1/49) + 128*arctg(1/57) - 20*arctg(1/239) + 48*arctg(1/110.443)
    mpf_mul_ui(arctg_1_49, arctg_1_49, 48); // arctg_1_49 <- 48*arctg(1/49)
    mpf_mul_ui(b, arctg_1_57, 128); // b <- 128*arctg(1/57) (poder reutilizar o valor de arctg(1/57))
    mpf_mul_ui(c, arctg_1_239, 20); // c <- 20*arctg(1/239) (poder reutilizar o valor de arctg(1/239))
    mpf_mul_ui(arctg_1_110443, arctg_1_110443, 48); // arctg_1_110443 <- 48*arctg(1/110.443)
    
    mpf_sub(piTak, arctg_1_49, c); // piTak <- 48*arctan(1/49) - 20*arctan(1/239)
    mpf_add(piTak, piTak, b); // piTak <- piTak + 128*arctg(1/57)
    mpf_add(piTak, piTak, arctg_1_110443); // piTak <- piTak + 12*arctg(1/110.443)

    // Limpar e liberar as variáveis alocadas
    mpf_clear(b);
    mpf_clear(c);
    mpf_clear(arctg_1_49);
    mpf_clear(arctg_1_110443);

    gmp_printf("Imprimindo as 5000 primeiras casas de Pi obtidas pela Fórmula de Takano: %.5000Ff\n", piTak);  // Mostrar até 5000 dígitos de pi obtidos pela Fórmula de Takano
    
    mpf_init(piStor); // Alocar espaço para conter valor de pi pela Fórmula de Stormer
    mpf_init(arctg_1_682); // Alocar espaço para conter valor de arctg (1/682)
    mpf_init(arctg_1_12943); // Alocar espaço para conter valor de arctg (1/12.943)
    mpf_init(d); // Alocar espaço para conter valor de 1/682
    mpf_init(e); // Alocar espaço para conter valor de 1/12.943
    mpf_set_ui(d, 682); // Inicializar com valor 682
    mpf_set_ui(e, 12943); // Inicializar com valor 12.943
    mpf_ui_div(d, 1, d); // d<-1/682
    mpf_ui_div(e, 1, e); // e<-1/12.943

    arctg(arctg_1_682, d, precisao); // Calcular arctg(1/682)
    arctg(arctg_1_12943, e, precisao); // Calcular arctg(1/12.943)

    // Limpar e liberar as variáveis alocadas
    mpf_clear(d);
    mpf_clear(e);
    
    //F.C.M. Stormer, 1896: pi = 176*arctg(1/57) + 28*arctg(1/239) - 48*arctg(1/682) + 96*arctg(1/12.943)
    mpf_mul_ui(arctg_1_682, arctg_1_682, 48); // arctg_1_682 <- 48*arctg(1/682)
    mpf_mul_ui(arctg_1_57, arctg_1_57, 176); // arctg_1_57 <- 176*arctg(1/57)
    mpf_mul_ui(arctg_1_239, arctg_1_239, 28); // arctg_1_239 <- 28*arctg(1/239)
    mpf_mul_ui(arctg_1_12943, arctg_1_12943, 96); // arctg_1_12943 <- 96*arctg(1/12.943)
    
    mpf_sub(piStor, arctg_1_12943, arctg_1_682); // piStor <- 96*arctg(1/12.943) - 48*arctg(1/682)
    mpf_add(piStor, piStor, arctg_1_57); // piStor <- pi + 176*arctg(1/57)
    mpf_add(piStor, piStor, arctg_1_239); // piStor <- pi + 28*arctg(1/239)

    // Limpar e liberar as variáveis alocadas
    mpf_clear(arctg_1_57);
    mpf_clear(arctg_1_239);
    mpf_clear(arctg_1_682);
    mpf_clear(arctg_1_12943);

    gmp_printf("Imprimindo as 5000 primeiras casas de Pi obtidas pela Fórmula de Stormer: %.5000Ff\n", piStor);  // Mostrar até 5000 dígitos de pi obtidos pela Fórmula de Stormer

    mpf_sub(piTak, piStor, piTak);
    gmp_printf("Imprimindo a diferença entre Pi de Takano e de Stormer: %.5000Ff\n", piTak);  // Mostrar a diferença entre os dois valores de pi obtidos

    // Limpar e liberar as variáveis alocadas
    mpf_clear(piTak);
    mpf_clear(piStor);
    
    return 0;
}
