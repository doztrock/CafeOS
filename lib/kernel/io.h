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

static inline uint8_t inb(uint16_t puerto);
static inline void outb(uint16_t puerto, uint8_t valor);

#endif /* IO_H */
