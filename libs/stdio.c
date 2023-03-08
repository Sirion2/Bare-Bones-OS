#include "headers/io.h" 

#define VIDEO_MEMORY 0xB8000

struct Color
{
#define BLACK           0
#define BLUE            1
#define GREEN           2
#define CYAN            3
#define RED             4
#define MAGENTA         5
#define BROWN           6
#define LIGHT_GRAY      7
#define DARK_GREY       8
#define LIGHT_BLUE      9
#define LIGHT_GREEN     10
#define LIGHT_CYAN      11
#define LIGHT_RED       12
#define LIGHT_MAGENTA   13
#define LIGHT_BROWN     14
#define WHITE           15
};

// I/O ports <-- hex  and commands <-- dec
#define COMMAND_PORT        0x3D4
#define DATA_PORT           0x3D5
#define HIGH_BYTE_LOCATION   14
#define LOW_BYTE_LOCATION    15


unsigned int cursor_x = 0, cursor_y = 0;

volatile char *display = (volatile char *)VIDEO_MEMORY; // video memory buffer address direction

void move_cursor();

void print_char(char character, unsigned char bg_color, unsigned char fg_color)
{
    unsigned int attribute_Byte = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);

    *display++ = character;
    *display++ = attribute_Byte;

    *display++ = character;
    *display++ = attribute_Byte;
}
// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c

void print_string(char *string, unsigned char bg_color, unsigned char fg_color)
{

    unsigned int attribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);

    while (*string != 0)
    {
        *display++ = *string++;
        *display++ = attribute_Byte;
    }
}

void clear_screen()
{
    unsigned int attribute_Byte = ((BLUE & 0x0F) << 4) | (WHITE & 0x0F);
    unsigned int blank_Space = ' ';

    for (int i = 0; i < 80 * 25; i++)
    {
        *display++ = blank_Space;
        *display++ = attribute_Byte;
    }
    cursor_x = 0;
	cursor_y = 0;
    move_cursor();
}

void move_cursor() {
    unsigned int pos = cursor_y * 80 + cursor_x;
    outb(COMMAND_PORT,  HIGH_BYTE_LOCATION);
    outb(DATA_PORT,     ((pos >> 8) & 0x00FF));
    outb(COMMAND_PORT,  LOW_BYTE_LOCATION);
    outb(DATA_PORT,     pos);

}