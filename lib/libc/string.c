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

/**
 * Funcion:  strncat
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
char *strncat(char *dest, const char *src, size_t n){
    return NULL;
}

/**
 * Funcion:  strcpy
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
char *strcpy(char *destino, const char *origen){
    return NULL;
}

/**
 * Funcion:  strncpy
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
char *strncpy(char *dest, const char *src, size_t n){
    return NULL;
}

/**
 * Funcion:  strcmp
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
int strcmp(const char *cadena1, const char *cadena2){
    return 0;
}

/**
 * Funcion:  strncmp
 * 
 * Objetivo: Determinar longitud de una cadena.
 * 
 * @param cadena Cadena a la que se le determinara la longitud.
 * @return Longitud de la cadena indicada.
 */
int strncmp(const char *str1, const char *str2, size_t n){
    return 0;
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