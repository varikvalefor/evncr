#include "hi.h"
#include "hv.h"
#include "hf.h"

/*
	==	Variables	==
	===	main_1	===
	<CODE>main_1</CODE> is an integer which iterates over the arguments which are passed to EVANNOUNCER.
	===	vaab	===
	<CODE>vaab</code> contains the string which is to be read by EVANNOUNCER.
*/

int main(int argc, char * argv[])
{
	for(int main_1 = 1;   main_1 < argc;   main_1++)
		fmp5(argv[main_1]);
	char vaab[512];
	fgets(vaab, sizeof vaab, stdin);
	return fred(vaab);
}
