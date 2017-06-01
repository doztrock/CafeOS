#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include "io.h"
#include "isr.h"
#include "irq.h"

#include "stdio.h"
#include "stdbool.h"

#define HERTZ_TEMPORIZADOR  50
#define TICKS_POR_SEGUNDO   100


/**
 * Funciones
 */
bool instalarTemporizador(void);
bool configurarTemporizador(int hertz);

void esperarTemporizador(int ticks);

void manejadorTemporizador(struct ISR_Informacion *informacion);

#endif /* TEMPORIZADOR_H */
