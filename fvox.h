/*	fvox is a function which outputs the audio file whose filename is the argument of fvox.	*/

/*	TODO: THIS PART OF THE PROGRAM MUST BE CROSS-PLATFORM.	*/
/*	TODO: EVAM'S VOICE SAMPLES SHOULD BE ADDED TO "SAMPLES/".	*/

int fvox(int fvox_1)
{
	std::string fvox_2 = std::string("aucat -i sound/").append(std::to_string(fvox_1)).append(".wav");
	return system(fvox_2.c_str());
}
