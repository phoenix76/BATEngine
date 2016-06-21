#include "../include/BStringUtils.h"

namespace BEngine
{
	CBString::CBString(const wchar_t* in)
	{
		std::wstring temp(in);
		m_str = std::string(temp.begin(), temp.end());
	}
	CBString& CBString::operator=(const wchar_t* in)
	{
		std::wstring temp(in);
		m_str = std::string(temp.begin(), temp.end());
		return *this;
	}
	CBString CBString::operator+(const wchar_t* in)
	{
		std::wstring temp(in);
		return CBString(m_str += std::string(temp.begin(), temp.end()));
	}
	std::wstring CBString::asWStr() const
	{
		typedef std::codecvt<wchar_t, char, mbstate_t> codec_t;
		return std::wstring_convert<codec_t>(&std::use_facet<codec_t>(std::locale(".1251"))).from_bytes(m_str.c_str());
	}
} //namespace BEngine