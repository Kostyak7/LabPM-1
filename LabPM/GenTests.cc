#include "GenTests.h"

int gtest::GenTest::counter = 0;
const int gtest::GenTest::start_size = 10000;
const int gtest::GenTest::step = 10000;

std::string gtest::GenTest::filename(int num) {
	return "test/test_" + std::to_string(num) + ".txt";
}

std::string gtest::GenTest::rand_string() {
	int size_ = rand() % 21 + 20;
	std::string str_(size_, ' ');
	for (char& c : str_) {
		c = char(rand() % 223 + 32);
	}
	return str_;
}

gtest::GenTest::GenTest()
	: _char_tests_(1), _int_tests_(1), _double_tests_(1), _string_tests_(1)
{}

gtest::GenTest& gtest::GenTest::char_tests(const unsigned int& num_tests) {
	_char_tests_ = num_tests;
	gen_char_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::int_tests(const unsigned int& num_tests) {
	_int_tests_ = num_tests;
	gen_int_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::double_tests(const unsigned int& num_tests) {
	_double_tests_ = num_tests;
	gen_double_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::string_tests(const unsigned int& num_tests) {
	_string_tests_ = num_tests;
	gen_str_tests();
	return *this;
}

void gtest::GenTest::gen_tests() {
	remove_files(1);
	gen_char_tests();
	gen_int_tests();
	gen_double_tests();
	gen_str_tests();
	std::cout << "End of test file generation\n\n";
}

bool gtest::GenTest::open_file(const std::string& path_name) {
	fin.open(path_name);
	if (!fin.is_open()) {
		std::cout << "File: " << path_name << " wasn`t opened!\n";
		return false;
	}
	return true;
}

void gtest::GenTest::close_file() {
	fin.close();
}

void gtest::GenTest::gen_char_tests() {
	int num_gen_files = 0;
	for (int num = counter, amount_ = start_size; num < counter + _char_tests_; ++num, amount_ += step) {
		if (open_file(filename(num))) {
			char c = char(rand() % 256);
			for (int i = 0; i < amount_; ++i, c = char(rand() % 256)) {
				if (!(fin << c)) {
					std::cout << "gen_char_tests: something went wrong!\n";
					counter += num;
					close_file();
					return;
				}
			}
			close_file();
			++num_gen_files;
		}
	}
	counter += _char_tests_;
	std::cout << "Generated " << num_gen_files << " files of char test\n";
}
void gtest::GenTest::gen_int_tests() {
	int num_gen_files = 0;
	for (int num = counter, amount_ = start_size; num < counter + _int_tests_; ++num, amount_ += step) {
		if (open_file(filename(num))) {
			int diap = pow(256, sizeof(int));
			int c = rand() % diap;
			for (int i = 0; i < amount_; ++i, c = rand() % diap) {
				if (!(fin << c << "\n")) {
					if (!(rand() % step)) fin << " \n";
					std::cout << "gen_int_tests: something went wrong!\n";
					counter += num;
					close_file();
					return;
				}
			}
			close_file();
			++num_gen_files;
		}
	}
	counter += _int_tests_;
	std::cout << "Generated " << num_gen_files << " files of int test\n";
}

void gtest::GenTest::gen_double_tests() {
	int num_gen_files = 0;
	for (int num = counter, amount_ = start_size; num < counter + _double_tests_; ++num, amount_ += step) {
		if (open_file(filename(num))) {
			double c = rand() % int(pow(256, sizeof(int))) / double(1 + rand() % int(pow(256, sizeof(int))));
			for (int i = 0; i < amount_; ++i, c = rand() % int(pow(256,sizeof(int))) / double(1 + rand() % int(pow(256, sizeof(int))))) {
				if (!(fin << c << "\n")) {
					if (!(rand() % step)) fin << " \n";
					std::cout << "gen_double_tests: something went wrong!\n";
					counter += num;
					close_file();
					return;
				}
			}
			close_file();
			++num_gen_files;
		}
	}
	counter += _double_tests_;
	std::cout << "Generated " << num_gen_files << " files of double test\n";
}
void gtest::GenTest::gen_str_tests() {
	int num_gen_files = 0;
	for (int num = counter, amount_ = start_size; num < counter + _string_tests_; ++num, amount_ += step) {
		if (open_file(filename(num))) {
			std::string str_ = rand_string();
			for (int i = 0; i < amount_; ++i, str_ = rand_string()) {
				if (!(fin << str_ << "\n")) {
					if (!(rand() % step)) fin << " \n";
					std::cout << "gen_str_tests: something went wrong!\n";
					counter += num;
					close_file();
					return;
				}
			}
			close_file();
			++num_gen_files;
		}
	}
	counter += _string_tests_;
	std::cout << "Generated " << num_gen_files << " files of string test\n";
}


unsigned int gtest::GenTest::get_num_char() const {
	return _char_tests_;
}
unsigned int gtest::GenTest::get_num_int() const {
	return _int_tests_;
}
unsigned int gtest::GenTest::get_num_double() const {
	return _double_tests_;
}
unsigned int gtest::GenTest::get_num_str() const {
	return _string_tests_;
}

int gtest::GenTest::get_counter() const {
	return counter;
}


void gtest::GenTest::remove_files(bool is_remove_statistics)
/*
* Remove test and statistics files
*/
{
	int test_files = 0;
	for (int i = 0; i < _char_tests_ + _int_tests_ + _double_tests_ + _string_tests_; ++i) {
		test_files += (std::remove(filename(i).c_str()))? 0: 1;
	}
	std::cout << "Removed " << test_files << " test files\n";

	if (is_remove_statistics) {
		int stat_files = 0;
		stat_files += (std::remove(tlog::TimeLogger::find_FileName.c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::sort_FileName.c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::popF_FileName.c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::popB_FileName.c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::pushF_FileName.c_str()) ? 0 : 1);
		stat_files += (std::remove(tlog::TimeLogger::pushB_FileName.c_str())) ? 0 : 1;
		std::cout << "Removed " << stat_files << " statistics files\n";
	}
	std::cout << "\n";
}