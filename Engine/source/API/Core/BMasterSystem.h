/***********************************************************************
BCMSYSTEM


***********************************************************************/

#ifndef BCMSYSTEM_H
#define BCMSYSTEM_H

#include <atomic>

#include "../Window/BWindowManager.h"

namespace BEngine 
{
	class BCMSystem 
	{
		public:
			BCMSystem() {}
			~BCMSystem() {}
			
			void initialize()
			{
				m_pWindowMgr = new CWindowManager;
				if(!m_pWindowMgr->initialize())
				{
					m_pWindowMgr->shutdown();
				}
				

				startUpdate();
				shutDown();
			}

			void forceShutDown(bool flag)
			{
				m_systemStateUpdate = flag;
			}
		private:

			void startUpdate()
			{
				while(m_pWindowMgr->isRunning())
				{
					m_pWindowMgr->update();
				}
			}

			void shutDown()
			{
				m_pWindowMgr->shutdown();
			}
			CWindowManager* m_pWindowMgr;
			std::atomic<bool> m_systemStateUpdate;

	};
} //namespace BEngine

#endif //BCMSYSTEM_H