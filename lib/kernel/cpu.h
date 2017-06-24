/**
 * Nombre:    CPU.H
 * 
 * Contenido: Funciones para determinar el tipo de CPU.
 * 
 */

#ifndef CPU_H
#define CPU_H

#include "stdint.h"

/**
 * CPUID
 */
#define CPUID(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

/**
 * Procesadores
 */
#define PROCESADOR_INTEL    0x756e6547
#define PROCESADOR_AMD      0x68747541

/**
 * Tipo de CPU
 */
typedef enum __tipo_cpu {
    INTEL, AMD, DESCONOCIDO
} TipoCPU;


/**
 * Funciones
 */
TipoCPU obtenerTipoCPU(void);

#endif /* CPU_H */
