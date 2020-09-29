//#define MINIAUDIO_IMPLEMENTATION
//#include "extl/miniaudio.h"

#if (_WIN32) || (_WIN64)
	#include <Windows.h>
	#include <Mmsystem.h>
#endif


#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "config/mamatoldmetoconfig.h"
