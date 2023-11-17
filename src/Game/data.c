#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <include/SDL2/SDL.h>
// #include <include/SDL2/SDL_ttf.h>

void loadRooms(Room **RoomsHead, Room **RoomsTail){
    FILE *roomsFile = fopen("data/rms.dat", "r");
    int Roomquant;
    while(){
        fscanf(roomsFile, &Roomquant);
        Room *newRoom = (Room*)malloc(sizeof(Room));
        fread()

        if(!*RoomsHead){

        }
    }

}

// int main(){
//     return 0;
// }