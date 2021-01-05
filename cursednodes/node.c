/*libraries included
*/
#include		"node.h"

/*node methods & functions  -> order is inverted (reversed) from the .h file
*/
	void	initialTest(struct extension *x) {
		int	e;//extension boundary
		printf("Enter an extension boundary for node:\n");
		scanf("%d", &e); 
		printf("%d was entered.\n", e);
		znode   zn = zmake(e);
		x -> n = e;
		x -> nodes[0] = zn;
		zinit(zn,x);
		//ztraverse(zn);
	}                                                      

	void	ztraverse(struct node *n) {
		for (struct node *z = n; z != NULL; z = z -> self) {
			for (int i = 0; i < z -> data; ++i) {
				printf("\t");
			}
			printf("node:%d\n", z -> data);
		}
		/*
		for (int i = 0; i < ext; ++i) {
			printf("node:%d has been flushed\n", n -> super[i] -> data);
			free(n -> super[i]);
		}*/
	}

	void	succession(struct node *n, int e, struct extension *x) {
		printf("Current succession node is %d. Checking for next succession.\n", e);

		switch (e) {
			/*case 	NULL:
				printf("No Extension was passed. Returning.\n");
			break;//fall-through*/
			case 	0:	
				printf("Starting a branch succession. \n");
				chain_succession(n, 0, x);//branch_succession(n);
			break;
			case	1:	
				printf("Starting a  chain succession. \n");
				chain_succession(n, 1, x);
			break;
			/*default://for now
				printf("Nothing else to do. Returning\n");
			break;*/
		}
		return;
	}
	/*-*-*/
	void	chain_succession(struct node *n, int e, struct extension *x) {
		printf("Chain succession Started. Passing node %d\n", n -> data);
		if (n != NULL) {
			if (e <= x -> n) {	
				struct node *a = malloc(sizeof(struct node));
				a -> data = e + 1;//n -> data + 1;
				printf("Incrementing node: %d\n", a -> data);
				if (a -> data == x -> n) {
					zchain(n, a);//a -> self = n;
				} else {
					zchain(n, NULL);//a -> self = n;
					return;
				}
			/*} else {return;}if (e <= ext) {*/	
				struct node *b = malloc(sizeof(struct node));
				b -> data = e + 2;//a -> data + 1;
				printf("Incrementing node: %d\n", b -> data);
				if (b -> data == x -> n) {
					zchain(a, b);//a -> self = n;
				} else {
					zchain(b, NULL);//a -> self = n;
					return;
				}
			//zchain(a, b);//b -> self = n;
			succession(b,1,x);
			/*} else {
				return;
			}*/
			} else {
				return;//Terminator
			}
		}
	}
	/*-*-*
	*//*
	void	branch_succession(struct node *n, int e) {
		printf("Branch succession Started. Passing node %d\n", n -> data);
		if (n != NULL) {
			if (e <= ext) {	
				struct node *a = malloc(sizeof(struct node));
				a -> data = n -> data + 1;
				if (a -> data == ext) {
					zchain(n, a);//a -> self = n;
				} else {
					zchain(n, NULL);//a -> self = n;
				}
				//zchain(n, a);//a -> self = n;
			} else {
				return;
			}
			if (e <= ext) {	
				struct node *b = malloc(sizeof(struct node));
				b -> data = a -> data + 1;
				if (b -> data == ext) {
					zchain(n, b);//a -> self = n;
				} else {
					zchain(n, NULL);//a -> self = n;
				}
			//	zchain(n, b);//b -> self = n;
				succession(b,1);
			} else {
				return;
			}
		} else {
			return;//Terminator
		}
	}*/

        void	zchain(struct node *z, struct node *n) {
		printf("linked %d to %d.\n", n -> data, z -> data);
		//n -> self = z;
		z -> self = n;
	}

        void	zswap(struct node *restrict z, struct node *restrict n) {
		/*voidstruct*/ 
		node t;
		t = *z;
		*z = *n;
		*n = t;//tt*a*a*b*bt
	}

        znode    zmemory(struct node *z) {
		z = malloc(sizeof(struct node));
		return z;
	}

        /*node    makenode(void) {
		struct node head;//= NULL;
		return head;
	}*/                        

        znode   zmake(int n) {
		struct node *head;
		printf("Creating node with boundary: %d\n",n);
		zmemory(head);
		head -> data = 0;
		return head;
	}                           

        void    zfree(struct node *z) {
		free(z);
		z = NULL;
	}

	void	zinit(struct node *z, struct extension *x) {
		chain_succession(z, z -> data, x);	
	}
