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
    

    volatile char *display = (volatile char*) VIDEO_MEMORY;


    void print_char(unsigned int xpos, char character, unsigned char fg, unsigned char bg)
    {
        char *fb = (char* ) VIDEO_MEMORY;
        fb[xpos] = character;
        fb[xpos + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);

    }

    /** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
    void print_string(char *string, unsigned char fg, unsigned char bg) {
        
        unsigned int atribute_Byte = (fg & 0x0F) << 4 | (bg & 0x0F);

        while ( *string != 0)
        {
            *display++ = *string++;
            *display++  = atribute_Byte;
        }
        
    }

    void clear_screen() {
        
        //unsigned int atribute_Byte = ((BLUE & 0x0F)<< 4) | (WHITE & 0x0F);
        unsigned int  blank_Space =  ' ' | (( BLUE & 0x0F) << 4);

        for (int i = 0; i < 80*25; i++)
        {
            display[i] = blank_Space;
        }
    }