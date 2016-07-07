/***********************************************************************
BWINDOWMANAGER


***********************************************************************/

#ifndef BWINDOWMANAGER_H
#define BWINDOWMANAGER_H

#include "../Core/BBaseManager.h"

namespace BEngine 
{
	class CIBaseWindow;
	class CIBaseInputSystem;

	class CWindowManager : public CIBaseManager
	{
		public:
			CWindowManager() {}
			~CWindowManager() {}
			
			bool initialize() override;
			void update() override;
			bool isRunning() const;
			void shutdown() override;

		private:
			CIBaseWindow* m_pWindow;
			CIBaseInputSystem* m_pInputSystem;
	};
} //namespace BEngine

#endif //BWINDOWMANAGER_H