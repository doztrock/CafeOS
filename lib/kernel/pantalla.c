#include "pantalla.h"

/**
 * Funcion:  iniciarPantalla
 * 
 * Objetivo: Inicializar los valores de las coordenadas del cursor del video,
 *           es decir, dar los valores a X & Y, para poder trabajar con estos posteriormente.
 * 
 * @return   No tiene ningun valor de retorno.
 */
void iniciarPantalla(void) {

    POSICION_X = 0;
    POSICION_Y = 0;

    return;
}

/**
 * Funcion:  limpiarPantalla
 * 
 * Objetivo: Limpiar todas las coordenadas contenidas en la pantalla.
 * 
 * @return   No tiene ningun valor de retorno.
 */
void limpiarPantalla(void) {

    char *video = (char*) DIRECCION_VIDEO;
    int i = 0;

    for (i = 0; i < 80 * 25; i++) {
        *video++ = 0x00;
    }

    return;
}