#include "GenTests.h"


/////////////////////////////GenTest///////////////////////////////////////////
const std::string gtest::GenTest::char_folder = "char";
const std::string gtest::GenTest::int_folder = "int";
const std::string gtest::GenTest::double_folder = "double";
const std::string gtest::GenTest::str_folder = "string";

const int gtest::GenTest::start_size = 10000;
const int gtest::GenTest::step = 10000;

std::string gtest::GenTest::folderpath(const std::string& folder_path, const int& num) {
	return "test/" + folder_path + "/" + filename(num);
}

std::string gtest::GenTest::filename(const int& num) {
	return "test_" + std::to_string(num) + ".txt";
}

std::string gtest::GenTest::rand_string() {
	int size_ = rand() % 21 + 20;
	std::string str_(size_, ' ');
	for (char& c : str_) {
		c = char(rand() % 94 + 33);
	}
	return str_;
}

gtest::GenTest::GenTest()
	: _char_tests_(10), _int_tests_(10), _double_tests_(10), _string_tests_(10)
{}

gtest::GenTest& gtest::GenTest::char_tests(const unsigned int& num_tests) {
	_char_tests_ = num_tests;
	//gen_char_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::int_tests(const unsigned int& num_tests) {
	_int_tests_ = num_tests;
	//gen_int_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::double_tests(const unsigned int& num_tests) {
	_double_tests_ = num_tests;
	//gen_double_tests();
	return *this;
}
gtest::GenTest& gtest::GenTest::string_tests(const unsigned int& num_tests) {
	_string_tests_ = num_tests;
	//gen_str_tests();
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

void gtest::GenTest::async_gen_tests() {
	remove_files(1);

	boost::thread_group* tgroup = new boost::thread_group;
	tgroup->create_thread(boost::bind(&gtest::GenTest::gen_char_tests, this));
	tgroup->create_thread(boost::bind(&gtest::GenTest::gen_int_tests, this));
	tgroup->create_thread(boost::bind(&gtest::GenTest::gen_double_tests, this));
	gen_str_tests();

	tgroup->join_all();

	delete tgroup;
	tgroup = nullptr;
}


void gtest::GenTest::gen_char_tests() {
	int num_gen_files = 0;
	for (int num = 0, amount_ = start_size; num < _char_tests_; ++num, amount_ += step) {
		std::ofstream fin(folderpath(char_folder, num));
		if (fin.is_open()) {
			char c = char(rand() % 94 + 33);
			for (int i = 0; i < amount_; ++i, c = char(rand() % 94 + 33)) {
				if (!(fin << c)) {
					std::cout << "gen_char_tests: something went wrong!\n";
					fin.close();
					return;
				}
			}
			fin.close();
			++num_gen_files;
		}
	}
	std::cout << "Generated " << num_gen_files << " files of char test\n";
}
void gtest::GenTest::gen_int_tests() {
	int num_gen_files = 0;
	for (int num = 0, amount_ = start_size; num < _int_tests_; ++num, amount_ += step) {
		std::ofstream fin(folderpath(int_folder, num));
		if (fin.is_open()) {
			int diap = pow(256, sizeof(int));
			int c = rand() % diap;
			for (int i = 0; i < amount_; ++i, c = rand() % diap) {
				if (!(fin << c)) {
					std::cout << "gen_int_tests: something went wrong!\n";
					fin.close();
					return;
				}
				fin << "\n";
			}
			fin.close();
			++num_gen_files;
		}
	}
	std::cout << "Generated " << num_gen_files << " files of int test\n";
}

void gtest::GenTest::gen_double_tests() {
	int num_gen_files = 0;
	for (int num = 0, amount_ = start_size; num < _double_tests_; ++num, amount_ += step) {
		std::ofstream fin(folderpath(double_folder, num));
		if (fin.is_open()) {
			double c = rand() % int(pow(256, sizeof(int))) / double(1 + rand() % int(pow(256, sizeof(int))));
			for (int i = 0; i < amount_; ++i, c = rand() % int(pow(256,sizeof(int))) / double(1 + rand() % int(pow(256, sizeof(int))))) {
				if (!(fin << c)) {
					std::cout << "gen_double_tests: something went wrong!\n";
					fin.close();
					return;
				}
				fin << "\n";
			}
			fin.close();
			++num_gen_files;
		}
	}
	std::cout << "Generated " << num_gen_files << " files of double test\n";
}
void gtest::GenTest::gen_str_tests() {
	int num_gen_files = 0;
	for (int num = 0, amount_ = start_size; num < _string_tests_; ++num, amount_ += step) {
		std::ofstream fin(folderpath(str_folder, num));
		if (fin.is_open()) {
			std::string str_ = rand_string();
			for (int i = 0; i < amount_; ++i, str_ = rand_string()) {
				if (!(fin << str_)) {
					std::cout << "gen_str_tests: something went wrong!\n";
					fin.close();
					return;
				}
				fin << "\n";
			}
			fin.close();
			++num_gen_files;
		}
	}
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

void gtest::GenTest::remove_test_files(const std::string& folder_, int& test_files) {
	int num = 0;
	while (std::ifstream(folderpath(folder_, num))) {
		test_files += (std::remove(folderpath(folder_, num++).c_str())) ? 0 : 1;
	}
}

void gtest::GenTest::remove_files(bool is_remove_statistics)
/*
* Remove test and statistics files
*/
{
	int test_files = 0;
	remove_test_files(char_folder, test_files);
	remove_test_files(int_folder, test_files);
	remove_test_files(double_folder, test_files);
	remove_test_files(str_folder, test_files);
	std::cout << "Removed " << test_files << " test files\n";

	if (is_remove_statistics) {
		int stat_files = 0;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::find_name).c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::sort_name).c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::popF_name).c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::popB_name).c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::pushF_name).c_str())) ? 0 : 1;
		stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::pushB_name).c_str())) ? 0 : 1;
		std::cout << "Removed " << stat_files << " statistics files\n";
		sqll::SQLdb to_clear;
		to_clear.open_db(tlog::TimeLogger::db_name);
		to_clear.clear_table(tlog::TimeLogger::find_name);
		to_clear.clear_table(tlog::TimeLogger::sort_name);
		to_clear.clear_table(tlog::TimeLogger::popF_name);
		to_clear.clear_table(tlog::TimeLogger::popB_name);
		to_clear.clear_table(tlog::TimeLogger::pushF_name);
		to_clear.clear_table(tlog::TimeLogger::pushB_name);
		std::cout << "DataBase: " << tlog::TimeLogger::db_name << " truncated tables\n";
	}
	std::cout << "\n";
}
