#include "lib.h"
#include "screen.h"
#include <math.h>

ScreenResult initializeWindow(void){
    ScreenResult result;
    result.window = NULL;
    result.renderer = NULL;
    result.font = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        result.status = -1;
        return result;
    }

    if(TTF_Init() != 0){
        fprintf(stderr, "Error initializing SDL TTF: %s\n", TTF_GetError());
        result.status = -1;
        SDL_Quit();
        return result;
    }

    result.window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );

    if(!result.window){
        fprintf(stderr, "Error creating SDL Window: %s\n", SDL_GetError());
        result.status = -1;
        SDL_Quit();
        TTF_Quit();
        return result;
    }

    result.renderer = SDL_CreateRenderer(result.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!result.renderer){
        fprintf(stderr, "Error initializing SDL Renderer: %s\n", SDL_GetError());
        result.status = -1;
        SDL_DestroyWindow(result.window);
        SDL_Quit();
        TTF_Quit();
        return result;
    }

    result.font = TTF_OpenFont("src/fonts/Pokemon_Classic.ttf", 25);

    if(!result.font){
        fprintf(stderr, "Error initializing TTF Font: %s\n", TTF_GetError());
        result.status = -1;
        SDL_DestroyRenderer(result.renderer);
        SDL_DestroyWindow(result.window);
        SDL_Quit();
        TTF_Quit();
        return result;
    }

    TTF_SetFontWrappedAlign(result.font, TTF_WRAPPED_ALIGN_CENTER);

    result.status = 0;
    return result;
}

//----------------------------------------------------------------

void setup(){

}

int disclaimerScene(ScreenResult *screen, int *lastFrameTime){
    SDL_Color color = { 255, 255, 255, 255};
    int texW = 0;
    int texH = 0;

    const char *disclaimerText =
        "Esta obra é fictícia e qualquer semelhança com pessoas reais,"
        "vivas ou mortas, é mera coincidência. Eventuais referências a "
        "eventos históricos, locais ou situações são puramente coincidentais "
        "e não devem ser interpretadas como fatos reais. Qualquer analogia "
        "com a realidade é completamente não intencional. Este é um produto "
        "de ficção e destina-se exclusivamente para entretenimento.";

    SDL_Event event;
    while(color.a > 1){

        SDL_PollEvent(&event);

        switch(event.type){
            case SDL_QUIT:
                return 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    return 0;
                }
                if(event.key.keysym.sym == SDLK_SPACE){
                    color.a = 1;
                }
                break;
        }

        int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - *lastFrameTime);

        if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
            SDL_Delay(timeToWait);
        }

        float deltaTime = (SDL_GetTicks() - *lastFrameTime) / 1000.0f;

        *lastFrameTime = SDL_GetTicks();

        if (*lastFrameTime > 15000) {
           color.a -= (50*deltaTime);
           if(color.a < 0 ){
            color.a = 0;
           }
        }

        SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 255);
        SDL_RenderClear(screen->renderer);

        SDL_Surface * surface = TTF_RenderUTF8_Blended_Wrapped(screen->font,disclaimerText, color, WINDOW_WIDTH - 50);
        SDL_Texture * texture = SDL_CreateTextureFromSurface(screen->renderer, surface);
        SDL_FreeSurface(surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

        SDL_Rect dstrect = {(WINDOW_WIDTH - texW)/2, (WINDOW_HEIGHT - texH)/2, texW, texH };

        SDL_RenderCopy(screen->renderer, texture, NULL, &dstrect);

        SDL_RenderPresent(screen->renderer);

        SDL_DestroyTexture(texture);
    }

    return 1;
}

void mainMenu(int *gameState, ScreenResult *screen, int *lastFrameTime) {
    int mouseX, mouseY;
    char *options[QUANT_MENU_OPTIONS] = {"Jogar", "Pódio", "Tutorial", "Sair"};
    int selected[QUANT_MENU_OPTIONS] = {0};
    SDL_Color color[2] = {{255, 255, 255}, {0, 0, 0}};
    SDL_Surface *menu[QUANT_MENU_OPTIONS];
    SDL_Texture *texture[QUANT_MENU_OPTIONS];
    SDL_Rect pos[QUANT_MENU_OPTIONS];

    int texW = 0;
    int texH = 0;
    int arrowSelection = 1;

    SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 255);
    SDL_RenderClear(screen->renderer);

    for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
        menu[i] = TTF_RenderUTF8(screen->font, options[i], color[0],color[1]);
        texture[i] = SDL_CreateTextureFromSurface(screen->renderer, menu[i]);
        SDL_FreeSurface(menu[i]);
        SDL_QueryTexture(texture[i], NULL, NULL, &texW, &texH);
        pos[i].x = (WINDOW_WIDTH - texW) / 2;
        pos[i].y = i * (texH + 10) + (WINDOW_HEIGHT - QUANT_MENU_OPTIONS * (texH + 10)) / 2;
        pos[i].w = texW;
        pos[i].h = texH;
        SDL_RenderCopy(screen->renderer, texture[i], NULL, &pos[i]);
    }

    SDL_RenderPresent(screen->renderer);

    SDL_Event event;
    while (*gameState == 1) {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
                    SDL_DestroyTexture(texture[i]);
                }
                *gameState = 0;
                return;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
                        SDL_DestroyTexture(texture[i]);
                    }
                    *gameState = 0;
                    return;
                }
                if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) {
                    arrowSelection = (event.key.keysym.sym == SDLK_UP) ? (arrowSelection - 1 + QUANT_MENU_OPTIONS) % QUANT_MENU_OPTIONS :
                                                                         (arrowSelection + 1) % QUANT_MENU_OPTIONS;

                    for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
                        selected[i] = (i == arrowSelection) ? 1 : 0;

                        SDL_DestroyTexture(texture[i]);
                        menu[i] = TTF_RenderUTF8(screen->font, options[i], selected[i] ? color[1] : color[0], selected[i] ? color[0] : color[1]);
                        texture[i] = SDL_CreateTextureFromSurface(screen->renderer, menu[i]);
                        SDL_FreeSurface(menu[i]);
                        SDL_RenderCopy(screen->renderer, texture[i], NULL, &pos[i]);
                    }
                }
                break;
            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
                    if (mouseX >= pos[i].x && mouseX <= pos[i].x + pos[i].w &&
                        mouseY >= pos[i].y && mouseY <= pos[i].y + pos[i].h) {
                        if (!selected[i]) {
                            selected[i] = 1;
                            SDL_DestroyTexture(texture[i]);
                            menu[i] = TTF_RenderUTF8(screen->font, options[i], color[1], color[0]);
                            texture[i] = SDL_CreateTextureFromSurface(screen->renderer, menu[i]);
                            SDL_FreeSurface(menu[i]);
                            SDL_RenderCopy(screen->renderer, texture[i], NULL, &pos[i]);
                        }
                    } else{
                        if (selected[i]) {
                            selected[i] = 0;
                            SDL_DestroyTexture(texture[i]);
                            menu[i] = TTF_RenderUTF8(screen->font, options[i], color[0], color[1]);
                            texture[i] = SDL_CreateTextureFromSurface(screen->renderer, menu[i]);
                            SDL_FreeSurface(menu[i]);
                            SDL_RenderCopy(screen->renderer, texture[i], NULL, &pos[i]);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseX = event.button.x;
                mouseY = event.button.y;
                for (int i = 0; i < QUANT_MENU_OPTIONS; i++) {
                    if (mouseX >= pos[i].x && mouseX <= pos[i].x + pos[i].w &&
                        mouseY >= pos[i].y && mouseY <= pos[i].y + pos[i].h) {
                        for (int j = 0; j < 4; j++) {
                            SDL_DestroyTexture(texture[j]);
                        }
                        *gameState = i + 2;
                        return;
                    }
                }
                break;
        }

        int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - *lastFrameTime);

        if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
            SDL_Delay(timeToWait);
        }

        *lastFrameTime = SDL_GetTicks();
        SDL_RenderPresent(screen->renderer);
    }

    *gameState = 1;
    return;
}

//rolando para cima
// static int yPos = WINDOW_HEIGHT; // Start position at the bottom of the screen
// yPos -= (int)(45 * deltaTime);

// if (yPos + texH <= 0) {
//     yPos = WINDOW_HEIGHT; // Reset the position for continuous scrolling
// }

// void update(int *lastFrameTime){

//     int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - *lastFrameTime);

//     if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
//         SDL_Delay(timeToWait);
//     }

//     float deltaTime = (SDL_GetTicks() - *lastFrameTime) / 1000.0f;

//     *lastFrameTime = SDL_GetTicks();   
// }

// void render(ScreenResult screen, SDL_Rect rectangle){
//     SDL_SetRenderDrawColor(screen.renderer, 0, 0, 0, 255);
//     SDL_RenderClear(screen.renderer);
    
//     SDL_RenderCopy(screen.renderer, screen.texture, NULL, &(SDL_Rect){100, 100, 200, 50});
    
//     SDL_SetRenderDrawColor(screen.renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(screen.renderer, &rectangle);

//     SDL_RenderPresent(screen.renderer);
// }

void destoryScreen(ScreenResult screen){
    SDL_DestroyRenderer(screen.renderer);
    SDL_DestroyWindow(screen.window);
    TTF_Quit();
    SDL_Quit();
}
int introducao(ScreenResult *screen, int *lastFrameTime) {
    SDL_Color color = {255, 255, 255, 255};
    int texW = 0;
    int texH = 0;

    char *vetor[13];
    char jogador[20];

    // Aloca espaço para cada mensagem
    for (int i = 0; i < 13; ++i) {
        vetor[i] = (char *)malloc(256 * sizeof(char));  // Tamanho arbitrário; ajuste conforme necessário
    }

    strcpy(vetor[0], "No majestoso Reino de Aedônia, sob o reinado da benevolente Rainha Natacha, a paz era mantida através do equilíbrio mágico das árvores que adornavam a terra.");
    strcpy(vetor[1], "Contudo, as sombras da intriga se aproximaram quando um exército inimigo, cobiçando o poder das árvores mágicas, ameaçou a tranquilidade do reino.");
    strcpy(vetor[2], "O alerta ecoou nos salões reais no exato momento em que a Rainha compartilhava os segredos mágicos das árvores com seus súditos.");
    strcpy(vetor[3], "Sem hesitar, Natacha decidiu formar um exército para enfrentar a iminente invasão.");
    strcpy(vetor[4], "Convocando os guerreiros mais destemidos dos reinos vizinhos, a Rainha os colocou em um complexo de arenas espalhadas por sua floresta real, conhecido como de Ceasar's Arena, que fica no 3º distrito de Aedônia.");
    strcpy(vetor[5], "O objetivo era claro: forjar um exército real capaz de proteger as preciosas árvores e repelir as ameaças que se aproximavam da fronteira.");
    strcpy(vetor[6], "Entre os soldados, destaca-se a hierarquia, liderada por um Marechal, seguido por um general, um tenente-general e os valorosos \"Cavaleiros da Rainha\".");
    strcpy(vetor[7], "No entanto, nem todo aspirante terá o privilégio de se tornar um Cavaleiro da Rainha...");
    strcpy(vetor[8], "Aqueles que não atingirem tal honra serão exilados para o humilde reino de Nassau, vizinho a Aedônia, mas notavelmente mais carente.");
    strcpy(vetor[9], "O desafio está lançado: será que você, como jogador, terá a coragem e a estratégia necessárias para se destacar nesta jornada e ajudar a Rainha Natacha a preservar a magia de seu reino?");
    strcpy(vetor[10], "Como se chama?\n");

    SDL_Event event;

    for (int i = 0; i < 11; ++i) {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                return 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return 0;
                }
                if (event.key.keysym.sym == SDLK_SPACE) {
                    color.a = 1;
                }
                break;
        }

        int timeToWait = 500; // Pausa de 0,5 segundo
        SDL_Delay(timeToWait);

        // Limpa a tela após a última mensagem
        if (i == 10) {
            printf("Pressione qualquer tecla para continuar...");
            getchar(); // Aguarda entrada do teclado
            system("clear || cls"); // Limpa a tela
        }

        // Imprime os caracteres na velocidade de 0,1s por caractere
        for (int j = 0; vetor[i][j] != '\0'; ++j) {
            printf("%c", vetor[i][j]);
            SDL_Delay(10);
        }

        // Renderiza o texto na tela
        SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 255);
        SDL_RenderClear(screen->renderer);

        SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped(screen->font, vetor[i], color, WINDOW_WIDTH - 50);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(screen->renderer, surface);
        SDL_FreeSurface(surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

        SDL_Rect dstrect = {(WINDOW_WIDTH - texW) / 2, (WINDOW_HEIGHT - texH) / 2, texW, texH};

        SDL_RenderCopy(screen->renderer, texture, NULL, &dstrect);

        SDL_RenderPresent(screen->renderer);
        SDL_DestroyTexture(texture);
    }

    // Solicita o nome do jogador
    scanf("%s", jogador);

    // Concatena a mensagem de boas-vindas
    strcat(vetor[11], "Bem vindo, ");
    strcat(vetor[11], jogador);
    strcat(vetor[11], "!");

    // Adiciona a última mensagem ao vetor
    strcpy(vetor[12], "Agora você é um aspirante a Cavaleiro da Rainha, e para isso você terá que passar por alguns testes.");

    // Renderiza a última mensagem
    SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped(screen->font, vetor[12], color, WINDOW_WIDTH - 50);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(screen->renderer, surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    SDL_Rect dstrect = {(WINDOW_WIDTH - texW) / 2, (WINDOW_HEIGHT - texH) / 2, texW, texH};

    SDL_RenderCopy(screen->renderer, texture, NULL, &dstrect);

    SDL_RenderPresent(screen->renderer);
    SDL_DestroyTexture(texture);

    return 1;
}