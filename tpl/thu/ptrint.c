/*this source code demonstrates how to implement pointers to functions in C.*/
#include	<stdio.h>
#include	<stddef.h>//ptrdiff_t

int main(void)	{
	int cats[100];
	int *f = cats + 20;
	int *g = cats + 60;
	
	ptrdiff_t d = g - f;
	
	printf("Decimal:%td\n",d);
	printf("Hex:%tX\n",d);
	
}
