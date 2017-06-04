/**
 * Nombre:    IRQ.H
 * 
 * Contenido: Funciones respectivas al manejo de las interrupciones, 
 *            en este caso de las IRQ (Interrupt ReQuest), 
 *            las cuales son generadas por los dispositivos.
 * 
 */

#ifndef IRQ_H
#define IRQ_H

#include "io.h"
#include "idt.h"
#include "isr.h"

#include "stddef.h"
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

void instalarManejadorIRQ(int indice, void (*manejador)(struct ISR_Informacion *informacion));
void desinstalarManejadorIRQ(int indice);

void IRQManejador(struct ISR_Informacion *informacion);

void IRQComun(void);

void IRQ1(void);
void IRQ2(void);
void IRQ3(void);
void IRQ4(void);
void IRQ5(void);
void IRQ6(void);
void IRQ7(void);
void IRQ8(void);
void IRQ9(void);
void IRQ10(void);
void IRQ11(void);
void IRQ12(void);
void IRQ13(void);
void IRQ14(void);
void IRQ15(void);
void IRQ16(void);

#endif /* IRQ_H */
