#include <stdio.h>
#include <stdlib.h>

#include "listaD.h"
#include "interface.h"

int main(void) {
    TLista Lista;

    FLDVazia(&Lista);

    MENU(&Lista);
    return 0;
}
