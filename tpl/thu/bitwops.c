//this source code demonstrates BITWISE OPERATIONS -> &AND, |OR, ^XOR and ~NOT
/* for each of these useaul math arithmetic conversoins take place on the operands - whic in this case must be integer type*/

#include <stdio.h>
typedef struct node node;

struct node {
	int a,	b,	c;
	
};

int main(void)	{
	struct node z = { .a=0, .b=39, .c=2 };
	z.a	&=	z.b;
	printf("[shorthand AND][&]\t[a]%d\t&=\t[b]%d\n", z.a, z.b);
	z.a	&=	z.c;
	printf("[shorthand AND][&]\t[a]%d\t&=\t[b]%d\n", z.a, z.c);
	z.a	=	z.b	&	z.c;
	printf("[AND][&]\t[a]%d\t=\t[b]%d & [c]%d\n", z.a, z.b, z.c);
	z.a	|=	z.b;
	printf("[shorthand OR ][|]\t[a]%d\t|=\t[b]%d\n", z.a, z.b);
	z.a	|=	z.c;
	printf("[shorthand OR][|]\t[a]%d\t|=\t[b]%d\n", z.a, z.c);
	z.a	=	z.b	|	z.c;
	printf("[OR ][|]\t[a]%d\t=\t[b]%d | [c]%d\n", z.a, z.b, z.c);
	z.a	^=	z.b;
	printf("[shorthand XOR][^]\t[a]%d\t^=\t[b]%d\n", z.a, z.b);
	z.a	^=	z.c;
	printf("[shorthand XOR][^]\t[a]%d\t^=\t[b]%d\n", z.a, z.c);
	z.a	=	z.b	^	z.c;
	printf("[XOR][^]\t[a]%d\t=\t[b]%d ^ [c]%d\n", z.a, z.b, z.c);
	z.a	=		~	z.a;
	printf("[NOT][~]\t[a]%d\t=\t ~ [a]%d\n", z.a, z.a);
	z.a	=		~	z.b;
	printf("[NOT][~]\t[a]%d\t=\t ~ [b]%d\n", z.a, z.b);
	z.a	=		~	z.c;
	printf("[NOT][~]\t[a]%d\t=\t ~ [c]%d\n", z.a, z.c);
	//printf("[AND][&][[a]%d=[b]%d&[c]%d]\n", z -> a, z -> b, z -> c);
}




