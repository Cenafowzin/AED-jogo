#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "bib.h"
#include "bib.c"

int main() {
    char *jogador;

    //disclaimer();
    //introducao(&jogador);
    printf("%d\n",rollD20());
    sleep(1);
    printf("%d\n",rollD20());
    sleep(1);
    printf("%d\n",rollD20());
    sleep(1);
    printf("%d\n",rollD20());
    sleep(1);
    printf("%d\n",rollD20());
    sleep(1);
    printf("%d\n",rollD20());
    sleep(1);

    // printf("\n--------Item-Test----------\n");
    // Item *item = loadItem("picareta");
    // if (item == NULL) {
    //     printf("Item Inexistente\n");
    // } else {
    //     printf("nome:%s\n", item->name);
    //     printf("texto:%s\n", item->text);
    //     printf("health:%d\n", item->healthMod);
    //     printf("money:%d\n", item->moneyMod);
    //     printf("damage:%d\n", item->damage);
    //     printf("attack:%d\n", item->attackMod);
    //     printf("defense:%d\n", item->defenseMod);
    //     printf("uses:%d\n", item->uses);
    //     free(item->name);
    //     free(item);
    // }
    // printf("\n--------Move-Test----------\n");
    // Move *move = loadMove("soco fraco");
    // if(move){
    //     printf("name:%s\n", move->name);
    //     printf("text:%s\n", move->text);
    //     printf("damage:%d\n", move->damage);
    //     printf("armorMod:%d\n", move->armorMod);
    //     printf("attackMod:%d\n", move->attackMod);
    //     printf("stunRounds:%d\n", move->stunRounds);
    // }else{
    //     printf("movimento não existente\n");
    // }
    // printf("\n--------Actor-Test----------\n");
    // Actor *actor = loadActor("alceu dias");
    // if(actor){
    //     printf("name:%s\n", actor->name);
    //     printf("text:%s\n", actor->text);
    //     printf("health:%d\n", actor->health);
    //     printf("armorClass:%d\n", actor->armorClass);
    //     printf("moneyDrop:%d\n", actor->moneyDrop);
    //     printf("---------ItemDrop---------\n");
    //     if(actor->itemDrop){
    //         printf("nome:%s\n", actor->itemDrop->name);
    //         printf("texto:%s\n", actor->itemDrop->text);
    //         printf("health:%d\n", actor->itemDrop->healthMod);
    //         printf("money:%d\n", actor->itemDrop->moneyMod);
    //         printf("damage:%d\n", actor->itemDrop->damage);
    //         printf("attack:%d\n", actor->itemDrop->attackMod);
    //         printf("defense:%d\n", actor->itemDrop->defenseMod);
    //         printf("uses:%d\n", actor->itemDrop->uses);
    //     }else{
    //         printf("Nada\n");
    //     }

    //     for(int i = 0; i<4; i++){
    //         printf("-----------Move[%d]------------\n", i);
    //         if(actor->moves[i]){
    //             printf("name:%s\n", actor->moves[i]->name);
    //             printf("text:%s\n", actor->moves[i]->text);
    //             printf("damage:%d\n", actor->moves[i]->damage);
    //             printf("armorMod:%d\n", actor->moves[i]->armorMod);
    //             printf("attackMod:%d\n", actor->moves[i]->attackMod);
    //             printf("stunRounds:%d\n", actor->moves[i]->stunRounds);
    //         }else{
    //             printf("nada\n");
    //         }
    //     }
    // }else{
    //     printf("inimigo inexistente\n");
    // }
    // Room *circHead = NULL, *circTail = NULL, *rootRoom = NULL;

    // int totalRooms = circLoadRooms(&circHead, &circTail);

    // printf("TOTAL:%d\n", totalRooms);

    // createMapAVL(&rootRoom, &circHead, &circTail, totalRooms);
    // Room um, dois, tres, quatro, cinco;
    // um.id = 1;
    // um.right = NULL;
    // um.left = NULL;
    // dois.id = 2;
    // dois.right = NULL;
    // dois.left = NULL;
    // tres.id = 3;
    // tres.right = NULL;
    // tres.left = NULL;
    // quatro.id = 4;
    // quatro.right = NULL;
    // quatro.left = NULL;
    // cinco.id = 5;
    // cinco.right = NULL;
    // cinco.left = NULL;

    // avlRoomInsert(&cinco, &rootRoom);
    // avlRoomInsert(&tres, &rootRoom);
    // avlRoomInsert(&dois, &rootRoom);
    // avlRoomInsert(&um, &rootRoom);
    // avlRoomInsert(&quatro, &rootRoom);

    // Room *n = circHead;
    // printf("\n\n-------Rooms-Test---------------\n");
    // do{
    //     printf("id:%d\n",n->id);
    //     printf("text:%s\n", n->text);
    //     printf("damage:%d\n", n->damage);
    //     printf("money:%d\n", n->money);
    //     if(n->loot){
    //         printf("itemName:%s\n", n->loot->name);
    //     }else{
    //         printf("itemName:nada\n");
    //     }
    //     if(n->enemy){
    //         printf("enemyName:%s\n", n->enemy->name);
    //     }else{
    //         printf("enemyName:nada\n");
    //     }if(n->ally){
    //         printf("allyName:%s\n", n->ally->name);
    //     }else{
    //         printf("allyName:nada\n");
    //     }
    //     printf("____________________________________\n");
    //     n = n->right;
    // }while(n != circHead);

    // Faça o que for necessário com o nome do jogador
    // Limpa a tela antes de exibir o disclaimer
    //system(CLEAR_SCREEN);
    // Faça o que for necessário após o disclaimer
    // Libera a memória alocada para o nome do jogador
    free(jogador);

    return 0;
}