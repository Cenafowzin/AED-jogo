#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../data_structure/bib.h"

void setUtf8Encoding(){
    #ifdef _WIN32
        system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
        printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}

void writeMove() {
  Move move;
  char name[50];
  char text[1000];
  int i = 0, j = 0;
  printf("Nome:");
  fgets(name, 50, stdin);
  for (i = 0; name[i] != '\n'; i++);
  name[i] = '\0';
  i++;
  move.name = malloc((i) * sizeof(char));
  strcpy(move.name, name);
  printf("Texto:");
  fgets(text, 1000, stdin);
  for (j = 0; text[j] != '\n'; j++);
  text[j] = '\0';
  j++;
  move.text = malloc((j) * sizeof(char));
  strcpy(move.text, text);
  printf("damage:");
  scanf("%d", &move.damage);
  printf("armorMod:");
  scanf("%d", &move.armorMod);
  printf("attackMod:");
  scanf("%d", &move.attackMod);
  printf("stunRounds:");
  scanf("%d", &move.stunRounds);
  getchar();
  FILE *moveFile = fopen("mvs.dat", "ab+");
  fwrite(&i, sizeof(int), 1, moveFile);
  fwrite(move.name, sizeof(char), i, moveFile);
  fwrite(&j, sizeof(int), 1, moveFile);
  fwrite(move.text, sizeof(char), j, moveFile);
  fwrite(&move, sizeof(Move), 1, moveFile);
  fclose(moveFile);
}

void writeItem() {
  Item item;
  char name[50];
  char text[1000];
  int i = 0, j = 0;
  printf("Nome:");
  fgets(name, 50, stdin);
  for (i = 0; name[i] != '\n'; i++);
  name[i] = '\0';
  i++;
  item.name = malloc((i) * sizeof(char));
  strcpy(item.name, name);
  printf("Texto:");
  fgets(text, 1000, stdin);
  for (j = 0; text[j] != '\n'; j++);
  text[j] = '\0';
  j++;
  item.text = malloc((j) * sizeof(char));
  strcpy(item.text, text);
  printf("healthMod:");
  scanf("%d", &item.healthMod);
  printf("moneyMod:");
  scanf("%d", &item.moneyMod);
  printf("damage:");
  scanf("%d", &item.damage);
  printf("attackMod:");
  scanf("%d", &item.attackMod);
  printf("defenseMod:");
  scanf("%d", &item.defenseMod);
  printf("uses:");
  scanf("%d", &item.uses);
  getchar();
  FILE *itemFile = fopen("itms.dat", "ab+");
  fwrite(&i, sizeof(int), 1, itemFile);
  fwrite(item.name, sizeof(char), i, itemFile);
  fwrite(&j, sizeof(int), 1, itemFile);
  fwrite(item.text, sizeof(char), j, itemFile);
  fwrite(&item, sizeof(Item), 1, itemFile);
  free(item.name);
  fclose(itemFile);
}

void writeActor() {
  Actor actor;
  char name[50];
  char itemName[50];
  char *itemSave;
  char moveName[4][50];
  char *moveSaves[4];
  char text[1000];
  int nameSize = 0, textSize = 0, itemSize = 0, moveSize[4] = {0};
  printf("Nome:");
  fgets(name, 50, stdin);
  for (nameSize = 0; name[nameSize] != '\n'; nameSize++);
  name[nameSize] = '\0';
  nameSize++;
  actor.name = malloc((nameSize) * sizeof(char));
  strcpy(actor.name, name);
  printf("Texto:");
  fgets(text, 1000, stdin);
  for (textSize = 0; text[textSize] != '\n'; textSize++);
  text[textSize] = '\0';
  textSize++;
  actor.text = malloc((textSize) * sizeof(char));
  strcpy(actor.text, text);
  printf("health:");
  scanf("%d", &actor.health);
  printf("armorClass:");
  scanf("%d", &actor.armorClass);
  printf("moneyDrop:");
  scanf("%d", &actor.moneyDrop);
  getchar();
  printf("itemDrop(nome do item):");
  fgets(itemName, 50, stdin);
  for (itemSize = 0; itemName[itemSize] != '\n'; itemSize++);
  itemName[itemSize] = '\0';
  itemSize++;
  itemSave = malloc(itemSize * sizeof(char));
  strcpy(itemSave, itemName);
  actor.itemDrop = NULL;
  
  for(int i=0; i<4; i++){
    printf("move[%d](nome do golpe):", i);
    fgets(moveName[i], 50, stdin);
    for (moveSize[i] = 0; moveName[i][moveSize[i]] != '\n'; moveSize[i]++);
    moveName[i][moveSize[i]] = '\0';
    moveSize[i]++;
    moveSaves[i] = malloc(moveSize[i] * sizeof(char));
    strcpy(moveSaves[i], moveName[i]);
    actor.moves[i] = NULL;
  }
  
  FILE *actorFile = fopen("acts.dat", "ab+");
  fwrite(&nameSize, sizeof(int), 1, actorFile);
  fwrite(actor.name, sizeof(char), nameSize, actorFile);
  fwrite(&textSize, sizeof(int), 1, actorFile);
  fwrite(actor.text, sizeof(char), textSize, actorFile);
  fwrite(&itemSize, sizeof(int), 1, actorFile);
  fwrite(itemSave, sizeof(char), itemSize, actorFile);
  for(int i = 0; i<4; i++){
    fwrite(&(moveSize[i]), sizeof(int), 1, actorFile);
    fwrite(moveSaves[i], sizeof(char), moveSize[i], actorFile);
    free(moveSaves[i]);
  }
  fwrite(&actor, sizeof(Actor), 1, actorFile);
  free(itemSave);
  free(actor.text);
  free(actor.name);
  fclose(actorFile);
}

void writeRoom(){
  Room room;
  char text[1000];
  char itemName[50];
  char *itemSave;
  char enemyName[50];
  char *enemySave;
  char allyName[50];
  char *allySave;
  int textSize = 0,itemNameSize = 0, enemyNameSize = 0, allyNameSize = 0, quantCop = 0;

  //cópias
  printf("Digite a quantidade de cópias da sala:");
  scanf("%d", &quantCop);
  getchar();
  //texto
  printf("Texto:");
  fgets(text, 1000, stdin);
  for (textSize = 0; text[textSize] != '\n'; textSize++);
  text[textSize] = '\0';
  textSize++;
  room.text = malloc((textSize) * sizeof(char));
  strcpy(room.text, text);
  //trap damage
  printf("trap damage:");
  scanf("%d", &room.damage);
  //money
  printf("money:");
  scanf("%d", &room.money);
  getchar();
  //item
  printf("Item(nome do item):");
  fgets(itemName, 50, stdin);
  for (itemNameSize = 0; itemName[itemNameSize] != '\n'; itemNameSize++);
  itemName[itemNameSize] = '\0';
  itemNameSize++;
  itemSave = malloc((itemNameSize) * sizeof(char));
  strcpy(itemSave, itemName);
  room.loot = NULL;
  //enemy
  printf("Inimigo(nome do inimigo):");
  fgets(enemyName, 50, stdin);
  for (enemyNameSize = 0; enemyName[enemyNameSize] != '\n'; enemyNameSize++);
  enemyName[enemyNameSize] = '\0';
  enemyNameSize++;
  enemySave = malloc((enemyNameSize) * sizeof(char));
  strcpy(enemySave, enemyName);
  room.enemy = NULL;
  //ally
  printf("Aliado(nome do aliado):");
  fgets(allyName, 50, stdin);
  for (allyNameSize = 0; allyName[allyNameSize] != '\n'; allyNameSize++);
  allyName[allyNameSize] = '\0';
  allyNameSize++;
  allySave = malloc((allyNameSize) * sizeof(char));
  strcpy(allySave, allyName);
  room.ally = NULL;

  FILE *roomFile = fopen("rms.dat", "ab+");
  fwrite(&quantCop, sizeof(int), 1, roomFile);
  fwrite(&textSize, sizeof(int), 1, roomFile);
  fwrite(room.text, sizeof(char), textSize, roomFile);
  fwrite(&itemNameSize, sizeof(int), 1, roomFile);
  fwrite(itemSave, sizeof(char), itemNameSize, roomFile);
  fwrite(&enemyNameSize, sizeof(int), 1, roomFile);
  fwrite(enemySave, sizeof(char), enemyNameSize, roomFile);
  fwrite(&allyNameSize, sizeof(int), 1, roomFile);
  fwrite(allySave, sizeof(char), allyNameSize, roomFile);
  fwrite(&room, sizeof(Room), 1, roomFile);
  free(itemSave);
  free(enemySave);
  free(allySave);
  fclose(roomFile);
}

void writeBossRoom(){
  Room room;
  char text[1000];
  char itemName[50];
  char *itemSave;
  char enemyName[50];
  char *enemySave;
  char allyName[50];
  char *allySave;
  int textSize = 0,itemNameSize = 0, enemyNameSize = 0, allyNameSize = 0, quantCop = 0;

  //cópias
  printf("Digite a quantidade de cópias da sala:");
  scanf("%d", &quantCop);
  getchar();
  //texto
  printf("Texto:");
  fgets(text, 1000, stdin);
  for (textSize = 0; text[textSize] != '\n'; textSize++);
  text[textSize] = '\0';
  textSize++;
  room.text = malloc((textSize) * sizeof(char));
  strcpy(room.text, text);
  //trap damage
  printf("trap damage:");
  scanf("%d", &room.damage);
  //money
  printf("money:");
  scanf("%d", &room.money);
  getchar();
  //item
  printf("Item(nome do item):");
  fgets(itemName, 50, stdin);
  for (itemNameSize = 0; itemName[itemNameSize] != '\n'; itemNameSize++);
  itemName[itemNameSize] = '\0';
  itemNameSize++;
  itemSave = malloc((itemNameSize) * sizeof(char));
  strcpy(itemSave, itemName);
  room.loot = NULL;
  //enemy
  printf("Inimigo(nome do inimigo):");
  fgets(enemyName, 50, stdin);
  for (enemyNameSize = 0; enemyName[enemyNameSize] != '\n'; enemyNameSize++);
  enemyName[enemyNameSize] = '\0';
  enemyNameSize++;
  enemySave = malloc((enemyNameSize) * sizeof(char));
  strcpy(enemySave, enemyName);
  room.enemy = NULL;
  //ally
  printf("Aliado(nome do aliado):");
  fgets(allyName, 50, stdin);
  for (allyNameSize = 0; allyName[allyNameSize] != '\n'; allyNameSize++);
  allyName[allyNameSize] = '\0';
  allyNameSize++;
  allySave = malloc((allyNameSize) * sizeof(char));
  strcpy(allySave, allyName);
  room.ally = NULL;

  FILE *roomFile = fopen("brms.dat", "ab+");
  fwrite(&quantCop, sizeof(int), 1, roomFile);
  fwrite(&textSize, sizeof(int), 1, roomFile);
  fwrite(room.text, sizeof(char), textSize, roomFile);
  fwrite(&itemNameSize, sizeof(int), 1, roomFile);
  fwrite(itemSave, sizeof(char), itemNameSize, roomFile);
  fwrite(&enemyNameSize, sizeof(int), 1, roomFile);
  fwrite(enemySave, sizeof(char), enemyNameSize, roomFile);
  fwrite(&allyNameSize, sizeof(int), 1, roomFile);
  fwrite(allySave, sizeof(char), allyNameSize, roomFile);
  fwrite(&room, sizeof(Room), 1, roomFile);
  free(itemSave);
  free(enemySave);
  free(allySave);
  fclose(roomFile);
}

int main(){
  writeItem();
  //writeMove();
  //writeActor();
  //writeRoom();
  //writeBossRoom();
  return 0;
}