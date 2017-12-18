#include "stringdata.hpp"
#include <iostream>
#include <memory>
#include <unicode/regex.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/utypes.h>

string_data get_string_data(const std::string& input) {
	string_data data;
	data.bytes = input.size();

	UErrorCode regex_status = U_ZERO_ERROR;
	auto word_matcher = std::make_unique<icu::RegexMatcher>("\\p{Letter}+", 0, regex_status);
	if (U_FAILURE(regex_status)) {
		std::cout << u_errorName(regex_status) << '\n';
	}

	auto line_matcher = std::make_unique<icu::RegexMatcher>("^.*$", UREGEX_MULTILINE, regex_status);
	if (U_FAILURE(regex_status)) {
		std::cout << u_errorName(regex_status) << '\n';
	}

	auto unicode_string = icu::UnicodeString::fromUTF8(icu::StringPiece(input.c_str()));
	word_matcher->reset(unicode_string);
	line_matcher->reset(unicode_string);

	data.chars = unicode_string.length();

	data.words = 0;
	while (word_matcher->find()) {
		data.words += 1;
	}

	data.lines = 0;
	data.longest_line = 0;

	while (line_matcher->find()) {
		auto start = line_matcher->start(regex_status);
		auto end = line_matcher->end(regex_status);

		std::size_t len = end - start;
		data.longest_line = std::max(len, data.longest_line);
		data.lines += 1;
	}

	data.lines = data.lines > 0 ? data.lines - 1 : 0;

	return data;
}