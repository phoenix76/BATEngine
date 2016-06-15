#ifndef BCONTAINERS_H
#define BCONTAINERS_H

#include <vector>
#include <list>
#include <map>

template<class T>
#ifdef USE_EASTL_VECTOR
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

template<class T>
#ifdef USE_EASTL
	using bmap = eastl::map<T>;
#else
	using bmap = std::map<T>;
#endif //USE_EASTL

#endif //BCONTAINERS_H