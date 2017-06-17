#include "gdt.h"

/**
 * Funcion:  instalarGDT
 * 
 * Objetivo: Inicializar la tabla de descriptores globales (gdt).

 * @return   TRUE si se inicializo correctamente, FALSE en caso contrario.
 */
bool instalarGDT(void) {

    GDTP.limite = (sizeof (struct GDT_Entrada) * 3) - 1;
    GDTP.base = (uint32_t) & GDT;

    setEntradaGDT(0, NULL, NULL, NULL, NULL); /* Entrada NULL */
    setEntradaGDT(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* Entrada seccion data -> 4GB */
    setEntradaGDT(2, 0, 0xFFFFFFFF, 0x92, 0xCF); /* Entrada seccion code -> 4GB */

    limpiarGDT();

    return true;
}

/**
 * Funcion:  limpiarGDT
 * 
 * Objetivo: Cargar la tabla de descriptores (gdt) o bien, 
 *           si ya existe alguna, que la sobreescriba.

 * @return   No tiene ningun valor de retorno.
 */
void limpiarGDT(void) {

    asm volatile("lgdtl (GDTP)");
    asm volatile(
                "movw $0x10, %ax \n"
                "movw %ax, %ds \n"
                "movw %ax, %es \n"
                "movw %ax, %fs \n"
                "movw %ax, %gs \n"
                "movw %ax, %ss \n"
                "ljmp $0x08, $next \n"
                "next:          \n"
                );

    return;
}

/**
 * Funcion:  setEntradaGDT
 * 
 * Objetivo: Agregar o bien (colocar) datos en cada una 
 *           de las entradas de la tabla de descriptores.
 * 
 * @param indice        Indice de la entrada a agregar
 * @param base          Parametro base de la entrada
 * @param limite        Parametro limite de la entrada
 * @param acceso        Parametro acceso de la entrada
 * @param granularidad  Parametro granularidad de la entrada
 * @param limite        Parametro limite de la entrada
 * @return              No tiene ningun valor de retorno.
 */
void setEntradaGDT(int indice, uint32_t base, uint32_t limite, uint8_t acceso, uint8_t granularidad) {

    GDT[indice].base_baja = (base & 0xFFFF);
    GDT[indice].base_media = (base >> 16) & 0xFF;
    GDT[indice].base_alta = (base >> 24) & 0xFF;

    GDT[indice].limite_bajo = (limite & 0xFFFF);
    GDT[indice].granularidad = (limite >> 16) & 0x0F;

    GDT[indice].granularidad |= (granularidad & 0xF0);
    GDT[indice].acceso = acceso;

    return;
}
