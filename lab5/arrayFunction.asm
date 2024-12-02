# arrayFunction.asm
       .data 
array: .word 8, 2, 1, 6, 9, 7, 3, 5, 0, 4
newl:  .asciiz "\n"

       .text
main:
	# Print the original content of array
	# setup the parameter(s)
    la $a0, array   #load arr address
    li $a1, 10      #load arr size
	# call the printArray function
    jal printArray

	# Ask the user for two indices
	li   $v0, 5         	# System call code for read_int
	syscall           
	addi $t0, $v0, 0    	# first user input in $t0
 
	li   $v0, 5         	# System call code for read_int
	syscall           
	addi $t1, $v0, 0    	# second user input in $t1

	# Call the findMin function
	# setup the parameter(s)
    la $t8, array           #load arr address
    sll $a0, $t0, 2         #index X 4
    add $a0, $a0, $t8       #addr in a0

    sll $a1, $t1, 2
    add $a1, $a1, $t8
	
    # call the function
    jal findMin

	# Print the min item
	# place the min item in $t3	for printing
    addi $s0, $v0, 0
    lw $t3, 0($s0)

	# Print an integer followed by a newline
	li   $v0, 1   		# system call code for print_int
    addi $a0, $t3, 0    # print $t3
    syscall       		# make system call

	li   $v0, 4   		# system call code for print_string
    la   $a0, newl    	# 
    syscall       		# print newline

	#Calculate and print the index of min item
    la $t9, array       #load addr of array
	sub $t0, $s0, $t9   #cal difference in addr
	# Place the min index in $t3 for printing	
    srl $t3, $t0, 2     #diff/4

	# Print the min index
	# Print an integer followed by a newline
	li   $v0, 1   		# system call code for print_int
    addi $a0, $t3, 0    # print $t3
    syscall       		# make system call
	
	li   $v0, 4   		# system call code for print_string
    la   $a0, newl    	# 
    syscall       		# print newline
	
	# End of main, make a syscall to "exit"
	li   $v0, 10   		# system call code for exit
	syscall	       		# terminate program
	

#######################################################################
###   Function printArray   ### 
#Input: Array Address in $a0, Number of elements in $a1
#Output: None
#Purpose: Print array elements
#Registers used: $t0, $t1, $t2, $t3
#Assumption: Array element is word size (4-byte)
printArray:
	addi $t1, $a0, 0	# $t1 is the pointer to the item
	sll  $t2, $a1, 2	# $t2 is the offset beyond the last item
	add  $t2, $a0, $t2 	# $t2 is pointing beyond the last item
l1:	
	beq  $t1, $t2, e1
	lw   $t3, 0($t1)	# $t3 is the current item
	li   $v0, 1   		# system call code for print_int
    addi $a0, $t3, 0   	# integer to print
    syscall       		# print it
	addi $t1, $t1, 4
	j    l1				# Another iteration
e1:
	li   $v0, 4   		# system call code for print_string
    la   $a0, newl    	# 
    syscall       		# print newline
	jr   $ra			# return from this function


#######################################################################
###   Student Function findMin   ### 
#Input: Lower Array Pointer in $a0, Higher Array Pointer in $a1
#Output: $v0 contains the address of min item 
#Purpose: Find and return the minimum item 
#              between $a0 and $a1 (inclusive)
#Registers used: $t0, $t1, $t2, $t9
#Assumption: Array element is word size (4-byte), $a0 <= $a1
findMin:
    addi $a1, $a1, 4
    addi $t0, $a0, 0      #load arr pointer($t0)
    addi $v0, $t0, 0      #load min addr($v0)
    lw $t1, 0($v0)      #load min value($t1)
loop:
    slt $t8, $t0, $a1
    beq $t8, $0, end
    lw $t2, 0($t0)      #load curr value($t2)
    slt $t9, $t2, $t1   #currVal < minVal ? change
    beq $0, $t9, increment
    addi $v0, $t0, 0      #change min addr to curr addr
    lw $t1, 0($v0)      #change min val to curr val
increment:
    addi $t0, $t0, 4
    j loop
end:
	jr $ra			# return from this function