#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <include/SDL2/SDL.h>
// #include <include/SDL2/SDL_ttf.h>

void loadRooms(Room **RoomsHead, Room **RoomsTail){
    fopen("data/rms.dat", "r");
    Room *newRoom = (Room*)malloc(sizeof(Room));

    if(!*RoomsHead){

    }
}

int main(){
    return 0;
}