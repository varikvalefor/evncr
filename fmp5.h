/*	FMP5 DETECTS AND PROCESSES COMMAND-LINE PROGRAM ARGUMENTS.	*/
/*
	\[
		\forall a,
		\texttt{fmp5}\left(a\right) =
		\left\{
			\begin{array}{ll}
				0 && a \textrm{ WAS PARSED SUCCESSFULLY}
			\end{array}
		\right.
		.
	\]
*/
int fmp5(char *fmp5_1)
{
	if(fmp5_1[0] == '-')
	{
		if(fmp5_1[1] == 'd')
		{
			char fmp5_3[5];
			for(int fmp5_2 = 2;   fmp5_2 < sizeof(fmp5_1);   fmp5_2++)
				fmp5_3[fmp5_2-2] = fmp5_1[fmp5_2];
			d[atoi(fmp5_3)] = true;
			printf("FMP5: DEBUGGING VARIABLE %s HAS BEEN ENABLED.\n",fmp5_3);
			return 0;
		}
		else if(fmp5_1[1] == 'x')
		{
			d[2] = false;
			return 0;
		}
		else if(fmp5_1[1] == 'C')
		{
			printf("EASTER EGGLET 341156 ACTIVATED.");
			d[20]=true;
			return 0;
		}
		else if(fmp5_1[1] == 'D')
		{
			char fmp5_2[4];
			if(!atoi(fmp5_2))
			{
				fmp5_2[0] = fmp5_1[2];
				vaad[0] = int(atoi(fmp5_2));
				printf("Strings are now broken into chunks of %d characters.\n",atoi(fmp5_2));
				return 0;
			}
			else
			{
				printf("What is your major malfunction, numbnuts?!\n");
				return 69;
			}
		}
		else
		{
			printf("What is your major malfunction, numbnuts?");
			return 1;
		}
	}
	else
		return 42;	/*	THIS MEANS WHATEVER YOU WANT IT TO MEAN.	*/
}
