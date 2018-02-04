/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/
#include "display.h"
#include "kernel.h"
#include "memory.h"
#include "common.h"


extern void load_idt(unsigned long *idt_ptr);
extern void kb_init(void);
extern void idt_init(void);
extern void init_gdt(void);

unsigned int current_loc = 0;
char *vidptr = (char*)0xb8000;
void kmain(void)
{
    //设置分辨率，暂时没弄好
    set_ratio();
    idt_init();
    //初始化段表会有问题，暂时不管了
    //init_gdt();
	const char *str = "my first kernel";
	/* video memory begins at address 0xb8000 */
	//char *vidptr = (char*)0xb8000;
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
    //kprint_newline();
    kprintEnter();
    unsigned int memtotal;
    memtotal = memory_explore();
    char t[20]; 
    itoa(memtotal,t);
    kprint("total: ");
    kprint(t);
    kprint_newline();
    struct MEMMAN *memman = (struct MEMMAN *) MEMMAN_ADDR;
    memman_init(memman);
    memman_free(memman, 0x00001000, 0x0009e000); /* 0x00001000 - 0x0009efff */
    memman_free(memman, 0x00400000, memtotal - 0x00400000);
    char free[20];
    itoa(memman_total(memman) / 1024,free);
    kprint("free: ");
    kprint(free);
    kb_init();
    kprintCmd();

    while(1);
	//return;
}
