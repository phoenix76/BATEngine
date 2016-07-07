/***********************************************************************
BWINUTILS


***********************************************************************/

#ifndef BWINUTILS_H
#define BWINUTILS_H

#include "BEngineDefs.h"
#include "include/BStringUtils.h"

BEngine::BString GetTimeStamp();

namespace BEngine
{
	class CWindowsSystemInfo
	{
	public:
		CWindowsSystemInfo()
		{
			m_screenWidth = GetSystemMetrics(SM_CXSCREEN);
			m_screenHeight = GetSystemMetrics(SM_CYSCREEN);
		}

		uint32 getScreenWidth() const { return m_screenWidth; }
		uint32 getScreenHeight() const { return m_screenHeight; }

		~CWindowsSystemInfo() {}

	private:
		uint32 m_screenWidth;
		uint32 m_screenHeight;

	};
}

#endif //BWINUTILS_H