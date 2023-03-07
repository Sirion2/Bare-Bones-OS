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


    //void print_char(unsigned int xpos, char character, unsigned char bg_color, unsigned char fg_color)
    void print_char(char character, unsigned char bg_color, unsigned char fg_color) {

        unsigned int atribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);

        *display++ = character;
        *display++ = atribute_Byte;
    }
    //https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c

    void print_string(char *string, unsigned char bg_color, unsigned char fg_color) {
        
        unsigned int atribute_Byte = (bg_color & 0x0F) << 4 | (fg_color & 0x0F);

        while ( *string != 0)
        {
            *display++ = *string++;
            *display++  = atribute_Byte;
        } 
    }

    void clear_screen() {
        
        unsigned char const blank_Space =  0x20;
        unsigned int atribute_Byte = ((BLUE & 0x0F)<< 4) | (WHITE & 0x0F);

        for (int i = 0; i < 80*25; i++)
        {
            *display++ = blank_Space;
            *display++ = atribute_Byte;
        }
    }