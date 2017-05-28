#include "lib/kernel/pantalla.h"
#include "lib/kernel/gdt.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int kmain(void) {

    /**
     * Color por defecto para el texto.
     */
    Color colorDefecto = NEGRO;


    /**
     * Pantalla
     */
    iniciarPantalla();
    limpiarPantalla();

    pintarPantalla(BLANCO);

    setForegroundColor(colorDefecto);
    setBackgroundColor(BLANCO);

    printf("Bienvenido a cafeOS!\n");


    /**
     * GDT
     */
    printf("Instalando GDT...");

    if (instalarGDT()) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);


    for (;;);

    return EXIT_SUCCESS;
}