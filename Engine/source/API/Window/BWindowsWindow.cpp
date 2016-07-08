#include "BWindowsWindow.h"
#include "../Core/include/BLogger.h"
#include "../Core/BConfig.h"
#include "BIOTypes.h"

namespace BEngine
{
	CWindowsWindow::CWindowsWindow(CWindowsInput* input) : m_windowTitle(L"Engine"), m_pInputSystem(input) { App = this; }

	void CWindowsWindow::initialize()
	{
		m_pThread = new std::thread(&CWindowsWindow::m_windowInitialize, this);
	}

	void CWindowsWindow::update()
	{
		// ****** TODO: Need MessageManager
		return;
	}

	void CWindowsWindow::startProcessing()
	{
		static MSG msg;
		while(m_windowIsRun.load())
		{
			if(PeekMessage(&msg, *(HWND*)m_pHwnd, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		m_destroyWINAPIResourses();
	}

	void CWindowsWindow::shutdown()
	{
		if(m_pThread->joinable())
		{
			m_pThread->join();
			if(m_pThread) delete m_pThread;
		}
		if(m_pHwnd) delete m_pHwnd;
	}

	LRESULT CALLBACK CWindowsWindow::MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		static SKeyEvent keyEvent;
		static SMouseButtonEvent mouseEvent;
		static short scancode;

		switch(msg)
		{
		case WM_CLOSE:
			m_windowIsRun = false;
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_KEYDOWN:
			if(wParam == VK_ESCAPE)
			{
				//if(MessageBox(NULL, L"You really want to exit?", L"Engine", MB_YESNO) == 6)
					m_windowIsRun = false;
			}
			
			uint8 scancode;

			return 0;

		case WM_KEYUP:
			return 0;

		case WM_LBUTTONDOWN:
			return 0;

		case WM_SETCURSOR:
			SetCursor(m_cursor);
			return 0;

		case WM_MOUSEMOVE:
			m_cursorPos.x = LOWORD(lParam);
			m_cursorPos.y = HIWORD(lParam);
			return 0;

		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	void CWindowsWindow::m_setWindowParams(const SWindowParameters& params)
	{
		m_width = params.width;
		m_height = params.height;
		m_fullScreen = params.fullScreen;
	}

	void CWindowsWindow::m_windowInitialize()
	{
		m_setWindowParams(sConfig.getWindowParameters());
		m_pHwnd = (void*) new HWND;
		m_appInstance = GetModuleHandle(NULL);
		if(SUCCEEDED(m_regClass()))
		{
			if(m_fullScreen)
			{
				if(FAILED(m_createFullscreenApp()))
				{
					m_isInitializedFailed = true;
					sLog.alwaysLog("Error create window");
					m_destroyWINAPIResourses();
				}
				else
					m_windowCreate = true;
			}
			else
			{
				if(FAILED(m_createWindowedApp()))
				{
					m_isInitializedFailed = true;
					sLog.alwaysLog("Error create window");
					m_destroyWINAPIResourses();
				}
				else
					m_windowCreate = true;
			}
		}
		else
		{
			m_isInitializedFailed = true;
			sLog.alwaysLog("Error register window class");
		}
		m_showCursor = true;

		//For test only
		changeCursor(LoadCursor(NULL, IDC_ARROW));
		setIcon(LoadIcon(NULL, IDI_APPLICATION));

		if(!m_isInitializedFailed)
		{
			m_isInitialized = true;
			m_windowIsRun = true;
		}

		if(m_isInitialized)
			startProcessing();
	}

	HRESULT CWindowsWindow::m_regClass()
	{
		WNDCLASSEX wc;
		ZeroMemory(&wc, sizeof(wc));
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.hInstance = m_appInstance;
		wc.lpfnWndProc = (WNDPROC)WndProc;
		wc.lpszClassName = m_windowTitle;
		wc.lpszMenuName = NULL;
		wc.hIcon = wc.hIconSm = NULL;
		wc.hCursor = NULL;
		wc.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
		wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		if(!RegisterClassEx(&wc))
			return E_FAIL;
		return S_OK;
	}

	HRESULT CWindowsWindow::m_createWindowedApp()
	{
		uint32 windowPosX = (GetSystemMetrics(SM_CXSCREEN) - m_width) / 2;
		uint32 windowPosY = (GetSystemMetrics(SM_CYSCREEN) - m_height) / 2;
		*(HWND*)m_pHwnd = CreateWindowEx(WS_EX_APPWINDOW, m_windowTitle, m_windowTitle, WS_OVERLAPPEDWINDOW, windowPosX,windowPosY, m_width, m_height, NULL, NULL, m_appInstance, NULL);
		if(!(*(HWND*)m_pHwnd))
			return E_FAIL;
		
		ShowWindow(*(HWND*)m_pHwnd, SW_SHOW);
		SetForegroundWindow(*(HWND*)m_pHwnd);
		SetFocus(*(HWND*)m_pHwnd);
		return S_OK;
	}

	HRESULT CWindowsWindow::m_createFullscreenApp()
	{
		m_width = m_systemInfo.getScreenWidth();
		m_height = m_systemInfo.getScreenHeight();
		uint32 windowPosX = 0U;
		uint32 windowPosY = 0U;

		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)m_width;
		dmScreenSettings.dmPelsHeight = (unsigned long)m_height;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		*(HWND*)m_pHwnd = CreateWindowEx(WS_EX_APPWINDOW, m_windowTitle, m_windowTitle, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			windowPosX, windowPosY, m_width, m_height, NULL, NULL, m_appInstance, NULL);
		if(!(*(HWND*)m_pHwnd))
			return E_FAIL;

		ShowWindow(*(HWND*)m_pHwnd, SW_SHOW);
		SetForegroundWindow(*(HWND*)m_pHwnd);
		SetFocus(*(HWND*)m_pHwnd);
		return S_OK;
	}

	void CWindowsWindow::m_destroyWINAPIResourses()
	{
		if(m_fullScreen)
			ChangeDisplaySettings(NULL, 0);
		UnregisterClass(m_windowTitle, m_appInstance);
		if(m_windowCreate)
			DestroyWindow(*(HWND*)m_pHwnd);
	}

	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return App->MessageHandler(hwnd, msg, wParam, lParam);
	}

} //namespace BEngine