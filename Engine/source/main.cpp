#include <windows.h>

#include "API/Core/include/BStringUtils.h"
//#include "API/Core/BConfig.h"

// ****** NOTE: Only for test purposes
#define USE_EASTL
#include "API/Core/BContainers.h"


void * operator new [](size_t size/*, const char * pName, int flags, unsigned debugFlags, const char * file, int line*/)
{
	return operator new[](size);
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{


	BEngine::bvector<int> testVector;
	testVector.push_back(1);
	testVector.push_back(2);
	testVector.push_back(5);
	testVector.push_back(10);
	testVector.push_back(20);
	BEngine::CBString str = testVector[4];
	MessageBoxA(NULL, str.asCStr(), "msg", MB_OK);
	testVector.clear();

	return 0;
}