/***********************************************************************
BWINDOWSWINDOW


***********************************************************************/

#ifndef BWINDOWSWINDOW_H
#define BWINDOWSWINDOW_H

#include "BBaseWindow.h"
#include "../Core/BWinUtils.h"
#include "BIOTypes.h"

#include <windows.h>
#include <thread>
#include <atomic>

namespace BEngine 
{
	struct SWindowParameters;
	class CWindowsInput;
	class CWindowSystemInfo;
	class CWindowsWindow;

	class CWindowsWindow : public CIBaseWindow
	{
		public:
			CWindowsWindow(CWindowsInput* input);
			~CWindowsWindow()
			{

			}

			void initialize() override;
			void update() override;
			void startProcessing();
			void stopProcessing() { m_windowIsRun = false; }
			void shutdown() override;
			
			bool isInitializedSucceeded() const { return m_isInitialized.load(); }
			bool isInitializedFailed() const { return m_isInitializedFailed.load(); }
			bool isWindowRunning() const override { return m_windowIsRun.load(); }

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

			bool cursorIsShow() { return m_showCursor; }
			void changeCursor(HCURSOR cur) { SetCursor(cur); m_cursor = cur; }
			void hideCursor()
			{
				if(m_showCursor)
				{
					int32 counter = ShowCursor(FALSE);
					while((counter = ShowCursor(FALSE)) >= 0);
					m_showCursor = false;
				}
			}
			void showCursor()
			{
				if(!m_showCursor)
				{
					int32 counter = ShowCursor(TRUE);
					while((counter = ShowCursor(TRUE)) <= 0);
					m_showCursor = true;
				}
			}
			void setIcon(HICON icon) { SendMessage(*(HWND*)m_pHwnd, WM_SETICON, ICON_BIG, (LPARAM)icon); }
			HINSTANCE getHInstance() const { return m_appInstance; }

			uint32 getClientWidth() const { return m_windowSizeParams.clientWidth; }
			uint32 getClientHeight() const { return m_windowSizeParams.clientHeigth; }
			
		private:
			void m_setWindowParams(const SWindowParameters& params);
			void m_windowInitialize();
			HRESULT m_regClass();
			HRESULT m_createWindowedApp();
			HRESULT m_createFullscreenApp();
			void m_destroyWINAPIResourses();

			CWindowsInput* m_pInputSystem;

			HINSTANCE m_appInstance;
			HCURSOR m_cursor;
			WCHAR* m_windowTitle;
			bool m_fullScreen;
			std::atomic<bool> m_windowIsRun;
			bool m_showCursor;
			bool m_windowCreate;
			std::atomic<bool> m_isInitialized;
			std::atomic<bool> m_isInitializedFailed;
			std::thread* m_pThread;
			POINT m_cursorPos;
			CWindowsSystemInfo m_systemInfo;
			SWindowSizeParameters m_windowSizeParams;
	};

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static	CWindowsWindow* App = 0;
} //namespace BEngine

#endif //BWINDOWSWINDOW_H