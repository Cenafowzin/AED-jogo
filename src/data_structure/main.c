#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"
#include "bib.c"

int main() {
    char *jogador;

    disclaimer();
    introducao(&jogador);

    // Faça o que for necessário com o nome do jogador
    // Limpa a tela antes de exibir o disclaimer
    system(CLEAR_SCREEN);
    // Faça o que for necessário após o disclaimer
    // Libera a memória alocada para o nome do jogador
    free(jogador);

    return 0;
}