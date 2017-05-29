#include "lib/kernel/pantalla.h"
#include "lib/kernel/gdt.h"
#include "lib/kernel/idt.h"
#include "lib/kernel/irq.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int kmain(void) {

    asm volatile("cli");

    /**
     * Color por defecto para el texto.
     */
    Color colorDefecto = NEGRO;


    /**
     * Pantalla
     */
    iniciarPantalla();
    limpiarPantalla();

    pintarPantalla(CAFE);

    setForegroundColor(colorDefecto);
    setBackgroundColor(CAFE);

    printf("Bienvenido a cafeOS!\n");


    /**
     * GDT
     */
    printf("Instalando GDT...");

    if (instalarGDT()) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);


    /**
     * IDT
     */
    printf("Instalando IDT...");

    if (instalarIDT()) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);


    /**
     * IRQ
     */
    printf("Instalando IRQ...");

    if (instalarIRQ()) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);

    asm volatile("sti");

    for (;;);

    return EXIT_SUCCESS;
}