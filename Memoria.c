//
//  Memory.c
//  BalazOS
//
//  Created by José Slon Baltodano on 24/06/14.
//  Copyright (c) 2014 UCR. All rights reserved.
//

#include <stdio.h>
#include "system.h"


/**
 Memoria() es una especie de "Constructor" que permite inicializar variables.
 Modifica: Inicializa la memoria, los archivos, y otras variables requeridas.
 @param  N/A
 */
void Memoria(){
    
    banderaCons = 0;
    banderaArch = 0;
    tamanoDePagina = 80*22;
    prompt = "root@BalazOS$ ";
    
    //Inicializo la memoria en 0 = vacio
    for ( int i =0; i<80*22*10; i++){
        memoria [i] = 0;
    }
    
    //Inicializo los archivos en 0 = vacio
    for (int i =0 ; i<10; i++) {
        archivos[i] = 0     ;
    }
    numProcs =0; 
}

/**
 Obtiene los caracteres de pantalla y los agrega a memoria.
 Modifica: La memoria y la tabla de archivos.
 @param datosProc son los caracteres que se digitan en pantalla, size indica el tamaño del la pagina del archivo, inicio indica el inicio del archivo
 */
void asignar(unsigned char * datosProc, int size, int inicio /*int hueco*/){
    int j=0;
    for (int i=0; i<size; i++) {
        memoria[i+inicio]=datosProc[j];
        j += 2;
        //Salta de uno de por medio para obtener solamente los caracteres en la memoria de video.
    }
    //los archivos se agregan a la tabla de archivos segun su ubicacion de incio
    agregarATabla(inicio);
}

/**
 Pemirte almacenar los archivos en la tabla de archivo.
 Modifica: La tabla de archivos.
 @param  EL inicio corresponde al numero de archivo que corresponde agregar.
 */
void agregarATabla(int inicio){
    if (numProcs < 10) {
        archivos[numProcs]= inicio  ;
        numProcs ++                 ;
    }
    else{
        clrscr();
        printStr("Ha superado el máximo de archivos, libere espacio eliminando archivos");
        banderaCons = 0;
        printStr(prompt);
    }
}

void liberarMemoria(int numeroArchivo){
   
}


/**
 Despliega el archivo almacenado en memoria.
 @param N/A 
 */
void open(){
    char *memoriaPtr = &memoria[numArchivo*tamanoDePagina];  //es un puntero a memoria donde esta el archivo
    int inicio  = archivos[numArchivo*tamanoDePagina];
    
    for (int i = inicio; i < inicio+tamanoDePagina; i++) {
        printCh(memoriaPtr+i);
    }
    
}
