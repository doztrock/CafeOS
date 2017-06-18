#include "idt.h"

/**
 * Funcion:  instalarIDT
 * 
 * Objetivo: Inicializar la tabla de descripcion de interrupciones (idt).

 * @return   TRUE si se inicializo correctamente, FALSE en caso contrario.
 */
bool instalarIDT(void) {

    IDTP.limite = (sizeof (struct IDT_Entrada) * 256) - 1;
    IDTP.base = (uint32_t) & IDT;

    memset(&IDT, 0, sizeof (struct IDT_Entrada) * 256);

    /* Llenamos la tabla de descripcion de interrupciones */
    setEntradaIDT(0, (uint32_t) ISR1, 0x08, 0x8E);
    setEntradaIDT(1, (uint32_t) ISR2, 0x08, 0x8E);
    setEntradaIDT(2, (uint32_t) ISR3, 0x08, 0x8E);
    setEntradaIDT(3, (uint32_t) ISR4, 0x08, 0x8E);
    setEntradaIDT(4, (uint32_t) ISR5, 0x08, 0x8E);
    setEntradaIDT(5, (uint32_t) ISR6, 0x08, 0x8E);
    setEntradaIDT(6, (uint32_t) ISR7, 0x08, 0x8E);
    setEntradaIDT(7, (uint32_t) ISR8, 0x08, 0x8E);
    setEntradaIDT(8, (uint32_t) ISR9, 0x08, 0x8E);
    setEntradaIDT(9, (uint32_t) ISR10, 0x08, 0x8E);
    setEntradaIDT(10, (uint32_t) ISR11, 0x08, 0x8E);
    setEntradaIDT(11, (uint32_t) ISR12, 0x08, 0x8E);
    setEntradaIDT(12, (uint32_t) ISR13, 0x08, 0x8E);
    setEntradaIDT(13, (uint32_t) ISR14, 0x08, 0x8E);
    setEntradaIDT(14, (uint32_t) ISR15, 0x08, 0x8E);
    setEntradaIDT(15, (uint32_t) ISR16, 0x08, 0x8E);
    setEntradaIDT(16, (uint32_t) ISR17, 0x08, 0x8E);
    setEntradaIDT(17, (uint32_t) ISR18, 0x08, 0x8E);
    setEntradaIDT(18, (uint32_t) ISR19, 0x08, 0x8E);
    setEntradaIDT(19, (uint32_t) ISR20, 0x08, 0x8E);
    setEntradaIDT(20, (uint32_t) ISR21, 0x08, 0x8E);
    setEntradaIDT(21, (uint32_t) ISR22, 0x08, 0x8E);
    setEntradaIDT(22, (uint32_t) ISR23, 0x08, 0x8E);
    setEntradaIDT(23, (uint32_t) ISR24, 0x08, 0x8E);
    setEntradaIDT(24, (uint32_t) ISR25, 0x08, 0x8E);
    setEntradaIDT(25, (uint32_t) ISR26, 0x08, 0x8E);
    setEntradaIDT(26, (uint32_t) ISR27, 0x08, 0x8E);
    setEntradaIDT(27, (uint32_t) ISR28, 0x08, 0x8E);
    setEntradaIDT(28, (uint32_t) ISR29, 0x08, 0x8E);
    setEntradaIDT(29, (uint32_t) ISR30, 0x08, 0x8E);
    setEntradaIDT(30, (uint32_t) ISR31, 0x08, 0x8E);
    setEntradaIDT(31, (uint32_t) ISR32, 0x08, 0x8E);

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
 * @param segmento      Parametro sel de la entrada
 * @param banderas      Parametro flags de la entrada
 * @return              No tiene ningun valor de retorno.
 */
void setEntradaIDT(int indice, uint32_t base, uint16_t segmento, uint8_t banderas) {

    IDT[indice].base_baja = (base & 0xFFFF);
    IDT[indice].base_alta = (base >> 16) & 0xFFFF;

    IDT[indice].segmento = segmento;
    IDT[indice].cero = 0;

    IDT[indice].banderas = banderas;

    return;
}
