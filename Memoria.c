//
//  Memory.c
//  BalazOS
//
//  Created by José Slon Baltodano on 24/06/14.
//  Copyright (c) 2014 UCR. All rights reserved.
//

#include <stdio.h>
#include "system.h"

void Memoria(){
    
    banderaCons = 0;
    banderaArch = 0;
    tamanoDePagina = 80*22;
    numArchivo = 0;
    nArchivoACargar = 0;
    prompt = "root@OS$ ";
    
    //Inicializo la memoria en 0
    for ( int i =0; i<80*22*10; i++){
        memoria [i] = 0;
    }
    
    for (int i =0 ; i<10; i++) {
        archivos[i] = 0     ;
    }
    
}

//Obtiene los caracteres de pantalla y los agrega a memoria
void asignar(unsigned char * datosArch, int size, int inicio){
    int j=0;
    for (int i=0; i<size; i++) {
        memoria[i+inicio]=datosArch[j];
        j += 2;
        //Salta de uno de por medio para obtener solamente los caracteres en la memoria de video.
    }
    agregarATabla(inicio);
}


void agregarATabla(int inicio){
    if (numArchivo < 10) {
        archivos[numArchivo] = inicio;
        numArchivo ++;
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
 Despliega el archivo almacenado en memoria
 @param noArchivo Es el numero que corresponde a la tupla en la tabla de procesos
 */
void open(){
    char *memoriaPtr = &memoria[nArchivoACargar*tamanoDePagina];
    int inicio  = archivos[nArchivoACargar];
    
    for (int i = inicio; i < inicio+tamanoDePagina; i++) {
        printCh(memoriaPtr+i);
    }
    
}
