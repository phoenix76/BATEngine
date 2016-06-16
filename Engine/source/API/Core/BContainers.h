#ifndef BCONTAINERS_H
#define BCONTAINERS_H

#include <vector>
#include <list>
#include <map>

#include <EASTL/vector.h>
#include <EASTL/sort.h>
#include <EASTL/algorithm.h>
#include <EASTL/list.h>
#include <EASTL/map.h>

// ****** TODO: Later remove these overriding operators as custom allocators will be made, they are needed for EASTL containers to work.
void * operator new [](size_t size, const char * pName, int flags, unsigned debugFlags, const char * file, int line)
{
	return operator new[](size);
}
void * operator new [](size_t size, size_t alignment, size_t alignmentOffset, const char * pName, int flags, unsigned debugFlags, const char * file, int line)
{
	// Does not support alignment
	return operator new[](size);
}
void operator delete [](void * ptr, const char * pName, int flags, unsigned debugFlags, const char * file, int line)
{
	operator delete[](ptr);
}
void operator delete [](void * ptr, size_t alignment, size_t alignmentOffset, const char * pName, int flags, unsigned debugFlags, const char * file, int line)
{
	// Does not support alignment
	operator delete[](ptr);
}



namespace BEngine {

	template<class T>
	#ifdef USE_EASTL
		using bvector = eastl::vector<T>;
	#else
		using bvector = std::vector<T>;
	#endif //USE_EASTL

	template<class T>
	#ifdef USE_EASTL
		using blist = eastl::list<T>;
	#else
		using blist = std::list<T>;
	#endif //USE_EASTL

		// ****** TODO: Causes error.
	// template<class T>
	// #ifdef USE_EASTL
	// 	using bmap = eastl::map<T>;
	// #else
	// 	using bmap = std::map<T>;
	// #endif //USE_EASTL
}
#endif //BCONTAINERS_H