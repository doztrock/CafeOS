/**
 * Nombre:    COLOR.H
 * 
 * Contenido: Constantes respectivas a los colores que soportara la pantalla.
 * 
 */

#ifndef COLOR_H
#define COLOR_H

/**
 * Lados de la pantalla, donde se podran colocar los colores. 
 * Es decir, en la pantalla se puede escribir en dos partes:
 * 
 * - Background     (Fondo)
 * - Foreground     (Primer Plano)
 * 
 */
typedef enum __lado_pantalla {
    BACKGROUND,
    FOREGROUND
} LadoPantalla;


/**
 * NOTA: Las pantallas, o bien, el controlador de VGA, solo soporta 16 colores.
 */

/**
 * Colores soportados
 */
typedef enum __color {
    NEGRO,
    AZUL,
    VERDE,
    CIAN,
    ROJO,
    MAGENTA,
    CAFE,
    GRIS_CLARO,
    GRIS_OSCURO,
    AZUL_CLARO,
    VERDE_CLARO,
    CIAN_CLARO,
    ROJO_CLARO,
    MAGENTA_CLARO,
    AMARILLO,
    BLANCO
} Color;

#endif /* COLOR_H */
