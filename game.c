#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL_ttf.h>
#include <SDL.h>

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
