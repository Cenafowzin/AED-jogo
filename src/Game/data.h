#ifndef __GAME_DATA_LIB__
#define  __GAME_DATA_LIB__

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

typedef struct Room{
    int id;
    char *text;
    int money;
    Item *loot;
    Enemy *enemy;
    struct Room *left;
    struct Room *right;
}Room;

#endif