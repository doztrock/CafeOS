#include "panico.h"

void mostrarMensajePanico(char *mensaje) {

    pintarPantalla(ROJO);
    moverCursor(0, 0);

    setForegroundColor(BLANCO);
    setBackgroundColor(ROJO);

    printf("Kernel Panic!!!\n");
    printf("Ha ocurrido un error grave en el sistema\n\n");

    printf("Error: ");
    printf(mensaje);

    return;
}
