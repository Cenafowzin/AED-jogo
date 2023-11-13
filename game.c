#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL_ttf.h>
#include <SDL.h>

char introducao (void);
//só mostra o texto pre ranknig se conseguir terminar o jogo vivo
char texto_pre_ranking (char jogador, int ranking);

int main(int argc, char *argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erro ao inicializar a SDL: %s\n", SDL_GetError());
        return 1;
    }

    int windowWidth = 1120;
    int windowHeight = 630;
    SDL_Window *window = SDL_CreateWindow("Testing...", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(window == NULL) {
        fprintf(stderr, "Erro ao criar a janela: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL) {
        fprintf(stderr, "Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Inicializar SDL_ttf
    if(TTF_Init() != 0) {
        fprintf(stderr, "Erro ao inicializar SDL_ttf: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Carregar a fonte
    TTF_Font *font = TTF_OpenFont("src/fonts/Pokemon_Classic.ttf", 24); // Substitua pelo caminho da sua fonte e tamanho desejado

    if(font == NULL) {
        fprintf(stderr, "Erro ao carregar a fonte: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    int quit = 0;

    while (!quit)  { //loop do jogo
        while(SDL_PollEvent(&event)) {//pega os inputs
            if(event.type == SDL_QUIT) {
                quit = 1;
            }else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    // Atualizar a posição do texto quando a janela for redimensionada
                    windowWidth = event.window.data1;
                    windowHeight = event.window.data2;
                }
            }

        }

        // Limpar o renderizador
        SDL_RenderClear(renderer);

        // Desenhar algo (por exemplo, um texto "Olá!")
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Cor branca
        SDL_Rect rect = {100, 100, 200, 200};
        SDL_RenderFillRect(renderer, &rect);

        // Cor do texto (preto)
        SDL_Color textColor = {0, 0, 0, 255};

        // Renderizar o texto
        SDL_Surface *textSurface = TTF_RenderUTF8_Blended_Wrapped(font, "DIEGO Designer", textColor, windowWidth - 50);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_QueryTexture(textTexture, NULL, NULL, &textSurface->w, &textSurface->h);
        // Posição do texto
        SDL_Rect textRect = { (windowWidth - textSurface->w) / 2, (windowHeight - textSurface->h)/2, textSurface->w, textSurface->h};

        // Desenhar o texto
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        // Limpar recursos de texto
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Atualizar a tela
        SDL_RenderPresent(renderer);
    }

    // Limpar recursos e sair
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

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
