#include "panico.h"

/**
 * Funcion:  mostrarMensajePanico
 * 
 * Objetivo: Mostrar un mensaje de panico del kernel (Kernel Panic).
 * 
 * @param limite        Mensaje a mostrar en la pantalla.
 * @return              No tiene ningun valor de retorno.
 */
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
