/**
 * STDLIB.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdlib.h>, salvo que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDLIB_H
#define STDLIB_H

/**
 * Estados de salida
 * 
 * Cabe recordar que generalmente, los estados de salida, suelen ser:
 * 
 * 0 -> Si la ejecucion fue exitosa.
 * 1 -> Si la ejecucion fue fallida.
 * 
 */
#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

#endif /* STDLIB_H */

