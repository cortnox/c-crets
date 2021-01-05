//#ifndef FOO_H//#define FOO_H
#include"foo.h"
	
void initPin(struct chip *c, int address) {
	//init by allocating space
	pin *tpin = calloc(1, sizeof(struct pin*));
	allocatePinMemory(tpin, address);//free(i);/free(act);/free(sta);
	setActive(tpin);// activates the pin so that pin state can be toggled.
	setPinChipSet(tpin, c);//reference the chip to the pin * - 1.
	c -> pins[address] = tpin;//here we adding *tpin to **pins pointer array
	printf("Pin:%d has been initiated.\n", address);
}

void allocatePinMemory(struct pin *p, int address) {
	int *i = malloc(sizeof(int)),//one stressfuthingis there is no way to free this memory!only by freeing the pins
	*act = malloc(sizeof(int)),//somehow values dont hold/sustain without allocating memory first
	*sta = malloc(sizeof(int));//allocating memory hopefully the pin that get freed also frees these declarations too!
	*i = address;
	p -> number = *i; //address;
	p -> active = *act;//here we are doing what we can to enable value assigment for these pin fields
	p -> state = *sta;//without allocating memory we cant assign values necessary.
	
}

void getPinStatus(struct pin *p) {
	printf("===-----------------=====-----------------===\n");
	printf("[%d][Activity:%d][State:%d][%.2fV][%.2fA][%.2fΩ]\n", p -> number, p -> active, p -> state,p -> voltage, p -> current, p -> resistance);
}

void getChipStatus(struct chip *c) {
	printf("===-----------------=====-----------------===\n");
	printf("Relaying Chip Stats:\n");
	printf("===-----------------=====-----------------===\n");
	printf("Chip Name:%s | Pin Factor:%d\n", c -> name, c -> pinFactor);
	printf("===---------Relaying Pin Stats:-----------===\n");
	for (int i = 0; i < c -> pinFactor; ++i) {
		getPinStatus(c -> pins[i]);
	}
	printf("===-----------------=====-----------------===\n");
}

void initChip(struct chip *c, char *n, int pF) {
	//c = calloc(1, sizeof(struct chip));
	if ( pF > 0 ) {
		c -> name = n;
		c -> pinFactor = pF;
		//allocate memory for aquired pins
		c -> pins = calloc(pF, sizeof(struct pin*));
		//initiate pins
		for (int i = 0; i < pF; i++) {
			initPin(c, i);
		}
	}
	//return true;
}

void flushChip(struct chip *c) {
	for (int i = 0; i < c -> pinFactor; ++i) {
		flushPin(c -> pins[i]);
		printf("Pin:%d has been flushed.\n",i);
	}
	printf("Chip: %s has been flushed.\n", c -> name);
}

void flushPin(struct pin *p) {
	Deactivate(p);
	p -> label = NULL;
	p -> active = NULL;
	p -> state = NULL;
	free(p);
}

void setPinChipSet(struct pin *p, struct chip *c) {
	p -> chipset = c;
}

/*static*/bool Deactivate(struct pin *p) {
	//p -> number = *p;
	p -> active = false;
	p -> state = false;
	return p -> active;
}

ops_pin Activate(pin *self) {
	self -> active = true;
	return self;
}

/*static*/bool setInActive(struct pin *p) {
	p -> active = false;
	p -> state = false;
	return p -> active;
}
/*static*/bool setActive(struct pin *p) {
	p -> active = true;
	return p -> active;
}
/*static*/bool setState(struct pin *p, bool condition) {
	if (p -> active) {
		p -> state = condition;
	}
	return p -> state;
}
/*pinop pin_Activate(pin*self){if(!self.active){self.active=true;}returnself;}*//*pinop pin_AddPin(chip*chip){return chip;}*/
/*static*/bool getActive(struct pin *p) {
	return p -> active;
}

/*UTILS->TODO:*/
//fetch an environment variable
/*char*/returnString getEnvironmentVariable(char *s) {
	char *p = getenv(s);
	checkEmptyString(p);
	return p;
}

//check empty string
bool checkEmptyString(char *s) {
	bool emptyCheck = s == NULL;
	if (emptyCheck) {
		printf("Empty String@fn:[%s]ln:[%d]\n",__func__, __LINE__);
	} 
	return emptyCheck;
}
//process input args
void printArgInputs(int argc, char **argv) {
	for (int i = 0; i < argc; ++i) {
		printf("arg %d: %s\n", i, argv[i]);
	}
}
//swap pins &
void swapPins(struct pin *restrict a, struct pin *restrict b) {
	pin t;
	//void *caster = a;//&t;//pin t;
	t = *a;
	*a = *b;
	*b = t;// caster;
}

//compar
int compar(const void *elem1, const void *elem2) {
	//return *((const int*)elem2) - *((const int*)elem1);
	const int *e1 = elem1;
	const int *e2 = elem2;
	return *e2 - *e1;
}
//void casting
struct pin voidCast(struct pin *p) {
	void *caster = &p;
	struct pin *newPin = caster;
	return *newPin;
}
//strtoul
unsigned long int convertStringifiedBase(char *s, int base) {
	char *badchar;
	return strtoul(s, &badchar, base);
}

void addArgv(int argc, char **argv) {
	int total = 0;
	for (int i = 0; i < argc; ++i) {
		int value = atoi(argv[i]);
		total += value;
		printf("Value:%d\n", value);
	}

	printf("Total:%d\n", total);
	total = 0;
	(void)argc;
	for (char **p = argv; *p != NULL; p++) {//argv[argc] == NULL [argv[i] -> *(argv + i)]
		int value = atoi(*p);
		total += value;
	}

}
//print Mandatory Macro References
void printMandatoryMacros() {
	
}
/*
Exit Status
Did you notice that the function signatures for main() have it returning type int? What’s that all about? It has to do with a thing called the exit status, which is an integer that can be returned to the program that launched yours to let it know how things went.
Now, there are a number of ways a program can exit in C, including returning from main(), or calling one of the exit() variants.
All of these methods accept an int as an argument.



Side note: did you see that in basically all my examples, even though main() is supposed to return an int, I don’t actually return anything? In any other function, this would be illegal, but there’s a special case in C: if execution reaches the end of main() without finding a return, it automatically does a return 0.
But what does the 0 mean? What other numbers can we put there? And how are they used?
The spec is both clear and vague on the matter, as is common. Clear because it spells out what you can do, but vague in that it doesn’t particularly limit it, either.
Nothing for it but to forge ahead and figure it out!
Let’s get Inception91 for a second: turns out that when you run your program,
you’re running it from another program.
Usually this other program is some kind of shell92 that doesn’t do much on its
own except launch other programs.
But this is a multi-phase process, especially visible in command-line shells:
1. Theshelllaunchesyourprogram
2. Theshelltypicallygoestosleep(forcommand-lineshells) 3. Yourprogramruns
4. Yourprogramterminates
5. Theshellwakesupandwaitsforanothercommand
Value

Now, there’s a little piece of communication that takes place between steps 4 and 5: the program can return a status value that the shell can interrogate. Typically, this value is used to indicate the success or failure of your program, and, if a failure, what type of failure.
This value is what we’ve been returning from main(). That’s the status.
Now, the C spec allows for two different status values, which have macro names
defined in <stdlib.h>:
Status
EXIT_SUCCESS or 0 EXIT_FAILURE
  Description
Program terminated successfully. Program terminated with an error.
    

*/

			/*pin *tpin = calloc(1,sizeof(struct pin));
			//activate pin
			setActive(tpin);
			//link pins with chip
			setPinChipSet(tpin, c);
			c -> pins[i] = tpin;//here we have an opportunity to link the *pin to the *chip. - gets "appended" / registered as a part of **pins - see header file.
			printf("Pin:%d has been initiated\n",i);
		}
	}
	return true;
//the important thing to get out of this is that the pins are independant of chip - when we init chip - chip will look at pinFactor and it will then create so many pins which it is able  to control.
//so if in the  future we hav multiple chips with their pins integrated - we have an advantage of **pin referencing multiples pins¿
}*/

	/*void *pinLabel = &(p -> label);
	if (pinLabel != NULL) {
		free(pinLabel);
	}
	void *pinActivity = &(p -> active);
	if (pinActivity != NULL) {//if (c -> pins[i] -> active != NULL) {
		free(pinActivity);
	}
	void *pinState = &(p -> state);
	if (pinState != NULL) {
		free(pinState);
	}*/
/*

void flushPin(struct pin *p) {
void flushPin(struct pin *p) {
	Deactivate(c -> pins[i]);
	void *pinLabel = &(c -> pins[i] -> label);
	if (pinLabel != NULL) {
		free(pinLabel);
	}
	void *pinActivity = &(c -> pins[i] -> active);
	if (pinActivity != NULL) {//if (c -> pins[i] -> active != NULL) {
		free(pinActivity);
	}
	void *pinState = &(c -> pins[i] -> state);
	if (pinState != NULL) {
		free(pinState);
	}
	free(c -> pins[i]);
	printf("Pin:%d has been flushed.\n",i);

}*/
