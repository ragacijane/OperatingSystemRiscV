#include "../project-base/lib/console.h"
#include "../project-base/lib/hw.h"

uint64 pc;

void a(){
    asm volatile("mv %0, ra" : "=r" (pc));
}

void b(){
    asm volatile("mv ra, %0" : : "r" (pc));
}

void main(){
    a();
    __putc('a');
    __putc('\n');
    b();
}