/**
 * Nombre:    KMAIN.C
 * 
 * Contenido: Funcion principal del sistema operativo.
 * 
 * Nota:      Esta es la primera funcion que se ejecuta en la secuencia de boot.
 *            Desde aqui se deben llamar a las otras funciones 
 *            respectivas al manejo del sistema operativo
 * 
 * Autor:     Ivan Botero <ivan.botero@protonmail.ch>
 */

#include "lib/kernel/pantalla.h"
#include "lib/kernel/gdt.h"
#include "lib/kernel/idt.h"
#include "lib/kernel/irq.h"
#include "lib/kernel/temporizador.h"
#include "lib/kernel/teclado.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int kmain(void) {

    /* Limpiamos la interrupciones */
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


    /**
     * Temporizador
     */
    printf("Instalando Temporizador...");

    if (instalarTemporizador() && configurarTemporizador(HERTZ_TEMPORIZADOR)) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);


    /**
     * Teclado
     */
    printf("Instalando Teclado...");

    if (instalarTeclado()) {
        setForegroundColor(VERDE);
        printf("OK\n");
    } else {
        setForegroundColor(ROJO);
        printf("ERROR\n");
    }

    setForegroundColor(colorDefecto);


    /* Iniciamos la interrupciones */
    asm volatile("sti");

    printf("Esperando 1 segundo...");
    esperarTemporizador(TICKS_POR_SEGUNDO);
    printf("OK\n");

    /* Dejamos un bucle infinito */
    for (;;);

    return EXIT_SUCCESS;
}