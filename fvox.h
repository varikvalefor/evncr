/*	fvox is a function which outputs the audio file whose filename is the argument of fvox.	*/

/*	TODO: EVAN'S VOICE SAMPLES SHOULD BE ADDED TO "SAMPLES/".	*/
/*	TODO: A CROSS-PLATFORM SOLUTION WHICH IS PREFERABLE TO USING A BUNCH OF IFDEFS SHOULD PROBABLY BE IMPLEMENTED.	*/

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
		/*	EVANNOUNCER _should_ work properly on FreeBSD systems which have <CODE>aucat</CODE> installed.  However, proper support for FreeBSD should probably be ensured.	*/
		sprintf(fvox_2, "aucat -i /usr/local/share/sound/%d.wav",fvox_1);
		if(d[0])
			printf("FVOX: CURRENT FILENAME IS %s.\n", fvox_2);
		return system(fvox_2);
	#elif __linux__
		printf("Get out... for the time being.  Linux should eventually be officially supported.\n");
		return 1;
	#elif defined(_WIN32) || defined(_WIN64)
		/*	TODO:	THIS SOLUTION SHOULD BE TESTED!	*/
		sprintf(fvox_2,"C:\\Program Files\\EVANNOUNCER\\sound\\%d.wav",fvox_1);
		return 1 - int(PlaySound(TEXT(fvox_2),	NULL,	SND_FILENAME));
	#else
		printf("Go away.  evncr shall most likely never support Chicken Shit OS.\n");
		return 1;
	#endif
}
