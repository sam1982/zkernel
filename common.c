#include "common.h"
#include "types.h"

void memory_write(){
    unsigned int end = 0x00010031a;
    unsigned int result;
    result = kernel_mem_end_test(end);
    char result_str[20];
    itoa(result,result_str);
    kprint("           ");
    kprint(result_str);
    kprint("test");
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


inline void outb(uint16_t port, uint8_t value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}
// 端口读一个字节
inline uint8_t inb(uint16_t port)
{
    uint8_t ret;

    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));

    return ret;
}

// 端口读一个字
inline uint16_t inw(uint16_t port)
{
    uint16_t ret;

    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));

    return ret;
}
