#ifndef MEMORIA_H
#define MEMORIA_H

#include "isr.h"
#include "irq.h"
#include "panico/panico.h"

#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"

#define INDEX_FROM_BIT(a)   (a / (8 * 4))
#define OFFSET_FROM_BIT(a)  (a % (8 * 4))

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
uint32_t kmalloc(uint32_t sz);
uint32_t kmalloc_a(uint32_t sz);
uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys);
void set_frame(uint32_t frame_addr);
void clear_frame(uint32_t frame_addr);
uint32_t first_frame();
void alloc_frame(struct PaginaMemoria *page, int32_t is_kernel, int32_t is_writeable);
void free_frame(struct PaginaMemoria *page);

#endif /* MEMORIA_H */
