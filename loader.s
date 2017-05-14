;
; Cargador del Sistema Operativo
;
; Aqui se encuentran las principales instrucciones por medio de las cuales
; el sistema operativo se ejecutara

;
; La funcion kmain, esta definida en el archivo kmain.c
; alli, estara la funcion principal, del sistema operativo. 
;
extern kmain


;
; DEFINICIONES
;

; Funciones
global loader 			; Definimos la funcion "loader"

; Constantes
MAGIC_NUMBER equ 0x1BADB002     ; Definimos la constante con el numero magico
FLAGS        equ 0x0            ; Definimos las banderas a usar con multiboot
CHECKSUM     equ -MAGIC_NUMBER  ; Generamos el checksum
                                ; (Numero Magico + Checksum + Banderas deberia ser 0)
KERNEL_STACK_SIZE equ 4096      ; Tamano de la pila donde se cargara el kernel


;
; Seccion .text
;
section .text:                  ; Seccion .text
align 4                         ; Alineamos las instrucciones a 4 bytes
				; Esto se hace por propositos de optimizacion

	dd MAGIC_NUMBER         ; Definimos el numero magico como un Double Word
	dd FLAGS                ; Definimos las banderas como un Double Word
	dd CHECKSUM             ; Definimos el checksum como un Double Word

loader:                         ; Iniciamos la funcion "loader"
        mov eax, 0xCAFEBABE     ; Asignamos el valor 0xCAFEBABE en el registro EAX
        call kmain              ; Llamamos a la funcion "kmain"

.loop:				; Creamos una etiqueta, para ejecutar un bucle
	jmp .loop               ; Iteramos...


;
; Seccion .bss
;
section .bss:
align 4                                         ; Alineamos las instrucciones a 4 bytes
                                                ; Esto se hace por propositos de optimizacion

kernel_stack:                                   ; Pila donde se cargara el kernel
    resb KERNEL_STACK_SIZE                      ; Reservamos espacio para el kernel
    mov esp, kernel_stack + KERNEL_STACK_SIZE   ; Apuntamos al final de la pila
