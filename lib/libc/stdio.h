/**
 * STDIO.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdio.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDIO_H
#define STDIO_H

#include "kernel/kernel.h"
#include "stdarg.h"

int printf(const char *formato, ...);
int sprintf(char *str, const char *format, ...);

int scanf(const char *format, ...);

int putchar(int char);

#endif /* STDIO_H */
