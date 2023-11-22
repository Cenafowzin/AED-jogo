#ifndef __BIB_GAME__
#define __BIB_GAME__

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define ARMOR -1
#define WEAPON -2
#define PLAYER_TURN 1
#define ENEMY_TURN 2
#define ALLY_TURN 3

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

typedef struct castleTree{
    char *text;
    int id;
    struct castleTree *left;
    struct castleTree *right;
} castleTree;

typedef struct Player {
  char name[21];
  int points;
  int health;
  int money;
  int armorClass;
  Item *armor;
  Item *weapon;
  Item *inventory[6];
  Actor *ally;
} Player;

//introdução e preparação

void mainMenu();
void charPrint(char *texto);
void milliSleep(unsigned long milliseconds);
void setUtf8Encoding();
void textoPreRanking (char jogador, int ranking);
void introducao (char *jogador);
void disclaimer(void);

//avl

void avlRoomInsert(Room *room, Room **rootRoom);
void rotateRight(Room **rootRoom);
void rotateLeft(Room **rootRoom);
int childHeight(Room *rootRoom);
void balance(Room **rootRoom);

//carregar na memória

Item *loadItem(const char *name);
Move *loadMove(const char *name);
Actor *loadActor(const char *name);
void circRoomInsert (Room *room, Room **head, Room **tail);
int circLoadRooms(Room **circHead, Room **circTail);
void createMapAVL(Room **rootRoom, Room **circHead, Room **circTail, int totalRooms);
int loadRank(Rank **rankHead, Rank **rankTail);
void saveRank(Rank **rankHead, Rank **rankTail);

//jogo

void startPlayer(Player *player);
int rollD20();
void showInventory(Player *player);
int useItem(Player *player, Actor *enemy, Item *tempEnemy, int *enemyStun);
void grabMoney(Player *player, int money);
void grabItem(Player *player,Item *item);
void battle(Player *player, Actor *enemy);
void gamePlayLoop(Player *player, Room *rootRoom);
void roomOptions(Player *player, Room *room);
void insertRank(Rank **rankHead, Rank **rankTail, Rank *rank);
void sortRank(Rank **rankHead, Rank **rankTail);
void showRank(Rank *rankHead);
void pressEnter();

//liberar memória

void freeItem(Item *item);

void dialogTreeInsert(castleTree *enredo, castleTree **root);
int joyce(Player *player);
int thiago (Player *player);
int pamela (Player *player);
int ricardo (Player *player);
void royalMenu (Player *player);



#endif