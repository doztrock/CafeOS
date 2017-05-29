/**
 * Nombre:    PANICO.H
 * 
 * Contenido: Funciones respectivas al manejo de los mensajes de panico del kernel (kernel panic).
 * 
 */

#ifndef PANICO_H
#define PANICO_H

#include "../pantalla.h"
#include "../pantalla/color.h"

#include "stdio.h"

void mostrarMensajePanico(char *mensaje);

#endif /* PANICO_H */
