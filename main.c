#include "system.h"

void principal() {

    indiceBuffer = 0;
    
    Memoria();      //inicializo la memoria
    clrscr();       //limpio la pantalla
    printStr("Bienvenido a BalazOS");
    enter();
    instalarInterrupciones();
    

    for(;;);
}
