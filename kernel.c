/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/
#include "display.h"
#include "kernel.h"

void kmain(void)
{
    //设置分辨率，暂时没弄好
    set_ratio();
	const char *str = "my first kernel";
	/* video memory begins at address 0xb8000 */
	char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int screensize;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	screensize = COLUMNS * LINE * 2;
	while (j < screensize) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte */
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/* this loop writes the string to video memory */
    kprint(str);
    kprintEnter();
    int total;
    total = memoryInt();
    char t[20]; 
    itoa(total,t);
    kprint(t);
	return;
}

//换行,因为分辨率不知道咋设置，所以换行也不行
void kprintEnter(){
    if (current_loc <=0){
        return;
    }
    if (current_loc < COLUMNS ){
        current_loc = COLUMNS;
        return;
    }
    current_loc =  current_loc + (current_loc%COLUMNS);
}

void kprint(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}
