#define VIDEO_MEMORY 0xB8000;
#define VIDEO_MEMORY_END 0xBFFFF;

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
    

    volatile char *display = (volatile char*) VIDEO_MEMORY;     // video memory buffer address direction


<<<<<<< HEAD:libs/functions/stdio.h
    //void print_char(unsigned int xpos, char character, unsigned char bg_color, unsigned char fg_color)
    void print_char(char character, unsigned char bg_color, unsigned char fg_color) {

        unsigned int atribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);
=======
    void print_char(char character, unsigned char bg_color, unsigned char fg_color)
    {
        unsigned int attribute_Byte = ((bg_color & 0x0F) << 4) | (fg_color & 0x0F);

        *display++ = character;
        *display++ = attribute_Byte;
>>>>>>> develop:libs/functions/stdio.c

        *display++ = character;
        *display++ = atribute_Byte;
    }
    //https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c

<<<<<<< HEAD:libs/functions/stdio.h
    void print_string(char *string, unsigned char bg_color, unsigned char fg_color) {
        
        unsigned int atribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);
=======
    /** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
    void print_string(char *string, unsigned char bg_color, unsigned char fg_color) {
        
        unsigned int attribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);
>>>>>>> develop:libs/functions/stdio.c

        while ( *string != 0)
        {
            *display++ = *string++;
<<<<<<< HEAD:libs/functions/stdio.h
            *display++  = atribute_Byte;
        } 
=======
            *display++  = attribute_Byte;
        }
        
>>>>>>> develop:libs/functions/stdio.c
    }

    void clear_screen() {
        
<<<<<<< HEAD:libs/functions/stdio.h
        unsigned char const blank_Space =  0x20;
        unsigned int atribute_Byte = ((BLUE & 0x0F)<< 4) | (WHITE & 0x0F);
=======
        unsigned int attribute_Byte = ((BLUE & 0x0F)<< 4) | (WHITE & 0x0F);
        unsigned int  blank_Space =  ' ';
>>>>>>> develop:libs/functions/stdio.c

        for (int i = 0; i < 80*25; i++)
        {
            *display++ = blank_Space;
<<<<<<< HEAD:libs/functions/stdio.h
            *display++ = atribute_Byte;
=======
            *display++ = attribute_Byte;
>>>>>>> develop:libs/functions/stdio.c
        }
    }