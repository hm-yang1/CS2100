#include <stdio.h>
#include <stdint.h>

// show how two-way multiplexors (MUX ) of different bit widths can be instantiated using
// the macro expansion facility of C. In other words, each call to the macro should yield a C function that
// implements a two-way multiplexing function (i.e., “if selection is 0, output is input0, and if selection
// is 1, output is input1) where the inputs and output are of bit width N.

#define MUX(N) \
uint##N##_t mux_##N(uint##N##_t input0, uint##N##_t input1, uint##N##_t sel) { \
    return (sel == 0) ? input0 : input1; \
}

//Bob
MUX(8)   // Generates a function mux_8 for 8-bit inputs
MUX(16)  // Generates a function mux_16 for 16-bit inputs
MUX(32)  // Generates a function mux_32 for 32-bit inputs

//
void main() {
    // Test MUX with 8-bit inputs
    uint8_t result8 = mux_8(5, 10, 0);  // Selects input0 (5)
    uint16_t result16 = mux_16(100, 200, 1);  // Selects input1 (200)
    printf("%d, %d", result8, result16);
    return;
}