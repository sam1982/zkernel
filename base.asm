bits 32


global a_memtest_sub
global io_load_eflags
global io_store_eflags
global load_cr0,store_cr0
global s_set_ratio


section .text



a_memtest_sub:   ; unsigned int memtest_sub(unsigned int start, unsigned int end)
        PUSH    EDI                     ; （EBX, ESI, EDI も使いたいので）
        PUSH    ESI
        PUSH    EBX
        MOV     ESI,0xaa55aa55          ; pat0 = 0xaa55aa55;
        MOV     EDI,0x55aa55aa          ; pat1 = 0x55aa55aa;
        MOV     EAX,[ESP+12+4]          ; i = start;

io_load_eflags:    ; int io_load_eflags(void);
        PUSHFD      ; PUSH EFLAGS という意味
        POP     EAX
        RET

io_store_eflags:   ; void io_store_eflags(int eflags);
        MOV     EAX,[ESP+4]
        PUSH    EAX
        POPFD       ; POP EFLAGS という意味
        RET

load_cr0:      ; int load_cr0(void);
        MOV     EAX,CR0
        RET

store_cr0:     ; void store_cr0(int cr0);
        MOV     EAX,[ESP+4]
        MOV     CR0,EAX
        RET

s_set_ratio:
        ;mov ax,4F02H
        ;mov bx,108h ;set 80x60
        ;int 10H
        ;hlt
