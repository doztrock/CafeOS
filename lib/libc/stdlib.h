/**
 * STDLIB.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdlib.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDLIB_H
#define STDLIB_H

/**
 * Estados de salida
 */

/* Ejecucion Exitosa */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS    0
#endif

/* Ejecucion Fallida */
#ifndef EXIT_FAILURE
#define EXIT_FAILURE    1
#endif

#endif /* STDLIB_H */
