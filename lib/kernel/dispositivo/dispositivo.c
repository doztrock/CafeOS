#include "dispositivo.h"

/**
 * Funcion:  registrarDispositivo
 * 
 * Objetivo: Registrar un dispositivo en la tabla de dispositivos.
 * 
 * @param informacion Estructura con la informacion del dispositivo.
 * @return            No tiene ningun valor de retorno.
 */
void registrarDispositivo(struct dispositivo dispositivo) {
    TABLA_DISPOSITIVOS[(dispositivo).identificador] = (dispositivo);
    return;
}

/**
 * Funcion:  escrituraDispositivo
 * 
 * Objetivo: Escribir N caracteres de informacion a un dispositivo 
 *           existente en la tabla de dispositivos.
 * 
 * @param identificador Identificador del dispositivo.
 * @param buffer        Contenedor de la informacion a escribir.
 * @param n             Cantidad de caracteres a escribir.
 * @return              No tiene ningun valor de retorno.
 */
void escrituraDispositivo(uint16_t identificador, unsigned char *buffer, uint16_t n) {
    TABLA_DISPOSITIVOS[identificador].escritura(buffer, n);
    return;
}