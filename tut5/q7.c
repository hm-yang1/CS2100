#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Write a C function that will model the behavior of the ALU having the following function prototype:
int32_t ALU(int32_t in0, int32_t in1,
    uint4_t ALUcontrol, bool *ALUiszero);

//1 bit alu
int alu(int in0, int in1, bool a, bool b, int op, int* cin) {
    if (a) {
        in0 = ~in0;
    }
    if (b) {
        in1 = ~in1;
    }

    if (op == 0) {
        return in0 & in1;
    } else if (op == 1) {
        return in0 | in1;
    } else if (op == 2) {
        int result = in0 + in1 + *cin;
        if (result > 2) {
            result -= 2;
            *cin = 1;
        }
        return result;
    } else if (op == 3) {

    }
}

int32_t ALU(int32_t in0, int32_t in1,
    uint4_t ALUcontrol, bool *ALUiszero) {
        bool a = (ALUcontrol & 8) > 0;
        bool b = (ALUcontrol & 4) > 0;
        int op = ALUcontrol & 3;

        int result = 0;
        int *cin = 0;
        int power = 1;

        for (size_t i = 0; i < 32; i++)
        {
            int i0 = (in0 & power);
            int i1 = (in1 & power);
            int r = alu(i0, i1, a, b, op, cin);
            result += r * power;
            power *= 2;
        }

        if (result == 0) {
            *ALUiszero = true;
        } else {
            *ALUiszero = false;
        }
        return result
    }