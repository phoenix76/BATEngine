#include <ctime>

#include "BWinUtils.h"

BEngine::BString GetTimeStamp()
{
	time_t rawtime;
	tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	BEngine::BString info;
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