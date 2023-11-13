#include "Game/lib.h"
#include "Game/screen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <include/SDL2/SDL.h>
#include <include/SDL2/SDL_ttf.h>

int main(int argc, char *argv[]) {
    int lastFrameTime = 0;
    int gameState = MAIN_MENU;
    
    ScreenResult screen = initializeWindow();
    if(screen.status < 0){
        fprintf(stderr, "Error initializing screen.\n");
        return 1;
    }

    gameState = disclaimerScene(&screen, &lastFrameTime);
    while(gameState > 0){
        switch (gameState){
            case MAIN_MENU:
                mainMenu(&gameState, &screen, &lastFrameTime);
                printf("(%d)\n", gameState);
                break;
            case GAME:
                printf("game\n");
                gameState = MAIN_MENU;
                break;
            case SCORE_BOARD:
                printf("scoreboard\n");
                gameState = MAIN_MENU;
                break;
            case TUTORIAL:
                printf("tutorial\n");
                gameState = MAIN_MENU;
                break;
            case 5:
                printf("sair\n");
                gameState = MAIN_MENU;
                break;
        }
    }

    destoryScreen(screen);

    return 0;
}

char introducao (void){
    char *vetor[12];
    char jogador[20];
    strcpy(vetor[0],"No majestoso Reino de Aedônia, sob o reinado da benevolente Rainha Natacha, a paz era mantida através do equilíbrio mágico das árvores que adornavam a terra.");
    //pausa
    strcpy(vetor[1],"Contudo, as sombras da intriga se aproximaram quando um exército inimigo, cobiçando o poder das árvores mágicas, ameaçou a tranquilidade do reino.");
    //pausa
    strcpy(vetor[2],"O alerta ecoou nos salões reais no exato momento em que a Rainha compartilhava os segredos mágicos das árvores com seus súditos.");
    //pausa
    strcpy(vetor[3],"Sem hesitar, Natacha decidiu formar um exército para enfrentar a iminente invasão.");
    //pausa e limpa a tela
    strcpy(vetor[4],"Convocando os guerreiros mais destemidos dos reinos vizinhos, a Rainha os colocou em um complexo de arenas espalhadas por sua floresta real, conhecido como de Ceasar's Arena, que fica no 3º distrito de Aedônia.");
    //pausa
    strcpy(vetor[5],"O objetivo era claro: forjar um exército real capaz de proteger as preciosas árvores e repelir as ameaças que se aproximavam da fronteira.");
    //pausa e limpa a tela
    strcpy(vetor[6],"Entre os soldados, destaca-se a hierarquia, liderada por um Marechal, seguido por um general, um tenente-general e os valorosos \"Cavaleiros da Rainha\".");
    //pausa e limpa a tela
    strcpy(vetor[7],"No entanto, nem todo aspirante terá o privilégio de se tornar um Cavaleiro da Rainha...");
    //pausa
    strcpy(vetor[8],"Aqueles que não atingirem tal honra serão exilados para o humilde reino de Nassau, vizinho a Aedônia, mas notavelmente mais carente.");
    //pausa e limpa a tela
    strcpy(vetor[9],"O desafio está lançado: será que você, como jogador, terá a coragem e a estratégia necessárias para se destacar nesta jornada e ajudar a Rainha Natacha a preservar a magia de seu reino?");
    //pausa
    strcpy(vetor[10],"Como se chama?\n");
    scanf("%s", jogador);
    //pausa e limpa a tela
    strcpy(vetor[11],"Bem vindo, ");
    strcat(vetor[11], jogador);
    strcat(vetor[11], "!");
    //pausa
    strcpy(vetor[12],"Agora você é um aspirante a Cavaleiro da Rainha, e para isso você terá que passar por alguns testes.");
    //pausa e limpa a tela
    return jogador;
}

//só mostra o texto se conseguir terminar o jogo vivo
char texto_pre_ranking (char jogador, int ranking){
    char *vetor[8];
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
}
