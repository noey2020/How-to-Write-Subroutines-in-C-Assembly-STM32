## Welcome to GitHub Pages

Repeated Code in Subroutines        July 14, 2020

I appreciate comments. Shoot me an email at noel_s_cruz@yahoo.com!

Hire me!

As you write more code, a pattern emerges. We repeatedly use the same set of instructions.
A subroutine is deployed to reuse those snippets of code just to carry out that specific 
task. Using subroutines can increase the readability, quality, reliability, and 
maintainability of programs. It is modularization. It can be called anywhere. Once the 
subroutine is complete, it should return back to the place that called the subroutine. A
subroutine is also called a procedure, function, or a routine. The calling program is
called Caller and the subroutine called is known as Callee. The instruction that transfer
control back to the caller is known as Return.

How you write your subroutine depends on the task. It may or may not return a result. 
Usually, it receives some input arguments which it processes thereon. For example, 
finding the maximum of an array of elements might necessitate two arguments, namely:
the memory address (Pointer in C) of the array, and the number of items in the array.

The block of instructions that constitute a subroutine can be included at every point in
the main program. However, this would result in unnecessary waste of memory space. So
using subroutines increases the versatily by using only one copy of the instructions. In
software, there are many ways to "skin the cat", so to speak. To standardize writing
subroutines, the ABI(with OS) and EABI(without OS) application binary interface 
specifications suggest protocols implementing subroutines.

Calling a subroutine requires a deviation from the default sequential execution of
instructions. When a program branches to a subroutine, the processor begins execution of
the instructions that make up the subroutine and branch to the subroutine by modifying the
Program Counter (PC). In ARM, the Branch and Link instruction (BL) is used to Branch to
subroutine.

BL mySubroutine   ; Points to first line of subroutine

This instruction saves the current address of program counter (PC) in the link register
(LR) before placing the starting address of the subroutine in the program counter. When 
the subroutine has completed its task, the processor must be able to branch back (return)
to the instruction immediately following the branch instruction that invoked the
subroutine. To return from the subroutine we move the value stored in the link register
to program counter which returns the control to the next instruction from which
subroutine was called. Thus, to return from subroutine we should use the following 
instruction:

BX LR        ; Return to the instruction that called the subroutine

MOV PC, LR   ; Same as BX LR

A programmer designs subroutines in assembly considering three special issues.

1) The subroutine saves the environment by pushing registers to be used in the subroutine
   onto the stack at the beginning of the procedure. Before it branches to the other 
   non-contiguous code section, it must save the PC + 4 address to the Link Register (LR)
   so it can safely return to normal execution after it finishes the subroutine. The CPU
   will copy address of callee function to PC so it can jump execution to the callee.
   The BL instruction is 32bits/4bytes long and PC is incremented by 4 so PC + 4.
2) Second, it restores the environment by popping off the stack after encountering BX LR.
3) To facilitate sharing of code and such that C, C++, and Assembly programs can call 
   these subroutines, the ABI and EABI standard should be followed such prescribed 
   protocols of parameter passing and returning values are performed in compliance. For
   example, registers to use for passing parameters in arguments and returning values
   should be r0, r1, r2, and r3, registers r4 r8, r10, and r11 are normally used to hold
   the values of a routine's local variables, ARM and THUMB C and C++ compilers always
   use a full descending stack and it must be eight-byte aligned, to name a few.

ARM supports different branch instructions for conditional executions. Depending on the
condition, these instructions transfer the control from one part of the program to other.
Unlike Branch-and-Link (BL) instruction they do not save contents of Program counter (PC)
register to the Link Register (LR).

We can also nest subroutines. To do this, I have written an example code to demonstrate.

The C code generated the assembly listing exactly the same as the concepts presented
above. You can view it also from Debug's Disassembly window or from fromelf or objdump.

C Program:

void second_sub(){

}

void first_sub(){

    second_sub();
    
}

int main(){

    first_sub();
    
	while(1);
	
}

Assembly Snippet:

  11:C:\training\c_exercises\subroutine\ex_subroutine.c **** void first_sub(){
  
  56              		.loc 1 11 17
  
  57              		.cfi_startproc
  
  58              		@ Function supports interworking.
  
  59              		@ args = 0, pretend = 0, frame = 0
  
  60              		@ frame_needed = 1, uses_anonymous_args = 0
  
  61 0018 00482DE9 		push	{fp, lr}
  
  62              		.cfi_def_cfa_offset 8
  
  63              		.cfi_offset 11, -8
  
  64              		.cfi_offset 14, -4
  
  65 001c 04B08DE2 		add	fp, sp, #4
  
  66              		.cfi_def_cfa 11, 4
  
  12:C:\training\c_exercises\subroutine\ex_subroutine.c ****     second_sub();
  
  67              		.loc 1 12 5
  
  68 0020 FEFFFFEB 		bl	second_sub
  
  13:C:\training\c_exercises\subroutine\ex_subroutine.c **** }
  
  69              		.loc 1 13 1
  
  70 0024 0000A0E1 		nop
  
  71 0028 04D04BE2 		sub	sp, fp, #4
  
  72              		.cfi_def_cfa 13, 8
  
  73              		@ sp needed
  
  74 002c 0048BDE8 		pop	{fp, lr}
  
  75              		.cfi_restore 14
  
  76              		.cfi_restore 11
  
  77              		.cfi_def_cfa_offset 0
  
  78 0030 1EFF2FE1 		bx	lr

I included some posts for reference.

https://github.com/noey2020/How-to-Write-Multitasking-STM32

https://github.com/noey2020/How-to-Generate-Triangular-Wave-STM32-DAC

https://github.com/noey2020/How-to-Generate-Sine-Table-LUT

https://github.com/noey2020/How-to-Illustrate-Multiple-Exceptions-

https://github.com/noey2020/How-to-Blink-LED-using-Standard-Peripheral-Library

I appreciate comments. Shoot me an email at noel_s_cruz@yahoo.com!

Hire me!

Have fun and happy coding!


You can use the [editor on GitHub](https://github.com/noey2020/How-to-Write-Subroutines-in-C-Assembly-STM32/edit/master/README.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/noey2020/How-to-Write-Subroutines-in-C-Assembly-STM32/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
