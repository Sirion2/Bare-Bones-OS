#include "headers/io.h" 

#define VIDEO_MEMORY    0xB8000
#define COLS            80
#define lINES           25

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


/**
 * STARTS Functions and Var Initialization
**/



volatile char *video_buffer = (volatile char *)VIDEO_MEMORY; // video memory buffer address direction

unsigned int attribute_Byte = (BLUE & 0x0F) << 4 | (WHITE & 0x0F);

unsigned volatile int cursor_x = 0, cursor_y = 0;

void move_cursor();
int get_ypos();
int get_xpos();

/**
 * ENDS Functions and Var Initialization
**/

void print_char(const char *buffer)
{
    *video_buffer++ = *buffer;
    *video_buffer++ = attribute_Byte;
}

void print_string(char *buffer)
{
    while (*buffer != 0)
    {
        *video_buffer++ = *buffer++;
        *video_buffer++ = attribute_Byte;

        cursor_x++;
        cursor_y = 0;
        move_cursor();
   }
}

void print_int()
{
    
}

void clear_screen()
{
    unsigned const int blank_Space = 0x20; // <-- denotes [space] in ascii.

    for (int i = 0; i <= COLS * lINES; i++)
    {
        *video_buffer++ = blank_Space;
        *video_buffer++ = attribute_Byte; 

    }
}

void move_cursor()
{
    unsigned int pos = cursor_y * COLS + cursor_x;

    outb(COMMAND_PORT,  HIGH_BYTE_LOCATION);
    outb(DATA_PORT,     ((pos >> 8) & 0x00FF));
    outb(COMMAND_PORT,  LOW_BYTE_LOCATION);
    outb(DATA_PORT,     pos & 0x00FF);


}

int get_ypos() {
    unsigned int pos = cursor_y * COLS + cursor_x;
    return pos / COLS;
}

int get_xpos() {
    unsigned int pos = cursor_y * COLS + cursor_x;
    return pos % COLS;
}



unsigned int strlen(const char *string)
{
    unsigned int counter = 0;

    for(int i=0; i < string[i]; i++)
        counter++;

    return counter;
}