#ifndef __LIB_SCREEN__
#define __LIB_SCREEN__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <include/SDL2/SDL.h>
#include <include/SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define MAIN_MENU 1
#define GAME 2
#define SCORE_BOARD 3
#define TUTORIAL 4
#define QUANT_MENU_OPTIONS 4

#define FPS 30
#define FRAME_TARGET_TIME (1000/FPS)

typedef struct ScreenResult{
    SDL_Window *window;
    SDL_Renderer * renderer;
    TTF_Font *font;
    SDL_Texture *texture;
    int status;
}ScreenResult;

ScreenResult initializeWindow(void);
void destoryScreen(ScreenResult screen);
int disclaimerScene(ScreenResult *screen, int *lastFrameTime);
void mainMenu(int *gameState, ScreenResult *screen, int *lastFrameTime);
void setup();

#endif