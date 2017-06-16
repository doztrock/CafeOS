/**
 * Nombre:    DISPOSITIVO.H
 * 
 * Contenido: Funciones respectivas al manejo de los dispositivos.
 * 
 */

#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include "stdint.h"

/**
 * Cantidad maxima de dispositivos
 */
#define CANTIDAD_MAXIMA_DISPOSITIVOS    64

/**
 * Estructura del dispositivo
 */
struct dispositivo {
    uint16_t identificador;
} __attribute__ ((packed));

/**
 * Tabla de dispositivos
 */
struct dispositivo TABLA_DISPOSITIVOS[CANTIDAD_MAXIMA_DISPOSITIVOS];


/**
 * Funciones
 */
void registrarDispositivo(struct dispositivo dispositivo);


#endif /* DISPOSITIVO_H */
