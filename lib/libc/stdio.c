#include "stdio.h"

/**
 * Funcion:  printf
 * 
 * Objetivo: Descripcion PENDIENTE.
 * 
 * @param color Color a usar para pintar la pantalla.
 * @return      No tiene ningun valor de retorno.
 */
int printf(char *formato) {

    unsigned int i;

    for (i = 0; i < strlen(formato); i++) {
        putchar(formato[i]);
    }

    return 0;
}

/**
 * Funcion:  putchar
 * 
 * Objetivo: Descripcion PENDIENTE..
 * 
 * @param color Color a usar para pintar la pantalla.
 * @return      No tiene ningun valor de retorno.
 */
int putchar(int caracter) {

    /* Atributos */
    uint8_t byteAtributo = (backgroundColor << 4) | (foregroundColor & 0x0F);
    uint16_t atributo = byteAtributo << 8;
    uint16_t *ubicacion;

    /* Puntero a la direccion del video */
    uint16_t *video = (uint16_t *) DIRECCION_VIDEO;

    /* Caracter imprimible */
    if (caracter == 0x08 && POSICION_X) {
        POSICION_X--;
    } else if (caracter == '\r') {
        POSICION_X = 0;
    } else if (caracter == '\n') {
        POSICION_X = 0;
        POSICION_Y++;
    }

    if (caracter >= ' ') {
        ubicacion = video + (POSICION_Y * 80 + POSICION_X);
        *ubicacion = caracter | atributo;
        POSICION_X++;
    }

    if (POSICION_X >= 80) {
        POSICION_X = 0;
        POSICION_Y++;
    }

    /* En caso que necesitemos hacer scroll (desplazamiento) */
    byteAtributo = (0 << 4) | (15 & 0x0F);
    uint16_t caracterEspacio = 0x20 | (byteAtributo << 8);

    if (POSICION_Y >= 25) {

        int i;

        for (i = 0; i < 80 * 24; i++) {
            video[i] = video[i + 80];
        }

        for (i = 80 * 24; i < 80 * 25; i++) {
            video[i] = caracterEspacio;
        }

        POSICION_Y = 24;
    }

    actualizarCursor();
    return caracter;
}
