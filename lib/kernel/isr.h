/**
 * Nombre:    ISR.H
 * 
 * Contenido: Funciones respectivas al manejo de interrupciones,
 *            es decir, los ISR (Interrupt Services Routines).
 *            Son aquellas funciones que se ejecutaran cuando se produzca una interrupcion.
 * 
 * Nota:      De acuerdo a variados documentos en internet, existen 32 interrupciones
 *            estandar, mas se dejan habilitadas 256, ya que el hardware o inclusive el software
 *            puede tener acceso a estas interrupciones.
 * 
 *  Las interrupciones son las siguientes:
 * 
 *  Exception               Description                     Error Code?
 *     0            Division By Zero Exception                  No
 *     1            Debug Exception                             No
 *     2            Non Maskable Interrupt Exception            No
 *     3            Breakpoint Exception                        No
 *     4            Into Detected Overflow Exception            No
 *     5            Out of Bounds Exception                     No
 *     6            Invalid Opcode Exception                    No
 *     7            No Coprocessor Exception                    No
 *     8            Double Fault Exception                      Yes
 *     9            Coprocessor Segment Overrun Exception 	No
 *     10           Bad TSS Exception                           Yes
 *     11           Segment Not Present Exception               Yes
 *     12           Stack Fault Exception                       Yes
 *     13           General Protection Fault Exception          Yes
 *     14           Page Fault Exception                        Yes
 *     15           Unknown Interrupt Exception                 No
 *     16           Coprocessor Fault Exception                 No
 *     17           Alignment Check Exception (486+)            No
 *     18           Machine Check Exception (Pentium/586+)      No
 *     19 to 31     Reserved Exceptions                         No
 * 
 *  Fuente: http://www.osdever.net/bkerndev/Docs/isrs.htm
 * 
 */

#ifndef ISR_H
#define ISR_H

#include "stdint.h"

/**
 * Esta estructura contiene la informacion respectiva a la interrupcion generada.
 */
struct ISR_Informacion {
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};


/**
 * Funciones
 */
void ISRManejador(struct ISR_Informacion *informacion);
char *obtenerMensajeISR(int indice);

void ISRComun(void);

void ISR0(void);
void ISR1(void);
void ISR2(void);
void ISR3(void);
void ISR4(void);
void ISR5(void);
void ISR6(void);
void ISR7(void);
void ISR8(void);
void ISR9(void);
void ISR10(void);
void ISR11(void);
void ISR12(void);
void ISR13(void);
void ISR14(void);
void ISR15(void);
void ISR16(void);
void ISR17(void);
void ISR18(void);
void ISR19(void);
void ISR20(void);
void ISR21(void);
void ISR22(void);
void ISR23(void);
void ISR24(void);
void ISR25(void);
void ISR26(void);
void ISR27(void);
void ISR28(void);
void ISR29(void);
void ISR30(void);
void ISR31(void);

#endif /* ISR_H */
