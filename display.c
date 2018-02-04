#include "display.h"
#include "common.h"

extern int current_loc;
extern  char *vidptr;
void set_ratio(){
    //s_set_ratio();
}

void kprint_char(const char str)
{
        vidptr[current_loc++] = str;
        vidptr[current_loc++] = 0x07;
}

void kprint(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

void kprint_newline(void)
{
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc = current_loc + (line_size - current_loc % (line_size));
}


void kprintEnter(){
    if (current_loc <=0){
        return;
    }
    unsigned int line_size = COLUMNS * 2;
    if (current_loc < line_size ){
        current_loc = line_size;
        return;
    }
    current_loc =  current_loc + (line_size -  current_loc%line_size);
}

void kprintCmd(){
    kprint_newline();
    kprint(">");
}
