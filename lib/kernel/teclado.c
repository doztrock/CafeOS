#include "teclado.h"
#include "teclado/mapa.h"

/**
 * Buffer donde se almacenaran las cadenas obtenidas desde el teclado
 */
char BUFFER_TECLADO[TAMANO_BUFFER_TECLADO];

/**
 * Indice del buffer del teclado.
 */
unsigned int INDICE_BUFFER_TECLADO = 0;

/**
 * Funcion:  instalarTeclado
 * 
 * Objetivo: Inicializar el teclado.

 * @return   TRUE si se inicializo correctamente, FALSE en caso contrario.
 */
bool instalarTeclado(void) {
    instalarManejadorIRQ(1, &manejadorTeclado);
    return true;
}

/**
 * Funcion:  manejadorTeclado
 * 
 * Objetivo: Guardar todos los caracteres obtenidos del teclado, 
 *           guardarlos en el buffer y mostrarlos en la pantalla.
 * 
 * @param informacion Estructura con la informacion recibida de la interrupcion.
 * @return            No tiene ningun valor de retorno.
 */
void manejadorTeclado(struct ISR_Informacion *informacion) {

    unsigned char caracter = obtenerCaracterTeclado();

    if (caracter != 255) {

        putchar(caracter);

        BUFFER_TECLADO[INDICE_BUFFER_TECLADO] = caracter;
        INDICE_BUFFER_TECLADO++;
    }

    return;
}

/**
 * Funcion:  obtenerCaracterTeclado
 * 
 * Objetivo: Leer la direccion E/S del teclado 
 *           y retornar el caracter correspondiente en el mapa del teclado.
 * 
 * @return   Caracter leido del teclado.
 */
unsigned char obtenerCaracterTeclado(void) {

    unsigned char caracter = (unsigned char) inb(DIRECCION_TECLADO);

    if (caracter & TECLA_LIBERADA) {
        return 255;
    } else {
        return MAPA_TECLADO[caracter];
    }

}

/**
 * Funcion:  obtenerCadenaTeclado
 * 
 * Objetivo: Retornar el contenido del buffer del teclado.
 * 
 * @return   Buffer del teclado.
 */
char *obtenerCadenaTeclado(void) {

    while (BUFFER_TECLADO[INDICE_BUFFER_TECLADO - 1] != '\n') {
    }

    INDICE_BUFFER_TECLADO = 0;
    return BUFFER_TECLADO;
}
