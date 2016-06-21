#include <windows.h>
#include <thread>

#pragma comment(lib, "EASTLd.lib")

#include "API/Core/include/BStringUtils.h"
//#include "API/Core/BConfig.h"

// ****** NOTE: Only for test purposes
#include "API/Core/BContainers.h"
#include "API/Core/BEngineDefs.h"
#include "API/Core/include/BLogger.h"

void f()
{
	unsigned int b = 0;
	while(b++ < 1000)
		sLog.debugLog("test #%d", b);
}
void f2()
{
	unsigned int b = 0;
	while(b++ < 1000)
		sLog.debugLog("test #%d", b);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	sLog.debugLog("tst");
	std::thread t1(f);
	std::thread t2(f2);
	t1.join();
	t2.join();

	eastl::vector<int> testVector;
	testVector.push_back(1);
	testVector.push_back(2);
	testVector.push_back(5);
	testVector.push_back(10);
	testVector.push_back(20);
	
	testVector.clear();

	return 0;
}