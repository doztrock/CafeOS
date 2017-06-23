#include "memoria.h"

/**
 * Posicion de memoria respectiva a la seccion "end" definida en link.ld
 */
uintptr_t ubicacionPaginacion = (uintptr_t) & end;

bool iniciarPaginacionMemoria(void) {

    uint32_t paginaMemoriaFinal = 0x1000000;

    cantidadMarcos = paginaMemoriaFinal / 0x1000;
    marcos = (uint32_t *) kmalloc(INDEX_FROM_BIT(cantidadMarcos));
    memset(marcos, 0, INDEX_FROM_BIT(cantidadMarcos));

    directorioMemoriaKernel = (struct DirectorioMemoria *) kmalloc_a(sizeof (struct DirectorioMemoria));
    memset(directorioMemoriaKernel, 0, sizeof (struct DirectorioMemoria));

    directorioMemoriaActual = directorioMemoriaKernel;

    uint32_t i = 0;
    while (i < ubicacionPaginacion) {
        alloc_frame(obtenerPaginaMemoria(i, 1, directorioMemoriaKernel), 0, 0);
        i += 0x1000;
    }

    cambiarDirectorioMemoria(directorioMemoriaKernel);

    return true;
}

void cambiarDirectorioMemoria(struct DirectorioMemoria *directorio) {

    uint32_t cr0;

    directorioMemoriaActual = directorio;

    asm volatile("mov %0, %%cr3"::"r"(&directorio->tablaFisica));
    asm volatile("mov %%cr0, %0" : "=r"(cr0));

    cr0 |= 0x80000000;

    asm volatile("mov %0, %%cr0"::"r"(cr0));

    return;
}

struct PaginaMemoria *obtenerPaginaMemoria(uint32_t direccion, bool construir, struct DirectorioMemoria *directorio) {

    uint32_t tablaIDX;
    uint32_t temporal;

    direccion /= 0x1000;
    tablaIDX = direccion / 1024;

    if (directorio->tablas[tablaIDX]) {
        return &directorio->tablas[tablaIDX]->paginas[direccion % 1024];
    } else if (construir) {

        directorio->tablas[tablaIDX] = (struct TablaMemoria *) kmalloc_ap(sizeof (struct TablaMemoria *), &temporal);
        memset(directorio->tablas[tablaIDX], 0, 0x1000);

        directorio->tablaFisica[tablaIDX] = temporal | 0x7;

        return &directorio->tablas[tablaIDX]->paginas[direccion % 1024];
    }

    return NULL;
}

uint32_t kmalloc(uint32_t sz) {

    uint32_t tmp = ubicacionPaginacion;
    ubicacionPaginacion += sz;

    return tmp;
}

uint32_t kmalloc_a(uint32_t sz) {

    if (ubicacionPaginacion & 0xFFFFF000) {
        ubicacionPaginacion &= 0xFFFFF000;
        ubicacionPaginacion += 0x1000;
    }
    uint32_t tmp = ubicacionPaginacion;
    ubicacionPaginacion += sz;
    return tmp;
}

uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys) {
    if (ubicacionPaginacion & 0xFFFFF000) {
        ubicacionPaginacion &= 0xFFFFF000;
        ubicacionPaginacion += 0x1000;
    }
    if (phys) {
        *phys = ubicacionPaginacion;
    }
    uint32_t tmp = ubicacionPaginacion;
    ubicacionPaginacion += sz;
    return tmp;
}

void set_frame(uint32_t frame_addr) {
    uint32_t frame = frame_addr / 0x1000;
    uint32_t idx = INDEX_FROM_BIT(frame);
    uint32_t off = OFFSET_FROM_BIT(frame);
    marcos[idx] |= (0x1 << off);
}

void clear_frame(uint32_t frame_addr) {
    uint32_t frame = frame_addr / 0x1000;
    uint32_t idx = INDEX_FROM_BIT(frame);
    uint32_t off = OFFSET_FROM_BIT(frame);
    marcos[idx] &= ~(0x1 << off);
}

uint32_t first_frame() {
    uint32_t i, j;
    for (i = 0; i < INDEX_FROM_BIT(cantidadMarcos); i++) {
        if (marcos[i] != 0xFFFFFFFF) {
            for (j = 0; j < 32; j++) {
                uint32_t toTest = 0x1 << j;
                if (!(marcos[i] & toTest)) {
                    return i * 4 * 8 + j;
                }
            }
        }
    }
    return 0;
}

void alloc_frame(struct PaginaMemoria *page, int32_t is_kernel, int32_t is_writeable) {
    if (page->frame != 0) {
        return;
    } else {
        uint32_t idx = first_frame();
        if (idx == (uint32_t) - 1) {
            asm volatile ("cli");
            for (;;);
        }
        set_frame(idx * 0x1000);
        page->present = 1;
        page->rw = (is_writeable) ? 1 : 0;
        page->user = (is_kernel) ? 0 : 1;
        page->frame = idx;
    }
}

void free_frame(struct PaginaMemoria *page) {
    uint32_t frame;
    if (!(frame = page->frame)) {
        return;
    } else {
        clear_frame(frame);
        page->frame = 0x0;
    }
}

