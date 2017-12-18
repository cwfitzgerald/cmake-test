#pragma once

#include <cinttypes>
#include <string>

struct string_data {
	std::size_t bytes;
	std::size_t chars;
	std::size_t words;
	std::size_t lines;
	std::size_t longest_line;
};

string_data get_string_data(const std::string& input);