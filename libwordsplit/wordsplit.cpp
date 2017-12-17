#include "wordsplit.hpp"
#include <iostream>
#include <memory>
#include <unicode/regex.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/utypes.h>

std::vector<std::string> split_on_word(const std::string& input) {
	UErrorCode regex_status = U_ZERO_ERROR;
	auto matcher = std::make_unique<icu::RegexMatcher>("\\p{Letter}+", 0, regex_status);

	if (U_FAILURE(regex_status)) {
		std::cout << u_errorName(regex_status) << '\n';
	}

	auto unicode_string = icu::UnicodeString::fromUTF8(icu::StringPiece(input.c_str()));
	matcher->reset(unicode_string);

	std::vector<std::string> word_list;

	while (matcher->find()) {
		auto start = matcher->start(regex_status);
		auto end = matcher->end(regex_status);

		icu::UnicodeString match;
		unicode_string.extract(start, end - start, match);
		match.toLower();

		std::string utf8_encoded;
		match.toUTF8String(utf8_encoded);
		word_list.emplace_back(std::move(utf8_encoded));
	}

	return word_list;
}