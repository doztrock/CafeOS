#include "lib/kernel/pantalla.h"

#include "stdio.h"
#include "stdlib.h"

int kmain(void) {

    iniciarPantalla();

    limpiarPantalla();

    pintarPantalla(AZUL);

    setForegroundColor(NEGRO);
    setBackgroundColor(AMARILLO);

    char mensaje[7] = "cafeOS";
    
    printf(mensaje);

    for (;;);

    return EXIT_SUCCESS;
}