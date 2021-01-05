#include	"node.h"
/*extern*/
static  struct extension *ext;
//int main(int argc, char **argv) {
int main(void) {
	ext = malloc(sizeof(struct extension));

	initialTest(ext);
	free(ext);
}
