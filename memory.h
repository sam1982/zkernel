#define EFLAGS_AC_BIT       0x00040000
#define CR0_CACHE_DISABLE   0x60000000

#define MEMMAN_FREES        4090    /* これで約32KB */
#define MEMMAN_ADDR         0x003c0000

//汇编
extern int io_load_eflags(void);
extern void io_store_eflags(int eflags);
extern void load_gdtr(int limit, int addr);
extern void load_idtr(int limit, int addr);
extern int load_cr0(void);
extern void store_cr0(int cr0);

//探测总内存的2个函数
unsigned int memtest_sub(unsigned int start, unsigned int end);
unsigned int memtest(unsigned int start, unsigned int end);

struct FREEINFO {   /* 可用信息 */
    unsigned int addr, size;
};

struct MEMMAN {     /* 内存管理 */
    int frees, maxfrees, lostsize, losts;
    struct FREEINFO free[MEMMAN_FREES];
};


void memman_init(struct MEMMAN *man);
int memoryInt();
unsigned int memman_total(struct MEMMAN *man);
unsigned int memman_alloc(struct MEMMAN *man, unsigned int size);
int memman_free(struct MEMMAN *man, unsigned int addr, unsigned int size);
unsigned int kernel_mem_end_test(unsigned int end);

