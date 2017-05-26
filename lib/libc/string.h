/**
 * STRING.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <string.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STRING_H
#define STRING_H

#include "stddef.h"

void *memcpy(void *destino, const void *origen, size_t n);
void *memset(void *cadena, int caracter, size_t n);
int memcmp(const void *cadena1, const void *cadena2, size_t n);
char *strcat(char *destino, char *origen);
char *strcpy(char *destino, const char *origen);
int strcmp(const char *cadena1, const char *cadena2);
size_t strlen(const char *cadena);

#endif /* STRING_H */
