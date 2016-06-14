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
#include <codecvt>

#include "BVariables.h"

namespace BEngine
{
	class CBString : private std::string
	{
	public:
		//Constructors
		CBString() : std::string("") {}
		//Copy ctor not required, generates automatically
		CBString(const std::string& in) : std::string(in) {}
		CBString(const std::wstring& in) : std::string(std::string(in.begin(), in.end())) {}
		CBString(const char* in) : std::string(in) {}
		CBString(const wchar_t* in);
		CBString(int8 in) : std::string(std::to_string(in)) {}
		CBString(uint8 in) : std::string(std::to_string(in)) {}
		CBString(int16 in) : std::string(std::to_string(in)) {}
		CBString(uint16 in) : std::string(std::to_string(in)) {}
		CBString(int32 in) : std::string(std::to_string(in)) {}
		CBString(uint32 in) : std::string(std::to_string(in)) {}
		CBString(int64 in) : std::string(std::to_string(in)) {}
		CBString(uint64 in) : std::string(std::to_string(in)) {}
// 		CBString(float in);
// 		CBString(double in);
// 		CBString(long double in);

		~CBString() {}

		//Assignment operators
		CBString& operator=(const CBString& in)		{ (std::string&)*this = (std::string&)in; return *this; }
		CBString& operator=(const std::string& in)	{ (std::string&)*this = in; return *this; }
		CBString& operator=(const std::wstring& in)	{ (std::string&)*this = std::string(in.begin(), in.end()); return *this; }
		CBString& operator=(const char* in)			{ (std::string&)*this = in; return *this; }
		CBString& operator=(const wchar_t* in);
		CBString& operator=(int8 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(uint8 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(int16 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(uint16 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(int32 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(uint32 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(int64 in)				{ (std::string&)*this = std::to_string(in); return *this; }
		CBString& operator=(uint64 in)				{ (std::string&)*this = std::to_string(in); return *this; }
// 		CBString& operator=(float in);
// 		CBString& operator=(double in);
// 		CBString& operator=(long double in);

		//Add operators
		CBString& operator+(const CBString& in)		{ (std::string&)*this += (std::string&)in; return *this; }
		CBString& operator+(const std::string& in)	{ (std::string&)*this += in; return *this; }
		CBString& operator+(const std::wstring& in) { (std::string&)*this += std::string(in.begin(), in.end()); return *this; }
		CBString& operator+(const char* in)			{ (std::string&)*this += in; return *this; }
		CBString& operator+(const wchar_t* in);
		CBString& operator+(int8 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(uint8 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(int16 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(uint16 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(int32 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(uint32 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(int64 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
		CBString& operator+(uint64 in)				{ (std::string&)*this += (std::string)CBString(in); return *this; }
// 		CBString& operator+(float in);
// 		CBString& operator+(double in);
// 		CBString& operator+(long double in);

		//Equal operators
		bool operator==(const CBString& in)			{ return (std::string&)*this == (std::string&)in; }
		bool operator==(const std::string& in)		{ return ((std::string&)*this == in); }
		bool operator==(const char* in)				{ return ((std::string&)*this == std::string(in)); }
		bool operator==(const std::wstring& in)		{ return (this->asWStr() == in); }
		bool operator==(const wchar_t* in)			{ return (this->asWStr() == std::wstring(in)); }

		//Getters
		std::string asStr()			const { return ((std::string)*this).c_str(); }
		const char* asCStr()		const { return this->c_str(); }
		std::wstring asWStr()		const;
		int8 asInt8()				const { return (int8)std::stoi((std::string&)*this); }
		uint8 asUInt8()				const { return (uint8)std::stoi((std::string&)*this); }
		int16 asInt16()				const { return (int16)std::stoi((std::string&)*this); }
		uint16 asUInt16()			const { return (uint16)std::stoi((std::string&)*this); }
		int32 asInt32()				const { return (int32)std::stoi((std::string&)*this); }
		uint32 asUInt32()			const { return (uint32)std::stoi((std::string&)*this); }
		int64 asInt64()				const { return (int64)std::stoll((std::string&)*this); }
		uint64 asUInt64()			const { return (uint64)std::stoull((std::string&)*this); }
// 		float asFloat()				const { return (float)std::strtof(((std::string&)*this).c_str(), nullptr); }
// 		double asDbl()				const { return (float)std::strtof(((std::string&)*this).c_str(), nullptr); }
// 		long double asLDbl()		const { return (float)std::strtof(((std::string&)*this).c_str(), nullptr); }

		//Using the base class's methods
		using std::string::empty;
		using std::string::size;
		using std::string::length;
		using std::string::clear;
		using std::string::erase;

		using std::string::operator[];

	private:
		std::stringstream m_dataConverter;

	};
} //namespace BEngine
#endif //CBSTRING_H