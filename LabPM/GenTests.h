#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "TimeLogger.h"
#include "sqlDataBase.h"

namespace gtest {

	class GenTest {
	private:
		static const int start_size;
		static const int step;
		static std::string rand_string();
		unsigned int _char_tests_, _int_tests_, _double_tests_, _string_tests_;

		void gen_char_tests();
		void gen_int_tests();
		void gen_double_tests();
		void gen_str_tests();

		static void remove_test_files(const std::string& folder_, int& test_files);

	public:
		static const std::string char_folder;
		static const std::string int_folder;
		static const std::string double_folder;
		static const std::string str_folder;

		static std::string folderpath(const std::string& folder_path, const int& num);
		static std::string filename(const int& num);

		GenTest();
		GenTest& char_tests(const unsigned int& num_tests);
		GenTest& int_tests(const unsigned int& num_tests);
		GenTest& double_tests(const unsigned int& num_tests);
		GenTest& string_tests(const unsigned int& num_tests);

		void gen_tests();
		void async_gen_tests();
		unsigned int get_num_char() const;
		unsigned int get_num_int() const;
		unsigned int get_num_double() const;
		unsigned int get_num_str() const;

		void remove_files(bool is_remove_statistics = 0);
	};
}