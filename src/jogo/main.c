#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "bib.h"

int main() {
    setUtf8Encoding();
    system(CLEAR_SCREEN);

    disclaimer();
    mainMenu();
    

    return 0;
}