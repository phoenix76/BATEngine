/***********************************************************************
PLATFORM DEPENDENCIES

In this file all platform dependencies are defined.

***********************************************************************/

#ifndef BPLATFORMDEPENDENCIES_H
#define BPLATFORMDEPENDENCIES_H

#ifdef _MSC_VER > 1000
	#pragma warning(disable : 4996)
#endif

#if (!defined (_WIN64)) && defined (_DEBUG)
	#define BAT_WIN_DEBUG_X86
#elif defined(_WIN64) && (_DEBUG)
	#define BAT_WIN_DEBUG_X64
#endif


#include <windows.h>
#define WIN_32_LEAN_AND_MEAN

#elif defined(...)

#endif

//This structure alienation stuff will be needed for aligned structure creation.
#if defined(__MINGW32__) || defined(__CYGWIN__) || (defined (_MSC_VER) && _MSC_VER < 1300)
#define B_FORCE_INLINE inline
#define B_ATTRIBUTE_ALIGNED16(a) a
#define B_ATTRIBUTE_ALIGNED64(a) a
#define B_ATTRIBUTE_ALIGNED128(a) a
#else
#pragma warning(disable : 4324)
#define B_FORCE_INLINE __forceinline
#define B_ATTRIBUTE_ALIGNED16(a) __declspec(align(16)) a
#define B_ATTRIBUTE_ALIGNED64(a) __declspec(align(64)) a
#define B_ATTRIBUTE_ALIGNED128(a) __declspec (align(128)) a
#endif

#endif //BPLATFORMDEPENDENCIES_H