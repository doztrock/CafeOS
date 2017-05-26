#include "pantalla.h"

/**
 * Funcion:  iniciarPantalla
 * 
 * Objetivo: Inicializar los valores de las coordenadas del cursor del video,
 *                es decir, dar los valores a X & Y, para poder trabajar con estos posteriormente.
 * 
 *           Inicializar los colores de los lados de la pantalla, es decir, el color de fondo
 *                y el color del primer plano.        
 * 
 * @return   No tiene ningun valor de retorno.
 */
void iniciarPantalla(void) {

    /* Coordenadas del cursor */
    POSICION_X = 0;
    POSICION_Y = 0;

    /* Colores de los lados */
    backgroundColor = NEGRO;
    foregroundColor = BLANCO;

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

void pintarPantalla(Color color) {

    uint16_t  *video = (uint16_t *) DIRECCION_VIDEO;
    int atributo = (color << 4) | (foregroundColor & 0x0F);
    int blank = 0x20 | (atributo << 8);
    int i = 0;

    for (i = 0; i < 80 * 25; i++) {
        video[i] = blank;
    }

    actualizarCursor();

    return;
}

void actualizarCursor(void) {

    uint16_t posicionCursor = POSICION_Y * 80 + POSICION_X;

    outb(0x3D4, 14);
    outb(0x3D5, posicionCursor >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, posicionCursor);

}

void testPanic(void) {

    limpiarPantalla();
    pintarPantalla(ROJO);
    actualizarCursor();

}
