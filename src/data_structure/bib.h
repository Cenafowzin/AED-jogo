#ifndef __BIB_GAME__
#define __BIB_GAME__

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define ARMOR -1
#define WEAPON -2

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
  int armorDebuff;
  int attackDebuff;
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
  int health;
  int money;
  int armorClass;
  Item *armor;
  Item *weapon;
  Item *inventory[6];
  Actor *companion;
} Player;

void milliSleep(unsigned long milliseconds);
void setUtf8Encoding();
char textoPreRanking (char jogador, int ranking);
void introducao (char **jogador);
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

int rollD20();

#endif