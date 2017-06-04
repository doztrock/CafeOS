/**
 * Nombre:    TECLADO.H
 * 
 * Contenido: Funciones y Constantes usadas para el manejo del Teclado.
 * 
 */

#ifndef TECLADO_H
#define TECLADO_H

#include "kernel.h"
#include "io.h"
#include "isr.h"
#include "irq.h"

#include "stdio.h"
#include "stdbool.h"

#define TECLA_LIBERADA          0x80
#define TAMANO_BUFFER_TECLADO   1024


/**
 * Funciones
 */
bool instalarTeclado(void);
void manejadorTeclado(struct ISR_Informacion *informacion);

unsigned char obtenerCaracterTeclado(void);
char *obtenerCadenaTeclado(void);

#endif /* TECLADO_H */
