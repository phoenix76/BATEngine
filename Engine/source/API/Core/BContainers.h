#ifndef BCONTAINERS_H
#define BCONTAINERS_H

#include <vector>
#include <list>
#include <map>
#include <set>

#include <EASTL/vector.h>
#include <EASTL/sort.h>
#include <EASTL/algorithm.h>
#include <EASTL/list.h>
#include <EASTL/map.h>
#include <EASTL/set.h>

#include "BEngineDefs.h"

// ****** TODO: Later remove these overriding operators as custom allocators will be made, they are needed for EASTL containers to work.
void * operator new[](size_t size, const char * pName, int flags, unsigned debugFlags, const char * file, int line);
void * operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char * pName, int flags, unsigned debugFlags, const char * file, int line);
void operator delete[](void * ptr, const char * pName, int flags, unsigned debugFlags, const char * file, int line);
void operator delete[](void * ptr, size_t alignment, size_t alignmentOffset, const char * pName, int flags, unsigned debugFlags, const char * file, int line);

namespace BEngine {

	// ****** NOTE: In file eabase.h line 724 typedef wchar_t  char16_t was commented.

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
	template<class Key, class ValType>
	#ifdef USE_EASTL
	using bmap = eastl::map<Key, ValType>;
	#else
		using bmap = std::map<Key, ValType>;
	#endif //USE_EASTL

	template<class Type1, class Type2>
	#ifdef USE_EASTL
		using bpair = eastl::pair<Type1, Type2>;
	#else
		using bpair = std::pair<Type1, Type2>;
	#endif //USE_EASTL

	template<class Key, class ValType>
	#ifdef USE_EASTL
		using bset = eastl::set<Key, ValType>;
	#else
		using set = std::set<Key, ValType>;
	#endif //USE_EASTL
}
#endif //BCONTAINERS_H