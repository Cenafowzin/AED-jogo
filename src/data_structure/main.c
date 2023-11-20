#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "bib.h"

int main() {
    setUtf8Encoding();
    system(CLEAR_SCREEN);
    char *jogador;

    // disclaimer();
    // introducao(&jogador);
    Player player;
    Room room;

    startPlayer(&player);

    Rank *head = NULL, *tail = NULL, *n = NULL;

    loadRank(&head, &tail);
    Rank um = {"um", 10};
    Rank dois = {"dois", 20};
    Rank tres = {"tres", 30};
    Rank quatro = {"quatro", 40};
    Rank cinco = {"cinco", 50};


    insertRank(&head, &tail, &cinco);
    insertRank(&head, &tail, &quatro);
    insertRank(&head, &tail, &tres);
    insertRank(&head, &tail, &dois);
    insertRank(&head, &tail, &um);
    insertRank(&head, &tail, &dois);
    insertRank(&head, &tail, &tres);
    insertRank(&head, &tail, &quatro);
    insertRank(&head, &tail, &cinco);

    
    showRank(head);

    saveRank(&head, &tail);
    

    //gamePlayLoop(&player, &room);

    // player.inventory[0] = loadItem("pot de cura");
    // player.inventory[1] = loadItem("pot de energia");
    // player.inventory[2] = loadItem("areia");
    // player.inventory[3] = loadItem("pedras pontudas");
    // player.inventory[4] = loadItem("bola de cristal");
    // player.inventory[5] = loadItem("12345678901234567890");


    // player.armor = loadItem("");
    // player.weapon = loadItem("");
    // if(player.armor){
    //     printf("[armor - %s]\n", player.armor->name);
    // }else{
    //     printf("[armor - nada]\n");
    // }
    // if(player.weapon){
    //     printf("[weapon - %s]\n", player.weapon->name);
    // }else{
    //     printf("[weapon - nada]\n");
    // }

    // Item *item = loadItem("areia");

    // grabItem(&player, item);

    // if(player.armor){
    //     printf("[armor - %s]\n", player.armor->name);
    // }else{
    //     printf("[armor - nada]\n");
    // }
    // if(player.weapon){
    //     printf("[weapon - %s]\n", player.weapon->name);
    // }else{
    //     printf("[weapon - nada]\n");
    // }

    // showInventory(&player);
    
    // Faça o que for necessário com o nome do jogador
    // Limpa a tela antes de exibir o disclaimer
    //system(CLEAR_SCREEN);
    // Faça o que for necessário após o disclaimer
    // Libera a memória alocada para o nome do jogador
    free(jogador);

    return 0;
}