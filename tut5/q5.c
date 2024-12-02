#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void Control(uint8_t opcode,
    bool *_RegDst,
    bool *_Branch,
    bool *_MemRead,
    bool *_MemtoReg,
    uint8_t *_ALUOp,
    bool *_MemWrite,
    bool *_ALUSrc,
    bool *_RegWrite);

// Provide the C code for computing the following signals that would be in this function
// (a) RegDst
void RegDst(uint8_t opcode, bool *_RegDst) {
    uint8_t temp = ~opcode;
    if (temp & temp == UINT8_MAX) {
        *_RegDst = true;
    } else {
        *_RegDst = false;
    }
}

// (b) ALUSrc
void AluSrc(uint8_t opcode, bool *_ALUsrc) {
    if (opcode & 32 > 1) {
        *_ALUsrc = true;
    } else {
        *_ALUsrc = false;
    }
}

// (c) MemRead
void MemRead(uint8_t opcode, bool *_MemRead) {
    //Assuming 6 bit opcode
    if (opcode & 32 > 1) {
        if (opcode & 8 < 1) {
            *_MemRead = true;
            return;
        }
    }
    *_MemRead = false;
}

// (d) ALUop
void AluOp(uint8_t opcode, uint8_t *_ALUop) {
    if (opcode & 2 > 1) {
        *_ALUop = 0;
        return;
    } else if (opcode & 4) {
        *_ALUop = 1;
        return;
    } else if (opcode == 0) {
        *_ALUop = 2;
        return;
    }
}