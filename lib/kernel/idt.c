#include "idt.h"

/**
 * Funcion:  instalarIDT
 * 
 * Objetivo: Inicializar la tabla de descriptores globales (gdt).

 * @return   TRUE si se inicializo correctamente, FALSE en caso contrario.
 */
bool instalarIDT(void) {

    IDTP.limit = (sizeof (struct IDT_Entrada)*256) - 1;
    IDTP.base = (uint32_t) & IDT;

    memset(&IDT, 0, sizeof (struct IDT_Entrada)*256);

    llenarIDT();

    limpiarIDT();

    return true;
}

/**
 * Funcion:  limpiarIDT
 * 
 * Objetivo: Cargar la tabla de descripcion de interrupciones (idt) o bien, 
 *           si ya existe alguna, que la sobreescriba.

 * @return   No tiene ningun valor de retorno.
 */
void limpiarIDT(void) {

    asm volatile("lidtl (IDTP)");

    return;
}

/**
 * Funcion:  setEntradaIDT
 * 
 * Objetivo: Agregar o bien (colocar) datos en cada una 
 *           de las entradas de la tabla de descripcion de interrupciones.
 * 
 * @param indice        Indice de la entrada a agregar
 * @param base          Parametro base de la entrada
 * @param sel           Parametro sel de la entrada
 * @param banderas      Parametro flags de la entrada
 * @return              No tiene ningun valor de retorno.
 */
void setEntradaIDT(int indice, uint32_t base, uint16_t segmento, uint8_t banderas) {

    IDT[indice].base_low = (base & 0xFFFF);
    IDT[indice].base_high = (base >> 16) & 0xFFFF;

    IDT[indice].sel = segmento;
    IDT[indice].always0 = 0;

    IDT[indice].flags = banderas;

    return;
}

/**
 * Funcion:  llenarIDT
 * 
 * Objetivo: Pobla la tabla de descripcion de interrupciones (idt) con todas las interrupciones, 
 *           es decir, esta funcion agregara las 32 interrupciones estandar a la tabla.
 * 
 * @return   No tiene ningun valor de retorno.
 */
void llenarIDT(void) {

    setEntradaIDT(0, (unsigned) ISR0, 0x08, 0x8E);


}