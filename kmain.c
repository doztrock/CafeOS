#include "lib/kernel/pantalla.h"
#include "lib/kernel/gdt.h"

#include "stdio.h"
#include "stdlib.h"

int kmain(void) {
    
    instalarGDT();
    
    iniciarPantalla();

    limpiarPantalla();

    pintarPantalla(AZUL);

    setForegroundColor(NEGRO);
    setBackgroundColor(AMARILLO);
    
    printf("cafeOS!");

    for (;;);

    return EXIT_SUCCESS;
}