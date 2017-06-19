#include "stdio.h"

/**
 * Funcion:  printf
 * 
 * Objetivo: Escribir un texto en la salida estandar.
 * 
 * @param formato Texto a imprimir en la pantalla.
 * @return        Cantidad de caracteres escritos.
 */
int printf(const char *formato) {

    unsigned int i;

    for (i = 0; i < strlen(formato); i++) {
        putchar(formato[i]);
    }

    return i;
}

/**
 * Funcion:  putchar
 * 
 * Objetivo: Escribe un caracter en la pantalla.
 * 
 * @param caracter Caracter a escribir.
 * @return         Caracter escrito convertido a unsigned char.
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
    byteAtributo = (backgroundColor << 4) | (foregroundColor & 0x0F);
    uint16_t caracterEspacio = 0x20 | (byteAtributo << 8);

    if (POSICION_Y >= 25) {

        /* Almacenamos la primera fila */
        struct FilaPantalla primeraFila = obtenerPrimeraFila();
        almacenarFilaBufferDesplazamiento(primeraFila, SUPERIOR);

        int i;

        for (i = 0; i < 80 * 24; i++) {
            video[i] = video[i + 80];
        }

        for (i = 80 * 24; i < 80 * 25; i++) {
            video[i] = caracterEspacio;
        }

        if (INDICE_BUFFER_DESPLAZAMIENTO_SUPERIOR == 5) {
            desplazarPantalla(1, SUPERIOR);
        }

        POSICION_Y = 24;
    }

    actualizarCursor();
    return (unsigned char) caracter;
}
