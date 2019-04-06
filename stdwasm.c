#include "stdwasm.h"

// you would use this variable to write your own malloc/free
extern unsigned char __heap_base;

export void *get_heap_base() { return &__heap_base; }

void* malloc(unsigned long size){
  return (void*)123;
}
