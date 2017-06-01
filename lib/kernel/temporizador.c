#include "temporizador.h"

unsigned int TICKS_TEMPORIZADOR = 0;

bool instalarTemporizador(void) {
    instalarManejadorIRQ(0, &manejadorTemporizador);
    return true;
}

bool configurarTemporizador(int hertz) {

    int divisor = 1193180 / hertz;

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, divisor >> 8);

    return true;
}

void esperarTemporizador(int ticks) {

    unsigned long ticksMaximos = TICKS_TEMPORIZADOR + ticks;

    while (TICKS_TEMPORIZADOR < ticksMaximos) {
    }

    return;
}

void manejadorTemporizador(struct ISR_Informacion *informacion) {
    TICKS_TEMPORIZADOR++;
    return;
}

