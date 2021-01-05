//#ifndef FOO_H//#define FOO_H
#include"foo.h"

int main(int argc, char **argv) {
#ifdef smallcaps
printf("Printing Small Caps: %s\n",smallcaps);
printf("Mandatory Builtin MACROS:\n"" \n"
	" __DATE__ Compilation Date: %s \n"
	" __TIME__ Compliation Time: %s \n"
	" __FILE__ This Files Name is: %s \n"
	" __LINE__ The Number of this very Line: %i \n"
	" __func__ The Function Name This appears in: %s \n"
	" __STDC_HOSTED__ ¿Isn't his an Embeddded System?: %d \n"
	" __STDC__ ¿Standard Compiler?: %d \n"
	" __STDC_VERSION__ Long const in the form of yyymmL: %lu \n"
	,__DATE__
	,__TIME__
	,__FILE__
	,__LINE__
	,__func__
	,__STDC_HOSTED__
	,__STDC__
	,__STDC_VERSION__);
#endif//program wont run entirely if theres  no DEFINITION Macro
#undef smallcaps//Lose the MACRO
	char *sV = *(argv + 1);
#ifdef DEFINITION
	#if DEFINITION == 0//"c;"
	char *eV = getEnvironmentVariable(sV);
	if (eV == NULL) {
		printf("Cannot Find \"%s\" environment variable.\n", sV);
	} else {
		printf("Found %s: %s\n", sV, eV);
	}
	#elif DEFINITION == 1//"C is Great."//#else//do this instead
	if (sV != NULL) {
		addArgv(argc, argv);
		printArgInputs(argc, argv);
		//create chip
		chip *tchip = calloc(1, sizeof(struct chip));
		//init the chip - automate memory allocation. according to pinFactor.
		initChip(tchip,"Pi", 9);
		Deactivate(tchip -> pins[tchip  -> pinFactor - 1]);
		setState(tchip -> pins[0], true);
		swapPins(tchip -> pins[0], tchip -> pins[tchip -> pinFactor - 1]);
		getChipStatus(tchip);
		flushChip(tchip);
		free(tchip);
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
	#else
printf("Nothing else to do.\n");
	#endif
#endif
}

//int main(void) { ¿?¿
	//         ?¿?
/*TODO:OUTPUT
Printing Small Caps: Its conventional to write macros in ALL_CAPS even though thats not technichally required.
Builtin MACROS:
 
 __DATE__ Compilation Date: Jan  1 2021 
 __TIME__ Compliation Time: 17:19:31 
 __FILE__ This Files Namemain.c 
 __LINE__ The Number of this very Line: 20 
 __func__ The Function Name This appears in : main 
 __STDC_HOSTED__ ¿Isn't his an Embeddded System?: 1 
 __STDC__ ¿Standard Compiler?: 1 
 __STDC_VERSION__ Long const in the form of yyymmL: 201710 
Found PWD: /Users/cortnau5/c/21/1/a

*/
/*  
TODO
qsort - 
poarith
substrlen
arpatofu
memcopy
align_alloc
realloc
*/
//tchip -> pins[3] -> active = false;
//#include<stdio.h>
//declare chip instances from .h file
	//configure chip struct
		//hint of a heart beat - make the chip al!vei
//create assignment method/function/operation for assigning pin to chip
//create assignment operation for assigning pin to pins-chip array
	//pin *tpin = calloc(1, sizeof(struct pin*));
	//OAOAprintf("active: %x\n\tstate:%d\n", tpin  -> active, tpin -> state);
//change the state when pin is active - safe lock from power surgezzzzzzzzzzzzzz!
	//setActive(tpin);
	//setState(tpin, true);
	//printf("active: %x\n\tstate:%d\n", tpin -> active, tpin -> state);
//toggle activity - deactivate - to toggle state
	//Deactivate(tpin);
	//printf("active: %x\n\tstate:%d\n", tpin -> active, tpin -> state);
	//tpin -> chipset = &tchip;
/*

DESCRIPTION
     An array of strings called the environment is made available by execve(2)
     when a process begins.  By convention these strings have the form
     ``name=value''.  The following names are used by various commands:

     BLOCKSIZE    The size of the block units used by several commands, most
                  notably df(1), du(1) and ls(1).  This variable is processed
                  by the getbsize(3) function.

     COLUMNS      The user's preferred width in column positions for the ter-
                  minal.  Utilities such as ls(1) and who(1) use this to for-
                  mat output into columns.  If unset or empty, utilities will
                  use an ioctl(2) call to ask the terminal driver for the
                  width.

     EDITOR       Default editor name.

     EXINIT       A startup list of commands read by ex(1) and vi(1).

     HOME         A user's login directory, set by login(1) from the password
                  file passwd(5).

     LANG         This variable configures all programs which use setlocale(3)
                  to use the specified locale unless the LC_* variables are
                  set.

     LC_ALL       Overrides the values of LC_COLLATE, LC_CTYPE, LC_MESSAGES,
                  LC_MONETARY, LC_NUMERIC, LC_TIME and LANG.

     LC_COLLATE   Locale to be used for ordering of strings.

     LC_CTYPE     Locale to be used for character classification (letter,
                  space, digit, etc.) and for interpreting byte sequences as
                  multibyte characters.

     LC_MESSAGES  Locale to be used for diagnostic messages.

     LC_MONETARY  Locale to be used for interpreting monetary input and for-
                  matting output.

     LC_NUMERIC   Locale to be used for interpreting numeric input and format-
                  ting output.

     LC_TIME      Locale to be used for interpreting dates input and for for-
                  matting output.

     MAIL         The location of the user's mailbox instead of the default in
                  /var/mail, used by mail(1), sh(1), and many other mail
                  clients.

     NLSPATH      List of directories to be searched for the message catalog
                  referred to by LC_MESSAGES.  See catopen(3).

     PAGER        Default paginator program.  The program specified by this
                  variable is used by mail(1), man(1), ftp(1), etc, to display
                  information which is longer than the current display.

     PATH         The sequence of directories, separated by colons, searched
                  by csh(1), sh(1), system(3), execvp(3), etc, when looking
                  for an executable file.  PATH is set to ``/usr/bin:/bin''
                  initially by login(1).

     PRINTER      The name of the default printer to be used by lpr(1),
                  lpq(1), and lprm(1).

     PWD          The current directory pathname.

     SHELL        The full pathname of the user's login shell.

     TERM         The kind of terminal for which output is to be prepared.
                  This information is used by commands, such as nroff(1) or
                  plot(1) which may exploit special terminal capabilities.
                  See /usr/share/misc/termcap (termcap(5)) for a list of ter-
                  minal types.

     TERMCAP      The string describing the terminal in TERM, or, if it begins
                  with a '/', the name of the termcap file.  See TERMPATH
                  below, and termcap(5).

     TERMPATH     A sequence of pathnames of termcap files, separated by
                  colons or spaces, which are searched for terminal descrip-
                  tions in the order listed.  Having no TERMPATH is equivalent
                  to a TERMPATH of ``$HOME/.termcap:/etc/termcap''.  TERMPATH
                  is ignored if TERMCAP contains a full pathname.

     TMPDIR       The directory in which to store temporary files.  Most
                  applications use either ``/tmp'' or ``/var/tmp''.  Setting
                  this variable will make them use another directory.

     TZ           The timezone to use when displaying dates.  The normal for-
                  mat is a pathname relative to ``/usr/share/zoneinfo''.  For
                  example, the command ``env TZ=America/Los_Angeles date''
                  displays the current time in California.  See tzset(3) for
                  more information.

     USER         The login name of the user.
*/

/*printf("Optional Builtin Macros\n");
printf(" __STDC_ISO_10646__: %d\n",__STDC_ISO_10646__);
printf(" __STDC_MB_MIGHT_NEO_WC__: %d\n",__STDC_MB_MIGHT_NEO_WC__);
printf(" __STDC_UTF_32__: %d\n",__STDC_UTF_32__);
printf(" __STDC_UTF_16__: %d\n",__STDC_UTF_16__);
printf(" __STDC_ANALYZABLE__: %d\n",__STDC_ANALYZABLE__);
printf(" __STDC_IEC_599_COMPLEX__: %d\n",__STDC_IEC_559_COMPLEX__);
printf(" __STDC_IEC_559__: %d\n",__STDC_IEC_559__);
printf(" __STDC_LIB_EXT1__: %d\n",__STDC_LIB_EXT1__);
printf(" __STDC_NO_ATOMICS__: %d\n",__STDC_NO_ATOMICS__);
printf(" __STDC_NO_COMPLEX__: %d\n",__STDC_NO_COMPLEX__);
printf(" __STDC_NO_THREADS__: %d\n",__STDC_NO_THREADS__);
printf(" __STD_NO_VLA__ support variable length arrays: %d\n",__STDC_NO_THREADS__);*/
