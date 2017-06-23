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
#include "lib/kernel/memoria.h"
#include "lib/kernel/temporizador.h"
#include "lib/kernel/teclado.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"

int kmain(void) {

    /* Limpiamos la interrupciones */
    asm volatile("cli");

    /**
     * Color por defecto para el texto.
     */
    Color colorDefecto = BLANCO;


    /**
     * Pantalla
     */
    iniciarPantalla();
    limpiarPantalla();

    pintarPantalla(NEGRO);

    setForegroundColor(colorDefecto);
    setBackgroundColor(NEGRO);


    /**
     * Mensaje de bienvenida
     * 
     * Bienvenido a cafeOS!
     * 
     */
    printf("Bienvenido a ");

    setForegroundColor(AMARILLO);
    putchar('c');
    putchar('a');

    setForegroundColor(AZUL);
    putchar('f');

    setForegroundColor(ROJO);
    putchar('e');

    setForegroundColor(colorDefecto);
    printf("OS!\n\n");


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
     * Paginacion
     */
    printf("Instalando Paginacion...");

    if (iniciarPaginacionMemoria()) {
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


    /**
     * A partir de este punto se toma por iniciado el SO
     * 
     * Por lo tanto se realizaran verificaciones de algunos de los dispositivos.
     * E incluso la inicializacion de los que falten.
     * 
     */

    /**
     * Prueba:      Temporizador
     * 
     * Objetivo:    Determinar si el temporizador (timer) funciona.
     * Metodo:      Detener el temporizador por 1 segundo.
     */

    /* Prueba de temporizador */
    printf("\nPrueba de temporizador:");
    printf("\nEsperando 1 segundo...");

    sleep(1);

    setForegroundColor(VERDE);
    printf("OK\n");

    setForegroundColor(colorDefecto);

    
    /* Dejamos un bucle infinito */
    for (;;);

    return EXIT_SUCCESS;
}