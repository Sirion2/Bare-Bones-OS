#include "headers/io.h" 



struct Screen
{
    #define VIDEO_MEMORY    0xB8000
    #define COLS            80
    #define lINES           25
};

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
}color;

/**
 * STARTS Functions and Var Initialization
**/

unsigned volatile int cursor_x = 0, cursor_y = 0;

volatile char *display = (volatile char *)VIDEO_MEMORY; // video memory buffer address direction

void move_cursor();

/**
 * ENDS Functions and Var Initialization
**/

void print_char(const char character, unsigned char bg_color, unsigned char fg_color)
{
    unsigned int attribute_Byte = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);

    *display++ = character;
    *display++ = attribute_Byte;
    *display++ = attribute_Byte;


    cursor_y=0;
    cursor_x=0;  
    move_cursor();
}

void printf(char attr, char *string)
{
    char error[] = "error no se ha especificado el valor de la cadena";
    //     for(int i=0; i < string[i]; i++)
    //     counter++;

    // return counter;
    unsigned int attribute_Byte = (BLUE & 0x0F) << 4 | (WHITE & 0x0F);
     while(*string != 0)
     {
           if(attr == 's')
           {
                *display++ = *string++;
                *display++ = attribute_Byte;
           }

    }
    
        *display++ = *error;
        *display++ = attribute_Byte;

        // else if (attr == 'c')
        // {
        //     *display++ = 'o';
        //     *display++ = attribute_Byte;
        // } else {
        //      *display++ = 'a';
        //     *display++ = attribute_Byte;
        // }
}

void print_string(const char *string, unsigned char bg_color, unsigned char fg_color)
{
    unsigned int attribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);

    while (*string != 0)
    {
        //if(*string )
        *display++ = *string++;
        *display++ = attribute_Byte;
    }

    cursor_y=0;
    cursor_x=0;  
    move_cursor(); 
        
}

void clear_screen()
{
    unsigned int attribute_Byte = ((BLUE & 0x0F) << 4) | (WHITE & 0x0F);
    unsigned int blank_Space = 0x20; // <-- denotes [space] in ascii.

    for (int i = 0; i <= COLS * lINES; i++)
    {
        *display++ = blank_Space;
        *display++ = attribute_Byte;
    }

    cursor_x = 0;
    cursor_y = 0;
    move_cursor(); 
}

void move_cursor()
{
    unsigned int pos = cursor_y * COLS + cursor_x;

    outb(COMMAND_PORT,  HIGH_BYTE_LOCATION);
    outb(DATA_PORT,     ((pos >> 8) & 0x00FF));
    outb(COMMAND_PORT,  LOW_BYTE_LOCATION);
    outb(DATA_PORT,     pos);
}

unsigned int strlen(const char *string)
{
    unsigned int counter = 0;

    for(int i=0; i < string[i]; i++)
        counter++;

    return counter;
}