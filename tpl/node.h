/*libraries included
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>

/*type definitions
*/
typedef	struct	node
		node,
		*znode;
/*structs
*/
struct	node	{

	int	size,
		n,
		*p;

	char 	*key, 
		*value;

	struct	node
		*self,
		**super;

};

/*funnctions
*/
