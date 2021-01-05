/*macro definitions
*/

/*libraries included
*/

#include		<stdio.h>
#include		<stdlib.h>

	
/*node type definitions
*/
typedef struct node node, *znode;
typedef struct extension extension;
//typedef struct *node znode;

/*extension struct
*/
struct extension {
	/*extension properties
	*/
	int	n;
	/*extension references
	*/
	//node	*initial;
	node	**nodes;
};
//extern struct extension *ext;
/*node struct
*/
struct 	node {
	/*node properties
	*/
	int	data, *zdata;
	char	*key, *value;

	/*node references
	*/
	struct 		node *self;
	struct		node **super;
	

};
	/*node methods & functions
	*/
	void		zinit(struct node *n, struct extension *x);
	void		zfree(struct node *z);//node
	znode 		zmake(int n);
	//node 		makenode(int n);
	znode		zmemory(struct node *z);
	void		zswap(struct node *z, struct node *n);
	void		zchain(struct node *z, struct node *n);//node
	void		branch_succession(struct node *n, int e);
	void		chain_succession(struct node *n, int e, struct extension *x);
	void		succession(struct node *n, int e, struct extension *x);//extension
	void		ztraverse(struct node *n);

	/*node unit load testing
	*/
	void		initialTest(struct extension *x);

