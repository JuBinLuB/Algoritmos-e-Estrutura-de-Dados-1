#include <stdio.h>
#include <stdlib.h>

#include "lista_dupla.h"
#include "interface.h"

int main(void) {
    TLista Lista;

    FLVazia(&Lista);

    MENU(&Lista);
    return 0;
}
