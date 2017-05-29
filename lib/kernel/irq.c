#include "irq.h"

bool instalarIRQ(void) {

    /* Remapeamos la tabla */
    remapearIRQ(0x20, 0x28);

    /* Agregamos los IRQ a la IDT */
    setEntradaIDT(32, (unsigned) IRQ1, 0x08, 0x8E);
    setEntradaIDT(33, (unsigned) IRQ2, 0x08, 0x8E);
    setEntradaIDT(34, (unsigned) IRQ3, 0x08, 0x8E);
    setEntradaIDT(35, (unsigned) IRQ4, 0x08, 0x8E);
    setEntradaIDT(36, (unsigned) IRQ5, 0x08, 0x8E);
    setEntradaIDT(37, (unsigned) IRQ6, 0x08, 0x8E);
    setEntradaIDT(38, (unsigned) IRQ7, 0x08, 0x8E);
    setEntradaIDT(39, (unsigned) IRQ8, 0x08, 0x8E);
    setEntradaIDT(40, (unsigned) IRQ9, 0x08, 0x8E);
    setEntradaIDT(41, (unsigned) IRQ10, 0x08, 0x8E);
    setEntradaIDT(42, (unsigned) IRQ11, 0x08, 0x8E);
    setEntradaIDT(43, (unsigned) IRQ12, 0x08, 0x8E);
    setEntradaIDT(44, (unsigned) IRQ13, 0x08, 0x8E);
    setEntradaIDT(45, (unsigned) IRQ14, 0x08, 0x8E);
    setEntradaIDT(46, (unsigned) IRQ15, 0x08, 0x8E);
    setEntradaIDT(47, (unsigned) IRQ16, 0x08, 0x8E);

    /* Activamos las IRQ */
    asm volatile("sti");

    return true;
}

void remapearIRQ(int pic1, int pic2) {

    outb(PIC1, ICW1);
    outb(PIC2, ICW1);

    outb(PIC1 + 1, pic1);
    outb(PIC2 + 1, pic2);

    outb(PIC1 + 1, 4);
    outb(PIC2 + 1, 2);

    outb(PIC1 + 1, ICW4);
    outb(PIC2 + 1, ICW4);

    outb(PIC1 + 1, 0xFF);

    return;
}

void IRQManejador(struct ISR_Informacion *informacion) {

    void (*manejador)(struct ISR_Informacion * informacionISR);

    if (informacion->int_no >= 40) {
        outb(0xA0, 0x20);
    }
    outb(0x20, 0x20);

    return;
}

void IRQComun(void) {

    asm volatile(
                "pusha \n"
                "push %ds\n"
                "push %es\n"
                "push %fs\n"
                "push %gs\n"
                "movw $0x10, %ax \n"
                "movw %ax, %ds \n"
                "movw %ax, %es \n"
                "movw %ax, %fs \n"
                "movw %ax, %gs \n"
                "movl %esp, %eax \n"
                "push %eax \n"
                "movl $IRQManejador, %eax \n"
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

void IRQ3(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x22\n"
                "jmp IRQComun"
                );
}

void IRQ4(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x23\n"
                "jmp IRQComun"
                );
}

void IRQ5(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x24\n"
                "jmp IRQComun"
                );
}

void IRQ6(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x25\n"
                "jmp IRQComun"
                );
}

void IRQ7(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x26\n"
                "jmp IRQComun"
                );
}

void IRQ8(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x27\n"
                "jmp IRQComun"
                );
}

void IRQ9(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x28\n"
                "jmp IRQComun"
                );
}

void IRQ10(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x29\n"
                "jmp IRQComun"
                );
}

void IRQ11(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2A\n"
                "jmp IRQComun"
                );
}

void IRQ12(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2B\n"
                "jmp IRQComun"
                );
}

void IRQ13(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2C\n"
                "jmp IRQComun"
                );
}

void IRQ14(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2D\n"
                "jmp IRQComun"
                );
}

void IRQ15(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2E\n"
                "jmp IRQComun"
                );
}

void IRQ16(void) {
    asm volatile(
                "popl %ebp	   \n"
                "cli	\n"
                "pushl	$0x00\n"
                "pushl	$0x2F\n"
                "jmp IRQComun"
                );
}