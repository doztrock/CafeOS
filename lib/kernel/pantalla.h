/**
 * Nombre:    PANTALLA.H
 * 
 * Contenido: Constantes y funciones que se utilizaran para manejar la pantalla.
 *            Mover el cursor del video y escribir cadenas.
 * 
 */

#ifndef PANTALLA_H
#define PANTALLA_H

#include "kernel.h"
#include "io.h"
#include "pantalla/color.h"

#include "stdint.h"

/**
 * Tamano de buffer de desplazamiento
 */
#define TAMANO_BUFFER_DEPLAZAMIENTO 64

/**
 * Indice de buffer de desplazamiento
 */
unsigned int INDICE_BUFFER_DESPLAZAMIENTO_SUPERIOR;
unsigned int INDICE_BUFFER_DESPLAZAMIENTO_INFERIOR;

/**
 * Posiciones del cursor
 */
unsigned int POSICION_X;
unsigned int POSICION_Y;

/**
 * Colores de los lados de la pantalla
 */
Color backgroundColor;
Color foregroundColor;

/**
 * Celda de pantalla
 */
struct CeldaPantalla {
    char caracter;
};

/**
 * Fila de la pantalla
 */
struct FilaPantalla {
    struct CeldaPantalla celda[80];
};

/**
 * Tipo de desplazamiento
 */
typedef enum __tipo_desplazamiento_pantalla {
    SUPERIOR, INFERIOR
} TipoDesplazamientoPantalla;

/**
 * Buffer de desplazamiento superior
 */
struct FilaPantalla BUFFER_DESPLAZAMIENTO_SUPERIOR[TAMANO_BUFFER_DEPLAZAMIENTO];

/**
 * Buffer de desplazamiento inferior
 */
struct FilaPantalla BUFFER_DESPLAZAMIENTO_INFERIOR[TAMANO_BUFFER_DEPLAZAMIENTO];


/**
 * Funciones
 */
void iniciarPantalla(void);
void limpiarPantalla(void);

void pintarPantalla(Color color);

void moverCursor(uint8_t X, uint8_t Y);
void actualizarCursor(void);

void setBackgroundColor(Color color);
void setForegroundColor(Color color);

Color getBackgroundColor(void);
Color getForegroundColor(void);

struct FilaPantalla obtenerPrimeraFila(void);
void almacenarFilaBufferDesplazamiento(struct FilaPantalla fila, TipoDesplazamientoPantalla tipoDesplazamiento);

void desplazarPantalla(uint32_t n, TipoDesplazamientoPantalla tipoDesplazamiento);

#endif /* PANTALLA_H */
