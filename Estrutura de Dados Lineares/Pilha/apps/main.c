#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main(void) {
    TPilha Pilha;

    FPVazia(&Pilha);

    MENU(&Pilha);
    return 0;
}
