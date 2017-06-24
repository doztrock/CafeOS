#ifndef MEMORIA_H
#define MEMORIA_H

#include "isr.h"
#include "irq.h"
#include "panico/panico.h"

#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"

#define INDICE_DESDE_BIT(a)             (a / (8 * 4))
#define DESPLAZAMIENTO_DESDE_BIT(a)     (a % (8 * 4))

/**
 * Pagina de memoria
 */
struct PaginaMemoria {
    uint32_t present : 1;
    uint32_t rw : 1;
    uint32_t user : 1;
    uint32_t accessed : 1;
    uint32_t dirty : 1;
    uint32_t unused : 7;
    uint32_t frame : 20;
};

/**
 * Tabla contenedora de las paginas de memoria
 */
struct TablaMemoria {
    struct PaginaMemoria paginas[1024];
};

/**
 * Directorio contenedor de las tablas de memoria
 */
struct DirectorioMemoria {
    struct TablaMemoria *tablas[1024];
    uint32_t tablaFisica[1024];
    uint32_t direccionFisica;
};

/**
 * Marco de memoria
 */
uint32_t *marcos;
uint32_t cantidadMarcos;

/**
 * Seccion "end" definida en el archivo link.ld
 */
extern uint32_t end;

/**
 * Directorios de memoria
 */
struct DirectorioMemoria *directorioMemoriaKernel;
struct DirectorioMemoria *directorioMemoriaActual;


/**
 * Funciones: Paginacion
 */
bool iniciarPaginacionMemoria(void);
void cambiarDirectorioMemoria(struct DirectorioMemoria *directorio);
struct PaginaMemoria *obtenerPaginaMemoria(uint32_t direccion, bool construir, struct DirectorioMemoria *directorio);

/**
 * Funciones: Asignacion
 */
uint32_t kmalloc(uint32_t bytes);
uint32_t kmalloc_a(uint32_t bytes);
uint32_t kmalloc_ap(uint32_t bytes, uint32_t *puntero);

void fijarMarco(uint32_t direccion);
void asignarMarco(struct PaginaMemoria *pagina, int32_t kernel, int32_t escritura);

uint32_t primerMarco(void);

void limpiarMarco(uint32_t direccion);
void liberarMarco(struct PaginaMemoria *pagina);

#endif /* MEMORIA_H */
