
#ifndef IRQ_H
#define IRQ_H

#include "io.h"
#include "idt.h"

#include "stdint.h"
#include "stdbool.h"

/**
 * PIC Usados para remapear la tabla de IRQ
 */
#define PIC1 0x20
#define PIC2 0xA0

/**
 * ICW Usados para remapear la tabla de IRQ
 */
#define ICW1 0x11
#define ICW4 0x01


/**
 * Funciones
 */
bool instalarIRQ(void);
void remapearIRQ(int pic1, int pic2);

void IRQManejador(struct ISR_Informacion *informacion);

void IRQComun(void);

void IRQ1(void);
void IRQ2(void);

#endif /* IRQ_H */
