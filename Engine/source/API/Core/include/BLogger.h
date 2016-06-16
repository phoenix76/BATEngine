/***********************************************************************
CBLOGMANAGER


***********************************************************************/

#ifndef CBLOGMANAGER_H
#define CBLOGMANAGER_H

#include <fstream>

#include "BStringUtils.h"
#include "../BEngineDefs.h"

namespace BEngine 
{
	class CBLogManager 
	{
		public:

			struct SLogChannel
			{
				SLogChannel(const BString& fileName, const BString& channelName, const BString& filePath)
				{
					file = new std::ofstream;
					_fileName = fileName;
					_channelName = channelName;
					_filePath = filePath;
					file->open(BString(_filePath + _fileName).asCStr(), std::ios_base::app);
					*file << "START SESSION AT " << GetTimeStamp().c_str() << "\n\n\n";
				}
				template<typename T>
				void Write(const T& msg)
				{
					*file << msg;
				}
				template<> void Write<>(const std::string& msg)
				{
					*file << msg.c_str();
				}
				void Destroy()
				{
					if(file)
					{
						*file << "\n\nEND SESSION AT " << GetTimeStamp().c_str() << '\n'
							<< "--------------------------------------------------------------------\n\n";
						file->close();
						delete file;
					}
				}
				std::string GetTimeStamp()
				{
					time_t rawtime;
					tm * timeinfo;
					time(&rawtime);
					timeinfo = localtime(&rawtime);
					std::string info = "";
					if(timeinfo->tm_mday < 10)
						info += '0' + std::to_string(timeinfo->tm_mday) + '.';
					else
						info += std::to_string(timeinfo->tm_mday) + '.';
					if(timeinfo->tm_mon < 10)
						info += '0' + std::to_string(timeinfo->tm_mon) + '.';
					else
						info += std::to_string(timeinfo->tm_mon) + '.';
					info += std::to_string(timeinfo->tm_year + 1900) + " | ";
					if(timeinfo->tm_hour < 10)
						info += '0' + std::to_string(timeinfo->tm_hour) + ':';
					else
						info += std::to_string(timeinfo->tm_hour) + ':';
					if(timeinfo->tm_min < 10)
						info += '0' + std::to_string(timeinfo->tm_min) + ':';
					else
						info += std::to_string(timeinfo->tm_min) + ':';
					if(timeinfo->tm_sec < 10)
						info += '0' + std::to_string(timeinfo->tm_sec);
					else
						info += std::to_string(timeinfo->tm_sec);
					return info;
				}

				void PrintTimeStamp()
				{
					*file << GetTimeStamp() << "-> ";
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