#include "cpu.h"

TipoCPU obtenerTipoCPU(void) {

    uintptr_t codigo;
    uintptr_t registro;

    CPUID(0, registro, codigo, registro, registro);

    switch (codigo) {

        case PROCESADOR_INTEL:
            return INTEL;

        case PROCESADOR_AMD:
            return AMD;

    }

    return DESCONOCIDO;
}