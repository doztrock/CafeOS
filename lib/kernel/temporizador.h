/**
 * Nombre:    TEMPORIZADOR.H
 * 
 * Contenido: Funciones y Constantes usadas para el manejo del Timer (Temporizador).
 * 
 * Nota:      La medida del reloj, se realiza a traves de un elemento conocido como "tick",
 *            es decir, los ciclos que ocurren en el temporizador.
 * 
 */

#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include "io.h"
#include "isr.h"
#include "irq.h"

#include "stdio.h"
#include "stdbool.h"

#define HERTZ_TEMPORIZADOR      50
#define TICKS_POR_SEGUNDO       50
#define FRECUENCIA_TEMPORIZADOR 1193180


/**
 * Funciones
 */
bool instalarTemporizador(void);
bool configurarTemporizador(int hertz);

void esperarTemporizador(int ticks);

void manejadorTemporizador(struct ISR_Informacion *informacion);

#endif /* TEMPORIZADOR_H */
