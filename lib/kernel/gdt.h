/**
 * Nombre:    GDT.H
 * 
 * Contenido: Funciones respectivas al manejo de la tabla de descriptores globales (gdt).
 * 
 */

#ifndef GDT_H
#define GDT_H

#include "stddef.h"
#include "stdint.h"
#include "stdbool.h"

/**
 * Entrada GDT
 */
struct GDT_Entrada {
    uint16_t limite_bajo;
    uint16_t base_baja;
    uint8_t base_media;
    uint8_t acceso;
    uint8_t granularidad;
    uint8_t base_alta;
} __attribute__ ((packed));

/**
 * Puntero GDT
 */
struct GDT_Puntero {
    uint16_t limite;
    uint32_t base;
} __attribute__ ((packed));

/**
 * Tabla GDT
 */
struct GDT_Entrada GDT[3];

/**
 * Puntero GDT
 */
struct GDT_Puntero GDTP;


/**
 * Funciones
 */
bool instalarGDT(void);
void limpiarGDT(void);

void setEntradaGDT(int indice, uint32_t base, uint32_t limite, uint8_t acceso, uint8_t granularidad);

#endif /* GDT_H */
