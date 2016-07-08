#include "BWindowManager.h"

#include "BWindowsWindow.h"
#include "BWindowsInput.h"
#include "../Core/include/BLogger.h"
#include "../Core/include/BPlatformDependencies.h"

namespace BEngine
{

	bool CWindowManager::initialize()
	{
#ifdef BAT_WINDOWS

		m_pInputSystem = new CWindowsInput();
		m_pInputSystem->initialize();
		m_pWindow = new CWindowsWindow(dynamic_cast<CWindowsInput*>(m_pInputSystem));
		CWindowsWindow* wnd = dynamic_cast<CWindowsWindow*>(m_pWindow);

		wnd->initialize();
		while(!wnd->isInitializedSucceeded())
		{
			if(!wnd->isInitializedFailed() && !wnd->isInitializedSucceeded())
				;
			else if(wnd->isInitializedFailed())
			{
				MessageBoxA(NULL, "Create window error", "ENGINE ERROR", MB_OK);
				return false;
			}
			else
				break;
		}
		return true;
#else
		return false;
#endif //BAT_WINDOWS
	}

	void CWindowManager::update()
	{

	}

	void CWindowManager::shutdown()
	{
		m_pWindow->shutdown();
		if(m_pWindow) m_pWindow;
		if(m_pInputSystem) m_pInputSystem;
	}

	bool CWindowManager::isRunning() const
	{
		return m_pWindow->isWindowRunning();
	}

}