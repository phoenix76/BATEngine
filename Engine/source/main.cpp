#include <windows.h>
#include <thread>

#pragma comment(lib, "EASTLd.lib")

#include "API/Core/BMasterSystem.h"
#include "API/Core/include/BStringUtils.h"
//#include "API/Core/BConfig.h"

// ****** NOTE: Only for test purposes
#include "API/Core/BContainers.h"
//#include "API/Core/BEngineDefs.h"
#include "API/Core/include/BLogger.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//Hides compiler's warnings
	UNREFERENCED_PARAMETER(hInst);
	UNREFERENCED_PARAMETER(hPrevInst);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	//sLog.debugLog("tst");
	
	BEngine::BCMSystem* master = new BEngine::BCMSystem;
	master->initialize();

	return 0;
}