/**
 * Nombre:    IDT.H
 * 
 * Contenido: Funciones respectivas al manejo de la tabla de descripcion de interruptores (idt).
 * 
 */

#ifndef IDT_H
#define IDT_H

#include "isr.h"

#include "string.h"
#include "stdint.h"
#include "stdbool.h"

/**
 * Entrada IDT
 */
struct IDT_Entrada {
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__ ((packed));

/**
 * Puntero IDT
 */
struct IDT_Puntero {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));

/**
 * Tabla IDT
 */
struct IDT_Entrada IDT[256];

/**
 * Puntero IDT
 */
struct IDT_Puntero IDTP;


/**
 * Funciones
 */
bool instalarIDT(void);
void limpiarIDT(void);

void setEntradaIDT(int indice, uint32_t base, uint16_t segmento, uint8_t banderas);

#endif /* IDT_H */
