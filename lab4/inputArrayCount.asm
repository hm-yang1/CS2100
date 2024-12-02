# arrayCount.asm
  .data 
arrayA: .word 11, 0, 31, 22, 9, 17, 6, 9   # arrayA has 5 values
count:  .word 0             # dummy value

  .text
main:    
    # code to setup the variable mappings
    la   $t0, arrayA  # map base address of arrayA to t0
    lw   $t8, count   # map value of count to t8

    # read 8 values to arrayA
    addi $t9, $0, 0   # set index for loop
    addi $t7, $0, 8   # set max for loop

read:
    beq $t9, $t7, endRead
    li   $v0, 5    # system call code for read_int
    syscall        # save integer to $v0
    addi $a0, $v0, 0  # save integer to $a0
    sw   $a0, 0($t0)   # store value to arrayA
    addi $t0, $t0, 4    # increment loop stuff
    addi $t9, $t9, 1
    j read

endRead:
    la   $t0, arrayA  # map base address of arrayA to t0

    # code for reading in the user value X
    li   $v0, 5    # system call code for read_int
    syscall        # save integer to $v0
    addi $a0, $v0, 0  # save integer to $a0
    addi $t5, $a0, -1   # save mask to $t5

    # set up index for loop
    addi $t9, $0, 0   # set index for loop
    addi $t7, $0, 8   # set max for loop

loop:
    # code for counting multiples of X in arrayA
    beq $t9, $t7, exitLoop
    lw  $t1, 0($t0) # read current value into $t9
    and  $t2, $t1, $t5  # check if is multiple, $t2 = 0 if multiple
    bne  $t2, $0, notMultiple
    addi  $t8, $t8, 1

notMultiple:
    # increment loop stuff
    addi $t0, $t0, 4    # increment loop stuff
    addi $t9, $t9, 1
    j loop

exitLoop:
    # code for printing result
    sw   $t8, count   # store no. of multiples back to count
    li   $v0, 1    # system call code for print_int
    addi  $a0, $t8, 0  # integer to print
    syscall        # print the integer

    # code for terminating program
    li  $v0, 10
    syscall
