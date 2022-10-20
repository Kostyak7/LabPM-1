#include "Test.h"

experiments::Test::Test() {

}

void experiments::Test::run() {
	start_char_test();
	start_int_test();
	start_double_test();
	start_str_test();
}

void experiments::Test::async_run() {
	boost::thread_group* tgroup = new boost::thread_group;
	tgroup->create_thread(boost::bind(&experiments::Test::start_char_test, this));
	tgroup->create_thread(boost::bind(&experiments::Test::start_int_test, this));
	tgroup->create_thread(boost::bind(&experiments::Test::start_double_test, this));
	tgroup->create_thread(boost::bind(&experiments::Test::async_start_str_test, this));
	//async_start_str_test();

	tgroup->join_all();

	delete tgroup;
	tgroup = nullptr;
}

int experiments::Test::test_check(const std::string& where_, const int& result, const std::string& type_) {
	if (result) std::cout << where_ << "\t" << type_ << " test failed\t - NO\n"; 
	else std::cout << where_ << "\t" << type_ << " test passed\t - OK\n";
	return result;
}

void experiments::Test::start_char_test() {
	std::cout << "Testing char containers...\n";
	int num_test = 0;

	for (int num = 0; std::ifstream(gtest::GenTest::folderpath(gtest::GenTest::char_folder, num)); ++num) {
		std::vector<char> vec = data::load_vector_char(gtest::GenTest::folderpath(gtest::GenTest::char_folder, num));
		std::deque<char> deq = data::load_deque_char(gtest::GenTest::folderpath(gtest::GenTest::char_folder, num));
		std::list<char> list_ = data::load_list_char(gtest::GenTest::folderpath(gtest::GenTest::char_folder, num));

		num_test += test_check("char", char_find_test(vec, deq, list_), "Find");
		num_test += test_check("char", char_sort_test(vec, deq, list_), "Sort");
		num_test += test_check("char", char_popF_test(vec, deq, list_), "PopF");
		num_test += test_check("char", char_popB_test(vec, deq, list_), "PopB");
		num_test += test_check("char", char_pushF_test(vec, deq, list_), "PushF");
		num_test += test_check("char", char_pushB_test(vec, deq, list_), "PushB");
	}
	if (num_test) {
		std::cout << "--Char tests failed!--\n";
		std::cout << "\tFailed " << num_test << "/6 tests";
	}
	else std::cout << "--Char tests success complete!--\n\n";
}
void experiments::Test::start_int_test() {
	std::cout << "Testing int containers...\n";
	int num_test = 0;

	for (int num = 0; std::ifstream(gtest::GenTest::folderpath(gtest::GenTest::int_folder, num)); ++num) {
		std::vector<int> vec = data::load_vector_int(gtest::GenTest::folderpath(gtest::GenTest::int_folder, num));
		std::deque<int> deq = data::load_deque_int(gtest::GenTest::folderpath(gtest::GenTest::int_folder, num));
		std::list<int> list_ = data::load_list_int(gtest::GenTest::folderpath(gtest::GenTest::int_folder, num));

		num_test += test_check("int", int_find_test(vec, deq, list_), "Find");
		num_test += test_check("int", int_sort_test(vec, deq, list_), "Sort");
		num_test += test_check("int", int_popF_test(vec, deq, list_), "PopF");
		num_test += test_check("int", int_popB_test(vec, deq, list_), "PopB");
		num_test += test_check("int", int_pushF_test(vec, deq, list_), "PushF");
		num_test += test_check("int", int_pushB_test(vec, deq, list_), "PushB");
	}
	if (num_test) {
		std::cout << "--Int tests failed!--\n";
		std::cout << "\tFailed " << num_test << "/6 tests";
	}
	else std::cout << "--Int tests success complete!--\n\n";
}
void experiments::Test::start_double_test() {
	std::cout << "Testing doubles containers...\n";
	int num_test = 0;

	for (int num = 0; std::ifstream(gtest::GenTest::folderpath(gtest::GenTest::double_folder, num)); ++num) {
		std::vector<double> vec = data::load_vector_double(gtest::GenTest::folderpath(gtest::GenTest::double_folder, num));
		std::deque<double> deq = data::load_deque_double(gtest::GenTest::folderpath(gtest::GenTest::double_folder, num));
		std::list<double> list_ = data::load_list_double(gtest::GenTest::folderpath(gtest::GenTest::double_folder, num));

		num_test += test_check("double", double_find_test(vec, deq, list_), "Find");
		num_test += test_check("double", double_sort_test(vec, deq, list_), "Sort");
		num_test += test_check("double", double_popF_test(vec, deq, list_), "PopF");
		num_test += test_check("double", double_popB_test(vec, deq, list_), "PopB");
		num_test += test_check("double", double_pushF_test(vec, deq, list_), "PushF");
		num_test += test_check("double", double_pushB_test(vec, deq, list_), "PushB");
	}
	if (num_test) {
		std::cout << "--Double tests failed!--\n";
		std::cout << "\tFailed " << num_test << "/6 tests";
	}
	else std::cout << "--Double tests success complete!--\n\n";
}
void experiments::Test::start_str_test() {
	std::cout << "Testing string containers...\n";
	int num_test = 0;

	for (int num = 0; std::ifstream(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num)); ++num) {
		std::vector<std::string> vec = data::load_vector_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));
		std::deque<std::string> deq = data::load_deque_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));
		std::list<std::string> list_ = data::load_list_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));

		num_test += test_check("string", str_find_test(vec, deq, list_), "Find");
		num_test += test_check("string", str_sort_test(vec, deq, list_), "Sort");
		num_test += test_check("string", str_popF_test(vec, deq, list_), "PopF");
		num_test += test_check("string", str_popB_test(vec, deq, list_), "PopB");
		num_test += test_check("string", str_pushF_test(vec, deq, list_), "PushF");
		num_test += test_check("string", str_pushB_test(vec, deq, list_), "PushB");
	}
	if (num_test) {
		std::cout << "--String tests failed!--\n";
		std::cout << "\tFailed " << num_test << "/6 tests";
	}
	else std::cout << "--String tests success complete!--\n\n";
}

void experiments::Test::async_str_pushF_test(int& num_test, const std::vector<std::string>& vec, const std::deque<std::string>& deq, const	std::list<std::string>& list_) {
	num_test += test_check("string", str_pushF_test(vec, deq, list_), "PushF");
}

void experiments::Test::async_start_str_test() {
	std::cout << "Testing string containers...\n";
	int num_test = 0;

	for (int num = 0; std::ifstream(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num)); ++num) {
		std::vector<std::string> vec = data::load_vector_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));
		std::deque<std::string> deq = data::load_deque_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));
		std::list<std::string> list_ = data::load_list_string(gtest::GenTest::folderpath(gtest::GenTest::str_folder, num));

		boost::thread* thrd_ = new boost::thread(boost::bind(&experiments::Test::async_str_pushF_test, this, num_test, vec, deq, list_));
		num_test += test_check("string", str_find_test(vec, deq, list_), "Find");
		num_test += test_check("string", str_sort_test(vec, deq, list_), "Sort");
		num_test += test_check("string", str_popF_test(vec, deq, list_), "PopF");
		num_test += test_check("string", str_popB_test(vec, deq, list_), "PopB");
		//num_test += test_check("string", str_pushF_test(vec, deq, list_), "PushF");
		num_test += test_check("string", str_pushB_test(vec, deq, list_), "PushB");
		thrd_->join();

		delete thrd_;
		thrd_ = nullptr;
	}
	if (num_test) {
		std::cout << "--String tests failed!--\n";
		std::cout << "\tFailed " << num_test << "/6 tests";
	}
	else std::cout << "--String tests success complete!--\n\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


int experiments::Test::char_find_test(const std::vector<char>& vec, const std::deque<char>& deq, const	std::list<char>& list_) {
	bool result = 0;
	tlog::TimeLogger tfind(tlog::TimeLogger::find_name, result);
	if (!result) return 1;
	int step_ = (vec.size() / 10) ? vec.size() / 10 : 1;
	//Vector
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(vec.begin(), vec.end(), vec[i]);
	}
	tfind.log_duration(vec.size(), "vector", "char");
	//Deque
	tfind.reset_start();
	for (int i = 0; i < deq.size(); i += step_) {
		std::find(deq.begin(), deq.end(), deq[i]);
	}
	tfind.log_duration(deq.size(), "deque", "char");
	//List
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(list_.begin(), list_.end(), vec[i]);
	}
	tfind.log_duration(list_.size(), "list", "char");
	return 0;
}
int experiments::Test::char_sort_test(std::vector<char> vec, std::deque<char> deq, std::list<char> list_) {
	bool result = 0;
	tlog::TimeLogger tsort(tlog::TimeLogger::sort_name, result);
	if (!result) return 1;
	//Vector
	tsort.reset_start();
	std::sort(vec.begin(), vec.end());
	tsort.log_duration(vec.size(), "vector", "char");
	//Deque
	tsort.reset_start();
	std::sort(deq.begin(), deq.end());
	tsort.log_duration(deq.size(), "deque", "char");
	//List
	tsort.reset_start();
	list_.sort();
	tsort.log_duration(list_.size(), "list", "char");
	return 0;
}
int experiments::Test::char_popF_test(std::vector<char> vec,std::deque<char> deq, std::list<char> list_) {
	bool result = 0;
	tlog::TimeLogger tpopF(tlog::TimeLogger::popF_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopF.reset_start();
	while (vec.size()) {
		vec.erase(vec.begin());
	}
	tpopF.log_duration(start_size, "vector", "char");
	//Deque
	tpopF.reset_start();
	while (deq.size()) {
		deq.pop_front();
	}
	tpopF.log_duration(start_size, "deque", "char");
	//List
	tpopF.reset_start();
	while (list_.size()) {
		list_.pop_front();
	}
	tpopF.log_duration(start_size, "list", "char");
	return 0;
}
int experiments::Test::char_popB_test(std::vector<char> vec, std::deque<char> deq, std::list<char> list_) {
	bool result = 0;
	tlog::TimeLogger tpopB(tlog::TimeLogger::popB_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopB.reset_start();
	while (vec.size()) {
		vec.pop_back();
	}
	tpopB.log_duration(start_size, "vector", "char");
	//Deque
	tpopB.reset_start();
	while (deq.size()) {
		deq.pop_back();
	}
	tpopB.log_duration(start_size, "deque", "char");
	//List
	tpopB.reset_start();
	while (list_.size()) {
		list_.pop_back();
	}
	tpopB.log_duration(start_size, "list", "char");
	return 0;
}
int experiments::Test::char_pushF_test(const std::vector<char>& vec, const  std::deque<char>& deq, const  std::list<char>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushF(tlog::TimeLogger::pushF_name, result);
	if (!result) return 1;
	//Vector
	std::vector<char> vec_vs;
	tpushF.reset_start();
	for (const char& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "char");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushF.reset_start();
	for (const char& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "char reserve");
	//Deque
	std::deque<char> deq_vs;
	tpushF.reset_start();
	for (const char& el : deq) {
		deq_vs.push_front(el);
	}
	tpushF.log_duration(deq.size(), "deque", "char");
	//List
	std::list<char> list_vs;
	tpushF.reset_start();
	for (const char& el : list_) {
		list_vs.push_front(el);
	}
	tpushF.log_duration(list_.size(), "list", "char");
	return 0;
}
int experiments::Test::char_pushB_test(const std::vector<char>& vec, const  std::deque<char>& deq, const  std::list<char>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushB(tlog::TimeLogger::pushB_name, result);
	if (!result) return 1;
	//Vector
	std::vector<char> vec_vs;
	tpushB.reset_start();
	for (const char& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "char");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushB.reset_start();
	for (const char& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "char reserve");
	//Deque
	std::deque<char> deq_vs;
	tpushB.reset_start();
	for (const char& el : deq) {
		deq_vs.push_back(el);
	}
	tpushB.log_duration(deq.size(), "deque", "char");
	//List
	std::list<char> list_vs;
	tpushB.reset_start();
	for (const char& el : list_) {
		list_vs.push_back(el);
	}
	tpushB.log_duration(list_.size(), "list", "char");
	return 0;
}

int experiments::Test::int_find_test(const std::vector<int>& vec, const std::deque<int>& deq, const	std::list<int>& list_) {
	bool result = 0;
	tlog::TimeLogger tfind(tlog::TimeLogger::find_name, result);
	if (!result) return 1;
	int step_ = (vec.size() / 10) ? vec.size() / 10 : 1;
	//Vector
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(vec.begin(), vec.end(), vec[i]);
	}
	tfind.log_duration(vec.size(), "vector", "int");
	//Deque
	tfind.reset_start();
	for (int i = 0; i < deq.size(); i += step_) {
		std::find(deq.begin(), deq.end(), deq[i]);
	}
	tfind.log_duration(deq.size(), "deque", "int");
	//List
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(list_.begin(), list_.end(), vec[i]);
	}
	tfind.log_duration(list_.size(), "list", "int");
	return 0;
}
int experiments::Test::int_sort_test(std::vector<int> vec, std::deque<int> deq, std::list<int> list_) {
	bool result = 0;
	tlog::TimeLogger tsort(tlog::TimeLogger::sort_name, result);
	if (!result) return 1;
	//Vector
	tsort.reset_start();
	std::sort(vec.begin(), vec.end());
	tsort.log_duration(vec.size(), "vector", "int");
	//Deque
	tsort.reset_start();
	std::sort(deq.begin(), deq.end());
	tsort.log_duration(deq.size(), "deque", "int");
	//List
	tsort.reset_start();
	list_.sort();
	tsort.log_duration(list_.size(), "list", "int");
	return 0;
}
int experiments::Test::int_popF_test(std::vector<int> vec, std::deque<int> deq, std::list<int> list_) {
	bool result = 0;
	tlog::TimeLogger tpopF(tlog::TimeLogger::popF_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopF.reset_start();
	while (vec.size()) {
		vec.erase(vec.begin());
	}
	tpopF.log_duration(start_size, "vector", "int");
	//Deque
	tpopF.reset_start();
	while (deq.size()) {
		deq.pop_front();
	}
	tpopF.log_duration(start_size, "deque", "int");
	//List
	tpopF.reset_start();
	while (list_.size()) {
		list_.pop_front();
	}
	tpopF.log_duration(start_size, "list", "int");
	return 0;
}
int experiments::Test::int_popB_test(std::vector<int> vec, std::deque<int> deq, std::list<int> list_) {
	bool result = 0;
	tlog::TimeLogger tpopB(tlog::TimeLogger::popB_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopB.reset_start();
	while (vec.size()) {
		vec.pop_back();
	}
	tpopB.log_duration(start_size, "vector", "int");
	//Deque
	tpopB.reset_start();
	while (deq.size()) {
		deq.pop_back();
	}
	tpopB.log_duration(start_size, "deque", "int");
	//List
	tpopB.reset_start();
	while (list_.size()) {
		list_.pop_back();
	}
	tpopB.log_duration(start_size, "list", "int");
	return 0;
}
int experiments::Test::int_pushF_test(const std::vector<int>& vec, const  std::deque<int>& deq, const  std::list<int>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushF(tlog::TimeLogger::pushF_name, result);
	if (!result) return 1;
	//Vector
	std::vector<int> vec_vs;
	tpushF.reset_start();
	for (const int& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "int");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushF.reset_start();
	for (const int& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "int reserve");
	//Deque
	std::deque<int> deq_vs;
	tpushF.reset_start();
	for (const int& el : deq) {
		deq_vs.push_front(el);
	}
	tpushF.log_duration(deq.size(), "deque", "int");
	//List
	std::list<int> list_vs;
	tpushF.reset_start();
	for (const int& el : list_) {
		list_vs.push_front(el);
	}
	tpushF.log_duration(list_.size(), "list", "int");
	return 0;
}
int experiments::Test::int_pushB_test(const std::vector<int>& vec, const  std::deque<int>& deq, const  std::list<int>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushB(tlog::TimeLogger::pushB_name, result);
	if (!result) return 1;
	//Vector
	std::vector<int> vec_vs;
	tpushB.reset_start();
	for (const int& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "int");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushB.reset_start();
	for (const int& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "int reserve");
	//Deque
	std::deque<int> deq_vs;
	tpushB.reset_start();
	for (const int& el : deq) {
		deq_vs.push_back(el);
	}
	tpushB.log_duration(deq.size(), "deque", "int");
	//List
	std::list<int> list_vs;
	tpushB.reset_start();
	for (const int& el : list_) {
		list_vs.push_back(el);
	}
	tpushB.log_duration(list_.size(), "list", "int");
	return 0;
}

int experiments::Test::double_find_test(const std::vector<double>& vec, const std::deque<double>& deq, const std::list<double>& list_) {
	bool result = 0;
	tlog::TimeLogger tfind(tlog::TimeLogger::find_name, result);
	if (!result) return 1;
	int step_ = (vec.size() / 10) ? vec.size()/ 10 : 1;
	//Vector
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(vec.begin(), vec.end(), vec[i]);
	}
	tfind.log_duration(vec.size(), "vector", "double");
	//Deque
	tfind.reset_start();
	for (int i = 0; i < deq.size(); i += step_) {
		std::find(deq.begin(), deq.end(), deq[i]);
	}
	tfind.log_duration(deq.size(), "deque", "double");
	//List
	tfind.reset_start();
	for (int i = 0; i < vec.size(); i += step_) {
		std::find(list_.begin(), list_.end(), vec[i]);
	}
	tfind.log_duration(list_.size(), "list", "double");
	return 0;
}
int experiments::Test::double_sort_test(std::vector<double> vec, std::deque<double> deq, std::list<double> list_) {
	bool result = 0;
	tlog::TimeLogger tsort(tlog::TimeLogger::sort_name, result);
	if (!result) return 1;
	//Vector
	tsort.reset_start();
	std::sort(vec.begin(), vec.end());
	tsort.log_duration(vec.size(), "vector", "double");
	//Deque
	tsort.reset_start();
	std::sort(deq.begin(), deq.end());
	tsort.log_duration(deq.size(), "deque", "double");
	//List
	tsort.reset_start();
	list_.sort();
	tsort.log_duration(list_.size(), "list", "double");
	return 0;
}
int experiments::Test::double_popF_test(std::vector<double> vec, std::deque<double> deq, std::list<double> list_) {
	bool result = 0;
	tlog::TimeLogger tpopF(tlog::TimeLogger::popF_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopF.reset_start();
	while (vec.size()) {
		vec.erase(vec.begin());
	}
	tpopF.log_duration(start_size, "vector", "double");
	//Deque
	tpopF.reset_start();
	while (deq.size()) {
		deq.pop_front();
	}
	tpopF.log_duration(start_size, "deque", "double");
	//List
	tpopF.reset_start();
	while (list_.size()) {
		list_.pop_front();
	}
	tpopF.log_duration(start_size, "list", "double");
	return 0;
}
int experiments::Test::double_popB_test(std::vector<double> vec, std::deque<double> deq, std::list<double> list_) {
	bool result = 0;
	tlog::TimeLogger tpopB(tlog::TimeLogger::popB_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopB.reset_start();
	while (vec.size()) {
		vec.pop_back();
	}
	tpopB.log_duration(start_size, "vector", "double");
	//Deque
	tpopB.reset_start();
	while (deq.size()) {
		deq.pop_back();
	}
	tpopB.log_duration(start_size, "deque", "double");
	//List
	tpopB.reset_start();
	while (list_.size()) {
		list_.pop_back();
	}
	tpopB.log_duration(start_size, "list", "double");
	return 0;
}
int experiments::Test::double_pushF_test(const std::vector<double>& vec, const  std::deque<double>& deq, const  std::list<double>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushF(tlog::TimeLogger::pushF_name, result);
	if (!result) return 1;
	//Vector
	std::vector<double> vec_vs;
	tpushF.reset_start();
	for (const double& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "double");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushF.reset_start();
	for (const double& el : vec) {
		vec_vs.push_back(0);
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "double reserve");
	//Deque
	std::deque<double> deq_vs;
	tpushF.reset_start();
	for (const double& el : deq) {
		deq_vs.push_front(el);
	}
	tpushF.log_duration(deq.size(), "deque", "double");
	//List
	std::list<double> list_vs;
	tpushF.reset_start();
	for (const double& el : list_) {
		list_vs.push_front(el);
	}
	tpushF.log_duration(list_.size(), "list", "double");
	return 0;
}
int experiments::Test::double_pushB_test(const std::vector<double>& vec, const  std::deque<double>& deq, const  std::list<double>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushB(tlog::TimeLogger::pushB_name, result);
	if (!result) return 1;
	//Vector
	std::vector<double> vec_vs;
	tpushB.reset_start();
	for (const double& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "double");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushB.reset_start();
	for (const double& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "double reserve");
	//Deque
	std::deque<double> deq_vs;
	tpushB.reset_start();
	for (const double& el : deq) {
		deq_vs.push_back(el);
	}
	tpushB.log_duration(deq.size(), "deque", "double");
	//List
	std::list<double> list_vs;
	tpushB.reset_start();
	for (const double& el : list_) {
		list_vs.push_back(el);
	}
	tpushB.log_duration(list_.size(), "list", "double");
	return 0;
}

int experiments::Test::str_find_test(const std::vector<std::string>& vec, const std::deque<std::string>& deq, const	std::list<std::string>& list_) {
	bool result = 0;
	tlog::TimeLogger tfind(tlog::TimeLogger::find_name, result);
	if (!result) return 1;
	int step_ = (vec.size() / 10) ? vec.size() / 10 : 1;
		//Vector
		tfind.reset_start();
		for (int i = 0; i < vec.size(); i += step_) {
			std::find(vec.begin(), vec.end(), vec[i]);
		}
		tfind.log_duration(vec.size(), "vector", "string");
		//Deque
		tfind.reset_start();
		for (int i = 0; i < deq.size(); i += step_) {
			std::find(deq.begin(), deq.end(), deq[i]);
		}
		tfind.log_duration(deq.size(), "deque", "string");
		//List
		tfind.reset_start();
		for (int i = 0; i < vec.size(); i += step_) {
			std::find(list_.begin(), list_.end(), vec[i]);
		}
		tfind.log_duration(list_.size(), "list", "string");
	return 0;
}
int experiments::Test::str_sort_test(std::vector<std::string> vec, std::deque<std::string> deq, std::list<std::string> list_) {
	bool result = 0;
	tlog::TimeLogger tsort(tlog::TimeLogger::sort_name, result);
	if (!result) return 1;
	//Vector
	tsort.reset_start();
	std::sort(vec.begin(), vec.end());
	tsort.log_duration(vec.size(), "vector", "string");
	//Deque
	tsort.reset_start();
	std::sort(deq.begin(), deq.end());
	tsort.log_duration(deq.size(), "deque", "string");
	//List
	tsort.reset_start();
	list_.sort();
	tsort.log_duration(list_.size(), "list", "string");
	return 0;
}
int experiments::Test::str_popF_test(std::vector<std::string> vec, std::deque<std::string> deq, std::list<std::string> list_) {
	bool result = 0;
	tlog::TimeLogger tpopF(tlog::TimeLogger::popF_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopF.reset_start();
	while (vec.size()) {
		vec.erase(vec.begin());
	}
	tpopF.log_duration(start_size, "vector", "string");
	//Deque
	tpopF.reset_start();
	while (deq.size()) {
		deq.pop_front();
	}
	tpopF.log_duration(start_size, "deque", "string");
	//List
	tpopF.reset_start();
	while (list_.size()) {
		list_.pop_front();
	}
	tpopF.log_duration(start_size, "list", "string");
	return 0;
}
int experiments::Test::str_popB_test(std::vector<std::string> vec, std::deque<std::string> deq, std::list<std::string> list_) {
	bool result = 0;
	tlog::TimeLogger tpopB(tlog::TimeLogger::popB_name, result);
	if (!result) return 1;
	const int start_size = vec.size();
	//Vector
	tpopB.reset_start();
	while (vec.size()) {
		vec.pop_back();
	}
	tpopB.log_duration(start_size, "vector", "string");
	//Deque
	tpopB.reset_start();
	while (deq.size()) {
		deq.pop_back();
	}
	tpopB.log_duration(start_size, "deque", "string");
	//List
	tpopB.reset_start();
	while (list_.size()) {
		list_.pop_back();
	}
	tpopB.log_duration(start_size, "list", "string");
	return 0;
}
int experiments::Test::str_pushF_test(const std::vector<std::string>& vec, const std::deque<std::string>& deq, const std::list<std::string>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushF(tlog::TimeLogger::pushF_name, result);
	if (!result) return 1;
	//Vector
	std::vector<std::string> vec_vs;
	tpushF.reset_start();
	for (const std::string& el : vec) {
		vec_vs.push_back(" ");
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "string");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushF.reset_start();
	for (const std::string& el : vec) {
		vec_vs.push_back(" ");
		for (size_t i = 0; i < vec_vs.size() - 1; ++i) {
			vec_vs[i + 1] = vec_vs[i];
		}
		vec_vs[0] = el;
	}
	tpushF.log_duration(vec.size(), "vector", "string reserve");
	//Deque
	std::deque<std::string> deq_vs;
	tpushF.reset_start();
	for (const std::string& el : deq) {
		deq_vs.push_front(el);
	}
	tpushF.log_duration(deq.size(), "deque", "string");
	//List
	std::list<std::string> list_vs;
	tpushF.reset_start();
	for (const std::string& el : list_) {
		list_vs.push_front(el);
	}
	tpushF.log_duration(list_.size(), "list", "string");
	return 0;
}
int experiments::Test::str_pushB_test(const std::vector<std::string>& vec, const  std::deque<std::string>& deq, const  std::list<std::string>& list_) {
	bool result = 0;
	tlog::TimeLogger tpushB(tlog::TimeLogger::pushB_name, result);
	if (!result) return 1;
	//Vector
	std::vector<std::string> vec_vs;
	tpushB.reset_start();
	for (const std::string& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "string");
	vec_vs.clear();
	vec_vs.reserve(vec.size());
	tpushB.reset_start();
	for (const std::string& el : vec) {
		vec_vs.push_back(el);
	}
	tpushB.log_duration(vec.size(), "vector", "string reserve");
	//Deque
	std::deque<std::string> deq_vs;
	tpushB.reset_start();
	for (const std::string& el : deq) {
		deq_vs.push_back(el);
	}
	tpushB.log_duration(deq.size(), "deque", "string");
	//List
	std::list<std::string> list_vs;
	tpushB.reset_start();
	for (const std::string& el : list_) {
		list_vs.push_back(el);
	}
	tpushB.log_duration(list_.size(), "list", "string");
	return 0;
}