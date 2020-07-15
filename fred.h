/*	fred() IS A FUNCTION WHICH USES fvox TO READ THE INPUT OF fred ALOUD.	*/
/*	TODO:	THE EXTENT TO WHICH THIS FUNCTION IS ELEGANT COULD PROBABLY BE INCREASED.	*/

/*
	VARIABLES
	fred_1 is the input of this function, i.e., the string which should be read.
	fred_2 is the current index of the string which should be read.
	fred_3 is the integer representation of fred_1[fred_2].
*/

int fred(char fred_1[])
{
	int fred_4 = 0;

	for(int fred_2 = 0;   fred_1 < sizeof(fred_1)/sizeof(fred_1[0])-1;   fred_2++)
	{
		int fred_3 = int(fred_1[fred_2]);

		fred_4 *= fvox(128);		/*	"LATIN"	*/
		sleep(vaaa[2]);
		if(fred_3 < 48)
			fred_4 += fvox(0);		/*	"OTHER"	*/
		else if(fred_3 < 58)
			fred_4 += fvox(1);		/*	"NUMERAL"	*/
		else if(fred_3 < 65)
			fred_4 += fvox(0);
		else if(fred_3 < 91)
			fred_4 += fvox(3);		/*	"MAJUSCULE"	*/
		else if(fred_4 < 97)
			fred_4 += fvox(0);
		else if(fred_4 < 123)
			fred_4 += fvox(4);		/*	"MINUSCULE"	*/
		else
			fred_4 += fvox(0);
		sleep(vaaa[2]);

		if(fred_3 == 40   ||   fred_3 == 60   ||   fred_3 == 91   ||   fred_3 == 123)
			fred_4 += fvox(5);		/*	"OPEN"	*/
		else if(fred_3 == 41   ||   fred_3 == 62   ||   fred_3 == 93   ||   fred_3 == 125)
			fred_4 += fvox(6);		/*	"CLOSE"	*/
		sleep(vaaa[2]);	

		fred_4 += fvox(fred_3);
		sleep(vaaa[1]);
	}
	return fred_4;
}
