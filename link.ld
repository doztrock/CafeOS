ENTRY(loader)                /* Funcion en Assembler */

SECTIONS {
    . = 0x00100000;          /* El codigo debe estar cargado en 1MB*/

    .text: ALIGN (0x1000) :   /* Alineamiento a 4KB*/
    {
        *(.text)             
    }

    .rodata: ALIGN (0x1000) : /* Alineamiento a 4KB*/ 
    {
        *(.rodata*)          
    }

    .data ALIGN (0x1000) :   /* Alineamiento a 4KB*/
    {
        *(.data)             
    }

    .bss ALIGN (0x1000) :    /* Alineamiento a 4KB*/
    {
        *(COMMON)            
        *(.bss)              
    }
}
