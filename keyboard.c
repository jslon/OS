//
//  keyboardHandler.c
//  BalazOS
//
//  Created by José Slon Baltodano on 30/05/14.
//  Copyright (c) 2014 UCR. All rights reserved.
//

#include <stdio.h>
#include "system.h"


/**
 Editor de Texto
 @param  N/A
 */
void write(){
    banderaCons = 1;
    banderaArch = 0;
    clrscr();
    printStr("                                     write");
    enter();
}

/**
 Editor de Texto
 @param  N/A
 */

void load(int n){
    write();
    numArchivo = n;
    banderaArch = 1;
    open();
    
}

/**
 Copia lo que se encuentra entre las lineas 3 y 24 a la memoria mediante el algoritmo bestFit y vuelve al modo consola.
 @param  N/A
 */
void guardarYSalir(){
    unsigned char *vidmem = (unsigned char *)0xB8000+(80*2);
    if (banderaCons == 1) {      //si esta en write
        //bestFit(vidmem, tamanoDePagina);
        asignar(vidmem, tamanoDePagina, numArchivo * tamanoDePagina);
        clrscr();
        printStr("Archivo guardado");
        
        //esperar unos segundos
        
        clrscr();
        printStr(prompt);
        banderaCons = 0;
        indiceBuffer = 0;
    }
}

/**
 <#Description#>
 @param  <# description#>
 */
void salir(){
    if (banderaCons == 1) {
        clrscr();
        printStr(prompt);
        banderaCons = 0;
        indiceBuffer = 0;
    }
}

//Teclas especiales
/**
 
 @param  <# description#>
 */
void enter(){
    unsigned short offset;
    unsigned int nlinea;
    
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    nlinea = offset/80;
    offset = 80*(nlinea+1);
    
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
    
    
    
    if (banderaCons == 0) {// si esta en consola
        printStr(prompt);
        indiceBuffer = 0;
    }
}

/*
void reubicarCursor(){
    unsigned short offset;
    unsigned char *vidmem = (unsigned char *)0xB8000+(tamanoDePagina*2);
    
    while (*vidmem == ' ') {
        vidmem -= 2;
    }
    
    offset = (short)vidmem;
    
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
}
*/

/**
 <#Description#>
 @param  <# description#>
 */
void left(){
    unsigned short offset;
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset--;
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
}

/**
 <#Description#>
 @param  <# description#>
 */
void right(){
    unsigned short offset;
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset++;
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
}

/**
 <#Description#>
 @param  <# description#>
 */
void up(){
    unsigned short offset;
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset -= 80;
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
}

/**
 <#Description#>
 @param  <# description#>
 */
void down(){
    unsigned short offset;
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset += 80;
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
}

/**
 <#Description#>
 @param  <# description#>
 */
void borrar(){
    unsigned short offset;
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset --;
    //*** si (cursor-1 == $) && (cursor == ' ') no haga nada
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
    // imprime un espacio
    printCh(&kbdus[58]);
    // Read new cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    offset --;
    // Set new cursor position
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
    indiceBuffer--;
    indiceBuffer--;
}

//Lectura de comandos

/**
 <#Description#>
 @param  <# description#>
 */
void comandos(){
    //write
    if(kbd_buffer[0]== 'w'){
        if(kbd_buffer[1] == 'r'){
            if(kbd_buffer[2] == 'i'){
                if (kbd_buffer[3] == 't') {
                    if (kbd_buffer[4] == 'e') {
                        write();
                        indiceBuffer = 0;
                    }
                }
            }
        }
    }
    //cargar archivo
    if (kbd_buffer[0]== 'l') {
        if (kbd_buffer[1] == 'o') {
            if (kbd_buffer[2] == 'a') {
                if (kbd_buffer[3] == 'd') {
                    if (0 < kbd_buffer[4] < 10) {
                        load((int)kbd_buffer[4]-48);
                        //write();
                        //open();
                        indiceBuffer = 0;
                    }
                }
            }
        }
    }
    
    //shutdown
    if (kbd_buffer[0] == 's') {
        if (kbd_buffer[1] == 'h') {
            if (kbd_buffer[2] == 'u') {
                if (kbd_buffer[3] == 't') {
                    if (kbd_buffer[4] == 'd') {
                        if (kbd_buffer[5] == 'o') {
                            if (kbd_buffer[6] == 'w') {
                                if (kbd_buffer[7] == 'n') {
                                    clrscr();
                                    __asm__( "hlt" );
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    else {
        enter();
    }
}

//Arreglo de caracteres del teclado
unsigned char kbdus[128] =

{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
    '9', '0', '-', '=', '\b',	/* Backspace */
    '\t',			/* Tab */
    'q', 'w', 'e', 'r',	/* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    122,			/* 29   - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
    '\'', '`',   0,		/* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
    'm', ',', '.', '/',   0,				/* Right shift */
    '*',
    123,	/* Alt */
    ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    124,	/* Up Arrow */
    0,	/* Page Up */
    '-',
    126,	/* Left Arrow */
    0,
    127,	/* Right Arrow */
    '+',
    0,	/* 79 - End key*/
    125,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};


// Maneja la interrupción del teclado
void keyboard_handler() {
    unsigned char scancode;
    
    //Lee del búfer del teclado
    scancode = in(0x60);
    
    /* Si el bit más significativo que leemos del teclado está
     encendido, significa que se acaba de soltar una tecla*/
    if (scancode & 0x80) {
        
    }
    else {  // Una tecla acaba de ser presionada
        char tecla = kbdus[scancode];
        
        switch (tecla) {        // *** Teclas especiales ***
            case '\n':          // \n
                comandos();
                break;
            case '\b':          // \b
                borrar();
                break;
            case 126:
                left();
                break;
            case 127:
                right();
                break;
            case 124:
                up();
                break;
            case 125:
                down();
                break;
            case 122:
                salir();
                break;
            case 123:         //alt
                guardarYSalir();
                break;
                
            default:
                printCh(&kbdus[scancode]);
                break;
        }
    }
}
