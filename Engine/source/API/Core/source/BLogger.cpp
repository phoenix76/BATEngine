#include <cstdarg>

#include "../include/BLogger.h"
#include "../BThreadUtils.h"

namespace BEngine
{
	void CBLogManager::alwaysLog(const char* startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
		m_currentDefaultLog->PrintTimeStamp();
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		m_currentDefaultLog->Write(buffer);
		va_end(args);
		free(buffer);
		m_currentDefaultLog->Write("\n");
	}

	void CBLogManager::alwaysLog(const BString& channel, const char* startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
		SLogChannel* temp = m_logChannels.find(channel)->second;
		temp->PrintTimeStamp();
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		temp->Write(buffer);
		va_end(args);
		free(buffer);
		temp->Write("\n");
	}

	void CBLogManager::debugLog(const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
#if defined BAT_WIN_DEBUG_X86 || defined BAT_WIN_DEBUG_X64
		m_currentDefaultLog->PrintTimeStamp();
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		m_currentDefaultLog->Write(buffer);
		va_end(args);
		free(buffer);
		m_currentDefaultLog->Write("\n");
#endif //BAT_WIN_DEBUG_X86 || BAT_WIN_DEBUG_X64
	}

	void CBLogManager::debugLog(const BString & channel, const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
#if defined BAT_WIN_DEBUG_X86 || defined BAT_WIN_DEBUG_X64
		SLogChannel* temp = m_logChannels.find(channel)->second;
		temp->PrintTimeStamp();
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		temp->Write(buffer);
		va_end(args);
		free(buffer);
		temp->Write("\n");
#endif //BAT_WIN_DEBUG_X86 || BAT_WIN_DEBUG_X64
	}

	void CBLogManager::addToLogD(const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
#if defined BAT_WIN_DEBUG_X86 || defined BAT_WIN_DEBUG_X64
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		m_currentDefaultLog->Write(buffer);
		va_end(args);
		free(buffer);
#endif //BAT_WIN_DEBUG_X86 || BAT_WIN_DEBUG_X64
	}

	void CBLogManager::addToLogD(const BString & channel, const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
#if defined BAT_WIN_DEBUG_X86 || defined BAT_WIN_DEBUG_X64
		SLogChannel* temp = m_logChannels.find(channel)->second;
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		temp->Write(buffer);
		va_end(args);
		free(buffer);
#endif //BAT_WIN_DEBUG_X86 || BAT_WIN_DEBUG_X64
	}

	void CBLogManager::addToLog(const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		m_currentDefaultLog->Write(buffer);
		va_end(args);
		free(buffer);
	}
	void CBLogManager::addToLog(const BString & channel, const char * startMsg, ...)
	{
		THREAD_GUARD(m_logMutex);
		SLogChannel* temp = m_logChannels.find(channel)->second;
		va_list args;
		va_start(args, startMsg);
		int len = _vscprintf(startMsg, args) + 1;
		char *buffer = static_cast<char*>(malloc(len*sizeof(char)));
		vsprintf_s(buffer, len, startMsg, args);
		temp->Write(buffer);
		va_end(args);
		free(buffer);
	}
	void CBLogManager::addLogChannel(const BString & channelName)
	{
		THREAD_GUARD(m_logMutex);
		//If log channel is not exist - find() will return end iterator and will be created a new log file
		if(m_logChannels.find(channelName) == m_logChannels.end())
			m_logChannels.insert(bpair<const char*, SLogChannel*>(channelName, new SLogChannel(channelName + ".txt", channelName)));
	}
	void CBLogManager::setLogByDefault(const BString & channelName)
	{
		THREAD_GUARD(m_logMutex);
		//If log channel is not exist - find() will return end iterator.
		if(m_logChannels.find(channelName) != m_logChannels.end())
			m_currentDefaultLog = m_logChannels.find(channelName)->second;
	}
} //namespace BEngine