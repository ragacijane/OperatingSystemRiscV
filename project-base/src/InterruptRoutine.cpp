#include "../lib/console.h"
#include "../lib/hw.h"

uint64 timerCount = 0;

extern "C" void handleSupervisorTrap(){
    uint64 scauseVar;
    __asm__ volatile ("csrr %[scause], scause" : [scause]"=r"(scauseVar));
    if (scauseVar == (0x01UL << 63 | 0x01)){
        timerCount++;
        if (timerCount >= 50){
            __putc('a');
            __putc('\n');
            timerCount=0;
        }
        __asm__ volatile ("csrc sip, 0x02"); //csr clean set 0 on bit 1
    }
    console_handler();
}
extern "C" void supervisorTrap();

void main(){
    __asm__ volatile ("csrw stvec, %[vector]" : : [vector] "r" (&supervisorTrap)); // csr write
    __asm__ volatile ("csrs sstatus, 0x02" ); // csr set
    while(1){}
}