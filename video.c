#include "system.h"

void clrscr()
{
  unsigned char *vidmem = (unsigned char *)0xB8000;
  const long size = 80*25;
  long loop;

  // Clear visible video memory
  for (loop=0; loop<size; loop++) {
    *vidmem++ = 0;
    *vidmem++ = 0xF;
  }

  // Set cursor position to 0,0
  out(0x3D4, 14);
  out(0x3D5, 0);
  out(0x3D4, 15);
  out(0x3D5, 0);
}

void printStr(const char *_message) {
  unsigned short offset;
  unsigned long i;
  unsigned char *vidmem = (unsigned char *)0xB8000;

  // Read cursor position
  out(0x3D4, 14);
  offset = in(0x3D5) << 8;
  out(0x3D4, 15);
  offset |= in(0x3D5);

  // Start at writing at cursor position
  vidmem += offset*2;

  // Continue until we reach null character
  i = 0;
  while (_message[i] != 0) {
    *vidmem = _message[i++];
	vidmem += 2;
  }
    
  // Set new cursor position
  offset += i;
  out(0x3D5, (unsigned char)(offset));
  out(0x3D4, 14);
  out(0x3D5, (unsigned char)(offset >> 8));
}

void  printCh(const char *_message){
    unsigned short offset;
    unsigned char *vidmem = (unsigned char *)0xB8000;
    
    // Read cursor position
    out(0x3D4, 14);
    offset = in(0x3D5) << 8;
    out(0x3D4, 15);
    offset |= in(0x3D5);
    
    // Start at writing at cursor position
    vidmem += offset*2;
    *vidmem = _message[0];
    vidmem += 2;
    
    // Set new cursor position
    offset ++;
    out(0x3D5, (unsigned char)(offset));
    out(0x3D4, 14);
    out(0x3D5, (unsigned char)(offset >> 8));
    
    if (banderaCons==0) {
    kbd_buffer[indiceBuffer] = *_message;
    indiceBuffer++;
    }
}


void  printInt(int num){
    int x = 10;
    resultado[0] = (char)(num%x)+48;
    num = num - (num%x);

    for (int i = 1; i < 5; i++) {
        x *= 10;
        resultado[i] = (char)((num%x)/(x/10))+48;
        num = num - (num%x);
    }
    
    for (int i = 4; i >= 0; i--) {
        printCh(&resultado[i]);
    }
}