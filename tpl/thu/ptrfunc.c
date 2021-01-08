/*this source code demonstrates how to implement pointers to functions in C.
*/
#include	<stdio.h>
#include	<stddef.h>//ptrdiff_t

/*this is a pointer to a function that takes two int arguments and returns a void */
//declare p* to be `a pointer to a function

//1. -> this function returns ``a float and takes in 1 integer arguments
float(*p)(int a);

//2. -> now we declare the function so that it can accommodate the function definition
void cpfunc(int n)	{
		printf("%d\n", n);
}



int main(void)	{
	//3. -> now we assign p to point to cpfunc
	void (*p)(int) = cpfunc;
	//call p
	p(199);
}
/*
function are just a colleciton of instructions in memory.
there no reason not to get a pointer to first instruction of the function
so that the th function can be called - this is useful for passing pointers into function within a function
-passing function which takes in pointer as an ARGUMENT - are you seeing this?
the  rough bit is just specifying arguments and out outputs
*/
