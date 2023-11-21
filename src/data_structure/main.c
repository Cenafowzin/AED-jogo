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

    //disclaimer();
    //introducao(&jogador);
    Player player;
    startPlayer(&player);
    Room *root;
    Room *roomsHead = NULL, *roomsTail = NULL;
    int totalRooms = circLoadRooms(&roomsHead, &roomsTail);
    Room *n = roomsHead;
    do{
        printf("%s\n", n->text);
        n = n->right;
    }while(n != roomsHead);
    createMapAVL(&root, &roomsHead, &roomsTail, totalRooms);

    gamePlayLoop(&player, root);
    // player.weapon = loadItem("espada temporal");
    // Actor *enemy = loadActor("leveza");
    // player.ally = loadActor("moribundo");


    // player.inventory[0] = loadItem("pot de cura");
    // player.inventory[1] = loadItem("pot de energia");
    // player.inventory[2] = loadItem("areia");
    // player.inventory[3] = loadItem("pedras pontudas");
    // player.inventory[4] = loadItem("bola de cristal");
    // player.inventory[5] = loadItem("12345678901234567890");
    // //printf("%d\n", player.inventory[2].);
    // //useItem(&player, NULL, NULL, 0);
    // textoPreRanking("cesar", 3);

    // battle(&player, enemy);

    // Rank *head = NULL, *tail = NULL, *n = NULL;

    // loadRank(&head, &tail);
    // Rank um = {"um", 100};
    // Rank dois = {"dois", 200};
    // Rank tres = {"tres", 300};
    // Rank quatro = {"quatro", 400};
    // Rank cinco = {"cinco", 500};


    // insertRank(&head, &tail, &cinco);
    // insertRank(&head, &tail, &quatro);
    // insertRank(&head, &tail, &tres);
    // insertRank(&head, &tail, &dois);
    // insertRank(&head, &tail, &um);
    

    // sortRank(&head, &tail);
    // showRank(head);

    // saveRank(&head, &tail);
    

    //gamePlayLoop(&player, &room);



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