#define EFLAGS_AC_BIT       0x00040000
#define CR0_CACHE_DISABLE   0x60000000

unsigned int memtest(unsigned int start, unsigned int end);
extern int io_load_eflags(void);
extern void io_store_eflags(int eflags);
extern void load_gdtr(int limit, int addr);
extern void load_idtr(int limit, int addr);
//extern unsigned int memtest_sub(unsigned int start, unsigned int end);
extern int load_cr0(void);
extern void store_cr0(int cr0);
unsigned int memtest_sub(unsigned int start, unsigned int end);




int memoryInt();
unsigned int memtest(unsigned int start, unsigned int end);

int memoryInt(){
    unsigned int memtotal;
    memtotal = memtest(0x01000000, 0xbfffffff);
    return memtotal;
}

unsigned int memtest(unsigned int start, unsigned int end)
{
    char flg486 = 0;
    unsigned int eflg, cr0, i;

    /* 386か、486以降なのかの確認 */
    i = memtest_sub(start, end);

    return i;
}
unsigned int memtest_sub(unsigned int start, unsigned int end)
{
    unsigned int i, *p, old, pat0 = 0xaa55aa55, pat1 = 0x55aa55aa;
    for (i = start; i <= end; i += 0x1000) {
        p = (unsigned int *) (i + 0xffc);
        old = *p;           /* いじる前の値を覚えておく */
        *p = pat0;          /* ためしに書いてみる */
        *p ^= 0xffffffff;   /* そしてそれを反転してみる */
        if (*p != pat1) {   /* 反転結果になったか？ */
not_memory:
            *p = old;
            break;
        }
        *p ^= 0xffffffff;   /* もう一度反転してみる */
        if (*p != pat0) {   /* 元に戻ったか？ */
            goto not_memory;
        }
        *p = old;           /* いじった値を元に戻す */
    }
    return i;
}
