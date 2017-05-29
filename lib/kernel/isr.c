#include "isr.h"

void ISRManejador(struct ISR_Informacion *informacion) {

}

void ISRComun(void) {

    asm volatile(
                "pusha \n"
                "push %ds \n"
                "push %es \n"
                "push %fs \n"
                "push %gs \n"
                "movw $0x10, %ax \n"
                "movw %ax, %ds \n"
                "movw %ax, %es \n"
                "movw %ax, %fs \n"
                "movw %ax, %gs \n"
                "movl %esp, %eax \n"
                "push %eax \n"
                "movl $ISRManejador, %eax \n"
                "call *%eax \n"
                "popl %eax \n"
                "popl %ds \n"
                "popl %es \n"
                "popl %fs \n"
                "popl %gs \n"
                "popa \n"
                "addl 8, %esp \n"
                "iret \n"
                );

    return;
}

void ISR0(void) {

    asm volatile(
                "cli \n"
                "pushl 0 \n"
                "pushl 0 \n"
                "jmp ISRComun \n"
                );

    return;
}