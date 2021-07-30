;
; BOOTLOADER
;

org 0x7C00  ; Se configura para iniciar desde la direccion de memoria 0x7C00
bits 16     ; Se configura para trabajar en 16 bits

;
; De acuerdo a la respuesta presentada en:
;
; https://stackoverflow.com/questions/27080364/write-assembly-code-that-stores-what-was-written-on-screen-clear-the-screen-and
;
; En esta seccion se definen dos variables cuyos valores almacenaran las posiciones en
; memoria perteneciente a las definiciones de la GDT
;
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

;
; De acuerdo con la documentacion que se presenta en:
;
; https://wiki.osdev.org/FAT#BPB_.28BIOS_Parameter_Block.29
;
; La BIOS puede sobreescribir algunos de las direcciones de memoria,
; para evitar esto se reservan 33 bytes que se llenaran con 0, de modo
; que no ocurra una posterior corrupcion de los valores
;
prestart:
    jmp short start ; Se salta al label start
    nop

times 33 db 0       ; Se llena la memoria con 33 valores en 0

start:
    jmp 0:realstart ; Se inicia desde la direccion de memoria 0x7C0 
                    ; y una vez alli se salta al label realstart

realstart:
    cli             ; Se limpian las interrupciones
    mov ax, 0x00    ; Se guarda el valor 0x00 en el registro AX
    mov ds, ax      ; Se ajusta el Data Segment (DS) en el valor del registro AX
    mov es, ax      ; Se ajusta el Extra Segment (ES) en el valor del registro AX
    mov ss, ax      ; Se ajusta el Stack Segment (SS) en el valor del registro AX
    mov sp, 0x7C00  ; Se guarda el valor 0x7C00 en el Stack Pointer (SP)
    sti             ; Se habilitan las interrupciones

;
; Basado en la respuesta presentada en:
;
; https://stackoverflow.com/questions/50934486/starting-32-bit-protected-mode
;
; Para hacer la transicion del modo real al modo protegido, se necesitan estas instrucciones
; las que se encargan de hacer el paso a 32 bits
;
; Asi tambien se presenta en la siguiente documentacion:
;
; https://wiki.osdev.org/Protected_Mode
;
; Sobre como pasar del modo real (en el que se permite maximo 1Mb de RAM), al modo protegido
; en el que se puede usar 2^32 bytes (4Gb de RAM)
;
.protected:
    cli                     ; Se limpian las interrupciones
    lgdt[gdt_descriptor]    ; Se establece la direccion donde esta la GDT
    mov eax, cr0            ; Se guarda el valor del registro CR0 en el registro EAX
    or eax, 0x1             ; Se configura el bit PE (Protection Enable)
    mov cr0, eax            ; Se guarda el valor del registro EAX en el registro CR0
    jmp CODE_SEG:load       ; Se salta al label load (32 bits)

;
; De acuerdo a la documentacion presentada en:
;
; https://wiki.osdev.org/Global_Descriptor_Table
;
; y basado en los valores que se definen por defecto para la creacion de la GDT
; se configuran de acuerdo a la documentacion presentada en:
;
; http://homepages.rpi.edu/~wangy52/PersonalWebsite/build/html/Misc/MyOS/src/Day02/Day02.html
;
; Para pasar al modo protegido y poder hacer uso de la memoria completa
;
gdt_start:
gdt_null:
    dd 0x0
    dd 0x0

gdt_code:
    dw 0xFFFF       ; Limit 0:15 bits
    dw 0            ; Base 0:15 bits
    db 0            ; Base 16:23 bits
    db 0x9A         ; Access byte
    db 11001111b    ; Flags
    db 0            ; Base 24:31 bits

gdt_data:
    dw 0xFFFF       ; Limit 0:15 bits
    dw 0            ; Base 0:15 bits
    db 0            ; Base 16:23 bits
    db 0x92         ; Access byte
    db 11001111b    ; Flags
    db 0            ; Base 24:31 bits

gdt_end:
gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

[bits 32]
load:
    mov eax, 1              ; Sector desde donde se cargara
    mov ecx, 100            ; Cantidad de sectores que se cargaran
    mov edi, 0x0100000      ; Direccion de memoria que se cargara
    call ata_lba_read       ; Se llama a la funcion ata_lba_read
    jmp CODE_SEG:0x0100000  ; Se salta a la posicion de memoria respectiva 
                            ; una vez que se cargan los sectores

;
; De acuerdo a la documentacion presentada en:
;
; https://wiki.osdev.org/ATA_read/write_sectors 
;
; Se inicializan los valores para poder acceder al disco usando LBA:
;
; https://en.wikipedia.org/wiki/Logical_block_addressing
;
; Esta es una forma mas recomendable de acceder al disco duro de 
; una manera mas sencilla que usando CHS:
;
; https://en.wikipedia.org/wiki/Logical_block_addressing#CHS_conversion
;
ata_lba_read:

    mov ebx, eax        ; Se guarda el valor del registro EAX en el registro EBX (backup)

    ; Se envian 8 bits de LBA al controlador del disco
    shr eax, 24
    or eax, 0xE0        ; Se indica el disco que sera leido (master)
    mov dx, 0x1F6
    out dx, al

    ; Se envia el total de sectores a leer
    mov eax, ecx
    mov dx, 0x1F2
    out dx, al

    ; Se envian mas bits del LBA
    mov eax, ebx        ; Se guarda el valor del registro EBX en el registro EAX (restore)
    mov dx, 0x1F3
    out dx, al

    ; Se envian mas bits del LBA
    mov dx, 0x1F4
    mov eax, ebx        ; Se guarda el valor del registro EBX en el registro EAX (restore)
    shr eax, 8
    out dx, al

    ; Se envian 16 bits de LBA al controlador del disco
    mov dx, 0x1F5
    mov eax, ebx
    shr eax, 16         ; Se guarda el valor del registro EBX en el registro EAX (restore)
    out dx, al

    mov dx, 0x1F7
    mov al, 0x20
    out dx, al

;
; Haciendo uso del stack se agrega el 
; registro ECX (el cual contiene la informacion de la cantidad 
; de sectores que se cargaran), para asi recorrerlos
;
.next_sector:
    push ecx            ; Se agrega el valor del registro ECX al stack

;
; Se hace el reintento de lectura del sector
;
; De acuerdo a la documentacion presentada en:
;
; https://programmerclick.com/article/51331125371/
;
; Se puede encontrar mas informacion al respecto del proceso de carga de los sectores
;
.try_again:

    mov dx, 0x1F7
    in al, dx
    test al, 8
    jz .try_again       ; Se salta al label .try_again

    ;
    ; Se hace la lectura del bus de datos respectivo
    ;
    ; De acuerdo a la informacion presentada en:
    ;
    ; https://faydoc.tripod.com/cpu/insw.htm
    ;
    ; Se explican las instrucciones respectivas para leer del puerto I/O especificado
    ;
    mov ecx, 256
    mov dx, 0x1F0
    rep insw
    pop ecx             ; Se elimina el valor del registro ECX del stack
    loop .next_sector   ; Se itera con el sublabel .next_sector

    ret

;
; Como el bootloader debe pesar 512 bytes se realiza el llenado 
; usando esta instruccion, que basicamente se encarga de ejecutarse 
; un determinado numero de veces para completar el resto del peso
;
; De acuerdo con la documentacion que se presenta en:
;
; https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/writing-a-custom-bootloader
;
; Se lee al final de los 512 bytes y se busca un "boot signature" en 0x55AA, que es el 
; que indica que la unidad contiene un bootloader
;
; Debido a que el procesador trabaja en little-endian, se escribe 0xAA55 para obtener
; el signature del bootloader
;
times 510-($ - $$) db 0     ; Llenado del espacio
dw 0xAA55                   ; 0x55AA => 0xAA55
