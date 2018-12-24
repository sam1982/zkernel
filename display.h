#define COLUMNS 80
#define LINE 60
#define RATIO 108H

#define BYTES_FOR_EACH_ELEMENT 2
#define COLUMNS_IN_LINE 80

void set_ratio();
extern void s_set_ratio();
void set_ratio();
void kprintEnter();
void kprintCmd();
void kprint(const char *str);
void kprint_char(const char str);
void move_cursor();
void kprint_newpage(void);
