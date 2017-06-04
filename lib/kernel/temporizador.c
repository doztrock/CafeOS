#include "temporizador.h"

/**
 * Contador de ticks
 */
unsigned int TICKS_TEMPORIZADOR = 0;

/**
 * Funcion:  instalarTemporizador
 * 
 * Objetivo: Inicializar el temporizador.

 * @return   TRUE si se inicializo correctamente, FALSE en caso contrario.
 */
bool instalarTemporizador(void) {
    instalarManejadorIRQ(0, &manejadorTemporizador);
    return true;
}

/**
 * Funcion:  configurarTemporizador
 * 
 * Objetivo: Configura los hertz del temporizador.
 * 
 * @param hertz Hertz sobre los que sera configurado el temporizador.
 * @return      TRUE si se configuro correctamente, FALSE en caso contrario.
 */
bool configurarTemporizador(int hertz) {

    int divisor = FRECUENCIA_TEMPORIZADOR / hertz;

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, divisor >> 8);

    return true;
}

/**
 * Funcion:  esperarTemporizador
 * 
 * Objetivo: Esperar a que los ticks del temporizador alcancen los ticks especificados.
 * 
 * @param ticks Cantidad de ticks hasta los que el contador del temporizador debe esperar.
 * @return      No tiene ningun valor de retorno.
 */
void esperarTemporizador(int ticks) {

    unsigned long ticksMaximos = TICKS_TEMPORIZADOR + ticks;

    while (TICKS_TEMPORIZADOR < ticksMaximos) {
    }

    return;
}

/**
 * Funcion:  manejadorTemporizador
 * 
 * Objetivo: Aumentar el contador de ticks del temporizador.
 * 
 * @param informacion Estructura con la informacion recibida de la interrupcion.
 * @return            No tiene ningun valor de retorno.
 */
void manejadorTemporizador(struct ISR_Informacion *informacion) {
    TICKS_TEMPORIZADOR++;
    return;
}
