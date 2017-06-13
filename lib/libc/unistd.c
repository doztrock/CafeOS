#include "unistd.h"

/**
 * Funcion:  sleep
 * 
 * Objetivo: Esperar durante N segundos.
 * 
 * @param segundos Segundos a esperar.
 * @return         Cantidad de segundos faltantes para terminar la espera.
 */
unsigned int sleep(unsigned int segundos) {

    esperarTemporizador(segundos * TICKS_POR_SEGUNDO);

    return 0;
}