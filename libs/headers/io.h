#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// I/O ports <-- hex  and commands <-- dec
#define COMMAND_PORT        0x3D4
#define DATA_PORT           0x3D5
#define HIGH_BYTE_LOCATION   14
#define LOW_BYTE_LOCATION    15

/**
 * outb:
 * envia la data al puerto I/O señalado
 * @param port el puerto al que irá dirigida la data
 * @param dat data  a set enviada al puerto señaladao
 * 
*/
void outb(unsigned short port, unsigned char data);

#endif