# For the analysis
> I ran the diff command on O0, O1 and O1 and O3

## Difference between O0 and O1
1. The label naming scheme is different O1 has .LVL# labels that differentiate where in the stack the code resides
2. the print_dump function in O0 pushes r12 and rbx in addition to rbp onto the function stack
3. In fact, r12 is used a lot in the beginning of a sequence of instruction after defining a label
4. In O0 data seems to move in and out of rbp pointer. Using the pointer to store data rather than in separate registers seen in O1
5. There are fewer assembly directives in O0 than O1
6. From O0 to O1, there is a shift from resizing rbp and rsp registers and using already defined registers like rdi. In the main function, O0 had those edi copied into the rbp register @-52. However, O1 had the edi register be compared on directly.
7. Also, the number of lines in O0 is 579 lines shorter than O1
    - This could be due to a number of additional directives that the compiler has included
8. The way the labeling is structured, almost each important step in the print_dump and the main function are separated.

## Difference between O1 and O3
1. O1 and O3 are relatively the same
2. Point #8 in the first set of differences is more pronounced in O3 compared to O1.
3. There a lot more debugging directives
4. Registers like r11 - r15 and the specialized registers (rbx, rdi, and rax) are used more frequently. O3 is using most registers to speed up the runtime
5. THe number of lines in O1 is 506 lines shorter than O3
    - This could be due to a number additional directives that the compiler has included
