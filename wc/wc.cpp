#include "CLI/CLI.hpp"
#include "stringdata.hpp"
#include "sum.hpp"

int main(int argc, char** argv) {
	CLI::App cli_app{"Fast reimplimentation of wc"};

	bool find_bytes = true;
	bool find_chars = false;
	bool find_words = true;
	bool find_lines = true;
	bool find_max_line = false;

	cli_app.add_flag("-c,--bytes", find_bytes, "print the byte counts");
	cli_app.add_flag("-m,--chars", find_chars, "print the character counts");
	cli_app.add_flag("-w,--words", find_words, "print the word counts");
	cli_app.add_flag("-l,--lines", find_lines, "print the newline counts");
	cli_app.add_flag("-L,--max-line-length", find_max_line, "print the maximum display width");

	CLI11_PARSE(cli_app, argc, argv)

	auto x = get_string_data("Hello, how are you doing.\nI am doing fineÜÜÜÜÜÜÜÜÜÜÜÜÜ");
	std::cout << "bytes: " << x.bytes << '\n';
	std::cout << "chars: " << x.chars << '\n';
	std::cout << "words: " << x.words << '\n';
	std::cout << "lines: " << x.lines << '\n';
	std::cout << "max-line-length: " << x.longest_line << '\n';
}