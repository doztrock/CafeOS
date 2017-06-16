/**
 * Nombre:    IO.H
 * 
 * Contenido: Funciones embebidas en assembler, que permitiran la interaccion
 *            con las diferentes Direcciones E/S (IO adresses).
 * 
 */

#ifndef IO_H
#define IO_H

#include "stdint.h"


/**
 * Funciones
 */
uint8_t inb(uint16_t puerto);
void outb(uint16_t puerto, uint8_t valor);

#endif /* IO_H */
