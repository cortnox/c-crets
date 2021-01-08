#include	<stdio.h>

enum enm	{
		one = 1,
		two = 2
	};

enum resource	{
		sheep,
		wheat,
		wood,
		brick,
		ore,
	};

int main(void)	{
	
	printf("one:%d\ttwo:%d\n", one, two);
	enum resource e = brick;
	
	printf(
		"sheep%d\n"
		"wheat%d\n"
		"wood%d\n"
		"brick%d\n"
		"ore%d\n",
		sheep,
		wheat,
		wood,
		brick,
		ore
		);
	if (e != ore) {
		printf("we need more ore!\n");
	}
	printf("we sell you %d brick for %d ore¿\n", ore, brick);
}
/*

Enumerated Types: enum
C offers us another way to have constant integer values by name: enum. For example:
enum { ONE=1,
TWO=2 };
printf("%d %d", ONE, TWO); // 1 2
In some ways, it can be better—or different—than using a #define. Key differences:
enums can only be integer types.
#define can define anything at all.
enums are often shown by their symbolic identifier name in a debugger. #defined numbers just show as raw numbers which are harder to know the meaning of while debugging.
Since they’re integer types, they can be used any place integers can be used, including in array dimensions and case statements.
Let’s tear into this more.
Behavior of enum Numbering
enums are automatically numbered unless you override them. They start at 0, and autoincrement up from there, by default:
enum {
SHEEP, // Value is 0 WHEAT, // Value is 1 WOOD, // Value is 2 BRICK, // Value is 3 ORE // Value is 4
};
printf("%d %d\n", SHEEP, BRICK); // 0 2 You can force particular integer values, as we saw earlier:
enum { X=2,
Y=18,
Z=-2 };




*/
