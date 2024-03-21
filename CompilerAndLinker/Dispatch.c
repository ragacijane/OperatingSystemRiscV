#include "../project-base/lib/hw.h"
#include "../project-base/lib/console.h"

uint64 pc;

void f() {
    __putc('a');
    __putc('\n');

    asm volatile("mv ra, %0" : :"r" (pc));
    asm volatile("sd ra, 8(sp)");
}

void dispatch() {
    asm volatile("mv %0, ra" : "=r" (pc));
    asm volatile("mv ra, %0" : :"r" (f));
}

void main(){
    dispatch();
}