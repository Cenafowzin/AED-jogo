#ifndef __BIB_GAME__
#define __BIB_GAME__

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

typedef struct Item{
    char *name;
    int healthMod;
    int moneyMod;
    int attackMod;
    int defenseMod;
    int uses;
}Item;

typedef struct Player{
    char name[21];
    int health;
    int money;
    int armorClass;
    Item *armor;
    Item *weapon;
    Item *inventory[6];
}Player;

typedef struct Move{
    char *name;
    char *text;
    int damage;
    int armorDebuff;
    int attackDebuff;
    int stunRounds;
}Move;

typedef struct Enemy{
    char *name;
    char *text;
    int health;
    int armorClass;
    int moneyDrop;
    Item *itemDrop;
    Move *moves[4];
}Enemy;

typedef struct room{
    int id;
    char *text;
    int money;
    Item *loot;
    Enemy *enemy;
    struct room *left;
    struct room *right;
}Room;

void setUtf8Encoding();
char texto_pre_ranking (char jogador, int ranking);
void introducao (char **jogador);
void disclaimer(void);
void circ_room_insert (Room *room, Room **head, Room **tail);
void avl_room_insert (Room *room, Room **root);
void rotate_double_right (Room **root);
void rotate_double_left (Room **root);
void rotate_right (Room **root);
void rotate_left (Room **root);
void balance_tree (Room **root);



#endif