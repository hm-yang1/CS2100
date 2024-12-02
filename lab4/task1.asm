# messages.asm
  .data 
str: .asciiz "the answer = "
  .text

main: 
    li   $v0, 4    # system call code for print_string
    la   $a0, str  # address of string to print
    syscall        # print the string

    li   $v0, 5    # system call code for read_int
    syscall        # save integer to $v0
    addi $a0, $v0, 0  # save integer to $a0

    li   $v0, 1    # system call code for print_int
    syscall        # print the integer
    
    li   $v0, 10   # system call code for exit
    syscall        # terminate program
