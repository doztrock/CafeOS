#include "irq.h"

bool instalarIRQ(void) {

    /* Remapeamos la tabla */
    remapearIRQ(0x20, 0x28);

    /* Agregamos los IRQ a la IDT */
    setEntradaIDT(32, (uint32_t) IRQ1, 0x08, 0x8E);
    setEntradaIDT(33, (uint32_t) IRQ2, 0x08, 0x8E);

    return true;
}

void remapearIRQ(int pic1, int pic2) {

    outb(PIC1, ICW1);
    outb(PIC2, ICW1);

    outb(PIC1 + 1, pic1);
    outb(PIC2 + 1, pic2);

    outb(PIC1 + 1, 0x04);
    outb(PIC2 + 1, 0x02);

    outb(PIC1 + 1, ICW4);
    outb(PIC2 + 1, ICW4);

    outb(PIC1 + 1, 0x01);
    outb(PIC2 + 1, 0x01);

    outb(PIC1 + 1, 0x00);
    outb(PIC2 + 1, 0x00);

    return;
}

void IRQManejador(struct ISR_Informacion *informacion) {

    //void (*manejador)(struct ISR_Informacion * informacionISR);

    if (informacion->int_no >= 40) {
        outb(0xA0, 0x20);
    }
    outb(0x20, 0x20);

    return;
}

void IRQComun(void) {

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
                "movl $IRQManejador, %eax \n"
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

void IRQ1(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x20\n"
                "jmp IRQComun"
                );
}

void IRQ2(void) {
    asm volatile(
                "popl %ebp	\n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x21\n"
                "jmp IRQComun"
                );
}
