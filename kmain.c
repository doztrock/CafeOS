#include "lib/kernel/kernel.h"
#include "lib/kernel/pantalla.h"
#include "lib/libreria.h"

#include "stdlib.h"

int kmain(void) {

    /* Limpiamos la pantalla */
    limpiarPantalla();

    char *fb = (char *) 0x000B8000;

    *fb++ = 'c';
    *fb++ = 0x07;

    *fb++ = 'a';
    *fb++ = 0x07;

    *fb++ = 'f';
    *fb++ = 0x07;

    *fb++ = 'e';
    *fb++ = 0x07;

    *fb++ = 'O';
    *fb++ = 0x07;

    *fb++ = 'S';
    *fb++ = 0x07;

    return EXIT_SUCCESS;
}