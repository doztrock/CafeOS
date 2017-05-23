/**
 * STDDEF.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stddef.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDDEF_H
#define STDDEF_H

/**
 * Definiciones
 */

/* Definicion: NULL */
#ifndef NULL
#define NULL    0
#endif

/* Definicion: size_t */
#ifndef __SIZE_TYPE_
#define __SIZE_TYPE_ long unsigned int
typedef __SIZE_TYPE_ size_t;
#endif

#endif /* STDDEF_H */
