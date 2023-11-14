#include "bib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void setUtf8Encoding() {
    #ifdef _WIN32
    system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
    printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}

//só mostra o texto se conseguir terminar o jogo vivo
char texto_pre_ranking (char jogador, int ranking){
    setUtf8Encoding();
    char *vetor[9];
    for (int i = 0; i < 10; ++i) {
        vetor[i] = (char *)malloc(256 * sizeof(char));  // Tamanho arbitrário; ajuste conforme necessário
    }
    strcpy(vetor[0],"Numa era em que as sombras dançam entre os bosques e os ventos sussurram segredos aos ouvidos das árvores antigas, ");
    //pausa
    strcpy(vetor[1],"surge um grupo destemido de guerreiros, forjados na chama da coragem e moldados pela lealdade inabalável.");
    //pausa
    strcpy(vetor[2],"Armados com espadas reluzentes e vestindo armaduras impenetráveis, esses destemidos defensores emergem das névoas da história para fazer história.");
    //pausa e limpa a tela
    strcpy(vetor[3],"Sob a égide da Rainha Natacha, eles juraram proteger os fracos, desafiar a escuridão e erguer seus estandartes em nome da justiça.");
    //pausa
    strcpy(vetor[4],"Nos campos de batalha e nos salões do castelo, esses guerreiros marcham como um escudo invencível, prontos para enfrentar desafios que ecoarão pelos séculos, eternizando seus nomes como símbolos de honra e bravura.");
    //pausa e limpa a tela
    strcpy(vetor[5],"Que o reino saiba que, quando o chamado ressoar, uma irmandade única se erguerá para defender a coroa com suas vidas.");
    //pausa
    strcpy(vetor[6],"A população agarrou-se aos bravos guerreiros, atribuindo-lhes um apelido...\n");
    //pausa
    strcpy(vetor[7],"Eles são os Lovelaces: Guardiões da Rainha.");

    for (int i = 0; i < 8; ++i) {
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
            if (i==7){
                usleep(250000);
                sleep(1);
            }else{
                usleep(10000);
            }
        }
        if (i==2||i==4){
            //aguarda 1 segundo e limpa a tela
            sleep(1);
            printf("\n");
            //system(CLEAR_SCREEN);
        }
        printf("\n"); // Pula uma linha após imprimir toda a string
        usleep(100000);
    }

    //imprime o ranking
    printf("%s, \n", jogador);
    if (ranking == 1){
        strcpy(vetor[8],"Você é o Marechal dos Lovelaces, o mais alto posto do exército, parabéns!");
    }else if (ranking == 2){
        strcpy(vetor[8],"Você é o General dos Lovelaces, o segundo posto mais alto do exército, parabéns!");
    }else if (ranking == 3){
        strcpy(vetor[8],"Você é o Tenente-General dos Lovelaces, o terceiro posto mais alto do exército, parabéns!");
    }else if (ranking <= 20){
        strcpy(vetor[8],"Você é um dos Lovelaces, parabéns!");
    }else{
        strcpy(vetor[8],"Você não conseguiu entrar para o exército, mas não desanime, tente novamente!");
    }
    int len = 0;
    while (vetor[8][len] != '\0') {
        len++;
    }
    for (int j = 0; j < len; ++j) {
        // Imprime o caractere atual
        printf("%c", vetor[8][j]);
        fflush(stdout);
        usleep(10000);
    }
    printf("\n\n");
    usleep(100000);
    //imprimir o ranking completo
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
    strcpy(vetor[10],"Como se chama?\n");
    // Loop para iterar sobre cada string no vetor
    for (int i = 0; i < 11; ++i) {
        // Obtém o comprimento da string atual
        printf("\n"); // Pula uma linha após imprimir toda a string
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
            printf(".. \n(Press Enter)");
            char c='a';
            while (c!='\n'){
                scanf("%c", &c);
            }
            system(CLEAR_SCREEN);
        }
        
        usleep(200000);
    }
    *jogador = (char *)malloc(256 * sizeof(char));
    scanf("%s", *jogador);
    getchar();
    system(CLEAR_SCREEN);
    //pausa e limpa a tela
    strcpy(vetor[11],"Bem vindo, ");
    strcat(vetor[11], *jogador);
    strcat(vetor[11], "!");
    strcpy(vetor[12],"Agora você é um aspirante a Cavaleiro da Rainha, e para isso você\nterá que passar por alguns testes...\n");
    for (int i = 11; i < 13; ++i) {
        printf("\n"); // Pula uma linha após imprimir toda a string
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
        if (i==12){
            //recebe input vazio e limpa a tela
            printf("\nVamos começar?\n");
            char c;
            scanf("%c", &c);
            system(CLEAR_SCREEN);
        }
        
        usleep(100000);

    }   
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
