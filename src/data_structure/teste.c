#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define ARMOR -1
#define WEAPON -2
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

/* Adicionar no principal:
void dialogTreeInsert(castleTree *enredo, castleTree **root);
int joyce(Player *player);

 */




void setUtf8Encoding(){
    #ifdef _WIN32
        system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
        printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}
void milliSleep(unsigned long milliseconds){
    clock_t start = clock();
    unsigned long wait = milliseconds * (CLOCKS_PER_SEC / 1000);

    while ((clock() - start) < wait);
}
typedef struct Rank{
  char name[21];
  int points;
  struct Rank *next;
  struct Rank *prev;
}Rank;
typedef struct Item {
  char *name;
  char *text;
  int healthMod;
  int moneyMod;
  int damage;
  int attackMod;
  int defenseMod;
  int uses;
} Item;
typedef struct Move {
  char *name;
  char *text;
  int damage;
  int armorMod;
  int attackMod;
  int stunRounds;
} Move;
typedef struct Actor {
  char *name;
  char *text;
  int health;
  int armorClass;
  int moneyDrop;
  Item *itemDrop;
  Move *moves[4];
} Actor;
typedef struct Room {
  int id;
  char *text;
  int damage;
  int money;
  Item *loot;
  Actor *enemy;
  Actor *ally;
  struct Room *left;
  struct Room *right;
} Room;
typedef struct Player {
  char name[21];
  int points;
  int health;
  int money;
  int armorClass;
  Item *armor;
  Item *weapon;
  Item *inventory[6];
  Actor *companion;
} Player;
typedef struct castleTree{
    char *text;
    int id;
    struct castleTree *left;
    struct castleTree *right;
} castleTree;
void gamePlayLoop(Player *player, Room *rootRoom);
void charPrint(char *texto);
void grabItem(Player *player,Item *item);
void freeItem(Item *item);
Item *loadItem(const char *name);
void showInventory(Player *player);
void startPlayer(Player *player);
Actor *loadActor(const char *name);
Move *loadMove(const char *name);
void introducao(char **jogador);
void pressEnter();
//precisa adicionar. Está pronta
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
    system(CLEAR_SCREEN);
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
        pressEnter();
        return 1;
    }else{
        pressEnter();
        return 0;
    }
}

int thiago (Player *player){
    system(CLEAR_SCREEN);
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
        pressEnter();
        return 0;
    }
    
}

int pamela (Player *player){
    system(CLEAR_SCREEN);
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
        pressEnter();
        return 1;
    }else{
        pressEnter();
        return 0;
    }
}

int ricardo (Player *player){
    system(CLEAR_SCREEN);
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
    "A rainha está mais que certa em montar o seu exército. Me diga, jovem, qual seu nome?\n[1 - responder]\n[2 - não responder]\n";
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
                pressEnter();
                return 0;
            }else if(ricardo->id==3){
                charPrint("– [Bardo]  Bom, eu saberei seu nome quando sair na lista de cavaleiros ou exilados, não é mesmo?\nBoa sorte no torneio.\n");
                pressEnter();
                return 0;
            }else if(ricardo->id==2){
                charPrint("[Você] Que mentira! Um bardo como você, guarda pessoal do rei? \n"
                    "Nem aqui, nem no reino de Nassau! Mais fácil um boi voar. Inclusive, eu soube que fizeram isso lá,\n"
                    "que um boi voou na inauguração da ponte que a conecta com o reino vizinho de Recife.\n"
                    "Enfim, vou-me embora. Até mais, bardo!\n");
                pressEnter();
                return 0;
            }else if(ricardo->id==2){
                charPrint("[Bardo] Tudo bem. Boa sorte na sua jornada!\n");
                pressEnter();
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
        pressEnter();
        return 1;
    }else{
        pressEnter();
        return 0;
    }
}

void royalMenu (Player *player){
    int j=-1, t=-1, r=-1, choice=0;
    charPrint("Você acabou de entrar no Salão Real.\n\nVocê está vendo um Rei e uma Rainha conversando, um bardo tocando violino, e a Rainha Natacha conversando com uma pessoa.\n\nO que deseja fazer?\n\n");
    while (t<0||r<0||j<0){
        if (t<0){
            charPrint("[1 - Ir em direção ao Rei e a Rainha]\n");
        }else{
            printf("\n");
        }
        if (r<0){
            charPrint("[2 - Ir em direção ao bardo]\n");
        }else{
            printf("\n");
        }
        if (j<0){
            charPrint("[3 - Ir em direção à Rainha Natacha]\n");
        }else{
            printf("\n");
        }
        charPrint("[4 - Sair do Salão Real]\n");
        scanf("%d", &choice);
        getchar();
        

        if (choice == 1){
            t=thiago(player);
        }else if(choice == 2){
            r=ricardo(player);
        }else if(choice == 3){
            j=joyce(player);
        }else if(choice == 4){
            break;
        }else{
            system(CLEAR_SCREEN);
            printf("Escolha uma opção válida!\n\n");
        }
        system(CLEAR_SCREEN);
        charPrint("Para onde deseja ir agora?\n\n");
    }
    charPrint("Você já fez o que tinha que fazer. Vamos embora, que uma jornada nos aguarda\n");    
}

int main(){
    setUtf8Encoding();
    system(CLEAR_SCREEN);
    Room room;
    Player player;
    
    startPlayer(&player);
    //gamePlayLoop(&player, &room);
    royalMenu(&player);
    //introducao(&player.name);
    return 0;
    
}






void charPrint(char *texto){
    //setUtf8Encoding();
    //system(CLEAR_SCREEN);

    for (int i = 0; texto[i] != '\0'; ++i){
        // Imprime o caractere atual
        printf("%c", texto[i]);
        fflush(stdout); // Certifica-se de que a saída é exibida imediatamente
        milliSleep(20);
    }
}
void gamePlayLoop(Player *player, Room *rootRoom){

    //setUtf8Encoding();

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
//Cena de introdução
void pressEnter(){
    printf("\n(Press Enter)");
    char c = 'a';
    while (c != '\n'){
        scanf("%c", &c);
    }
    system(CLEAR_SCREEN);
}
void freeItem(Item *item){
    free(item->name);
    free(item->text);
    free(item);
}
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