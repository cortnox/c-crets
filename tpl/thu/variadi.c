#include	<stdio.h>
#include	<stdlib.h>

struct 	node	{
	int	a;
	struct	node	
		*left,	
		*right;

};

void	occupy	(struct	node	**,	int);
void	suffix	(struct	node	*);//a morpheme added at the end of a node to form a derivative
void	infex	(struct	node	*);
void	prefix	(struct	node	*);//a node before another node
void	delete	(struct	node	**);



int	main	(void)	{
	int	choice	=	0,
		flag	=	0,
		j;//input
	
	struct	node	*head	=	NULL;
	do	{
		printf("options:\n");
		printf("[1] -> insert\t[2] -> index\t[3] -> prefix\t[4] -> suffix\t[5] -> exit\n");
		printf("Enter your choice:    ");
		scanf("%d",	&choice);
		switch	(choice)	{
		case 1:
			printf("enter element to insert: \n");
			scanf("%d",	&j);
			occupy(&head,j);
		break;
		case 2:
			infex(head);
		break;
		case 3:
			prefix(head);
		break;
		case 4:
			suffix(head);
		break;
		case 5:
			delete(&head);
			printf("Memory Cleared. Program Terminated.\n");
		break;
		default:
			printf("Invalid choice.\n");
		}

	}	while	(choice != 5);

	return EXIT_SUCCESS;
}

void	occupy(struct	node	**head,	int	j)	{
	struct	node
		*temp = *head,
		*prev = *head;
		if	(*head == NULL)	{
			*head = (struct node*)malloc(sizeof(struct node));
			(*head) -> a = j;
			(*head) -> left = (*head) -> right = NULL;
		}	else	{
			while	(temp != NULL)	{
				if	(j > temp -> a)	{
					prev = temp;
					temp = temp -> right;
				}	else	{
					prev = temp;
					temp = temp -> left;
				}
			}
			temp = (struct node*)malloc(sizeof(struct node));
			temp -> a = j;
			if	(j >= prev -> a)	{
				prev -> right = temp;
			}	else	{
				prev -> left = temp;
			}
		}
}

void	infex(struct	node	*head)	{
	if	(head)	{
		infex(head -> left);
		printf("%d\n", head -> a);
		infex(head -> right);
	}
}

void	prefix(struct	node	*head)	{
	if	(head)	{
		printf("%d\n", head -> a);
		prefix(head -> left);
		prefix(head -> right);
	}
}

void	suffix(struct	node	*head)	{
	if	(head)	{
		suffix(head -> left);
		suffix(head -> right);
		printf("%d\n", head -> a);
	}
}


void	delete(struct	node	**head)	{
	if	(*head != NULL)	{
		if	((*head) -> left)	{
			delete(&(*head) -> left);
		}
		if	((*head) -> right)	{
			delete(&(*head) -> right);
		}
	free(*head);
	}
}
/*
void	delete(struct	node	**head)	{
	if	(*head != NULL)	{
		if	((*head) -> left)	{
			delete(&(*head) -> left);
		}
		if	((*head) -> right)	{
			delete(&(*head) -> right);
		}
	free(*head);
	}
}

*/

/*


Variadic Functions
Variadic is a fancy word for functions that take arbitrary numbers of arguments. A regular function takes a specific number of arguments, for example:
    int add(int x, int y)
    {
return x + y; }
You can only call that with exactly two arguments which correspond to parameters x and y.
    add(2, 3);
    add(5, 12);
But if you try it with more, the compiler won’t let you:
add(2, 3, 4); // ERROR add(5); // ERROR
Variadic functions get around this limitation to a certain extent.
We’ve already seen a famous example in printf()! You can pass all kinds of things to it.
printf("Hello, world!\n");
printf("The number is %d\n", 2);
printf("The number is %d and pi is %f\n", 2, 3.14159);
It seems to not care how many arguments you give it!
Well, that’s not entirely true. Zero arguments will give you an error:
printf(); // ERROR
This leads us to one of the limitations of variadic functions in C: they must have
at least one argument.
But aside from that, they’re pretty flexible, even allows arguments to have
different types just like printf() does. Let’s see how they work!
Ellipses in Function Signatures
So how does it work, syntactically?
What you do is put all the arguments that must be passed first (and remember
there has to be at least one) and after that, you put .... Just like this: void func(int a, ...) // Literally 3 dots here
Here’s some code to demo that:
#include <stdio.h>
void func(int a, ...) {
printf("a is %d\n", a); // Prints "a is 2"
}
    int main(void)
    {
        func(2, 3, 4, 5, 6);
    }
So, great, we can get that first argument that’s in variable a, but what about the rest of the arguments? How do you get to them?
Here’s where the fun begins!
*/
