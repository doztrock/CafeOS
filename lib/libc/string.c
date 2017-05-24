#include "string.h"

/**
 * Funcion:  strcat
 * 
 * Objetivo: Concatenar el contenido de una cadena al final de otra.
 * 
 * @param  destino  Cadena donde se agregara lo contenido en origen.
 * @param  origen   Cadena contenedora de la informacion a concatenar en destino.
 * @return          Puntero hacia la informacion de la cadena de destino.
 */
char *strcat(char *destino, char *origen) {

    strcpy(&destino[strlen(destino)], origen);

    return destino;
}

/**
 * Funcion:  strcpy
 * 
 * Objetivo: Copiar el contenido de una cadena a otra.
 * 
 * @param   destino Cadena a la que se copiara el contenido de origen.
 * @param   origen  Cadena contenedora de la informacion a copiar en destino.
 * @return          Puntero hacia la informacion de la cadena de destino.
 */
char *strcpy(char *destino, const char *origen) {

    char *puntero = destino;

    while ((*puntero++ = *origen++) != NULL);

    return destino;
}

/**
 * Funcion:  strcmp
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
int strcmp(const char *cadena1, const char *cadena2) {

    for (; *cadena1 == *cadena2; cadena1++, cadena2++) {

        if (*cadena1 == '\0') {
            return 0;
        }

    }

    return ((*(unsigned char *) cadena1 < *(unsigned char *) cadena2) ? -1 : +1);
}

/**
 * Funcion:  strlen
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
size_t strlen(const char *cadena) {

    size_t longitud = 0;
    register const char *copia;

    for (copia = cadena; *copia; ++copia);

    longitud = (copia - cadena);

    return longitud;
}