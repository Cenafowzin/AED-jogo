#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "bib.h"

int main() {
    setUtf8Encoding();
    system(CLEAR_SCREEN);
    char *jogador = "jose testa";

    // disclaimer();
    //introducao(&jogador);
    Rank *rankHead = NULL, *rankTail = NULL;
    loadRank(&rankHead, &rankTail);
    Room *roomsHead = NULL, *roomsTail = NULL, *root = NULL;
    int totalRooms = circLoadRooms(&roomsHead, &roomsTail);
    createMapAVL(&root, &roomsHead, &roomsTail, totalRooms);
    printf(">>>>%d<<<<", totalRooms);
    sleep(2);

    Actor *finalBoss = loadActor("erico");
    Player player;
    startPlayer(&player);
    strcpy(player.name, jogador);

    gamePlayLoop(&player, root);
    royalMenu(&player);
    char * finalText = "Ao sair do castelo, você é surpreendido, ali no meio da floresta estava o seu desafio final\n"
    "Erico o Terrível, andando com sua prancha mágica e com seu dinossauro de estimação ao lado\n"
    "você sabe que não pode perder essa oportunidade e vai desafiá-lo sem pensar muito\n";
    charPrint(finalText);
    sleep(3);
    battle(&player, finalBoss);
    if(player.health > 0){
        player.points += 1000;
        charPrint("Você conseguiu vencer o desafio, mas será que é o suficiente para não ser exilado?\n");
        sleep(4);
        Rank rank;
        strcpy(rank.name, player.name);
        rank.points = player.points;
        insertRank(&rankHead, &rankTail, &rank);
        sortRank(&rankHead, &rankTail);
        showRank(rankHead);
        saveRank(&rankHead, &rankTail);
    }else{
        charPrint("Infelizmente você foi derrotado e será exilado para o reino de Nassau!\n");
        showRank(rankHead);
        sleep(3);
    }
    
    //system(CLEAR_SCREEN);
    // Faça o que for necessário após o disclaimer
    // Libera a memória alocada para o nome do jogador
    free(jogador);

    return 0;
}