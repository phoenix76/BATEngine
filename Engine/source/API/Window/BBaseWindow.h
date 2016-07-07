/***********************************************************************
BBASEWINDOW


***********************************************************************/

#include "../Core/include/BVariables.h"

#ifndef BBASEWINDOW_H
#define BBASEWINDOW_H

namespace BEngine 
{
	class CIBaseInputSystem;
	class CIBaseWindow 
	{
		public:
			CIBaseWindow() {}
			virtual ~CIBaseWindow() {}
			
			virtual void initialize() = 0;
			virtual bool isWindowRunning() const = 0;
			virtual void update() = 0;
			virtual void shutdown() = 0;

			uint32 getWidth() const { return m_width; }
			uint32 getHeight() const { return m_height; }
			void* getHandle() const { return m_pHwnd; }

		protected:
			uint32 m_width;
			uint32 m_height;

			void* m_pHwnd;

		private:
		
	};
} //namespace BEngine

#endif //BBASEWINDOW_H