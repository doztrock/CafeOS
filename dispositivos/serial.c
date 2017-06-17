#include "serial.h"

/**
 * Registro del dispositivo
 */
static struct dispositivo DISPOSITIVO_SERIAL = {
    .identificador = 0,
    .escritura = escrituraSerial
};

/**
 * Funcion:  inicializarSerial
 * 
 * Objetivo: Registrar un dispositivo en la tabla de dispositivos.
 * 
 * @param informacion Estructura con la informacion del dispositivo.
 * @return            No tiene ningun valor de retorno.
 */
void inicializarSerial(void) {

    /* Puerto COM */
    struct puertoCOM COM1;

    /* Configuramos el Puerto COM */
    configurarPuertoSerial(COM1);

    /* Registramos el dispositivo */
    registrarDispositivo(DISPOSITIVO_SERIAL);

    return;
}

/**
 * Funcion:  escrituraSerial
 * 
 * Objetivo: Registrar un dispositivo en la tabla de dispositivos.
 * 
 * @param informacion Estructura con la informacion del dispositivo.
 * @return            No tiene ningun valor de retorno.
 */
void escrituraSerial(unsigned char *buffer, unsigned short n) {

    uint32_t i = 0;

    /* Verificamos si la escritura hacia el puerto esta ocupada */
    while (escrituraSerialOcupada(PUERTO_COM1) == 0);

    while (i < n) {
        outb(PUERTO_COM1, buffer[i++]);
    }

    return;
}

char lecturaSerial(uint16_t com) {

    /* Verificamos si la lectura del el puerto esta ocupada */
    while (lecturaSerialOcupada(com) == 0);

    return (char) inb(com);
}

void configurarVelocidadSerial(struct puertoCOM puerto) {

    outb(SERIAL_PUERTO_LINEA(puerto.com), SERIAL_HABILITAR_DLAB);
    outb(SERIAL_PUERTO_DATOS(puerto.com), (puerto.divisor >> 8) & 0x00FF);
    outb(SERIAL_PUERTO_DATOS(puerto.com), puerto.divisor & 0x00FF);
    outb(SERIAL_PUERTO_LINEA(puerto.com), 0x00);

    return;
}

void configurarLineaSerial(struct puertoCOM puerto) {
    outb(SERIAL_PUERTO_LINEA(puerto.com), 0x03);
    return;
}

void configurarBufferSerial(struct puertoCOM puerto) {
    outb(SERIAL_PUERTO_FIFO(puerto.com), 0xC7);
    return;
}

void configurarModemSerial(struct puertoCOM puerto) {
    outb(SERIAL_PUERTO_MODEM(puerto.com), 0x03);
    return;
}

void configurarPuertoSerial(const struct puertoCOM puerto) {

    configurarVelocidadSerial(puerto);
    configurarLineaSerial(puerto);
    configurarBufferSerial(puerto);
    configurarModemSerial(puerto);

    return;
}

uint32_t escrituraSerialOcupada(uint16_t com) {
    return inb(SERIAL_ESTADO_PUERTO_LINEA(com)) & 0x20;
}

uint32_t lecturaSerialOcupada(uint16_t com) {
    return inb(SERIAL_ESTADO_PUERTO_LINEA(com)) & 1;
}
