#ifndef __LIB_GAME__
#define __LIB_GAME__

typedef struct item{
    char *name;
    int healthMod;
    int moneyMod;
    int attackMod;
    int defenseMod;
    int uses;
}item;

typedef struct player{
    char name[21];
    int health;
    int money;
    int armorClass;
    item *armor;
    item *weapon;
    item *inventory[6];
}player;

typedef struct move{
    char *name;
    char *text;
    int damage;
    int armorDebuff;
    int attackDebuff;
    int stunRounds;
}move;

typedef struct enemy{
    char *name;
    char *text;
    int health;
    int armorClass;
    int moneyDrop;
    item *itemDrop;
    move *moves[4];
}enemy;

typedef struct room{
    int id;
    char *text;
    int money;
    item *loot;
    enemy *enemy;
}room;

#endif