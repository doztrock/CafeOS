/**
 * STDBOOL.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdbool.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDBOOL_H
#define STDBOOL_H

/**
 * Definimos los valores booleanos (TRUE y FALSE)
 */
typedef enum {
    false, true
} bool;

#endif /* STDBOOL_H */
