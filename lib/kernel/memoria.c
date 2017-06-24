#include "memoria.h"

/**
 * Posicion de memoria respectiva a la seccion "end" definida en link.ld
 */
uintptr_t ubicacionPaginacion = (uintptr_t) & end;

bool iniciarPaginacionMemoria(void) {

    uint32_t paginaMemoriaFinal = 0x1000000;

    cantidadMarcos = paginaMemoriaFinal / 0x1000;
    marcos = (uint32_t *) kmalloc(INDICE_DESDE_BIT(cantidadMarcos));
    memset(marcos, 0, INDICE_DESDE_BIT(cantidadMarcos));

    directorioMemoriaKernel = (struct DirectorioMemoria *) kmalloc_a(sizeof (struct DirectorioMemoria));
    memset(directorioMemoriaKernel, 0, sizeof (struct DirectorioMemoria));

    directorioMemoriaActual = directorioMemoriaKernel;

    uint32_t i = 0;
    while (i < ubicacionPaginacion) {
        asignarMarco(obtenerPaginaMemoria(i, 1, directorioMemoriaKernel), 0, 0);
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

uint32_t kmalloc(uint32_t bytes) {

    uint32_t temporal;

    temporal = ubicacionPaginacion;
    ubicacionPaginacion += bytes;

    return temporal;
}

uint32_t kmalloc_a(uint32_t bytes) {

    uint32_t temporal;

    if (ubicacionPaginacion & 0xFFFFF000) {
        ubicacionPaginacion &= 0xFFFFF000;
        ubicacionPaginacion += 0x1000;
    }

    temporal = ubicacionPaginacion;
    ubicacionPaginacion += bytes;

    return temporal;
}

uint32_t kmalloc_ap(uint32_t bytes, uint32_t *puntero) {

    uint32_t temporal;

    if (ubicacionPaginacion & 0xFFFFF000) {
        ubicacionPaginacion &= 0xFFFFF000;
        ubicacionPaginacion += 0x1000;
    }

    if (puntero) {
        *puntero = ubicacionPaginacion;
    }

    temporal = ubicacionPaginacion;
    ubicacionPaginacion += bytes;

    return temporal;
}

void fijarMarco(uint32_t direccion) {

    uint32_t marco = direccion / 0x1000;
    uint32_t indice = INDICE_DESDE_BIT(marco);
    uint32_t desplazamiento = DESPLAZAMIENTO_DESDE_BIT(marco);

    marcos[indice] |= (0x1 << desplazamiento);

    return;
}

void asignarMarco(struct PaginaMemoria *pagina, int32_t kernel, int32_t escritura) {

    uint32_t indice;

    if (pagina->frame == NULL) {

        indice = primerMarco();

        if (indice == (uint32_t) - 1) {
            asm volatile ("cli");
            for (;;);
        }

        fijarMarco(indice * 0x1000);

        pagina->present = 1;
        pagina->rw = (escritura) ? 1 : 0;
        pagina->user = (kernel) ? 0 : 1;
        pagina->frame = indice;

    }

    return;
}

uint32_t primerMarco(void) {

    uint32_t i, j;
    uint32_t test;

    for (i = 0; i < INDICE_DESDE_BIT(cantidadMarcos); i++) {

        if (marcos[i] != 0xFFFFFFFF) {

            for (j = 0; j < 32; j++) {

                test = 0x1 << j;

                if (!(marcos[i] & test)) {
                    return i * 4 * 8 + j;
                }

            }
        }

    }

    return 0;
}

void limpiarMarco(uint32_t direccion) {

    uint32_t marco = direccion / 0x1000;
    uint32_t indice = INDICE_DESDE_BIT(marco);
    uint32_t desplazamiento = DESPLAZAMIENTO_DESDE_BIT(marco);

    marcos[indice] &= ~(0x1 << desplazamiento);

    return;
}

void liberarMarco(struct PaginaMemoria *pagina) {

    uint32_t marco;

    if ((marco = pagina->frame)) {
        limpiarMarco(marco);
        pagina->frame = 0x0;
    }

    return;
}


