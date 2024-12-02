#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 6. Write a C program that will model ALUcontrol

uint4_t ALUcontrol(uint2_t _ALUop, uint6_t _funct) {
    int a0, a1, a2, a3;

    //ALUcontrol3 = 0
    a3 = 0;
    

    //ALUcontrol2 = (F1 & ALUop1) | (ALUop0)
    if (_ALUop > 1 && (_funct & 2) > 1) {
        a2 = 1;
    } else if ((_ALUop & 1) == 1) {
        a2 = 1;
    } else {
        a2 = 0;
    }
    
    //ALUcontrol1 = ALUop1 & !F2
    if (_ALUop > 1 && (_funct|0) < 2) {
        a1 = 1;
    } else {
        a1 = 0;
    }

    //ALUcontrol0 = (F0 | F3) & ALUop1


}