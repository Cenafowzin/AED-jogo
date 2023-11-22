#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "bib.h"

int main() {
    setUtf8Encoding();
    system(CLEAR_SCREEN);
    int choice = 0;
    Room *roomsHead = NULL, *roomsTail = NULL, *root = NULL;

    disclaimer();
    while(choice != 3){
    charPrint("\t\tCAVALEIROS DE AEDÔNIA\n\n\n");
    milliSleep(100);
    charPrint("\t\t Escolha uma opção:\n\n");
    charPrint("\t\t[   1 - JOGAR     ]\n");
    charPrint("\t\t[   2 - RANKING   ]\n");
    charPrint("\t\t[   3 - SAIR      ]\n");

        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            char jogador[21];
            int totalRooms = circLoadRooms(&roomsHead, &roomsTail);
            createMapAVL(&root, &roomsHead, &roomsTail, totalRooms);
            introducao(jogador);
            Player player;
            startPlayer(&player);
            strcpy(player.name, jogador);
            gamePlayLoop(&player, root);
            system(CLEAR_SCREEN);
        }else if(choice == 2){
            Rank *rankHead = NULL, *rankTail = NULL;
            loadRank(&rankHead, &rankTail);
            showRank(rankHead);
            system(CLEAR_SCREEN);
        }else{
            system(CLEAR_SCREEN);
        }
    }

    return 0;
}