/* Noel S Cruz	July 14, 2020

   ex_subroutine.c Demonstrates subroutine calling. Starting from main calling first_sub
   and first_sub calling second_sub. We generate assembly listing to show first_sub
   preserving context by cpu automatically saving registers according to eabi before
   yielding control to second_sub. */

void second_sub(){
}

void first_sub(){
    second_sub();
}

int main(){
    first_sub();
	while(1);
}
