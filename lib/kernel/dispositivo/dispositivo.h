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
 * Prototipo de funcion para escritura en dispositivo
 */
typedef void (* _escritura) (unsigned char *, unsigned short);

/**
 * Estructura del dispositivo
 */
struct dispositivo {
    uint16_t identificador;
    _escritura escritura;
} __attribute__ ((packed));

/**
 * Tabla de dispositivos
 */
struct dispositivo TABLA_DISPOSITIVOS[CANTIDAD_MAXIMA_DISPOSITIVOS];


/**
 * Funciones
 */
void registrarDispositivo(struct dispositivo dispositivo);
void escrituraDispositivo(uint16_t identificador, unsigned char *buffer, uint16_t n);

#endif /* DISPOSITIVO_H */
