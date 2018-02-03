char *vidptr = (char*)0xb8000;
unsigned int current_loc = 0;
extern void dtoc(int num, char *str);
char* itoa(int i, char b[]);
void kprint(const char *str);
void kprintEnter();
void kprint_newline(void);
