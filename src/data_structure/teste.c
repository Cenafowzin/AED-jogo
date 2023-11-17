#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "bib.h"

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void setUtf8Encoding() {
    #ifdef _WIN32
    system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
    printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}

void introducao (char **jogador){
    setUtf8Encoding();
    /* é chamado assim:
    char *jogador;
    introducao(&jogador); */
    system(CLEAR_SCREEN);
    char *vetor[13];
    for (int i = 0; i < 14; ++i) {
        vetor[i] = (char *)malloc(256 * sizeof(char));  // Tamanho arbitrário; ajuste conforme necessário
    }
    strcpy(vetor[0],"No majestoso Reino de Aedônia, sob o reinado da benevolente Rainha Natacha,\na paz era mantida através do equilíbrio mágico das árvores que adornavam a terra.\n");
    //pausa
    strcpy(vetor[1],"Contudo, as sombras da intriga se aproximaram quando um exército inimigo,\ncobiçando o poder das árvores mágicas, ameaçou a tranquilidade do reino.\n");
    //pausa
    strcpy(vetor[2],"O alerta ecoou nos salões reais no exato momento em que a Rainha compartilhava\nos segredos mágicos das árvores com seus súditos.\n");
    //pausa
    strcpy(vetor[3],"Sem hesitar, Natacha decidiu formar um exército para enfrentar a iminente invasão.");
    //pausa e limpa a tela
    strcpy(vetor[4],"Convocando os guerreiros mais destemidos dos reinos vizinhos, a Rainha os colocou\nem um complexo de arenas espalhadas por sua floresta real, conhecido como\nCeasar's Arena, que fica no 3º distrito de Aedônia.\n");
    //pausa
    strcpy(vetor[5],"O objetivo era claro: forjar um exército real capaz de proteger as preciosas árvores\ne repelir as ameaças que se aproximavam da fronteira.");
    //pausa e limpa a tela
    strcpy(vetor[6],"Entre os soldados, destaca-se a hierarquia, liderada por um Marechal,\nseguido por um general, um tenente-general e os valorosos \"Cavaleiros da Rainha\".");
    //pausa e limpa a tela
    strcpy(vetor[7],"No entanto, nem todo aspirante terá o privilégio de se tornar um Cavaleiro da Rainha...\n");
    //pausa
    strcpy(vetor[8],"Aqueles que não atingirem tal honra serão exilados para o humilde reino de Nassau,\nvizinho a Aedônia, mas notavelmente mais carente.");
    //pausa e limpa a tela
    strcpy(vetor[9],"O desafio está lançado: será que você, como jogador, terá a coragem\ne a estratégia necessárias para se destacar nesta jornada e ajudar a Rainha\nNatacha a preservar a magia de seu reino?\n");
    //pausa
    strcpy(vetor[10],"Como se chama?");
    // Loop para iterar sobre cada string no vetor
    for (int i = 0; i < 11; ++i) {
        // Obtém o comprimento da string atual
        int len = 0;
        while (vetor[i][len] != '\0') {
            len++;
        }
        // Loop para iterar sobre cada caractere da string
        for (int j = 0; j < len; ++j) {
            // Imprime o caractere atual
            printf("%c", vetor[i][j]);
            fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
            usleep(10000);
        }
        if (i==3||i==5||i==6||i==8){
            //recebe input vazio e limpa a tela
            printf("..");
            char c;
            scanf("%c", &c);
            system(CLEAR_SCREEN);
        }
        printf("\n"); // Pula uma linha após imprimir toda a string
        usleep(200000);
    }
    *jogador = (char *)malloc(256 * sizeof(char));
    scanf("%s", *jogador);
    getchar();
    //pausa e limpa a tela
    strcpy(vetor[11],"Bem vindo, ");
    strcat(vetor[11], *jogador);
    strcat(vetor[11], "!");
    strcpy(vetor[12],"Agora você é um aspirante a Cavaleiro da Rainha, e para isso você\nterá que passar por alguns testes...\nVamos começar?\n");
    for (int i = 11; i < 13; ++i) {
        // Obtém o comprimento da string atual
        int len = 0;
        while (vetor[i][len] != '\0') {
            len++;
        }
        // Loop para iterar sobre cada caractere da string
        for (int j = 0; j < len; ++j) {
            // Imprime o caractere atual
            printf("%c", vetor[i][j]);
            fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
            usleep(10000);
        }
        printf("\n"); // Pula uma linha após imprimir toda a string
        usleep(100000);
    }  
    char c;
    scanf("%c", &c);
}

//disclaimer
void disclaimer(void) {
    setUtf8Encoding();
    // Limpa a tela
    system(CLEAR_SCREEN);

    // Aguarda por 2 segundos
    sleep(1);
    printf("Esta obra é fictícia e qualquer semelhança com pessoas reais,\n"
           "vivas ou mortas, é mera coincidência. Eventuais referências a eventos\n"
           "históricos, locais ou situações são puramente coincidentais e não devem\n"
           "ser interpretadas como fatos reais. Qualquer analogia com a realidade é\n"
           "completamente não intencional. Este é um produto de ficção e destina-se\n"
           "exclusivamente para entretenimento.");

    // Aguarda por 5 segundos
    sleep(5);

    // Limpa a tela
    system(CLEAR_SCREEN);

    printf("Classificação PEGI 12: Este jogo é recomendado para maiores de 12 anos\n"
    "e pode conter violência leve, linguagem moderada ou temas sugestivos.\n"
    "Os pais devem considerar o conteúdo antes de permitir que seus filhos joguem.\n");
    // Aguarda por 5 segundos
    sleep(5);
    // Exibe a mensagem preta na tela
    system(CLEAR_SCREEN);
    // Aguarda por 2 segundos
    sleep(1);
    fflush(stdout);
}

int main() {
    char *jogador;

    disclaimer();
    introducao(&jogador);

    // Faça o que for necessário com o nome do jogador
    // Limpa a tela antes de exibir o disclaimer
    system(CLEAR_SCREEN);
    // Faça o que for necessário após o disclaimer
    // Libera a memória alocada para o nome do jogador
    free(jogador);

    return 0;
}