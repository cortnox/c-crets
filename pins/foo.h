/*current procedures
1. Declare 1st thing in the Header file. -> void displayMacros();
2. Ctrl + B <--> toggles screens - keep mouse on GUI display.
3. Copy declaration signature to the source .c file 
4. Group Utility functions
4. Code Impelementation
5. Compiler shall not display any warnings or errors
5. Build and run 	-> clang -std2z -Weverything foo.c main.c
6. Implement and Test	-> ./a.out PWD
7. Refactor and retest.	-> ./a.out

*/
#ifndef FOO_H//-> if not defined -> prevents being loaded more than once - pragma comment ONCE
#define FOO_H
/*MACROS->TODO:macros are not types but they are used to store primitives / values  - effectively global - their value cannot be changedODa*/

#define PI 3.14159

#define SQUAREROOT(x) ((x) * (x)) //brackets demark according bodmas priority- giving natural math precedence//here is declaration for a macro that takes a single argument
#define CIRCLEAREA(r) ((2 * PI * ((r) * (r)))
#define TRIANGLEAREA (w,h) (0.5*(w)*(h))
/*
 x = ( -b ± rt((b*b) - 4ac))/2a
*/
//These can get hectic advanced and Its worth using them  for mathemic equations.
#define QUADPLUS(a, b, c) ( ( - (b) + sqrt( (b) * (b) - 4 * (a) * (c) ) ) ) / (2 * (a) )
#define QUADMINUS(a, b, c) ( ( - (b) - sqrt( (b) * (b) - 4 * (a) * (c) ) ) ) / (2 * (a) )
#define QUAD(a, b, c) QUADPLUS(a, b, c), QUADMINUS(a, b, c)//printf("x = %f or x = %f", QUAD(a, b, c));
#define DEFINITION 0// "C is Great."
#define EMPTY_MACRO//useful for replacing data.
/*INCLUDES->TODO:*/
#define smallcaps "Its conventional to write macros in ALL_CAPS even though thats not technichally required."
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdatomic.h>
//aliasing pin and chip naming convention for structs
typedef struct pin pin, *ops_pin;
typedef struct chip chip, *ops_chip;
//TODO: segment chip and pin into seperate header files
//Object file Linking - segment source code for pin
//Design Makefile
//Pin Struct to Control and Manage Pin States once integrated.
/*_Atomic*/ struct pin {
	/*Methods*/
	ops_pin(*Activate)(pin*);
	bool(*Deactivate)(pin*);
	//pinop(*AddPin)(chip*);
	/*Properties*/
/*	_Atomic volatile */
	int	number;

	char 	*label,
		*type;

	/*volatile*/ bool 	active, 
		state;

	double 	voltage,
		current,
		resistance;
	
	chip 	*chipset;//bind pin to chipset.
};
/*functions - we want to figure how to convert these into methods if need be!*/
//Setters
//TODO:
 	  void initPin(struct chip *c, int address);//we want to abstract pin from chip as far and as much as possible **pins and &chipsets are the self and super references used to communicate and control with each other - understand that.                             						 this system must accomodate any MICROCHIP
	  void setPinChipSet(struct pin *p, struct chip *c);
/*static*/bool setActive(struct pin *p);
/*static*/bool setInActive(struct pin *p);
/*static*/bool Deactivate(struct pin *p);
/*static*/bool setState(struct pin *p, bool condition);
	  void getPinStats(struct pin *p);
	  struct chip getPinSource(struct pin *p);
	  void flushPin(struct pin *p);
//Getters
/*static*/bool getActive(struct pin *p);
//TODO: 
	  void getPinStatus(struct pin *p);
//chip struct to control and  manage multiple pin States simultaneously.
struct chip {
	/*Methods*/
	
	/*Properties*/
	char 	*name;//here we can do string manipulation with the name
	int 	pinFactor;//we want to create multiple types of chips - even eeprom or 555 timers.
	struct 	pin **pins;//this is new grey area - but what i want is for pins to be exposed - so all im doing here is storing an an array of pointers - so chips will have access to the &address of those pins - and this means i only need to allocate pointer space for memory - which is more convenient - we want to allocate minimal memory and we need to keep improving memory managemnet which is what this system will eventaully accomplish
};
//Chip Functions
//intialize chip/**/
void initChip(struct chip *c, char *n, int pF);
void allocatePinMemory(struct pin *p, int address);
void getChipStatus(struct chip *c);
//flush memory allocated on chip
void flushChip(struct chip *c);

/*
Typedef return types
*/
typedef char *returnString;

/*UTILS->TODO: Util Functions*/
/*char*/returnString getEnvironmentVariable(char *s);
bool checkEmptyString(char *s);
void addArgv(int argc, char **argv);
void printArgInputs(int argc, char **argv);
void swapPins(struct pin *restrict a, struct pin *restrict b);
int compar(const void *elem1, const void *elem2);
struct pin voidCast(struct pin *p);

unsigned long int convertStringifiedBase(char *s, int base);
struct pin voidCast(struct pin *p);
/*/strtoul - converts a stringified number to its base number ie base 10 or even binary.
	char *badchar;
	return strtoul(s, &badchar, base);
}*/
int add(int x, int y);


#endif
//aliasing pin and chip naming convention for structs
//pins = calloc(sizeof(pin), pinFactor);
//int *pins = malloc(sizeof(int) * pinFactor);
//memset(pins, 0, sizeof(int) * pinFactor);
/*
*/
