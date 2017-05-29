#include "idt.h"

/**
 * Funcion:  instalarIDT
 * 
 * Objetivo: Inicializar la tabla de descripcion de interrupciones (idt).

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
    setEntradaIDT(1, (unsigned) ISR1, 0x08, 0x8E);
    setEntradaIDT(2, (unsigned) ISR2, 0x08, 0x8E);
    setEntradaIDT(3, (unsigned) ISR3, 0x08, 0x8E);
    setEntradaIDT(4, (unsigned) ISR4, 0x08, 0x8E);
    setEntradaIDT(5, (unsigned) ISR5, 0x08, 0x8E);
    setEntradaIDT(6, (unsigned) ISR6, 0x08, 0x8E);
    setEntradaIDT(7, (unsigned) ISR7, 0x08, 0x8E);
    setEntradaIDT(8, (unsigned) ISR8, 0x08, 0x8E);
    setEntradaIDT(9, (unsigned) ISR9, 0x08, 0x8E);
    setEntradaIDT(10, (unsigned) ISR10, 0x08, 0x8E);
    setEntradaIDT(11, (unsigned) ISR11, 0x08, 0x8E);
    setEntradaIDT(12, (unsigned) ISR12, 0x08, 0x8E);
    setEntradaIDT(13, (unsigned) ISR13, 0x08, 0x8E);
    setEntradaIDT(14, (unsigned) ISR14, 0x08, 0x8E);
    setEntradaIDT(15, (unsigned) ISR15, 0x08, 0x8E);
    setEntradaIDT(16, (unsigned) ISR16, 0x08, 0x8E);
    setEntradaIDT(17, (unsigned) ISR17, 0x08, 0x8E);
    setEntradaIDT(18, (unsigned) ISR18, 0x08, 0x8E);
    setEntradaIDT(19, (unsigned) ISR19, 0x08, 0x8E);
    setEntradaIDT(20, (unsigned) ISR20, 0x08, 0x8E);
    setEntradaIDT(21, (unsigned) ISR21, 0x08, 0x8E);
    setEntradaIDT(22, (unsigned) ISR22, 0x08, 0x8E);
    setEntradaIDT(23, (unsigned) ISR23, 0x08, 0x8E);
    setEntradaIDT(24, (unsigned) ISR24, 0x08, 0x8E);
    setEntradaIDT(25, (unsigned) ISR25, 0x08, 0x8E);
    setEntradaIDT(26, (unsigned) ISR26, 0x08, 0x8E);
    setEntradaIDT(27, (unsigned) ISR27, 0x08, 0x8E);
    setEntradaIDT(28, (unsigned) ISR28, 0x08, 0x8E);
    setEntradaIDT(29, (unsigned) ISR29, 0x08, 0x8E);
    setEntradaIDT(30, (unsigned) ISR30, 0x08, 0x8E);
    setEntradaIDT(31, (unsigned) ISR31, 0x08, 0x8E);

    return;
}