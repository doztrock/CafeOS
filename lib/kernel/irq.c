#include "irq.h"

bool instalarIRQ(void) {

    /* Remapeamos la tabla */
    remapearIRQ(0x20, 0x28);

    /* Agregamos los IRQ a la IDT */
    setEntradaIDT(32, (uint32_t) IRQ1, 0x08, 0x8E);
    setEntradaIDT(33, (uint32_t) IRQ2, 0x08, 0x8E);
    setEntradaIDT(34, (uint32_t) IRQ3, 0x08, 0x8E);
    setEntradaIDT(35, (uint32_t) IRQ4, 0x08, 0x8E);
    setEntradaIDT(36, (uint32_t) IRQ5, 0x08, 0x8E);
    setEntradaIDT(37, (uint32_t) IRQ6, 0x08, 0x8E);
    setEntradaIDT(38, (uint32_t) IRQ7, 0x08, 0x8E);
    setEntradaIDT(39, (uint32_t) IRQ8, 0x08, 0x8E);
    setEntradaIDT(40, (uint32_t) IRQ9, 0x08, 0x8E);
    setEntradaIDT(41, (uint32_t) IRQ10, 0x08, 0x8E);
    setEntradaIDT(42, (uint32_t) IRQ11, 0x08, 0x8E);
    setEntradaIDT(43, (uint32_t) IRQ12, 0x08, 0x8E);
    setEntradaIDT(44, (uint32_t) IRQ13, 0x08, 0x8E);
    setEntradaIDT(45, (uint32_t) IRQ14, 0x08, 0x8E);
    setEntradaIDT(46, (uint32_t) IRQ15, 0x08, 0x8E);
    setEntradaIDT(47, (uint32_t) IRQ16, 0x08, 0x8E);

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

    //    void (*manejador)(struct ISR_Informacion * informacion);

    if (informacion->int_no >= 40) {
        outb(0xA0, 0x20);
    } else {
        outb(0x20, 0x20);
    }

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