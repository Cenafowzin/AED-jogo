#include "bib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void setUtf8Encoding(){
    #ifdef _WIN32
        system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
        printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}

//Sleep em millisegundos
void milliSleep(unsigned long milliseconds){
    clock_t start = clock();
    unsigned long wait = milliseconds * (CLOCKS_PER_SEC / 1000);

    while ((clock() - start) < wait);
}

//Cena de apresentação do ranking caso jogador chegue no fim
char textoPreRanking(char jogador, int ranking){
    setUtf8Encoding();
    char *vetor[9];
    for (int i = 0; i < 10; ++i){
        vetor[i] = (char *)malloc(256 * sizeof(char)); // Tamanho arbitrário; ajuste conforme necessário
    }
    strcpy(vetor[0], "Numa era em que as sombras dançam entre os bosques e os ventos sussurram segredos aos ouvidos das árvores antigas, ");
    // pausa
    strcpy(vetor[1], "surge um grupo destemido de guerreiros, forjados na chama da coragem e moldados pela lealdade inabalável.");
    // pausa
    strcpy(vetor[2], "Armados com espadas reluzentes e vestindo armaduras impenetráveis, esses destemidos defensores emergem das névoas da história para fazer história.");
    // pausa e limpa a tela
    strcpy(vetor[3], "Sob a égide da Rainha Natacha, eles juraram proteger os fracos, desafiar a escuridão e erguer seus estandartes em nome da justiça.");
    // pausa
    strcpy(vetor[4], "Nos campos de batalha e nos salões do castelo, esses guerreiros marcham como um escudo invencível, prontos para enfrentar desafios que ecoarão pelos séculos, eternizando seus nomes como símbolos de honra e bravura.");
    // pausa e limpa a tela
    strcpy(vetor[5], "Que o reino saiba que, quando o chamado ressoar, uma irmandade única se erguerá para defender a coroa com suas vidas.");
    // pausa
    strcpy(vetor[6], "A população agarrou-se aos bravos guerreiros, atribuindo-lhes um apelido...\n");
    // pausa
    strcpy(vetor[7], "Eles são os Lovelaces: Guardiões da Rainha.");

    for (int i = 0; i < 8; ++i){
        // Obtém o comprimento da string atual
        int len = 0;
        while (vetor[i][len] != '\0'){
            len++;
        }
        // Loop para iterar sobre cada caractere da string
        for (int j = 0; j < len; ++j){
            // Imprime o caractere atual
            printf("%c", vetor[i][j]);
            fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
            if (i == 7){
                milliSleep(350);
                sleep(1);
            }else{
                milliSleep(20);
            }
        }
        if (i == 2 || i == 4){
            // aguarda 1 segundo e limpa a tela
            sleep(1);
            printf("\n");
            // system(CLEAR_SCREEN);
        }
        printf("\n"); // Pula uma linha após imprimir toda a string
        milliSleep(200);
    }

    // imprime o ranking
    printf("%s, \n", jogador);
    if (ranking == 1){
        strcpy(vetor[8], "Você é o Marechal dos Lovelaces, o mais alto posto do exército, parabéns!");
    }else if (ranking == 2){
        strcpy(vetor[8], "Você é o General dos Lovelaces, o segundo posto mais alto do exército, parabéns!");
    }else if (ranking == 3){
        strcpy(vetor[8], "Você é o Tenente-General dos Lovelaces, o terceiro posto mais alto do exército, parabéns!");
    }else if (ranking <= 20){
        strcpy(vetor[8], "Você é um dos Lovelaces, parabéns!");
    }else{
        strcpy(vetor[8], "Você não conseguiu entrar para o exército, mas não desanime, tente novamente!");
    }
    int len = 0;
    while (vetor[8][len] != '\0'){
        len++;
    }
    for (int j = 0; j < len; ++j){
        // Imprime o caractere atual
        printf("%c", vetor[8][j]);
        fflush(stdout);
        milliSleep(20);
    }
    printf("\n\n");
    milliSleep(200);
    // imprimir o ranking completo
}

//Printa caracter por caracter
void charPrint(char *texto){
    for (int i = 0; texto[i] != '\0'; ++i){
        // Imprime o caractere atual
        printf("%c", texto[i]);
        fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
        milliSleep(20);
    }
}

//Cena de introdução
void introducao(char **jogador){
    setUtf8Encoding();
    /* é chamado assim:
    char *jogador;
    introducao(&jogador); */
    system(CLEAR_SCREEN);
    char *vetor[13];
    for (int i = 0; i < 14; ++i){
        vetor[i] = (char *)malloc(256 * sizeof(char)); // Tamanho arbitrário; ajuste conforme necessário
    }
    strcpy(vetor[0], "No majestoso Reino de Aedônia, sob o reinado da benevolente Rainha Natacha,\na paz era mantida através do equilíbrio mágico das árvores que adornavam a terra.\n");
    // pausa
    strcpy(vetor[1], "Contudo, as sombras da intriga se aproximaram quando um exército inimigo,\ncobiçando o poder das árvores mágicas, ameaçou a tranquilidade do reino.\n");
    // pausa
    strcpy(vetor[2], "O alerta ecoou nos salões reais no exato momento em que a Rainha compartilhava\nos segredos mágicos das árvores com seus súditos.\n");
    // pausa
    strcpy(vetor[3], "Sem hesitar, Natacha decidiu formar um exército para enfrentar a iminente invasão.");
    // pausa e limpa a tela
    strcpy(vetor[4], "Convocando os guerreiros mais destemidos dos reinos vizinhos, a Rainha os colocou\nem um complexo de arenas espalhadas por sua floresta real, conhecido como\nCeasar's Arena, que fica no 3º distrito de Aedônia.\n");
    // pausa
    strcpy(vetor[5], "O objetivo era claro: forjar um exército real capaz de proteger as preciosas árvores\ne repelir as ameaças que se aproximavam da fronteira.");
    // pausa e limpa a tela
    strcpy(vetor[6], "Entre os soldados, destaca-se a hierarquia, liderada por um Marechal,\nseguido por um general, um tenente-general e os valorosos \"Cavaleiros da Rainha\".");
    // pausa e limpa a tela
    strcpy(vetor[7], "No entanto, nem todo aspirante terá o privilégio de se tornar um Cavaleiro da Rainha...\n");
    // pausa
    strcpy(vetor[8], "Aqueles que não atingirem tal honra serão exilados para o humilde reino de Nassau,\nvizinho a Aedônia, mas notavelmente mais carente.");
    // pausa e limpa a tela
    strcpy(vetor[9], "O desafio está lançado: será que você, guerreiro, terá a coragem\ne a estratégia necessárias para se destacar nesta jornada e ajudar a Rainha\nNatacha a preservar a magia de seu reino?\n");
    // pausa
    strcpy(vetor[10], "Como se chama?\n");
    // Loop para iterar sobre cada string no vetor
    for (int i = 0; i < 11; ++i){
        // Obtém o comprimento da string atual
        printf("\n"); // Pula uma linha após imprimir toda a string
        int len = 0;
        while (vetor[i][len] != '\0'){
            len++;
        }
        // Loop para iterar sobre cada caractere da string
        for (int j = 0; j < len; ++j){
            // Imprime o caractere atual
            printf("%c", vetor[i][j]);
            fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
            milliSleep(20);
        }
        if (i == 3 || i == 5 || i == 6 || i == 8){
            // recebe input vazio e limpa a tela
            printf(".. \n(Press Enter)");
            char c = 'a';
            while (c != '\n'){
                scanf("%c", &c);
            }
            system(CLEAR_SCREEN);
        }

        milliSleep(300);
    }
    *jogador = (char *)malloc(256 * sizeof(char));
    scanf("%s", *jogador);
    getchar();
    system(CLEAR_SCREEN);
    // pausa e limpa a tela
    strcpy(vetor[11], "Bem vindo, ");
    strcat(vetor[11], *jogador);
    strcat(vetor[11], "!");
    strcpy(vetor[12], "Agora você é um aspirante a Cavaleiro da Rainha, e para isso você\nterá que passar por alguns testes...\n");
    for (int i = 11; i < 13; ++i){
        printf("\n"); // Pula uma linha após imprimir toda a string
        // Obtém o comprimento da string atual
        int len = 0;
        while (vetor[i][len] != '\0'){
            len++;
        }
        // Loop para iterar sobre cada caractere da string
        for (int j = 0; j < len; ++j){
            // Imprime o caractere atual
            printf("%c", vetor[i][j]);
            fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
            milliSleep(20);
        }
        if (i == 12){
            // recebe input vazio e limpa a tela
            printf("\nVamos começar?\n");
            char c;
            scanf("%c", &c);
            system(CLEAR_SCREEN);
        }

        milliSleep(200);
    }
}

//cena de disclaimer
void disclaimer(void){
    setUtf8Encoding();
    // Limpa a tela
    system(CLEAR_SCREEN);

    // Aguarda por 2 segundos
    sleep(1);
    printf("Esta obra é fictícia e qualquer semelhança com pessoas reais,\n"
           "vivas ou mortas, é mera coincidência. Eventuais referências a eventos\n"
           "históricos, locais ou situações são puramente coincidentais e não devem\n"
           "ser interpretadas como fatos reais. Qualquer analogia com a realidade é\n"
           "completamente não intencional. Este é um produto de ficção e destina-se\n"
           "exclusivamente para entretenimento.\n");

    // Aguarda por 5 segundos
    sleep(5);

    // Limpa a tela
    system(CLEAR_SCREEN);

    printf("Classificação PEGI 7: Este jogo é recomendado para maiores de 7 anos.\n"
           "Pode conter formas leves de violência ou linguagem, moderadas e não perturbadoras para crianças mais novas.\n"
           "Os pais devem considerar o conteúdo antes de permitir que seus filhos joguem.\n");
    // Aguarda por 5 segundos
    sleep(5);
    // Exibe a mensagem preta na tela
    system(CLEAR_SCREEN);
    // Aguarda por 2 segundos
    sleep(1);
    fflush(stdout);
}

//-------------------------------------------------Memória--------------------------------------------------

//Carrega um item determinado na memória
Item *loadItem(const char *name){
    //verificação de nome vazio
    if(strcmp(name, "") == 0){
        return NULL;
    }
    //aloca espaço para item
    Item *item = (Item *)malloc(sizeof(Item));
    if(!item){
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }
    //abre arquivo dos itens
    FILE *itemFile = fopen("../data/itms.dat", "rb");
    if (!itemFile) {
        fprintf(stderr, "Error opening itemFile.\n");
        exit(1);
    }

    int nameSize = 0, textSize = 0;
    //procura item desejado no arquivo
    while (fread(&nameSize, sizeof(int), 1, itemFile) == 1) {
        //salva nome
        char *itemName = malloc(nameSize * sizeof(char));
        fread(itemName, sizeof(char), nameSize, itemFile);
        fread(&textSize, sizeof(int), 1, itemFile);

        //ao achar salva resto dos dados e retorna o item
        if (strcmp(itemName, name) == 0) {
            char *itemText = malloc(textSize * sizeof(char));
            fread(itemText, sizeof(char), textSize, itemFile);
            fread(item, sizeof(Item), 1, itemFile);
            item->name = itemName;
            item->text = itemText;
            fclose(itemFile);
            return item;
        }
        //pula para próximo item
        fseek(itemFile,((sizeof(char) * textSize) + sizeof(Item)), SEEK_CUR);
        free(itemName);
    }

    fclose(itemFile);
    free(item);
    return NULL;
}

//Carrega um ataque determinado na memória
Move *loadMove(const char *name){
    if(strcmp(name, "") == 0){
        return NULL;
    }
    Move *move = (Move *)malloc(sizeof(Move));
    if(!move){
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }
    int nameSize = 0, textSize = 0;

    //abre arquivo
    FILE *moveFile = fopen("../data/mvs.dat", "rb");
    if (!moveFile) {
        fprintf(stderr, "Error opening moveFile.\n");
        exit(1);
    }

    //procura ataque desejado no arquivo
    while (fread(&nameSize, sizeof(int), 1, moveFile) == 1) {
    //salva nome
    char *moveName = malloc(nameSize * sizeof(char));
    fread(moveName, sizeof(char), nameSize, moveFile);
    //le tamanho do texto
    fread(&textSize, sizeof(int), 1, moveFile);

    //ao achar salva resto dos dados e retorna o ataque
    if (strcmp(moveName, name) == 0) {
        char *moveText = malloc(textSize * sizeof(char));
        fread(moveText, sizeof(char), textSize, moveFile);
        fread(move, sizeof(Move), 1, moveFile);
        move->name = moveName;
        move->text = moveText;
        fclose(moveFile);
        return move;
    }

    //pula para próximo ataque
    fseek(moveFile, ((sizeof(char) * textSize) + sizeof(Move)), SEEK_CUR);
    free(moveName);
    }

    fclose(moveFile);
    return NULL;
}

//Carrega um determinado personagem na memória
Actor *loadActor(const char *name){
    if(strcmp(name, "") == 0){
        return NULL;
    }
    Actor *actor = (Actor *)malloc(sizeof(Actor));
    int nameSize, textSize, itemNameSize, moveNameSize[4];
    char *moveName[4];
    FILE *actorFile = fopen("../data/acts.dat", "rb");
    if (!actorFile) {
        fprintf(stderr, "Error opening actorFile.\n");
        exit(1);
    }

    //procura o inimigo desejado
    while (fread(&nameSize, sizeof(int), 1, actorFile) == 1) {
        //carrega nome
        char *actorName = (char*)malloc(nameSize * sizeof(char));
        fread(actorName, sizeof(char), nameSize, actorFile);
        //carrega texto
        fread(&textSize, sizeof(int), 1, actorFile);
        char *actorText = (char*)malloc(textSize * sizeof(char));
        fread(actorText, sizeof(char), textSize, actorFile);
        //carrega item
        fread(&itemNameSize, sizeof(int), 1, actorFile);
        char *itemName = (char*)malloc(itemNameSize * sizeof(char));
        fread(itemName, sizeof(char), itemNameSize, actorFile);
        //carrega golpes
        for(int i = 0; i < 4; i++){
            fread(&moveNameSize[i], sizeof(int), 1, actorFile);
            moveName[i] = (char*)malloc(moveNameSize[i] * sizeof(char));
            fread(moveName[i], sizeof(char), moveNameSize[i], actorFile);
        }
        //carrega a estrutura
        fread(actor, sizeof(Actor), 1, actorFile);
        //ao achar passa os dados para a estrutura
        if (strcmp(actorName, name) == 0) {
            actor->name = actorName;
            actor->text = actorText;
            actor->itemDrop = loadItem(itemName);
            for(int i = 0; i < 4; i++){
                actor->moves[i] = loadMove(moveName[i]);
            }
            fclose(actorFile);
            return actor;
        }
        free(actorName);
        free(actorText);
        free(itemName);
        for(int i = 0; i < 4; i++){
            free(moveName[i]);
        }
    }

    fclose(actorFile);
    free(actor);
    return NULL;
}

// insere uma sala na lista circular
void circRoomInsert(Room *room, Room **circHead, Room **circTail){
    if (*circHead == NULL){
        *circHead = room;
        *circTail = room;
        room->left = room;
        room->right = room;
    }else{
        room->left = *circTail;
        room->right = *circHead;
        (*circTail)->right = room;
        (*circHead)->left = room;
        *circTail = room;
    }
}

//Carrega todas as salas em uma lista circular
int circLoadRooms(Room **circHead, Room **circTail){
    FILE *roomFile = fopen("../data/rms.dat", "rb");
    if(!roomFile){
        fprintf(stderr, "Error opening roomFile.\n");
        exit(1);
    }
    int roomCopies, idCount = 0, textSize, itemNameSize, enemyNameSize, allyNameSize;
    Room *room = NULL;
    Room roomBase;

    //le cada sala do arquivo
    while(fread(&roomCopies, sizeof(int), 1, roomFile) == 1){
        //carrega
        fread(&textSize, sizeof(int), 1, roomFile);
        char *text = (char*)malloc(sizeof(char) * textSize);
        fread(text, sizeof(char), textSize, roomFile);
        //carrega nome do item
        fread(&itemNameSize, sizeof(int), 1, roomFile);
        char *itemName = (char*)malloc(sizeof(char) * itemNameSize);
        fread(itemName, sizeof(char), itemNameSize, roomFile);
        //carrega nome do inimigo
        fread(&enemyNameSize, sizeof(int), 1, roomFile);
        char *enemyName = (char*)malloc(sizeof(char) * enemyNameSize);
        fread(enemyName, sizeof(char), enemyNameSize, roomFile);
        //carrega nome do aliado
        fread(&allyNameSize, sizeof(int), 1, roomFile);
        char *allyName = (char*)malloc(sizeof(char) * allyNameSize);
        fread(allyName, sizeof(char), allyNameSize, roomFile);
        //carrega resto dos dados da sala
        fread(&roomBase, sizeof(Room), 1, roomFile);
        //cria a quantidade de salas e adiciona na lista
        for(int i = 0; i < roomCopies; i++){
            room = (Room*)malloc(sizeof(Room));
            (*room) = roomBase;
            room->id = idCount;
            room->text = text;
            room->loot = loadItem(itemName);
            room->enemy = loadActor(enemyName);
            room->ally = loadActor(allyName);
            circRoomInsert(room, circHead, circTail);
            idCount++;
            room = NULL;
        }
        free(itemName);
        free(enemyName);
        free(allyName);
    }
    fclose(roomFile);
    return idCount;
}

//Insere uma sala na AVL de salas
void avlRoomInsert(Room *room, Room **rootRoom){
    if (*rootRoom == NULL){
        *rootRoom = room;
    }else if (room->id < (*rootRoom)->id){
        avlRoomInsert(room, &((*rootRoom)->left));
    }else if(room->id > (*rootRoom)->id){
        avlRoomInsert(room, &((*rootRoom)->right));
    }

    balance(rootRoom);
}

//Roda arvore para a direita
void rotateRight(Room **rootRoom){
    if (*rootRoom == NULL || (*rootRoom)->left == NULL){
        return;
    }
    Room *aux = (*rootRoom)->left;
    (*rootRoom)->left = aux->right;
    aux->right = *rootRoom;
    *rootRoom = aux;
}

//Roda arvore para a esquerda
void rotateLeft(Room **rootRoom){
    if (*rootRoom == NULL || (*rootRoom)->right == NULL){
        return;
    }
    Room *aux = (*rootRoom)->right;
    (*rootRoom)->right = aux->left;
    aux->left = *rootRoom;
    *rootRoom = aux;
}
void pressEnter(){
    printf("\n(Press Enter)");
    char c = 'a';
    while (c != '\n'){
        scanf("%c", &c);
    }
    system(CLEAR_SCREEN);
}
//Indica a altura de uma árvore
int childHeight(Room *rootRoom){
    if(!rootRoom){
        return 0;
    }else{
        int lh = childHeight(rootRoom->left);
        int rh = childHeight(rootRoom->right);
        return 1 + (lh > rh ? lh : rh);
    }
}

//Balanceia a AVL
void balance(Room **rootRoom){
    if (!*rootRoom){ 
        return;
    }
    Room *aux;
    int balance = childHeight((*rootRoom)->right) - childHeight((*rootRoom)->left);

    if (balance < -1){
        aux = (*rootRoom)->left;
        balance = childHeight(aux->right) - childHeight(aux->left);

        if (balance > 0){
            rotateLeft(&((*rootRoom)->left));
            rotateRight(rootRoom);
        }else{
            rotateRight(rootRoom);
        }
    }else if (balance > 1){
        aux = (*rootRoom)->right;
        balance = childHeight(aux->right) - childHeight(aux->left);

        if (balance < 0){
            rotateRight(&((*rootRoom)->right));
            rotateLeft(rootRoom);
        }else{
            rotateLeft(rootRoom);
        }
    }
}

//Cria uma árvore de ordem aleatória para o mapa do jogo
void createMapAVL(Room **rootRoom, Room **circHead, Room **circTail, int totalRooms){
    if(!*circHead || !*circTail || totalRooms <= 0){
        fprintf(stderr, "Missing initial data to create map.");
        exit(1);
    }
    time_t t;
    srand((unsigned) time(&t));

    int randomPos;
    Room *circSelect = *circHead;
    Room *selectedRoom = NULL;

    while(*circHead){
        
        //Escolhe aleatóriamente uma sala da lista circular
        if(*circHead == *circTail){
            selectedRoom = *circHead;
            *circHead = NULL;
            *circTail = NULL;

        }else{
            randomPos = (rand() % totalRooms);

            for(int i = 0; i < randomPos; i++){
                circSelect = circSelect->right;
            }

            selectedRoom = circSelect;
            circSelect = circSelect->right;
            selectedRoom->left->right = selectedRoom->right;
            selectedRoom->right->left = selectedRoom->left;
            if(selectedRoom == *circHead){
                *circHead = selectedRoom->right;
            }else if(selectedRoom == *circTail){
                *circTail = selectedRoom->left;
            }
        }
        selectedRoom->right = NULL;
        selectedRoom->left = NULL;
        //Insere na árvore
        avlRoomInsert(selectedRoom, rootRoom);
    }
}

//Carrega o ranking na lista
int loadRank(Rank **rankHead, Rank **rankTail){
    FILE *rankFile = fopen("../data/rk.dat", "rb");
    if(!rankFile){
        return 0;
    }

    Rank rank;
    while(fread(&rank, sizeof(Rank), 1, rankFile) == 1){
        Rank *saveRank = (Rank*)malloc(sizeof(Rank));
        *saveRank = rank;
        insertRank(rankHead, rankTail, saveRank);
    }
    fclose(rankFile);
    return 1;
}

//Salva novo ranking no arquivo
void saveRank(Rank **rankHead, Rank **rankTail){
    if(!*rankHead || !*rankTail){
        return;
    }

    FILE *rankFile = fopen("../data/rk.dat", "wb+");
    if(!rankFile){
        fprintf(stderr, "Error creating rankFile.");
        exit(1);
    }

    int limit = 0;
    Rank *temp;
    while(*rankHead && limit <20){
        fwrite(*rankHead, sizeof(Rank), 1, rankFile);
        temp = *rankHead;
        *rankHead = (*rankHead)->next;
        free(temp);
        limit++;
    }

    while(*rankHead){
        temp = *rankHead;
        *rankHead = (*rankHead)->next;
        free(temp);
    }

    fclose(rankFile);
}

//-------------------------------------------------Jogo--------------------------------------------------

//Inicia a struct do jogador
void startPlayer(Player *player){
    player->health = 100;
    player->money = 0;
    player->points = 0;
    player->armorClass = 10;
    player->armor = loadItem("");
    player->weapon = loadItem("");
    for(int i = 0; i<6; i++){
        player->inventory[i] = loadItem("");
    }
    player->companion = loadActor("");
}

//Libera a memória de um item
void freeItem(Item *item){
    free(item->name);
    free(item->text);
    free(item);
}

//Rolagem de dado para combate
int rollD20(){
    time_t t;
    srand((unsigned) time(&t));

    return (rand() % 20) + 1;
}

//Mostra os itens no inventário do jogador
void showInventory(Player *player){
    printf("\n\t\t     Inventário\n");
    for(int i = 0; i < 6; i++){
        if(player->inventory[i]){
            printf("%d - %-21s", i+1, player->inventory[i]->name);
        }else{
            printf("%d - nada                 ", i+1);
        }
        if(i%2 != 0){
            printf("\n");
        }else{
            printf(" | ");
        }
    }
}

//Trata ação de pegar um item
void grabItem(Player *player,Item *item){
    printf("%s\n", item->text);
    int choice;
    if(item->uses == WEAPON || item->uses == ARMOR){ //Para armas ou armaduras
        if(((item->uses == WEAPON) ? player->weapon: player->armor)){
            while(1){
                printf("Você deseja trocar %s por %s?\n[1=sim][2=não]\n", ((item->uses == WEAPON) ? player->weapon->name: player->armor->name), item->name);
                scanf("%d", &choice);
                if(choice == 1){
                    if(item->uses == WEAPON){
                        printf("Você trocou %s por %s!\n", player->weapon->name,item->name);
                        freeItem(player->weapon);
                        player->weapon = item;
                    }else{
                        printf("Você trocou %s por %s!\n", player->armor->name,item->name);
                        freeItem(player->armor);
                        player->armor = item;
                    }
                    sleep(2);
                    system(CLEAR_SCREEN);
                    return;
                }else if(choice == 2){
                    system(CLEAR_SCREEN);
                    return;
                }
                system(CLEAR_SCREEN);
            }
        }else{
            while(1){
                printf("Você deseja equipar %s?\n[1=sim][2=não]\n", item->name);
                scanf("%d", &choice);
                if(choice == 1){
                    if(item->uses == WEAPON){
                        printf("Você equipou %s!\n", item->name);
                        player->weapon = item;
                    }else{
                        printf("Você equipou %s!\n", item->name);
                        player->armor = item;
                    }
                    sleep(2);
                    system(CLEAR_SCREEN);
                    return;
                }else if(choice == 2){
                    system(CLEAR_SCREEN);
                    return;
                }
                system(CLEAR_SCREEN);
            }
        }

    }else{ //Para iten usáveis
        int inventorySlot = 0;
        for(inventorySlot; inventorySlot < 5 && player->inventory[inventorySlot] != NULL; inventorySlot++);
        printf("((%d))\n", inventorySlot);
        if(player->inventory[inventorySlot] == NULL){
            while(1){
                printf("Você deseja adicionar %s ao seu inventário?\n[1=sim][2 = nao]\n", item->name);
                scanf("%d", &choice);
                if(choice == 1){
                    printf("%s foi adicionado no seu inventário!\n", item->name);
                    player->inventory[inventorySlot] = item;
                    sleep(2);
                    system(CLEAR_SCREEN);
                    return;
                }else if(choice == 2){
                    system(CLEAR_SCREEN);
                    return;
                }
                system(CLEAR_SCREEN);
            }
        }else{
            while(1){
                printf("Sua mochila parece cheia!\n");
                printf("Você deseja trocar %s por algum item do seu inventário?\n", item->name);
                showInventory(player);
                printf("\n[1=sim][2 = nao]\n");
                scanf("%d", &choice);
                if(choice == 1){
                    while(1){
                        system(CLEAR_SCREEN);
                        printf("Por qual item?\n");
                        showInventory(player);
                        printf("\n[0=cancelar]\n");
                        scanf("%d", &choice);
                        if(choice > 0 && choice < 7){
                            printf("%s foi trocado por %s!\n", player->inventory[choice-1]->name, item->name);
                            freeItem(player->inventory[choice-1]);
                            player->inventory[choice-1] = item;
                            sleep(2);
                            system(CLEAR_SCREEN);
                            return;
                        }else if(choice == 0){
                            system(CLEAR_SCREEN);
                            return;
                        }
                    }
                }else if(choice == 2){
                    system(CLEAR_SCREEN);
                    return;
                }
                system(CLEAR_SCREEN);
            }
        }
    }
}

//Trata o ganho de dinheiro
void grabMoney(Player *player, int money){
    printf("Voçê ganhou %d Gitcoins!\n", money);
    player->money += money;
    player->points += money;
    sleep(2);
}

//Loop principal de gameplay
void gamePlayLoop(Player *player, Room *rootRoom){
    int choice;
    Room *currentRoom = rootRoom, *level2 = NULL, *level3 = NULL;
    char *starText = "Ao seguir o caminho inicial para dentro das florestas da Ceasar's Arena,\n"
    "após um tempo caminhando na mata fechada, você se encontra uma clareira.\n"
    "Um pouco afastado das árvores você vê a luz do sol sendo refletida de algum objeto\n"
    "fincado em um toco de árvore. Ao se aproximar você se depara com uma espada estranha,\n"
    "sua lâmina é composta por vários segmentos que parecem estar conectados por um fio brilhante \n"
    "que atravessa do cabo até a ponta.\n"
    "\nNão parece a melhor das armas, mas é melhor do que nada.\n";
    
    //Sala inicial
    charPrint(starText);

    Item *startWeapon = loadItem("espada simplesmente encadeada");

    grabItem(player, startWeapon);

    //Loop de níveis
    for(int level = 0; level < 3; level++){
        system(CLEAR_SCREEN);
        char *choicePathText = "Após alguns minutos de caminhada você se depara com uma bifurcação em seu caminho\n"
        "Qual lado faria você chegar mais próximo de seu sonho?\n"
        "Qual lado lado seria a melhor escolha?\n"
        "Você não sabe, porém confia em seus instintos e segue...\n\n"
        "[1 - O caminho da esquerda]\n"
        "[2 - O caminho da direita]\n";
        charPrint(choicePathText);
        while(1){
            scanf("%d", &choice);
            if(choice == 1){
                if(currentRoom == rootRoom){ //marca inicio do level 2
                    level2 = currentRoom->right;
                }else if(currentRoom == level2){//marca inicio do level 3
                    level3 == currentRoom->right;
                }
                currentRoom = currentRoom->left;
                break;
            }else if(choice == 2){
                if(currentRoom == rootRoom){//marca inicio do level 2
                    level2 = currentRoom->left;
                }else if(currentRoom == level2){//marca inicio do level 3
                    level3 == currentRoom->left;
                }
                currentRoom = currentRoom->right;
                break;
            }else{
                system(CLEAR_SCREEN);
                printf("Escolha um caminho!\n\n[1 - O caminho da esquerda]\n[2 - O caminho da direita]\n");
            }
        }

        while(currentRoom->left && currentRoom->right){

        }
    }
}

// char *text; X
// int damage; X
// int money; X
// Item *loot; X
// Actor *enemy; - combate
// Actor *ally; X

//Realiza os eventos de cada sala
void roomOptions(Player *player, Room *room){
    int choice;
    //introdução da sala
    charPrint(room->text);

    if(room->damage != 0){//sala de armadilha
        int roll = rollD20();
        if((roll + player->armor->defenseMod) > 15){
            printf("Seus reflexos afiados e armadura resistente o fizeram sofrer menos dano!\n");
            printf("Você toma %d de dano.", (room->damage/2));
            player->health -= (room->damage/2);
            player->points += room->damage/4;
        }else{
            printf("Você toma %d de dano!", room->damage);
            player->health -= room->damage;
        }
    }else if(room->money != 0){//sala com dinheiro
        grabMoney(player, room->money);

    }else if(room->loot){//sala com loot
        grabItem(player, room->loot);

    }else if(room->ally){//sala de conversa
        //introdução do aliado
        charPrint(room->ally->text);
        while(1){
            scanf("%d", &choice);
            if(choice == 1){
                if(room->ally->moneyDrop){
                    grabMoney(player, room->money);
                    return;

                }else if(room->ally->itemDrop){
                    player->points += ((room->ally->itemDrop->attackMod*5) + (room->ally->itemDrop->defenseMod*5));
                    grabItem(player, room->ally->itemDrop);
                    return;
                }
            }else if(choice == 2){
                system(CLEAR_SCREEN);
                return;
            }
        }

    }else if(room->enemy){//sala de combate
        //introdução do inimigo
        charPrint(room->enemy->text);

        //combate
    }
}

//-------------------------------------------------Rank--------------------------------------------------

//Insere novo ranking
void insertRank(Rank **rankHead, Rank **rankTail, Rank *rank){
    rank->next = NULL;
    rank->prev = NULL;
    
    if(!(*rankHead)){
        *rankHead = rank;
        *rankTail = rank;
    }else{
        (*rankTail)->next = rank;
        rank->prev = *rankTail;
        *rankTail = rank;
    }
}

//Organiza o ranking por insertionSort
void sortRank (Rank **rankHead, Rank **rankTail){
    if (*rankHead == NULL || (*rankHead)->next == NULL) {
        return;
    }

    Rank *sorted, *unsorted, *temp;
    sorted= *rankHead;
    unsorted = (*rankHead)->next;
    while(unsorted){
        temp = unsorted;
        unsorted = unsorted->next;
        while((temp->prev!=NULL) && (temp->points > temp->prev->points)){
            temp->prev->next = temp->next;
            if(temp->next){
                temp->next->prev = temp->prev;
            }else{
                *rankTail = temp->prev;
            }
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;
            if(temp->prev){
                temp->prev->next = temp;
            }else{
                *rankHead = temp;
            }
        }
    }
}



/* 

    while(current!=*rankTail){
        Rank *compare = current;
        while((compare->prev!=NULL) && (compare->points < compare->prev->points)){
            //Rank *aux = compare->prev;
            //compare->prev = compare;
            //compare=aux;
            //compare=compare->prev;
            //insertion sorte em duplamente encadeada
            Rank *aux = compare->prev;
            if (aux->prev!=NULL){
                aux->prev->next = compare;
            }else{
                *rankHead = compare;
            }
            aux->prev = compare;
            aux->next = compare->next;
            compare->prev = aux->prev;
            if (compare->next!=NULL){
                compare->next->prev = aux;
            }else{
                *rankTail = aux;
            }
            compare->next = aux;

            compare = compare->prev;
        }
        current = current->next;
    } */
    




/* void sortRank(Rank **rankHead, Rank **rankTail){
    if (*rankHead == NULL || (*rankHead)->next == NULL) {
        return;
    }

    Rank *current = (*rankHead)->next;
    Rank *compare = NULL;
    while(current){
        compare = current;
        while(compare->prev && compare->points < compare->prev->points){
            Rank *aux = compare->prev;
            aux->prev->next = compare;
            aux->prev = compare;
            aux->next = compare->next;
            compare->prev = aux->prev;
            compare->next->prev = aux;
            compare->next = aux;

            //compare->next->prev = aux;
            if (aux->next) {
                aux->next->prev = aux;
            }
            if (compare->prev) {
                compare->prev->next = compare;
            } else {
                *rankHead = compare;
            }
            compare = compare->prev;
        }

        current = current->next;
    }
    
} */

//Mostra o ranking
void showRank(Rank *rankHead){
    int choice;
    Rank *current = rankHead;
    while(1){
        system(CLEAR_SCREEN);
        int i=0;
        charPrint("------------Ranking------------\n");
        while (current){
            if(i == 20){
                charPrint("\nExilado para o Reino de Nassau\n");
            }
            printf("%.2d > ", i+1);
            charPrint(current->name);
            printf(" - %d\n", current->points);
            current = current->next;
            i++;
        }
        charPrint("-------------------------------\n");
        printf("[1-voltar]\n");
        scanf("%d", &choice);
        if(choice == 1){
            return;
        }else{
            current = rankHead;
        }
    }
}

void dialogTreeInsert(castleTree *enredo, castleTree **root){
    if (*root == NULL){
        *root = enredo;
    }else if (enredo->id < (*root)->id){
        dialogTreeInsert(enredo, &((*root)->left));
    }else if(enredo->id > (*root)->id){
        dialogTreeInsert(enredo, &((*root)->right));
    }
}

//precisa adicionar. Está pronta, mas falta ver um jeito de retornar a resposta 1, 2 ou 3
int joyce(Player *player){
    castleTree j1;
    castleTree *joyce=NULL;
    j1.id=3;
    j1.text="Seguiu em direção à Rainha Natacha.\n"
    "Entretanto, antes de chegar perto dela, ela aparentemente encerrou sua conversa com quem parecia\n"
    "ser uma mulher e se distanciou. A pessoa com quem a Rainha Natacha estava conversando então lhe dirigiu a palavra.\n\n"
    "— Olá! Me chamo Joyce, sou a responsável pela coordenação desse evento. Como se chama?\n[1 - responder seu nome]\n[2 - ignorar e sair]\n";
    j1.left=NULL;
    j1.right=NULL;
    dialogTreeInsert(&j1, &joyce);

    castleTree j2;
    j2.id=2;
    j2.text= "Espero que esteja gostando de Aedônia! Eu sou a responsável por tudo aqui.\n"
    "Os súditos da nossa Rainha são muito exigentes, e vivem reclamando de várias coisas. Algumas são pertinentes, \n"
    "entretanto outras são besteira. O que você faria no meu lugar?\n[1 - ignoraria as demandas]\n"
    "[2 - atenderia a todas, independente do que fosse]\n[3 - faria um filtro, e separaria elas em critérios de prioridade]\n[4 - ignorar e sair]\n";
    j2.left=NULL;
    j2.right=NULL;
    dialogTreeInsert(&j2, &joyce);

    castleTree j3;
    j3.id=1;
    j3.text="Ok, vou anotar sua sugestão! Se você chegar até a final do torneio, nós nos encontraremos mais uma vez\ne eu lhe digo o que aconteceu. Boa sorte!\n";
    j3.left=NULL;
    j3.right=NULL;
    dialogTreeInsert(&j3, &joyce);

    while (joyce != NULL){
        system(CLEAR_SCREEN);
        inicio:
        charPrint(joyce->text);
        if (joyce->id==1){
            break;
        }
        int choice;
        scanf("%d", &choice);
        if (joyce->id==2 ){
            if (choice == 3){
                joyce = joyce->left;    
                //salvar essa opção, pois ela ajuda a diminuir o ataque de Érico
            }
            else if(choice == 1 || choice == 2){
                if (joyce->right==NULL){
                    charPrint("Ok, vou anotar sua sugestão! Se você chegar até a final do torneio,\n"
                    "nós nos encontraremos mais uma vez\ne eu lhe digo o que aconteceu. Boa sorte!\n");
                    break;
                }
            }else if(choice == 4){
                if (joyce->right==NULL){
                    charPrint("Boa sorte no torneio!\n");
                    break;
                }
            }else{
                system(CLEAR_SCREEN);
                printf("Escolha uma opção válida!\n\n");
                goto inicio;
            }
        }else if(choice == 1){
            joyce = joyce->left;
        }else if(choice == 2){
            if (joyce->right==NULL){
                charPrint("Boa sorte no torneio!\n");
                break;
            }
            //joyce = joyce->right;
        }else{
            system(CLEAR_SCREEN);
            printf("Escolha uma opção válida!\n\n");
            goto inicio;
        }
    }
    if (joyce->id==1){
        return 1;
    }else{
        return 0;
    }
}

int thiago (Player *player){
    castleTree t1;
    castleTree *thiago=NULL;
    t1.id=3;
    t1.text="Olá, jovem! Como se chama?\n[1 - responder seu nome]\n[2 - ignorar e sair]\n";
    t1.left=NULL;
    t1.right=NULL;
    dialogTreeInsert(&t1, &thiago);

    castleTree t2;
    t2.id=2;
    t2.text="[Rei] Olá! Eu sou o rei Thiago, seja bem-vindo ao reino da minha amiga, a rainha Natacha!\n"
    "Você veio pelo torneio, ou veio por algum outro motivo em especial?\n"
    "[1 - Vim pelo torneio]\n[2 - Estou a passeio]\n[3 - ignorar e sair]\n";
    t2.left=NULL;
    t2.right=NULL;
    dialogTreeInsert(&t2, &thiago);

    castleTree t3;
    t3.id=1;
    t3.text="[rei] Que interessante! Nós também viemos por conta do torneio.\n"
    "Ao fim haverá uma cerimônia para os que conseguirem se tornar cavaleiros, então nossa presença \n"
    "foi requisitada pela Rainha Natacha. Deixe-me lhe apresentar minha amiga, a rainha Pâmela, \n"
    "ela chegou esses dias de um período de estudos em Londres.\n";
    t3.left=NULL;
    t3.right=NULL;
    dialogTreeInsert(&t3, &thiago);

    charPrint("Se dirigiu ao casal de reis desconhecidos. Ficou em pé ao lado deles só ouvindo a conversa:\n\n"
    "[Rainha] Londres é incrível! Saudades de passear nos arredores da Imperial College em South Kensington!\n"
    "[Rei] Imagino, deve ter sido uma experiência incrível!\n");
    milliSleep(1000);
    charPrint("[...]\n");
    milliSleep(1000);
    charPrint("\n[Nesse momento o rei notou sua presença]\n");
    pressEnter();

    while (thiago !=NULL){
        system(CLEAR_SCREEN);
        inicio:
        charPrint(thiago->text);
        if (thiago->id==1){
            break;
        }
        int choice;
        scanf("%d", &choice);
        if (thiago->id==2){
            if (choice == 1){
                thiago = thiago->left;
            }else if(choice == 2){
                if (thiago->right==NULL){
                    charPrint("[Thiago] Que legal! Aedônia é realmente um reino muito bonito para passear.\n"
                    "Existem muitas árvores aqui. Entretanto está rolando um torneio, então cuidado para não \n"
                    "se perder e acabar tendo que enfrentar um dos guerreiros que a rainha Natacha trouxe. \n"
                    "Eles são muito poderosos. Até mais\n");
                    break;
                }
            }else if (choice ==3){
                if (thiago->right==NULL){
                    system(CLEAR_SCREEN);
                    charPrint("[Rainha] Que rapaz deselegante, vai embora sem me responder.\n"
                    "Vou anotar o nome dele no meu caderno para nunca me esquecer \n");
                    break;
                }
            }else{
                system(CLEAR_SCREEN);
                printf("Escolha uma opção válida!\n\n");
                goto inicio;
            }
        }else if (choice ==1){
            thiago = thiago->left;
        }else if(choice ==2){
            if (thiago->right==NULL){
                charPrint("[Rei] ah, vejo que está com pressa. Adeus.\n");
                break;
            }
        }else{
            system(CLEAR_SCREEN);
            printf("Escolha uma opção válida!\n\n");
            goto inicio;
        }
    }

    if (thiago->id==1){
        //return 1;
        pamela(player);
    }else{
        return 0;
    }
    
}

int pamela (Player *player){
    getchar();
    pressEnter();

    castleTree p1;
    castleTree *pamela=NULL;
    p1.id=3;
    p1.text="Olá! Você está empolgado com o torneio?\n[1 - sim]\n[2 - não]\n";
    p1.left=NULL;
    p1.right=NULL;
    dialogTreeInsert(&p1, &pamela);

    castleTree p2;
    p2.id=2;
    p2.text="[você] Não estou muito. Estou aqui só por pressão da minha família, querem que eu me torne alguém\n"
    "e disseram que ser cavaleiro é uma maneira fácil de conseguir fama e fortuna. Entretanto não estou me\n"
    "esforçando muito nos treinos, faço só o básico. Me ofereceram inclusive um emprego no reino que os derrotados\n"
    "no torneio serão exilados e estou pensando em ir para lá. Dizem que lá a vida é mais fácil.\n\n[Pâmela] Verdade, a vida pode até ser mais fácil, mas você não terá uma vida muito fácil no futuro.\n"
    "É como dizem, “se o treinamento for duro, o combate será fácil”. Creio que deva repensar esse modo de encarar sua vida e se esforçar mais.\n\n"
    "\nO quê você vai responder?\n[1 Sim, tem razão! Vou me esforçar mais]\n[2 - Eu sei, já me falaram isso várias vezes. Entretanto, prefiro a vida fácil agora. No futuro eu aceitarei as consequências dos meus atos.]\n";
    p2.left=NULL;
    p2.right=NULL;
    dialogTreeInsert(&p2, &pamela);

    castleTree p3;
    p3.id=1;
    p3.text= "Muito bom! Eu gosto assim, pessoas empolgadas e que vão atrás do que querem. \n"
    "Vou lhe contar uma coisa: no meu período em Londres, eu estudei muitas coisas, como por exemplo as propriedades\n"
    "mágicas das árvores que existem aqui em Aedônia. Entretanto uma das coisas que me especializei foi na arte de atirar\n"
    "flechas de ponteiros. O segredo é você sempre direcionar a flecha de ponteiro para o seu alvo. Caso a flecha não esteja\n"
    "apoiada no arco, ela deve estar no estojo, com a ponta virada para o fundo, que chamamos de NULL. Não tenho flechas aqui,\n"
    "mas tenho o meu Arco Estruturado, que comprei em Camden Town, em Londres. Fique com ele para você! Procure algumas\n"
    "flechas de ponteiros e use em suas batalhas. Boa sorte!\n";
    p3.left=NULL;
    p3.right=NULL;
    dialogTreeInsert(&p3, &pamela);

    while (pamela !=NULL){
        system(CLEAR_SCREEN);
        inicio:
        charPrint(pamela->text);
        if (pamela->id==1){
            break;
        }
        int choice;
        scanf("%d", &choice);
        system(CLEAR_SCREEN);
        if (pamela->id==2&&choice == 2){

            charPrint("[Pâmela] Ok, então. Você faz o que quiser com sua vida. Boa sorte na competição!\n");
            return 0;
        }else if (pamela->id==2){
            if (choice == 1){
                pamela = pamela->left;
                printf(".");
            }else if(choice == 2){
                printf(".");
                /* if (pamela->right==NULL){
                    charPrint("Não estou muito. Estou aqui só por pressão da minha família, querem que eu me torne alguém\n"
                    "e disseram que ser cavaleiro é uma maneira fácil de conseguir fama e fortuna. Entretanto não estou me\n"
                    "esforçando muito nos treinos, faço só o básico. Me ofereceram inclusive um emprego no reino que os derrotados\n"
                    "no torneio serão exilados e estou pensando em ir para lá. Dizem que lá a vida é mais fácil.\n");
                    break;
                } */
            }else{
                system(CLEAR_SCREEN);
                printf("Escolha uma opção válida!\n\n");
                goto inicio;
            }
        }else if (choice ==2){
            pamela = pamela->left;
        }else if(choice ==1){
            if (pamela->right==NULL){
                charPrint("Muito bom! Eu gosto assim, pessoas empolgadas e que vão atrás do que querem. \n"
                "Vou lhe contar uma coisa: no meu período em Londres, eu estudei muitas coisas, como por exemplo as propriedades\n"
                "mágicas das árvores que existem aqui em Aedônia. Entretanto uma das coisas que me especializei foi na arte de atirar\n"
                "flechas de ponteiros. O segredo é você sempre direcionar a flecha de ponteiro para o seu alvo. Caso a flecha não esteja\n"
                "apoiada no arco, ela deve estar no estojo, com a ponta virada para o fundo, que chamamos de NULL. Não tenho flechas aqui,\n"
                "mas tenho o meu Arco Estruturado, que comprei em Camden Town, em Londres. Fique com ele para você! Procure algumas\n"
                "flechas de ponteiros e use em suas batalhas. Boa sorte!\n");
                break;
            }
        }else{
            system(CLEAR_SCREEN);
            printf("Escolha uma opção válida!\n\n");
            goto inicio;
        }
    }
    if (pamela->id==1){
        return 1;
    }else{
        return 0;
    }
}

int ricardo (Player *player){
    castleTree r1;
    castleTree *ricardo=NULL;
    r1.id=4;
    r1.text="Ele parou de tocar e se virou para você:\n\n[bardo] Olá, jovem! O que te traz a essa terra longínqua? \n\n"
    "[1 - vim pelo torneio]\n[2 - ignorar e sair]\n";
    r1.left=NULL;
    r1.right=NULL;
    dialogTreeInsert(&r1, &ricardo);

    castleTree r2;
    r2.id=3;
    r2.text="[Bardo] Essa juventude de hoje não sabe o que foram os tempos sombrios de 40 anos atrás.\n"
    "A rainha está mais que certa em montar o seu exército. Me diga, jovem, qual seu nome?\n[1 - continua]\n[2 - sai]\n";
    r2.left=NULL;
    r2.right=NULL;
    dialogTreeInsert(&r2, &ricardo);

    castleTree r3;
    r3.id=2;
    r3.text="[Bardo] Gostei do nome! Já imagino ver seu nome no futuro, Marechal dos Cavaleiros da rainha!\n"
    "Você sabia que eu fui guarda pessoal do pai da Rainha Natacha?\n[1 - acreditar]\n[2 não acreditar]\n";
    r3.left=NULL;
    r3.right=NULL;
    dialogTreeInsert(&r3, &ricardo);

    castleTree r4;
    r4.id=1;
    r4.text="[Você] Que legal! Como foi isso?\n\n[Bardo] Pode não parecer, mas eu sou Ricardo o Grande! Eu atravessei o Oceano para terras longínquas,\n"
    "onde as pessoas falam um idioma diferente e possuem olhos estreitos. Lá, me encontrei com um grande mestre\n"
    "e ele me ensinou uma arte marcial chamada karatê. Se você quiser, eu posso lhe acompanhar. O que acha?\n"
    "[1 - aceitar]\n[2 - recusar]\n";
    r4.left=NULL;
    r4.right=NULL;
    dialogTreeInsert(&r4, &ricardo);

    
    charPrint("Ele estava tocando uma música animada com seu violino. Entretido com seu instrumento, sequer parecia\n"
    "que tinha percebido a sua aproximação.\n");
    milliSleep(1000);
    charPrint("Estávamos enganados.\n");
    milliSleep(1000);

    int choice;
    while (ricardo!=NULL){
        system(CLEAR_SCREEN);
        inicio:
        charPrint(ricardo->text);
        if (ricardo->id==1){
            scanf("%d", &choice);
            break;
        }
        scanf("%d", &choice);
        getchar();
        if (choice == 2){
            if (ricardo->id==4){
                charPrint("[Bardo] Esses jovens de hoje em dia... vou ficar tocando meu violino que é o melhor que eu faço.\n");
                return 0;
            }else if(ricardo->id==3){
                charPrint("– [Bardo]  Bom, eu saberei seu nome quando sair na lista de cavaleiros ou exilados, não é mesmo?\nBoa sorte no torneio.\n");
                return 0;
            }else if(ricardo->id==2){
                charPrint("[Você] Que mentira! Um bardo como você, guarda pessoal do rei? \n"
                    "Nem aqui, nem no reino de Nassau! Mais fácil um boi voar. Inclusive, eu soube que fizeram isso lá,\n"
                    "que um boi voou na inauguração da ponte que a conecta com o reino vizinho de Recife.\n"
                    "Enfim, vou-me embora. Até mais, bardo!\n");
                return 0;
            }else if(ricardo->id==2){
                charPrint("[Bardo] Tudo bem. Boa sorte na sua jornada!\n");
                return 0;
            }
        }else if (ricardo->id==2){
            if (choice == 1){
                ricardo = ricardo->left;
            }else if(choice == 2){
                if (ricardo->right==NULL){
                    charPrint("[Você] Que mentira! Um bardo como você, guarda pessoal do rei? \n"
                    "Nem aqui, nem no reino de Nassau! Mais fácil um boi voar. Inclusive, eu soube que fizeram isso lá,\n"
                    "que um boi voou na inauguração da ponte que a conecta com o reino vizinho de Recife.\n"
                    "Enfim, vou-me embora. Até mais, bardo!\n");
                    break;
                }
            }else{
                system(CLEAR_SCREEN);
                printf("Escolha uma opção válida!\n\n");
                goto inicio;
            }
        }else if (choice ==1){
            ricardo = ricardo->left;
        }else if(choice ==2){
            if (ricardo->right==NULL){
                charPrint("texto 4...\n");
                //break;
            }
        }else{
            system(CLEAR_SCREEN);
            printf("Escolha uma opção válida!\n\n");
            goto inicio;
        }
    }
    if (ricardo->id==1 && choice == 1){
        charPrint("Ótimo! Vamos indo, vou tocar muitas músicas na nossa jornada!\n");
        return 1;
    }else{
        return 0;
    }
}

 