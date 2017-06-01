#include "teclado.h"
#include "teclado/mapa.h"

char BUFFER_TECLADO[TAMANO_BUFFER_TECLADO];
unsigned int INDICE_BUFFER_TECLADO = 0;

bool instalarTeclado(void) {
    instalarManejadorIRQ(1, &manejadorTeclado);
    return true;
}

void manejadorTeclado(struct ISR_Informacion *informacion) {

    unsigned char caracter = obtenerCaracterTeclado();

    if (caracter != 255) {

        putchar(caracter);

        BUFFER_TECLADO[INDICE_BUFFER_TECLADO] = caracter;
        INDICE_BUFFER_TECLADO++;
    }

    return;
}

unsigned char obtenerCaracterTeclado(void) {

    unsigned char caracter = (unsigned char) inb(DIRECCION_TECLADO);

    if (caracter & TECLA_LIBERADA) {
        return 255;
    } else {
        return MAPA_TECLADO[caracter];
    }

}

char *obtenerCadenaTeclado(void) {

    while (BUFFER_TECLADO[INDICE_BUFFER_TECLADO - 1] != '\n') {

    }

    INDICE_BUFFER_TECLADO = 0;
    return BUFFER_TECLADO;
}

