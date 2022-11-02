Ref: 
https://www.bogotobogo.com/cplusplus/debugging_core_memory_dump_segmentation_fault_gdb.php

1. Enable core file generated
  sudo bash -c 'echo core.%e.%p > /proc/sys/kernel/core_pattern'
  cat /proc/sys/kernel/core_pattern
  ulimit -c unlimited

2. Build, run and generate core file
  gcc test.cpp -lstdc++
  gdb a.out
  
    (gdb) disassemble main
    Dump of assembler code for function main:
      0x00005555554007aa <+0>:     push   %rbp
      0x00005555554007ab <+1>:     mov    %rsp,%rbp
      0x00005555554007ae <+4>:     sub    $0x40,%rsp
      0x00005555554007b2 <+8>:     mov    %fs:0x28,%rax
      0x00005555554007bb <+17>:    mov    %rax,-0x8(%rbp)
      0x00005555554007bf <+21>:    xor    %eax,%eax
      0x00005555554007c1 <+23>:    movl   $0x0,-0x30(%rbp)
      0x00005555554007c8 <+30>:    movl   $0x1,-0x2c(%rbp)
      0x00005555554007cf <+37>:    movl   $0x2,-0x28(%rbp)
      0x00005555554007d6 <+44>:    movl   $0x3,-0x24(%rbp)
      0x00005555554007dd <+51>:    movl   $0x4,-0x20(%rbp)
      0x00005555554007e4 <+58>:    movl   $0x5,-0x1c(%rbp)
      0x00005555554007eb <+65>:    movl   $0x6,-0x18(%rbp)
      0x00005555554007f2 <+72>:    movl   $0x7,-0x14(%rbp)
      0x00005555554007f9 <+79>:    movl   $0x8,-0x10(%rbp)
      0x0000555555400800 <+86>:    movl   $0x9,-0xc(%rbp)
      0x0000555555400807 <+93>:    movq   $0x0,-0x38(%rbp)
      0x000055555540080f <+101>:   mov    -0x38(%rbp),%rax
      0x0000555555400813 <+105>:   movl   $0x1,(%rax)
      0x0000555555400819 <+111>:   mov    $0x0,%eax
      0x000055555540081e <+116>:   mov    -0x8(%rbp),%rdx
      0x0000555555400822 <+120>:   xor    %fs:0x28,%rdx
      0x000055555540082b <+129>:   je     0x555555400832 <main+136>
      0x000055555540082d <+131>:   callq  0x555555400670 <__stack_chk_fail@plt>
      0x0000555555400832 <+136>:   leaveq 
      0x0000555555400833 <+137>:   retq   
    End of assembler dump.

Command to manager break points:
    b* 0x00005555554007f9
    b* 0x0000555555400822
    info b
      (gdb) info b
      Num     Type           Disp Enb Address            What
      1       breakpoint     keep y   0x00005555554007f9 <main+12>
      2       breakpoint     keep y   0x0000555555400822 <main+16>
    del 1-2

The vscode gdb help manage the break points for us.

running and continue:
  r
  c
check info
  info registers    =    i r
  inspect 
  p 0x7   (print a 0x7 in base 10)
  i r
  p/s (char*)$rdi   (print a string in this register)
  p/d $edx          (print a digital)
  p/d $rax


r and generate a core file, then you can:
gdb executable core_file
That is:
gdb a.out core_file    // this one should provide the exact function name



common assemble language explain
mov: move one to another, just like a copy operation.
movl (movw) (movb): move a long(4byte) word(2byte) byte.
https://zhuanlan.zhihu.com/p/410215049

