#include	<stdio.h>

/*my memcopy fucntion*/

int main(void)	{

	int x = 3490;
	int *p = &x;
	int **q = &p;
	int ***r = &q;
	int ****s = &r;
	int *****t = &s;
	printf("%d -> x\n\a",x);
	printf("%p -> &x\n\a",&x);
	printf("%d -> *p\n\a",*p);
	printf("%p -> &p\n\a",&p);
	printf("%d -> **q\n\a",**q);
	printf("%p -> &q\n\a",&q);
	printf("%d -> ***r\n\a",***r);
	printf("%p -> &r\n\a",&r);
	printf("%d -> ****s\n\a",****s);
	printf("%p -> &s\n\a",&s);
	int const ***const po;//po++ is not allowed on const
	int *const cp = &x;
	int *const *const cq = &cp;//will complain if *const isnt set
	/*causes
ptrptr.c:23:8: warning: initializing 'int **' with an expression of type 'int *const *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
        int **cq = &cp;
              ^    ~~~
1 warning generated.
That is, we’re saying that q is type int **, and if you dereference that, the
rightmost * in the type goes away. So after the dereference, we have type int *. And we’re assigning &p into it which is a pointer to an int *const, or, in other
words, int *const *.
But q is int **! A type with different constness on the first *! So we get a warning that the const in p’s int *const * is being ignored and thrown away.
We can fix that by making sure q’s type is at least as const as p.
    int x = 3490;
    int *const p = &x;
    int *const *q = &p;
And now we’re happy.
We could make q even more const. As it is, above, we’re saying, “q isn’t itself
const, but the thing it points to is const.” But we could make them both const:
    int x = 3490;
    int *const p = &x;
    int *const *const q = &p;  // More const!
And that works, too. Now we can’t modify q, or the pointer q points to.^^^
	*/
}
