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
	class CBString
	{
	private:
		std::string m_str;

	public:
		//Constructors
		CBString() : m_str("") {}
		//Copy ctor not required, generates automatically
		CBString(const std::string& in) : m_str(in) {}
		CBString(const std::wstring& in) : m_str(std::string(in.begin(), in.end())) {}
		CBString(const char* in) : m_str(in) {}
		CBString(const wchar_t* in);
		CBString(int8 in) : m_str(std::to_string(in)) {}
		CBString(uint8 in) : m_str(std::to_string(in)) {}
		CBString(int16 in) : m_str(std::to_string(in)) {}
		CBString(uint16 in) : m_str(std::to_string(in)) {}
		CBString(int32 in) : m_str(std::to_string(in)) {}
		CBString(uint32 in) : m_str(std::to_string(in)) {}
		CBString(int64 in) : m_str(std::to_string(in)) {}
		CBString(uint64 in) : m_str(std::to_string(in)) {}

		~CBString() {}

		//Assignment operators
		CBString& operator=(const CBString& in)		{ m_str = in.m_str; return *this; }
		CBString& operator=(const std::string& in)	{ m_str = in; return *this; }
		CBString& operator=(const std::wstring& in)	{ m_str = std::string(in.begin(), in.end()); return *this; }
		CBString& operator=(const char* in)			{ m_str = in; return *this; }
		CBString& operator=(const wchar_t* in);
		CBString& operator=(int8 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(uint8 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(int16 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(uint16 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(int32 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(uint32 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(int64 in)				{ m_str = std::to_string(in); return *this; }
		CBString& operator=(uint64 in)				{ m_str = std::to_string(in); return *this; }

		//Add operators
		CBString operator+(const CBString& in)		const { return CBString(m_str + in.m_str); }
		CBString operator+(const std::string& in)	const { return CBString(m_str + in); }
		CBString operator+(const std::wstring& in)	const { return CBString(m_str + std::string(in.begin(), in.end())); }
		CBString operator+(const char* in)			const { return CBString(m_str + in); }
		CBString operator+(const wchar_t* in);
		CBString operator+(int8 in)					const { return CBString(m_str + (char)in); }
		CBString operator+(uint8 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(int16 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(uint16 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(int32 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(uint32 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(int64 in)				const { return CBString(m_str + std::to_string(in)); }
		CBString operator+(uint64 in)				const { return CBString(m_str + std::to_string(in)); }

		CBString& operator+=(const std::string& in) { m_str += in; return *this; }
		CBString& operator+=(const char* in)		{ m_str += in; return *this; }
		CBString& operator+=(const char& in)		{ m_str += in; return *this; }

		//Equal operators
		bool operator==(const CBString& in)			const { return m_str == in.m_str; }
		bool operator==(const std::string& in)		const { return m_str == in; }
		bool operator==(const char* in)				const { return m_str == in; }
		bool operator==(const std::wstring& in)		const { return (this->asWStr() == in); }
		bool operator==(const wchar_t* in)			const { return (this->asWStr() == std::wstring(in)); }

		char operator[](int index) const { return m_str[index]; }
		char& operator[](int index)		 { return m_str[index]; }
		

		//Getters
		std::string asStr()			const { return m_str; }
		const char* asCStr()		const { return m_str.c_str(); }
		std::wstring asWStr()		const;
		int8 asInt8()				const { return (int8)std::stoi(m_str); }
		uint8 asUInt8()				const { return (uint8)std::stoi(m_str); }
		int16 asInt16()				const { return (int16)std::stoi(m_str); }
		uint16 asUInt16()			const { return (uint16)std::stoi(m_str); }
		int32 asInt32()				const { return (int32)std::stoi(m_str); }
		uint32 asUInt32()			const { return (uint32)std::stoi(m_str); }
		int64 asInt64()				const { return (int64)std::stoll(m_str); }
		uint64 asUInt64()			const { return (uint64)std::stoull(m_str); }

		auto begin() -> decltype(m_str.begin()) { return m_str.begin(); }
		auto end() -> decltype(m_str.end()) { return m_str.end(); }

		void clear() { m_str.clear(); }


		operator std::string()		const { return m_str; }
		operator const char*()		const { return m_str.c_str(); }

		explicit operator std::wstring() const { return this->asWStr(); }

	};

	typedef CBString BString;
} //namespace BEngine
#endif //CBSTRING_H