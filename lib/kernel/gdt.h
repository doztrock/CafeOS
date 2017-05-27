#ifndef GDT_H
#define GDT_H

#include "stdint.h"

/**
 * Entrada GDT
 */
struct GDT_Entrada {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__ ((packed));

/**
 * Puntero GDT
 */
struct GDT_Puntero {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));

/**
 * Tabla GDT
 */
struct GDT_Entrada GDT[3];

/**
 * Tabla de Punteros GDT
 */
struct GDT_Puntero GDPT;

#endif /* GDT_H */
