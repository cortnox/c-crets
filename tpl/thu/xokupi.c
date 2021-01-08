#include	<stdio.h>
#include	<stdlib.h>
#include	<stdint.h>//uintptr_t/intptr_t
#include	<stddef.h>//ptrdiff_t



typedef struct node node;

struct node	{
	char	c,
		*key,
		*value;
	unsigned	
	int	guid;
};



void *xokupi(void *dest, const void *src, size_t n)	{
	//make local unsigned char variables
	const unsigned char *s = src;
	unsigned char *d = dest;
	while (n-- > 0)	{
		*d++ = *s++;
		printf("[%s]",s);
	}
	return dest;
}

void zout(struct node *z)	{
	printf("[c:%c][key:%s][value:%s][guid:%d]\n",
		z->c, z->key, z->value, z -> guid);
}


int main(void)	{
	struct node Z = {
		 .c	= 'c'
		,.key	= "name"
		,.value	= "c-node"
		,.guid	= 9
	};
	struct node *pZ = &Z;
	struct node cz;
	struct node *cZ = &cz;
	xokupi(&cz, &Z, sizeof(Z)); 
	printf("\n");
	zout(cZ);
	zout(pZ);
	unsigned char *p = (unsigned char *)&Z;

	for (size_t i = 0; i < sizeof Z; ++i)	{
		printf("[%02X]",p[i]);
	}
	return EXIT_SUCCESS;
}
