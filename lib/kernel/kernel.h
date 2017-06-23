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
 * Nombre del Software
 */
#define SOFTWARE_NOMBRE     "cafeOS"

/**
 * Version del Software
 */
#define SOFTWARE_VERSION    "0.0.1"


/**
 * Direccion I/O del video
 */
#define DIRECCION_VIDEO     0x000B8000

/**
 * Direccion I/O del teclado
 */
#define DIRECCION_TECLADO   0x60

/**
 * Macro manejador de variables que no seran usadas
 * PENDIENTE MOVER
 */
#define SIN_USAR(variable)  (void)(variable)


#endif /* KERNEL_H */
