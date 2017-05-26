/**
 * Nombre:    PANTALLA.H
 * 
 * Contenido: Constantes y funciones que se utilizaran para manejar la pantalla.
 *            Mover el cursor del video y escribir cadenas.
 * 
 */

#ifndef PANTALLA_H
#define PANTALLA_H

#include "kernel.h"
#include "io.h"
#include "pantalla/color.h"

#include "stdint.h"

/**
 * Posiciones del cursor    (kernel.h)
 */
extern unsigned int POSICION_X;
extern unsigned int POSICION_Y;


/**
 * Funciones
 */
void iniciarPantalla(void);
void limpiarPantalla(void);

void pintarPantalla(Color color);

void actualizarCursor(void);

#endif /* PANTALLA_H */
