/**
 * Nombre:    SERIAL.H
 * 
 * Contenido: Funciones respectivas al manejo del dispositivo: Serial.
 * 
 */

#ifndef SERIAL_H
#define SERIAL_H

#include "kernel/io.h"
#include "kernel/dispositivo/dispositivo.h"

#include "stdint.h"

/**
 * Puertos COM
 */
#define PUERTO_COM1 0x3F8
#define PUERTO_COM2 0x2F8
#define PUERTO_COM3 0x3E8
#define PUERTO_COM4 0x2E8

/**
 * Estado de puertos de cada Puerto COM
 * 
 * De acuerdo a la documentacion:
 * 
 * Register map for a given COM port:
 *
 *	+========+======================================================+
 *	| Offset | Description						|
 *	+========+======================================================+
 *	| +0     | Data register. If DLAB is disabled, reading from     |
 *	|        | this register is reading from the RECEIVE buffer and |
 *	|        | writing to it is the same as writing to the TRANSMIT |
 *	|        | buffer. If DLAB is enabled then this will hold the   |
 *	|        | low byte of the baud rate divisor value.             |
 *	+--------+------------------------------------------------------+
 *	| +1     | Interrupt enabling register. If DLAB is enabled,     |
 *	|        | this register will hold the high byte of the baud    |
 *	|        | rate divisor value.                                  |
 *	+--------+------------------------------------------------------+
 *	| +2     | Interrupt identification and buffer / FIFO config.   |
 *	+--------+------------------------------------------------------+
 *	| +3     | Line control register. Configures the line protocol. |
 *	+--------+------------------------------------------------------+
 *	| +4     | Modem control register.                              |
 *	+--------+------------------------------------------------------+
 *	| +5     | Line status register.                                |
 *	+--------+------------------------------------------------------+
 *	| +6     | Modem status register.                               |
 *	+--------+------------------------------------------------------+
 *	| +7     | Scratch register.                                    |
 *	+========+======================================================+
 */
#define SERIAL_PUERTO_DATOS(base)           (base)
#define SERIAL_PUERTO_FIFO(base)            (base + 2)
#define SERIAL_PUERTO_LINEA(base)           (base + 3)
#define SERIAL_PUERTO_MODEM(base)           (base + 4)
#define SERIAL_ESTADO_PUERTO_LINEA(base)    (base + 5)

/**
 * Constante de habilitacion del DLAB (Divisor Latch Access Bit)
 */
#define SERIAL_HABILITAR_DLAB             0x80

/**
 * Estructura del Puerto COM
 */
struct puertoCOM {
    uint16_t com;
    uint16_t divisor;
};


/**
 * Funciones
 */
void inicializarSerial(void);
void escrituraSerial(unsigned char *buffer, unsigned short n);
char lecturaSerial(uint16_t com);

void configurarVelocidadSerial(struct puertoCOM puerto);
void configurarLineaSerial(struct puertoCOM puerto);
void configurarBufferSerial(struct puertoCOM puerto);
void configurarModemSerial(struct puertoCOM puerto);
void configurarPuertoSerial(const struct puertoCOM puerto);

uint32_t escrituraSerialOcupada(uint16_t com);
uint32_t lecturaSerialOcupada(uint16_t com);

#endif /* SERIAL_H */
