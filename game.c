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
