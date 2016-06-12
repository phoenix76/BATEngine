/***********************************************************************
CBSTRING

This class allows working with the strings.
Makes a string from digital values.
Returns the string's digital representations.

***********************************************************************/

#ifndef CBSTRING_H
#define CBSTRING_H

#include <string>
#include <sstream>

#include "BVariables.h"

namespace BEngine
{
	class CBString : private std::string
	{
	public:
		//Constructors
		CBString() : std::string("") {}
		//Copy ctor not required, generates automatically
		CBString(const std::string& in)	: std::string(in) {}
		CBString(const char* in)		: std::string(in) {}
		CBString(const wchar_t* in);
		CBString(int8 in)				: std::string(std::to_string(in)) {}
		CBString(uint8 in)				: std::string(std::to_string(in)) {}
		CBString(int16 in)				: std::string(std::to_string(in)) {}
		CBString(uint16 in)				: std::string(std::to_string(in)) {}
		CBString(int32 in)				: std::string(std::to_string(in)) {}
		CBString(uint32 in)				: std::string(std::to_string(in)) {}
		CBString(int64 in)				: std::string(std::to_string(in)) {}
		CBString(uint64 in)				: std::string(std::to_string(in)) {}
		CBString(float in);
		CBString(double in);
		CBString(long double in);

		//Assignment operators
		//Assignment operator for CBString not required, generates automatically
		CBString& operator=(const std::string& in)	{ (std::string&)*this = in; }
		CBString& operator=(const char* in)			{ (std::string&)*this = in; }
		CBString& operator=(const wchar_t* in);
		CBString& operator=(int8 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(uint8 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(int16 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(uint16 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(int32 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(uint32 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(int64 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(uint64 in)				{ (std::string&)*this = std::to_string(in); }
		CBString& operator=(float in);
		CBString& operator=(double in);
		CBString& operator=(long double in);

		//Add operators
		CBString& operator+(const std::string& in)	{ (std::string&)*this += in; }
		CBString& operator+(const char* in)			{ (std::string&)*this += in; }
		CBString& operator+(const wchar_t* in);
		CBString& operator+(int8 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(uint8 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(int16 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(uint16 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(int32 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(uint32 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(int64 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(uint64 in)				{ (std::string&)*this += (std::string)CBString(in); }
		CBString& operator+(float in);
		CBString& operator+(double in);
		CBString& operator+(long double in);

		//Getters
		std::string asStr()			const;
		const char* asCStr()		const;
		std::wstring asWStr()		const;
		const wchar_t* asWCStr()	const;
		int8 asInt8()				const;
		uint8 asUInt8()				const;
		int16 asInt16()				const;
		uint16 asUInt16()			const;
		int32 asInt32()				const;
		uint32 asUInt32()			const;
		int64 asInt64()				const;
		uint64 asUInt64()			const;
		float asFloat()				const;
		double asDbl()				const;
		long double asLDbl()		const;

		//Using the base class's methods
		using std::string::length;
		using std::string::clear;
		using std::string::erase;

		~CBString() {}

	private:
		std::stringstream m_dataConverter;

	};
} //namespace BEngine
#endif //CBSTRING_H