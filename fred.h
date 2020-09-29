/*	fred() IS A FUNCTION WHICH USES fvox TO READ THE INPUT OF fred ALOUD.	*/
/*	TODO:	THE EXTENT TO WHICH THIS FUNCTION IS ELEGANT COULD PROBABLY BE INCREASED.	*/

/*
	== Space-Saving Technology ==
	The amount of storage space which is used by evncr was decreased by reducing character redundancy; as an example of this lack of redundancy, "a" and "A" share the same "main" file, sounds/65.wav, despite being "pronounced" differently.  This technique results in only needing to index half of the total alphabetical characters and brackets of the ASCII character set.  The sounds of alphabetical characters and brackets are saved to the integer representations of the majuscule alphabetical characters and opening brackets, respectively.

	== Variables ==
	<CODE>fred_1</CODE> is the input of <CODE>fvox</CODE>, i.e., the string which should be read.
	<CODE>fred_2</CODE> is the current index of the string which should be read.
	<CODE>fred_3</CODE> is the integer representation of <CODE>fred_1[fred_2]</CODE>.
	<CODE>fred_4</CODE> is used as the error code which is output by <CODE>fred</CODE>.
*/

int fred(char *fred_1)
{
	int fred_4 = 0;
	struct timespec tim, tim2;
	tim.tv_sec	= SLIZZEEP1;
	tim.tv_nsec	= SLIZZEEP;
	struct timespec tym, tym2;
	tym.tv_sec	= SLIZZLE1;
	tym.tv_nsec	= SLIZZLE;
	struct timespec thm, thm2;
	thm.tv_sec = SLIZZY1;
	thm.tv_sec = SLIZZY;

	for(int fred_2 = 0;   fred_1[fred_2+1] != '\0';   fred_2++)
	{
		int fred_3 = int(fred_1[fred_2]);
		if(d[2])
		{
			/* PREFIX ONE	*/
			{
				if(fred_3 < 58   &&   fred_3 >= 48)
					fred_4 *= fvox(129);	/*	"ARABIC"	*/
				else
					fred_4 *= fvox(128);		/*	"LATIN"	*/
				nanosleep(&tim, &tim2);
			}
			/* PREFIX TWO	*/
			{
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
				nanosleep(&tim, &tim2);
			}
			/*	PARENS	*/
			{
				if(fred_3 == 40   ||   fred_3 == 60   ||   fred_3 == 91   ||   fred_3 == 123)
				{
					fred_4 += fvox(5);		/*	"OPEN"	*/
					nanosleep(&tim, &tim2);
				}
				else if(fred_3 == 41   ||   fred_3 == 62   ||   fred_3 == 93   ||   fred_3 == 125)
				{
					fred_4 += fvox(6);		/*	"CLOSE"	*/
					nanosleep(&tim, &tim2);
				}
			}
		}
		/*	READ THE ACTUAL CHARACTER	*/
		{
			if(fred_3 > 96   &&   fred_3 < 123)
				fred_4 += fvox(fred_3-32);
			else if(fred_3 == 93   ||   fred_3 == 125   ||   fred_3 == 62)
				fred_4 += fvox(fred_3-2);
			else if(fred_3 == 41)
				fred_4 += 40;
			else
				fred_4 += fvox(fred_3);
		}

		/*	ADD SPACING	*/
		{
			if(fred_1[fred_2+2] != '\0')
			{
				if(vaad[0])
					if((fred_2 + 1) % vaad[0] == 0 && fred_2 != 0)
						nanosleep(&thm, &thm2);
				nanosleep(&tym, &tym2);
			}
		}
	}
	return fred_4;
}
