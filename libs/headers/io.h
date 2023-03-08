#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/**
 * outb:
 * envia la data al puerto I/O señalado
 * @param port el puerto al que irá dirigida la data
 * @param dat data  a set enviada al puerto señaladao
 * 
*/
void outb(unsigned short port, unsigned char data);

#endif