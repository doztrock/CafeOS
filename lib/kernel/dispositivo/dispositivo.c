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
