#include "io.h"

/**
 * Funcion: inb
 * 
 * Objetivo: Obtener lo que se recibe por parte de una direccion E/S.
 * 
 * @param   puerto  Direccion E/S del puerto a revisar.
 * @return          Codigo obtenido del puerto.
 */
static inline uint8_t inb(uint16_t puerto) {

    uint8_t resultado;

    asm volatile ("inb %1, %0"
                : "=a"(resultado)
                : "Nd"(puerto));

    return resultado;
}

/**
 * Funcion: outb
 * 
 * Objetivo: Escribir una instruccion en una direccion E/S.
 * 
 * @param  puerto    Direccion E/S del puerto donde se escribira.
 * @param  valor     Valor a escribir en el puerto especificado.
 * @return           No tiene ningun valor de retorno.
 */
static inline void outb(uint16_t puerto, uint8_t valor) {
    asm volatile ("outb %0, %1" : : "a"(valor), "Nd"(puerto));
}
