/*	fvox is a function which outputs the audio file whose filename is the argument of fvox.	*/

/*	TODO: THIS PART OF THE PROGRAM MUST BE CROSS-PLATFORM.	*/
/*	TODO: EVAN'S VOICE SAMPLES SHOULD BE ADDED TO "SAMPLES/".	*/

/*
	== System-Specific Approach ==
	An effort to use the utilities which are by default provided by operating systems was made when writing this function; by using the utilities, e.g., <CODE>aucat</CODE>, which are provided by operating systems, the number of dependencies can be decreased.  However, this approach has the cost of requiring a custom solution for each operating system which is supported by <CODE>evncr</CODE>.
	== Variables ==
	fvox_1 is the input of fvox, i.e., the integer representation of the desired phrase.
	fvox_2 is the path at which the desired phrase exists.
*/

int fvox(int fvox_1)
{
	char fvox_2[64];
	#if defined(__OpenBSD__) || defined(__FreeBSD__)
	{
		/*	EVANNOUNCER _should_ work properly on FreeBSD systems which have <CODE>aucat</CODE> installed.  However, proper support for FreeBSD should probably be ensured.	*/
		sprintf(fvox_2, "aucat -i sound/%d.wav",fvox_1);
		if(d[0])
			printf("FVOX: CURRENT FILENAME IS %s.\n", fvox_2);
		return system(fvox_2);
	}
	#elif __linux__
	{
		printf("Get out... for the time being.  Linux should eventually be officially supported.\n");
		return 1;
	}
	#elif defined(_WIN32) || defined(_WIN64)
	{
		/*	TODO:	THIS SOLUTION SHOULD BE TESTED!	*/
		sprintf(fvox_2,"sound/%d.wav",fvox_1);
		PlaySound(TEXT(fvox_2),	NULL,	SND_FILENAME);
		return 0;
	}
	#else
	{
		printf("Go away.\n");
		return 1;
	}
	#endif
}
