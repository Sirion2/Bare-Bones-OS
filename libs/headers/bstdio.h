#ifndef INCLUDE_BSTDIO_H
#define INCLUDE_BSTDIO_H

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


void print_char(const char *buffer);

void print_string(const char *buffer);

void clear_screen();

void move_cursor();

int get_ypos();

int get_xpos();


#endif