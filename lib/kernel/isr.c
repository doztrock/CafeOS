#include "isr.h"

/**
 * Funcion:  ISRManejador
 * 
 * Objetivo: Manejar la interrupcion recibida.
 * 
 * @param informacion Estructura con la informacion recibida de la interrupcion.
 * @return            No tiene ningun valor de retorno.
 */
void ISRManejador(struct ISR_Informacion *informacion) {

    if (informacion->int_no < 32) {
        mostrarMensajePanico(obtenerMensajeISR(informacion->int_no));
    } else {
        mostrarMensajePanico("Desconocido");
    }

    for (;;);

    return;
}

/**
 * Funcion:  obtenerMensajeISR
 * 
 * Objetivo: Devolver el texto correspondiente a la interrupcion, basado en el indice.

 * @return   Mensaje correspondiente a la interrupcion.
 */
char *obtenerMensajeISR(int indice) {

    char *mensajeISR[] = {
        "Division by zero",
        "Debug exception",
        "Non maskable interrupt exception",
        "Breakpoint exception",
        "Into detected overflow exception",
        "Out of bounds exception",
        "Invalid opcode",
        "No coprocessor exception",
        "Double fault exception",
        "Coprocessor segment overrun exception",
        "Bad TSS exception",
        "Segment not present exception",
        "Stack fault exception",
        "General protection fault exception",
        "Page fault exception",
        "Unknown interrupt exception",
        "Coprocessor fault exception",
        "Alignment check exception",
        "Machine check exception",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved"
    };

    return mensajeISR[indice];
}

/**
 * Funcion:  ISRComun
 * 
 * Objetivo: Ser "puente" entre la informacion de la interrupcion y la funcion ISRManejador, 
 *           es decir cuando se ejecute la funcion de la interrupcion, 
 *           esta funcion enviara los datos respectivos a ISRManejador.

 * @return   No tiene ningun valor de retorno.
 */
void ISRComun(void) {

    asm volatile(
                "popl %ebp	   \n"
                "pushal	   \n"
                "pushl	%ds\n"
                "pushl	%es\n"
                "pushl	%fs\n"
                "pushl	%gs\n"
                "movw $0x10, %ax \n"
                "movw %ax, %ds \n"
                "movw %ax, %es \n"
                "movw %ax, %fs \n"
                "movw %ax, %gs \n"
                "pushl %esp \n"
                "movl $ISRManejador, %eax \n"
                "call *%eax \n"
                "popl %esp \n"
                "popl %gs \n"
                "popl %fs \n"
                "popl %es \n"
                "popl %ds \n"
                "popal    \n"
                "add $0x8, %esp \n"
                "sti	\n"
                "iret \n"
                );

    return;
}

/**
 * De aqui en adelante se encuentran las funciones que "atraparan" cada una de las interrupciones.
 */

void ISR1(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x00\n"
                "jmp ISRComun \n"
                );
}

void ISR2(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x01 \n"
                "jmp ISRComun \n"
                );
}

void ISR3(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x02 \n"
                "jmp ISRComun \n"
                );
}

void ISR4(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x03 \n"
                "jmp ISRComun \n"
                );
}

void ISR5(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x04 \n"
                "jmp ISRComun \n"
                );
}

void ISR6(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x05 \n"
                "jmp ISRComun \n"
                );
}

void ISR7(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x06 \n"
                "jmp ISRComun \n"
                );
}

void ISR8(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x07 \n"
                "jmp ISRComun \n"
                );
}

void ISR9(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x08 \n"
                "jmp ISRComun \n"
                );
}

void ISR10(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x09 \n"
                "jmp ISRComun \n"
                );
}

void ISR11(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x0A \n"
                "jmp ISRComun \n"
                );
}

void ISR12(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x0B \n"
                "jmp ISRComun \n"
                );
}

void ISR13(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x0C \n"
                "jmp ISRComun \n"
                );
}

void ISR14(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x0D \n"
                "jmp ISRComun \n"
                );
}

void ISR15(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x0E \n"
                "jmp ISRComun \n"
                );
}

void ISR16(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x0F \n"
                "jmp ISRComun \n"
                );
}

void ISR17(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x10 \n"
                "jmp ISRComun \n"
                );
}

void ISR18(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x11 \n"
                "jmp ISRComun \n"
                );
}

void ISR19(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x12 \n"
                "jmp ISRComun \n"
                );
}

void ISR20(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x13 \n"
                "jmp ISRComun \n"
                );
}

void ISR21(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x14 \n"
                "jmp ISRComun \n"
                );
}

void ISR22(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x15 \n"
                "jmp ISRComun \n"
                );
}

void ISR23(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x16 \n"
                "jmp ISRComun \n"
                );
}

void ISR24(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x17 \n"
                "jmp ISRComun \n"
                );
}

void ISR25(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x18 \n"
                "jmp ISRComun \n"
                );
}

void ISR26(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x19 \n"
                "jmp ISRComun \n"
                );
}

void ISR27(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1A \n"
                "jmp ISRComun \n"
                );
}

void ISR28(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1B \n"
                "jmp ISRComun \n"
                );
}

void ISR29(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1C \n"
                "jmp ISRComun \n"
                );
}

void ISR30(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1D \n"
                "jmp ISRComun \n"
                );
}

void ISR31(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1E \n"
                "jmp ISRComun \n"
                );
}

void ISR32(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli \n"
                "pushl $0x00 \n"
                "pushl $0x1F \n"
                "jmp ISRComun \n"
                );
}