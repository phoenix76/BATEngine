#include "../include/BStringUtils.h"

namespace BEngine
{
	CBString::CBString(const wchar_t* in)
	{
		std::wstring temp(in);
		(std::string&)*this = std::string(temp.begin(), temp.end());
	}
	CBString::CBString(float in)
	{
		m_dataConverter << in;
		m_dataConverter >> (std::string&)*this;
	}
	CBString::CBString(double in)
	{
		m_dataConverter << in;
		m_dataConverter >> (std::string&)*this;
	}
	CBString::CBString(long double in)
	{
		m_dataConverter << in;
		m_dataConverter >> (std::string&)*this;
	}
	CBString& CBString::operator=(const wchar_t* in)
	{
		std::wstring temp(in);
		(std::string&)*this = std::string(temp.begin(), temp.end());
	}
	CBString& CBString::operator+(const wchar_t* in)
	{
		std::wstring temp(in);
		(std::string&)*this += std::string(temp.begin(), temp.end());
	}
	CBString& CBString::operator+(float in)
	{
		
		m_dataConverter << in;
		(std::string&)*this += m_dataConverter.str();
	}
	CBString& CBString::operator+(double in)
	{

		m_dataConverter << in;
		(std::string&)*this += m_dataConverter.str();
	}
	CBString& CBString::operator+(long double in)
	{

		m_dataConverter << in;
		(std::string&)*this += m_dataConverter.str();
	}
	std::wstring CBString::asWStr() const
	{
		typedef std::codecvt<wchar_t, char, mbstate_t> codec_t;
		return std::wstring_convert<codec_t>(&std::use_facet<codec_t>(std::locale(".1251"))).from_bytes(((std::string*)this)->c_str());
	}
	const wchar_t* CBString::asWCStr() const
	{
		typedef std::codecvt<wchar_t, char, mbstate_t> codec_t;
		return (std::wstring_convert<codec_t>(&std::use_facet<codec_t>(std::locale(".1251"))).from_bytes(((std::string*)this)->c_str())).c_str();
	}
} //namespace BEngine