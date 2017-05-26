/**
 * Nombre:    COLOR.H
 * 
 * Contenido: Constantes respectivas a los colores que soportara la pantalla.
 * 
 */

#ifndef COLOR_H
#define COLOR_H

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
