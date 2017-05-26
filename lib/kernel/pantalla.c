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
    setBackgroundColor(NEGRO);
    setForegroundColor(BLANCO);

    return;
}

/**
 * Funcion:  setBackgroundColor
 * 
 * Objetivo: Asigna el color que se usara para el lado de la pantalla -> Fondo (Background)
 * 
 * @param color Color a asignar.
 * @return      No tiene ningun valor de retorno.
 */
void setBackgroundColor(Color color) {
    backgroundColor = color;
    return;
}

/**
 * Funcion:  setForegroundColor
 * 
 * Objetivo: Asigna el color que se usara para el lado de la pantalla -> Primer Plano (Foreground)
 * 
 * @param color Color a asignar.
 * @return      No tiene ningun valor de retorno.
 */
void setForegroundColor(Color color) {
    foregroundColor = color;
    return;
}

/**
 * Funcion:  getBackgroundColor
 * 
 * Objetivo: Devuelve el color que se usa para el lado de la pantalla -> Fondo (Background)
 * 
 * @return   Color usado de Fondo.
 */
Color getBackgroundColor(void) {
    return backgroundColor;
}

/**
 * Funcion:  getForegroundColor
 * 
 * Objetivo: Devuelve el color que se usa para el lado de la pantalla -> Primer Plano (Foreground)
 * 
 * @return   Color usado de Primer Plano.
 */
Color getForegroundColor(void) {
    return foregroundColor;
}

/**
 * Funcion:  limpiarPantalla
 * 
 * Objetivo: Limpiar todas las coordenadas contenidas en la pantalla.
 * 
 * @return   No tiene ningun valor de retorno.
 */
void limpiarPantalla(void) {

    /* Puntero a la direccion del video */
    uint16_t *video = (uint16_t *) DIRECCION_VIDEO;
    int i = 0;

    for (i = 0; i < 80 * 25; i++) {
        video[i] = 0x00;
    }

    return;
}

/**
 * Funcion:  pintarPantalla
 * 
 * Objetivo: Pinta todas las coordenadas contenidas en la pantalla.
 * 
 * @param color Color a usar para pintar la pantalla.
 * @return      No tiene ningun valor de retorno.
 */
void pintarPantalla(Color color) {

    /* Elemento con el que se pintara la pantalla */
    int atributo = (color << 4) | (15 & 0x0F);
    int elemento = 0x20 | (atributo << 8);

    /* Puntero a la direccion del video */
    uint16_t *video = (uint16_t *) DIRECCION_VIDEO;
    int i = 0;

    for (i = 0; i < 80 * 25; i++) {
        video[i] = elemento;
    }

    /* Devolvemos el cursor la posicion inicial */
    moverCursor(0, 0);

    return;
}

/**
 * Funcion:  moverCursor
 * 
 * Objetivo: Desplaza la posicion del cursor a traves de coordenadas.
 * 
 * @return   No tiene ningun valor de retorno.
 */
void moverCursor(uint8_t X, uint8_t Y) {

    /* Asignamos las coordenadas */
    POSICION_X = X;
    POSICION_Y = Y;

    /* Actualizamos el cursor */
    actualizarCursor();

    return;
}

/**
 * Funcion:  actualizarCursor
 * 
 * Objetivo: Actualiza la posicion del cursor usando los registros VGA
 * 
 * @return   No tiene ningun valor de retorno.
 */
void actualizarCursor(void) {

    uint16_t posicionCursor = POSICION_Y * 80 + POSICION_X;

    outb(0x3D4, 14);
    outb(0x3D5, posicionCursor >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, posicionCursor);

    return;
}
