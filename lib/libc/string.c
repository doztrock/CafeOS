#include "string.h"

/**
 * Funcion:  memcpy
 * 
 * Objetivo: Copia N caracteres de una cadena a otra.
 * 
 * @param  destino  Cadena donde se agregaran los N caracteres de lo contenido en origen.
 * @param  origen   Cadena contenedora de la informacion a concatenar en la cadena de destino.
 * @param  n        Cantidad de caracteres a copiar.
 * @return          Puntero hacia la informacion de la cadena de destino.
 */
void *memcpy(void* destino, const void* origen, size_t n) {

    const unsigned char *punteroOrigen = (const unsigned char *) origen;
    unsigned char *punteroDestino = (unsigned char *) destino;

    for (; n != 0; n--) *punteroDestino++ = *punteroOrigen++;

    return destino;
}

/**
 * Funcion:  memset
 * 
 * Objetivo: Copia un caracter en los primeros N espacios de una cadena.
 * 
 * @param  cadena   Cadena donde se agregara el caracter al inicio.
 * @param  caracter Caracter que sera reemplazado N veces al principio de la cadena.
 * @param  n        Cantidad de veces a reemplazar el caracter al inicio de la cadena.
 * @return          Puntero hacia la informacion de la cadena.
 */
void *memset(void *cadena, int caracter, size_t n) {

    unsigned char *punteroTemporal = (unsigned char*) cadena;

    while (n--) {
        *punteroTemporal++ = caracter;
    }

    return punteroTemporal;
}

/**
 * Funcion:  memcmp
 * 
 * Objetivo: Comparar los primeros N caracteres de dos cadenas.
 * 
 * @param  cadena1  Cadena a comparar respecto a la segunda cadena.
 * @param  cadena2  Cadena sobre la que se comparara la primera cadena.
 * @param  n        Cantidad de caracteres a comparar de cada cadena.
 * @return          < 0 Si cadena1 es menor que cadena2
 *                  > 0 Si cadena1 es mayor que cadena2
 *                  = 0 Si ambas cadenas son iguales. 
 */
int memcmp(const void* cadena1, const void* cadena2, size_t n) {

    const char* primeraCadena = (const char *) cadena1;
    const char* segundaCadena = (const char *) cadena2;
    size_t indice = 0;

    for (; indice < n; indice++) {

        if (primeraCadena[indice] < segundaCadena[indice]) {
            return -1;
        } else if (primeraCadena[indice] > segundaCadena[indice]) {
            return 1;
        }

    }

    return 0;
}

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
 * Objetivo: Comparar el contenido de dos cadenas.
 * 
 * @param  cadena1  Cadena a comparar respecto a la segunda cadena.
 * @param  cadena2  Cadena sobre la que se comparara la primera cadena.
 * @return          < 0 Si cadena1 es menor que cadena2
 *                  > 0 Si cadena1 es mayor que cadena2
 *                  = 0 Si ambas cadenas son iguales. 
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