/***********************************************************************
CBLOGMANAGER

This class allows to log to *.txt files. Logging may be to a several files.
This class may be to use in multiple threads.
It is a singleton. To initialize need to call some method.

METHODS:

void alwaysLog(const char* startMsg, ...);
void alwaysLog(const BString& channel, const char* startMsg, ...);
void addToLog(const char* startMsg, ...);
void addToLog(const BString& channel, const char* startMsg, ...);

will be called with a release and debug configurations.

METHODS:

void debugLog(const char* startMsg, ...);
void debugLog(const BString& channel, const char* startMsg, ...);
void addToLogD(const char* startMsg, ...);
void addToLogD(const BString& channel, const char* startMsg, ...);

will be called with only debug configuration.

By default, logging is to a file base_system_log.txt, which has a channel name "system".
If you want to add a log file, you need to call a addLogChannel() method and next to call setLogByDefault() method in which to pass new channel's name.

Call debugLog(const char* startMsg, ...) method will be log to a default log file.
Call debugLog(const BString& channel, const char* startMsg, ...) method will be log to a channel specified in "channel" argument.

//IMPORTANT!!! Method setLogByDefault() don't process cases if log channel not exist.

***********************************************************************/

#ifndef CBLOGMANAGER_H
#define CBLOGMANAGER_H

#include <fstream>
#include <mutex>

#include "../BWinUtils.h"
#include "BStringUtils.h"
#include "../BThreadUtils.h"
#include "../BContainers.h"

namespace BEngine 
{
	class CBLogManager 
	{
		public:
			struct SLogChannel
			{
				SLogChannel(const BString& fileName, const BString& channelName, const BString& filePath = "logs/")
				{
					file = new std::ofstream;
					_fileName = fileName;
					_channelName = channelName;
					_filePath = filePath;
					std::string temp = BString(_filePath + _fileName).asCStr();
					file->open(BString(_filePath + _fileName).asCStr(), std::ios_base::app);
					*file << "START SESSION AT " << GetTimeStamp().asCStr() << "\n\n\n";
				}
				template<typename T>
				void Write(const T& msg)
				{
					*file << msg;
				}
				void Destroy()
				{
					if(file)
					{
						*file << "\n\nEND SESSION AT " << GetTimeStamp().asCStr() << '\n'
							<< "--------------------------------------------------------------------\n\n";
						file->close();
						delete file;
					}
				}
				void PrintTimeStamp()
				{
					*file << GetTimeStamp().asCStr() << "-> ";
				}

				std::ofstream* file;
				BString _fileName;
				BString _channelName;
				BString _filePath;
			};

			static CBLogManager& getInstance() 
			{
				static CBLogManager cInstance;
				return cInstance;
			}

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
			CBLogManager() 
			{
				m_logChannels.insert(bpair<const char*, SLogChannel*>("system", new SLogChannel("base_system_log.txt", "system")));
				m_currentDefaultLog = m_logChannels.find("system")->second;
			}
			~CBLogManager()
			{
				for(auto it = m_logChannels.begin(); it != m_logChannels.end(); it++)
				{
					it->second->Destroy();
					delete it->second;
				}
			}
			CBLogManager(const CBLogManager&) {}
			CBLogManager& operator=(const CBLogManager&) {}
		
			std::mutex m_logMutex;
			bmap<std::string, SLogChannel*> m_logChannels;
			SLogChannel* m_currentDefaultLog;
	};
} //namespace BEngine

#define sLog BEngine::CBLogManager::getInstance()

#endif //CBLOGMANAGER_H