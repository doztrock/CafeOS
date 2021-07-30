;
; Se configura para trabajar en 32 bits
;
[bits 32]

;
; Se exporta el label prestart para que pueda ser visible 
; por el enlazador al momento de compilar
;
global prestart

CODE_SEG equ 0x08
DATA_SEG equ 0x10

prestart:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp

    ;
    ; De acuerdo a la documentacion presentada en:
    ;
    ; https://wiki.osdev.org/A20_Line
    ;
    ; Se hace la habilitacion de la linea A20
    ;
    in al, 0x92
    or al, 2
    out 0x92, al

    jmp $