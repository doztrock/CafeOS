/**
 * Nombre:    KERNEL.H
 * 
 * Contenido: Constantes que se podran usar durante la ejecucion del nucleo
 *            se guardaran en este archivo con proposito de centralizar la informacion.
 * 
 */

#ifndef KERNEL_H
#define KERNEL_H

/**
 * Direccion del video
 */
#define DIRECCION_VIDEO   0x000B8000

/**
 * Posiciones del cursor
 */
unsigned int POSICION_X;
unsigned int POSICION_Y;

#endif /* KERNEL_H */
