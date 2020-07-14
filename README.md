## Welcome to GitHub Pages

Repeated Code in Subroutines        July 14, 2020

I appreciate comments. Shoot me an email at noel_s_cruz@yahoo.com!

Hire me!

As you write more code, a pattern emerges. We repeatedly use the same set of instructions.
A subroutine is enabled to reuse those snippets of code just to carry out that specific 
task. Using subroutines can increase the readability, quality, reliability, and 
maintainability of programs. It is modularization. A subroutine is also called a 
procedure, function, or a routine.

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

A programmer designs subroutines in assembly considering three special issues.

1) The subroutine saves the environment by pushing registers to be used in the subroutine
   onto the stack at the beginning of the procedure. Before it branches to the other 
   non-contiguous code section, it must save the PC + 4 address to the Link Register (LR)
   so it can safely return to normal execution after it finishes the subroutine. The CPU
   will copy address of callee function to PC so it can jump execution to the callee.
2) Second, it restores the environment by popping off the stack after encountering BX LR.
3) To facilitate sharing of code and such that a C program can call these subroutines,
   the ABI and EABI standard should be followed such prescribed protocols of parameter
   passing and returning values are performed in compliance. For example, registers to 
   use for passing parameters in arguments should be r0, r1, and r2, etc.

We can also nest subroutines. To do this, I have written an example code to demonstrate

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
