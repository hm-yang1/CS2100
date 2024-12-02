#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t instruction_memory[1073741824];
uint32_t data_memory[1073741824];
uint32_t registers[32];
// (a) Write a C data structure and a function to describe the register file and its operation.
typedef struct RegFile
{
    uint8_t rr1;
    uint8_t rr2;

    uint8_t wr;
    uint32_t wd;

    uint32_t rd1;
    uint32_t rd2;

    bool regWrite
} rf;

rf rfOperation(uint8_t r1, uint8_t r2, uint8_t wR, uint32_t wD, bool rW) {
    rf regFile;
    regFile.rr1 = r1;
    regFile.rr2 = r2;
    regFile.wr = wR;
    regFile.wd = wD;
    regFile.regWrite = rW;

    regFile.rd1 = registers[regFile.rr1];
    regFile.rd2 = registers[regFile.rr2];

    if (regFile.regWrite) {
        registers[regFile.wr] = regFile.wd;
    }

    return regFile;
}

// (b) Write a C data structure and a function to describe the data memory and its operation.
typedef struct DataMemory
{
    uint32_t address;
    uint32_t wd;
} dm;

uint32_t dataMemOperation(uint32_t addr, uint32_t data, bool memR, bool memW) {
    dm dataMem;
    dataMem.address = addr;
    dataMem.wd = data;

    if (memR && memW) {
        return 1;
    }

    if (memR) {
        return data_memory[dataMem.address];
    }
    if (memW) {
        data_memory[dataMem.address] = dataMem.wd;
    }
    return 0;
}