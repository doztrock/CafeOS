#include "string.h"

/**
 * Funcion:  strcat
 * 
 * Objetivo: Concatenar dos cadenas.
 * 
 * @param  destino  Cadena donde se agregara lo contenido en origen.
 * @param  origen   Cadena contenedora de la informacion a concatenar en destino.
 * @return Puntero hacia la informacion de la cadena de destino.
 */
char *strcat(char *destino, char *origen) {

    while (*destino != NULL) {
        ++destino;
    }

    while (*origen != NULL) {
        *destino++ = *origen++;
    }

    return destino;
}
