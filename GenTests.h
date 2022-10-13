#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>

#include "TimeLogger.h"

namespace gtest {
	class GenTest {
	private:
		static int counter;
		static const int start_size;
		static const int step;
		static std::string rand_string();
		unsigned int _char_tests_, _int_tests_, _double_tests_, _string_tests_;
		std::ofstream fin;

		bool open_file(const std::string& path_name);
		void close_file();

		void gen_char_tests();
		void gen_int_tests();
		void gen_double_tests();
		void gen_str_tests();

	public:
		static std::string filename(int num);

		GenTest();
		GenTest& char_tests(const unsigned int& num_tests);
		GenTest& int_tests(const unsigned int& num_tests);
		GenTest& double_tests(const unsigned int& num_tests);
		GenTest& string_tests(const unsigned int& num_tests);

		void gen_tests();

		unsigned int get_num_char() const;
		unsigned int get_num_int() const;
		unsigned int get_num_double() const;
		unsigned int get_num_str() const;

		int get_counter() const;

		void remove_files(bool is_remove_statistics = 0);
	};
}