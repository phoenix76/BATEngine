/***********************************************************************
CBLOGMANAGER


***********************************************************************/

#ifndef CBLOGMANAGER_H
#define CBLOGMANAGER_H

#include "BStringUtils.h"

namespace BEngine 
{
	class CBLogManager 
	{
		public:
			static CBLogManager& getInstance() 
			{
				static CBLogManager cInstance;
				return cInstance;
			}

			//By default
			void alwaysLog(const char* startMsg, ...);
			void alwaysLog(const BString& channel, const char* startMsg, ...);
			void debugLog(const char* startMsg, ...);
			void debugLog(const BString& channel, const char* startMsg, ...);
			void addToLogD(const char* startMsg, ...);
			void addToLogD(const BString& channel, const char* startMsg, ...);
			void addToLog(const char* startMsg, ...);
			void addToLog(const BString& channel, const char* startMsg, ...);

			void addLogChannel(const BString& channelName);
			void setLogByDefault(const BString& channelName);

		private:
			CBLogManager() {}
			~CBLogManager() {}
			CBLogManager(const CBLogManager&) {}
			CBLogManager& operator=(const CBLogManager&) {}
	};
} //namespace BEngine
#endif //CBLOGMANAGER_H