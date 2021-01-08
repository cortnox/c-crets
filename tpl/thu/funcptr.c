#include	<stdio.h>
/*this is some source code worth digesting.
the idea here is that we're passing a pointer to a function -> to operate(), 
its goig to do one of four avaible operation functions -> this way we can change the behaviour by passing anaother function into itinside main function are passing pointers to functions with the matching arguments types*/.

double	di	(	double	a,	double	b	)	
{
	return	a	/	b;
}

double	mu	(	double	a,	double	b	)	
{
	return	a	*	b;
}

double	su	(	double	a,	double	b	)	
{
	return	a	-	b;
}

double	ad	(	double	a,	double	b	)	
{
	return	a	+	b;
}
/*
the ops is a generic function that can take 2 double args and returns a double 
the second and third are normal x, y parameters;
*/
//                             |----------op-----------|        |---x---|       |---y---|\
\
parenthesis and * are what give away function pointers . -> it worths understanding these differnet signatures used fro the standard library functions -> qsort
void	operate	(	double	(*op)(double,	double),	double	x,	double	y)
{
	double	result	=	op(	x,	y	);
	printf	(	"	result:	\t	%.8f	\n	",	result	);
}

int	main	(void)	
{
	operate	(	di,	9,	8	);
	operate	(	mu,	9,	8	);
	operate	(	su,	9,	8	);
	operate	(	ad,	9,	8	);
}

