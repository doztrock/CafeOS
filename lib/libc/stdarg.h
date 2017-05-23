/**
 * STDARG.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdarg.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDARG_H
#define STDARG_H

typedef char * va_list;

#define __va_promote(type) \
        (((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define va_start(ap, last) \
        (ap = ((char *)&(last) + __va_promote(last)))

#define va_arg(ap, type) \
        ((type *)(ap += sizeof(type)))[-1]

#define va_end(ap)

#endif /* STDARG_H */
