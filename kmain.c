#include "lib/kernel/pantalla.h"

#include "stdio.h"
#include "stdlib.h"

int kmain(void) {
    
    iniciarPantalla();

    limpiarPantalla();

    pintarPantalla(AZUL);

    setForegroundColor(NEGRO);
    setBackgroundColor(AMARILLO);
    
    printf("cafeOS!");

    for (;;);

    return EXIT_SUCCESS;
}