/*	FMP5 DETECTS AND PROCESSES COMMAND-LINE PROGRAM ARGUMENTS.	*/
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
		else
			return 1;
	}
	else
			return 42;	/*	THIS MEANS WHATEVER YOU WANT IT TO MEAN.	*/
}
