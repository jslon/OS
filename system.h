//
//  system.h
//  BalazOS
//
//  Created by José Slon Baltodano on 11/06/14.
//  Copyright (c) 2014 UCR. All rights reserved.
//

#ifndef BalazOS_system_h
#define BalazOS_system_h

int banderaCons;        //Si está 0 = Consola, 1 = editor de texto.
int banderaArch;        //Si está en 0 = archivo nuevo si esta en 1 es un archivo siendo modificado
int tamanoDePagina;
char * prompt;
int numArchivo;

//char *prompt = "admin@Balazos:";


//INTERRUPTS.C
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

extern void loadIDT();
extern void instalarInterrupciones();
struct idt;
struct idtr;

//KEYBOARD.C
extern unsigned char kbdus[];
extern void keyboakrd_handler();
extern void enter();
extern void comando();
extern void borrar();
extern void left();
extern void right();
extern void up();
extern void down();
extern void guardarYSalir();
extern void write();
extern void load(int numArchivo);
//extern void reubicarCursor();

//PORTS.C
extern unsigned char in();
extern unsigned char out();

//VIDEO.C
#define MAX_KEYS 0x100
#define MAX_LINE 200
extern void clrscr();
extern void printCh(const char *);
extern void printStr(const char *);
extern void printInt(int);
char kbd_buffer[MAX_KEYS];
int indiceBuffer;
char resultado[5];

//MEMORIA.c
#define INT32_MAX 0x7fffffff;
char memoria [80*22*10];   //memoria total = 17600 b
int archivos[10];           // 1 = hay un archivo, 0 = está vacio
int numProcs;   //numero de procesos actualemente en memoria.
extern void Memoria();
extern void asignar(unsigned char * datosProc, int size, int inicio);
extern void agregarATabla(int inicio);
extern void liberarMemoria (int numeroDeProceso);
//extern void bestFit(unsigned char * datosProc, int size);
extern void eliminarDeTabla(int numeroDeProceso);
extern void open();


#endif
