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
 * Colores de los lados de la pantalla
 */
Color backgroundColor;
Color foregroundColor;


/**
 * Funciones
 */
void iniciarPantalla(void);
void limpiarPantalla(void);

void pintarPantalla(Color color);

void moverCursor(uint8_t X, uint8_t Y);
void actualizarCursor(void);

void setBackgroundColor(Color color);
void setForegroundColor(Color color);

Color getBackgroundColor(void);
Color getForegroundColor(void);

#endif /* PANTALLA_H */
