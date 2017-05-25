/**
 * LIBRERIA.C
 * 
 * Este archivo contendra las inicializaciones de las funciones
 * de uso general, que puedan ser usadas durante la ejecucion del nucleo.
 * 
 */

#include "libreria.h"

/**
 * Funcion encargada de:
 * 
 * -Limpiar la pantalla
 * 
 * Recorre cada una de las posiciones del puntero de video
 * escribiendo en cada una de ellas el valor 0x00
 * lo cual hara que no aparezca el mensaje posterior al boot.
 *  
 */
void limpiarPantalla(void) {

    char *video = (char*) DIRECCION_VIDEO;
    int i = 0;

    for (i = 0; i < 4000; i++) {
        *video++ = 0x00;
    }

    return;
}
