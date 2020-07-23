/*	fred() IS A FUNCTION WHICH USES fvox TO READ THE INPUT OF fred ALOUD.	*/
/*	TODO:	THE EXTENT TO WHICH THIS FUNCTION IS ELEGANT COULD PROBABLY BE INCREASED.	*/

/*
	== Space-Saving Technology ==
	The amount of storage space which is used by evncr was decreased by reducing character redundacy; as an example of this lack of redundancy, "a" and "A" share the same "main" file, sounds/65.wav, despite being "pronounced" differently.  This technique results in only needing to index half of the total alphabetical characters and brackets of the ASCII character set.  The sounds of alphabetical characters and brackets are saved to the integer representations of the majuscule alphabetical characters and opening brackets, respectively.

	== Variables ==
	fred_1 is the input of this function, i.e., the string which should be read.
	fred_2 is the current index of the string which should be read.
	fred_3 is the integer representation of fred_1[fred_2].
*/

int fred(char fred_1[])
{
	int fred_4 = 0;

	for(int fred_2 = 0;   fred_1[fred_2+1] != '\0';   fred_2++)
	{
		int fred_3 = int(fred_1[fred_2]);

		if(d[2])
		{
			fred_4 *= fvox(128);		/*	"LATIN"	*/
			usleep(vaaa[2]);

			if(fred_3 < 48)
				fred_4 += fvox(0);		/*	"OTHER"	*/
			else if(fred_3 < 58)
				fred_4 += fvox(1);		/*	"NUMERAL"	*/
			else if(fred_3 < 65)
				fred_4 += fvox(0);
			else if(fred_3 < 91)
				fred_4 += fvox(3);		/*	"MAJUSCULE"	*/
			else if(fred_3 < 97)
				fred_4 += fvox(0);
			else if(fred_3 < 123)
				fred_4 += fvox(4);		/*	"MINUSCULE"	*/
			else
				fred_4 += fvox(0);
			sleep(vaaa[2]);

			if(fred_3 == 40   ||   fred_3 == 60   ||   fred_3 == 91   ||   fred_3 == 123)
				fred_4 += fvox(5);		/*	"OPEN"	*/
			else if(fred_3 == 41   ||   fred_3 == 62   ||   fred_3 == 93   ||   fred_3 == 125)
				fred_4 += fvox(6);		/*	"CLOSE"	*/
			usleep(vaaa[2]);	
		}
		if(fred_3 > 96   &&   fred_3 < 123)
			fred_4 += fvox(fred_3-32);
		else if(fred_3 == 93   ||   fred_3 == 125   ||   fred_3 == 62)
			fred_4 += fvox(fred_3-2);
		else if(fred_3 == 41)
			fred_4 += fvox(fred_3-1);
		else
			fred_4 += fvox(fred_3);
		sleep(vaaa[1]);
	}
	return fred_4;
}
