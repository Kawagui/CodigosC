#include <stdio.h>
char M=65;
int x=0;
void Menu (char y){
    do{
        scanf("%s", &M);
        if (M>=65&&M<=91){
            printf("Por favor, responda sem Caps Lock ativo.\n");
        } else {
            if (M<97||M>99){
                printf("Por favor, responda com 'a','b' ou 'c'.\n");
            }
        }
    }while(M<97||M>99);
    if (M==y){
        printf("RESPOSTA CORRETA!\n");
        x++;
    } else {
        printf("RESPOSTA INCORRETA!\n");
    }
}
int main(){
    printf("Quiz 'Final da primeira semana'\n");
    printf("Obs.: Só será considerado o primeiro caracter digitado.\n");
    printf("1. Nós nos estressamos quando:\na. temos de nos adaptar ao nosso ambiente.\nb. vamos fazer exames.\nc. mudamos de trabalho.\n");
    Menu('a');
    printf("2. O hormônio secretado quando há estresse é:\na. o aperol.\nb. o cortisol.\nc. o sonasol.\n");
    Menu('b');
    printf("3. O estresse:\na. é tratado do mesmo modo por todos.\nb. pode ser físico, psicológico e/ou emocional.\nc. é um falso problema.\n");
    Menu('b');
    printf("4. Em geral, que doença(s) não é (são) associada(s) ao estresse?\na. A gripe.\nb. Alguns cânceres.\nc. As doenças cardiovasculares.\n");
    Menu('a');
    printf("5. Quem foi o primeiro cientista a estudar o estresse?\na. Sigmund Freud.\nb. Hans Selye.\nc. Carl Rogers.\n");
    Menu('b');
    printf("6. Qual é a porcentagem de consultas médicas ligadas direta ou indiretamente ao estresse?\na. 20%.\nb. 50%.\nc. 80%.\n");
    Menu('c');
    printf("7. A respiração diafragmática é:\na. uma fonte de relaxamento, pois permite oxigenar bem o sangue.\nb. mais rápida que a respiração natural.\nc. uma respiração que acontece essencialmente na parte de cima do corpo.\n");
    Menu('a');
    printf("8. O relaxamento muscular progressivo:\na. centra-se na contração e na descontração física.\nb. é uma espécie de hipnose.\nc. é uma disciplina esportiva.\n");
    Menu('a');
    printf("9. O estresse é:\na. unicamente influenciado pelos eventos externos.\nb. resultante da previsão de uma possível ameaça e da capacidade de enfrentá-la.\nc. uma emoção difícil.\n");
    Menu('b');
    printf("10. As distorções cognitivas são:\na. uma deformação do estresse.\nb. representações e interpretações distorcidas do mundo.\nc. pensamentos apavorantes.\n");
    Menu('b');
    printf("11. O melhor meio de controlar os pensamentos é:\na. confrontá-los com a realidade.\nb. procurar ter pensamentos positivos.\nc. procurar, a todo custo, evitá-los.\n");
    Menu('a');
    printf("12. Entre as emoções fundamentais, encontramos:\na. a alegria, a vergonha, a aversão e a raiva.\nb. a alegria, o medo, a raiva e a tristeza.\nc. a alegria, o medo, a raiva e a vergonha.\n");
    Menu('b');
    printf("13. A inteligência emocional é:\na. equivalente ao Q.I.\nb. fazer bom uso das emoções, identificando-as, aceitando-as e administrando-as.\nc. saber bloquear a emoção, se for necessário.\n");
    Menu('b');
    printf("14. A procrastinação é:\na. a tendência de esquecer as coisas.\nb. a tendência de deixar para o dia seguinte.\nc. o poder de antecipar.\n");
    Menu('b');
    printf("15. Um método de resolução de problema pode:\na. ajudar a procrastinar mais.\nb. dividir-se em diversas etapas distintas: da definição do problema à avaliação dos resultados.\nc. garantir-nos uma vida sem estresse.\n");
    Menu('b');
    printf("Pontuação: %d\nGabarito: 1. a, 2. b, 3. b, 4. a, 5. b, 6. c, 7. a, 8. a, 9. b, 10. b, 11. a, 12. b, 13. b, 14. b, 15. b", x);
    return 0;
}
