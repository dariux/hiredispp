/*
 * hiredispp.cpp
 */

#include "hiredispp.h"
#include <boost/archive/detail/utf8_codecvt_facet.hpp>

namespace hiredispp
{
	template<>
	const std::basic_string<char> RedisConst<char>::Nil = "**NIL**";

	template<>
	const std::basic_string<wchar_t> RedisConst<wchar_t>::Nil = L"**NIL**";

	template<>
	void RedisEncoding<wchar_t>::decode(const char* data, size_t size, std::basic_string<wchar_t>& string)
	{
		const size_t bufferSize = 512;
		wchar_t buffer[bufferSize];

		if (size)
		{
			std::codecvt_base::result result = std::codecvt_base::partial;

			while (result == std::codecvt_base::partial)
			{
				wchar_t* bufferIt;
				const char* dataIt;

				std::mbstate_t conversionState = std::mbstate_t();
				result = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t> >(std::locale(std::locale::classic(),
						new boost::archive::detail::utf8_codecvt_facet)).in(conversionState, data, data + size, dataIt, buffer, buffer + bufferSize, bufferIt);

				string.append(buffer, bufferIt);
				size -= (dataIt - data);
				data = dataIt;
			}

			if (result == std::codecvt_base::error)
			{
			}
		}
	}

	template<>
	void RedisEncoding<wchar_t>::encode(const std::basic_string<wchar_t>& string, std::string& data)
	{
		const size_t bufferSize = 512;
		char buffer[bufferSize];
		size_t size = string.size();

		if (size)
		{
			std::codecvt_base::result result = std::codecvt_base::partial;
			char* bufferIt;
			const wchar_t* stringBegin = string.c_str();
			const wchar_t* stringIt;

			while (result == std::codecvt_base::partial)
			{
				std::mbstate_t conversionState = std::mbstate_t();
				result = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t> >(std::locale(std::locale::classic(),
						new boost::archive::detail::utf8_codecvt_facet)).out(conversionState, stringBegin, stringBegin + size, stringIt, buffer, buffer + bufferSize, bufferIt);

				data.append(buffer, bufferIt);
				size -= (stringIt - stringBegin);
				stringBegin = stringIt;
			}

			if (result == std::codecvt_base::error)
			{
			}
		}
	}
}