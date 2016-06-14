/***********************************************************************
PLATFORM DEPENDENCIES

In this file all platform dependencies are defined.

***********************************************************************/

#ifndef BPLATFORMDEPENDENCIES_H
#define BPLATFORMDEPENDENCIES_H

#ifdef _MSC_VER > 1000
	#pragma warning(disable : 4996)
#endif

#ifdef _WIN32
#include <windows.h>
#define WIN_32_LEAN_AND_MEAN

#elif defined(...)

#endif

#endif //BPLATFORMDEPENDENCIES_H