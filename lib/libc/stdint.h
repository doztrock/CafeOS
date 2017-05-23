/**
 * STDINT.H
 * 
 * Este archivo contiene las declaraciones de algunas de las funciones
 * que corresponden al estandar de C y que por lo tanto se encuentran
 * en <stdint.h>, por que al ser un sistema operativo distinto, se tienen
 * que hacer todas y cada una de las funciones para que sirvan sin la libreria.
 * 
 */

#ifndef STDINT_H
#define STDINT_H

/**
 * Definiciones
 */

/* Definicion: uint8 */
#ifndef __UINT8_T_
#define __UINT8_T_
typedef char uint8_t;
#endif

/* Definicion: int8_t */
#ifndef __INT8_T_
#define __INT8_T_
typedef signed char int8_t;
#endif


/* Definicion: uint16_t */
#ifndef __UINT16_T_
#define __UINT16_T_
typedef unsigned short uint16_t;
#endif

/* Definicion: int16_t */
#ifndef __INT16_T_
#define __INT16_T_
typedef short int16_t;
#endif


/* Definicion: uint32_t */
#ifndef __UINT32_T_
#define __UINT32_T_
typedef unsigned int uint32_t;
#endif

/* Definicion: int32_t */
#ifndef __INT32_T_
#define __INT32_T_
typedef int int32_t;
#endif


/* Definicion: uint64_t */
#ifndef __UINT64_T_
#define __UINT64_T_
typedef unsigned long long uint64_t;
#endif

/* Definicion: int64_t */
#ifndef __INT64_T_
#define __INT64_T_
typedef long long int64_t;
#endif

#endif /* STDINT_H */
