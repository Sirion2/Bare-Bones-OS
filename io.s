global outb

; outb <- Envia un byte a un puerto I/O

outb: 
    mov al, [esp + 8]   ; mueve la data a ser enviada a registro 'al'
    mov dx, [esp + 4]   ; mueve la direccion del puerto I/O al registro 'dx'
    out dx, al          ; envia la data guardad in 'al' to the I/O port
    ret                 ; retorna