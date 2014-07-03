//
//  Interrupts.c
//  BalazOS
//
//  Created by José Slon Baltodano on 02/06/14.
//  Copyright (c) 2014 UCR. All rights reserved.
//
#include "system.h"


#pragma pack (push, 1)
//!Descriptor de una interrupcion
struct idt {
    
	//! bits 0-16 of interrupt routine (ir) address
	unsigned short		baseLo;
    
	//! code selector in gdt
	unsigned short		sel;
    
	//! reserved, shold be 0
	unsigned char		reserved;
    
	//! bit flags. Set with flags above
	unsigned char		flags;
    
	//! bits 16-32 of ir address
	unsigned short		baseHi;
};


//!Descriptor del registro que apunta al vector de descriptores de interrupciones
struct idtr {
    
    //! size of the interrupt descriptor table (idt)
    unsigned short      limit;
    
    //! base address of idt
    unsigned long      base;
};
#pragma pack (pop)

struct idtr reg_idts;
struct idt int_[48]; //Vector de Interripciones



//!para uso de los PIC;s - chips que controlan IRQ's del 0 - 7 y  8 - 15
#define MASTER       0x20
#define MASTERDATA   0x21
#define SLAVE        0xA0
#define SLAVEDATA    0xA1
#define EOI          0x20
#define ICW1_INIT    0x10               // required for PIC initialisation
#define ICW1_EDGE    0x08               // edge triggered IRQs
#define ICW1_SINGLE  0x02               // only MASTER (not cascaded)
#define	ICW1_ICW4    0x01               // there IS an ICW4 control word

#define ICW4_SFNM    0x10               // Special Fully Nested Mode
#define ICW4_BUFFER  0x08               // Buffered Mode
#define ICW4_MASTER  0x04               // this is the Master PIC
#define ICW4_AEOI    0x02               // Auto EOI
#define ICW4_8086    0x01               // 80/86 Mode

#define cantIRQS 48

//!Actualiza el PIC para que las interrupciones de Modo
//!Protegido queden en pocisiones distinas a los IRQ'S
void remapPIC(int pic1, int pic2) {
    unsigned char md,sd;
    
    md=in(MASTERDATA);                     // save state of MASTER DATA
    sd=in(SLAVEDATA);                      // save state of SLAVE DATA
    
    out(MASTER, EOI);                      // Send EOI | resets the chip
    
    out(MASTER, ICW1_INIT+ICW1_ICW4);      // ICW1 control word setup | just basic PIC stuff
    out(SLAVE, ICW1_INIT+ICW1_ICW4);       // see pic.h for more details about the values
    
    out(MASTERDATA, pic1);                 // ICW2 maps IRQs 0-7 to whatever kernel passes
    out(SLAVEDATA, pic2);                  // and same here except with IRQs 8-15
    
    out(MASTERDATA, 0x04);                 // ICW3
    out(SLAVEDATA, 0x02);
    
    out(MASTERDATA, ICW4_8086);            // ICW4 control word setup
    out(SLAVEDATA, ICW4_8086);
    
    out(MASTERDATA,md);                    // restore both MASTER DATA
    out(SLAVEDATA,sd);                     // restore SLAVE DATA
}


void cargarInt(unsigned int base, int numInt){
    int_[numInt].baseLo      =   base & 0xffff;
    int_[numInt].baseHi      =   (base >> 16) & 0xffff;
    int_[numInt].reserved    =   0;
    int_[numInt].flags       =   0x8E ;
    int_[numInt].sel         =   0x08;
    
}



void instalarInterrupciones(){
    //!remap para que no hagan conflictos los irqs con los errores de cpu
    remapPIC(0x20, 0x28);
    
    //!pongo los punteros al vector de IDT's
    reg_idts.limit = sizeof (struct idt)*(cantIRQS -1);
    reg_idts.base = (unsigned int) int_;
    
    //Habilita interrupcion para el reloj
    out(0x21,0xFC);
    out(0xA1,0xFF);
    
    
    //unsigned int base = (unsigned int) &isr0;

    /*
    //!inicializo los IDTs
    int e;
    for ( e= 0; e < cantIRQS; e++) {
        int_[e].baseLo      =   base & 0xffff;
        int_[e].baseHi      =   (base >> 16) & 0xffff;
        int_[e].reserved    =   0;
        int_[e].flags       =   0x8E ;
        int_[e].sel         =   0x08;
    }
    */

    //ISR'S
    cargarInt((unsigned int)&isr0, 0);
    cargarInt((unsigned int)&isr1, 1);
    cargarInt((unsigned int)&isr2, 2);
    cargarInt((unsigned int)&isr3, 3);
    cargarInt((unsigned int)&isr4, 4);
    cargarInt((unsigned int)&isr5, 5);
    cargarInt((unsigned int)&isr6, 6);
    cargarInt((unsigned int)&isr7, 7);
    cargarInt((unsigned int)&isr8, 8);
    cargarInt((unsigned int)&isr9, 9);
    cargarInt((unsigned int)&isr10, 10);
    cargarInt((unsigned int)&isr11, 11);
    cargarInt((unsigned int)&isr12, 12);
    cargarInt((unsigned int)&isr13, 13);
    cargarInt((unsigned int)&isr14, 14);
    cargarInt((unsigned int)&isr15, 15);
    cargarInt((unsigned int)&isr16, 16);
    cargarInt((unsigned int)&isr17, 17);
    cargarInt((unsigned int)&isr18, 18);
    cargarInt((unsigned int)&isr19, 19);
    cargarInt((unsigned int)&isr20, 20);
    cargarInt((unsigned int)&isr21, 21);
    cargarInt((unsigned int)&isr22, 22);
    cargarInt((unsigned int)&isr23, 23);
    cargarInt((unsigned int)&isr24, 24);
    cargarInt((unsigned int)&isr25, 25);
    cargarInt((unsigned int)&isr26, 26);
    cargarInt((unsigned int)&isr27, 27);
    cargarInt((unsigned int)&isr28, 28);
    cargarInt((unsigned int)&isr29, 29);
    cargarInt((unsigned int)&isr30, 30);
    cargarInt((unsigned int)&isr31, 31);
    
    //IRQ'S
    cargarInt((unsigned int)&irq0, 32);
    cargarInt((unsigned int)&irq1, 33);
    cargarInt((unsigned int)&irq2, 34);
    cargarInt((unsigned int)&irq3, 35);
    cargarInt((unsigned int)&irq4, 36);
    cargarInt((unsigned int)&irq5, 37);
    cargarInt((unsigned int)&irq6, 38);
    cargarInt((unsigned int)&irq7, 39);
    cargarInt((unsigned int)&irq8, 40);
    cargarInt((unsigned int)&irq9, 41);
    cargarInt((unsigned int)&irq10, 42);
    cargarInt((unsigned int)&irq11, 43);
    cargarInt((unsigned int)&irq12, 44);
    cargarInt((unsigned int)&irq13, 45);
    cargarInt((unsigned int)&irq14, 46);
    cargarInt((unsigned int)&irq15, 47);
    
    
     __asm__("sti");
    
    //!cargo el registro que contiene la dir de los IDTS
    //__asm__("lidt [ ebx ]" : : "ebx" (&reg_idts));
    //asm volatile("LIDT (%0) ": :"p"(&reg_idts));
    loadIDT();
}


// INTERRUPCIONES

void interrupt_0(){}
void interrupt_1(){}
void interrupt_2(){}
void interrupt_3(){}
void interrupt_4(){}
void interrupt_5(){}
void interrupt_6(){}
void interrupt_7(){}
void interrupt_8(){}
void interrupt_9(){}
void interrupt_10(){}
void interrupt_11(){}
void interrupt_12(){}
void interrupt_13(){}
void interrupt_14(){}
void interrupt_15(){}
void interrupt_16(){}
void interrupt_17(){}
void interrupt_18(){}
void interrupt_19(){}
void interrupt_20(){}
void interrupt_21(){}
void interrupt_22(){}
void interrupt_23(){}
void interrupt_24(){}
void interrupt_25(){}
void interrupt_26(){}
void interrupt_27(){}
void interrupt_28(){}
void interrupt_29(){}
void interrupt_30(){}
void interrupt_31(){}
void interrupt_32(){    //interrupción del temporizador
    
}
void interrupt_33(){    //interrupción del teclado
    keyboard_handler();
}

void interrupt_34(){}
void interrupt_35(){}
void interrupt_36(){}
void interrupt_37(){}
void interrupt_38(){}
void interrupt_39(){}
void interrupt_40(){}
void interrupt_41(){}
void interrupt_42(){}
void interrupt_43(){}
void interrupt_44(){}
void interrupt_45(){}
void interrupt_46(){}
void interrupt_47(){}

