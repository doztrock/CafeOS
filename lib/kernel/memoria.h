#ifndef MEMORIA_H
#define MEMORIA_H

#include "isr.h"

#include "stdint.h"

#define INDEX_FROM_BIT  (a) (a / (8 * 4))
#define OFFSET_FROM_BIT (a) (a % (8 * 4))

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

page_directory_t * kernel_directory;
page_directory_t * current_directory;


/**
 * Funciones: Paginacion
 */
void init_paging();
void switch_page_directory(page_directory_t * new);
page_t *get_page(uint32_t address, int32_t make, page_directory_t *dir);
void page_fault(struct ISR_Informacion *regs);

/**
 * Funciones: Asignacion
 */
uint32_t kmalloc(uint32_t sz);
uint32_t kmalloc_a(uint32_t sz);
uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys);
static void set_frame(uint32_t frame_addr);
static void clear_frame(uint32_t frame_addr);
static uint32_t test_frame(uint32_t frame_addr);
static uint32_t first_frame();
void alloc_frame(page_t *page, int32_t is_kernel, int32_t is_writeable);
void free_frame(page_t *page);

#endif /* MEMORIA_H */
