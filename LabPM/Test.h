#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include "TimeLogger.h"
#include "LabFunctions.h"
#include "GenTests.h"


namespace experiments {

	class Test {
	private:
		static int test_check(const int& result, const std::string& type_);

		static int char_find_test(const std::vector<char>& vec, const std::deque<char>& deq,const	std::list<char>& list_);
		static int char_sort_test(std::vector<char> vec, std::deque<char> deq, std::list<char> list_);
		static int char_popF_test(std::vector<char> vec,   std::deque<char> deq,   std::list<char> list_);
		static int char_popB_test(std::vector<char> vec,   std::deque<char> deq,   std::list<char> list_);
		static int char_pushF_test(const std::vector<char>& vec, const  std::deque<char>& deq, const  std::list<char>& list_);
		static int char_pushB_test(const std::vector<char>& vec, const  std::deque<char>& deq, const  std::list<char>& list_);

		static int int_find_test(const std::vector<int>& vec, const std::deque<int>& deq, const	std::list<int>& list_);
		static int int_sort_test(std::vector<int> vec, std::deque<int> deq, std::list<int> list_);
		static int int_popF_test( std::vector<int> vec,   std::deque<int> deq,   std::list<int> list_);
		static int int_popB_test( std::vector<int> vec,   std::deque<int> deq,   std::list<int> list_);
		static int int_pushF_test(const std::vector<int>& vec, const  std::deque<int>& deq, const  std::list<int>& list_);
		static int int_pushB_test(const std::vector<int>& vec, const  std::deque<int>& deq, const  std::list<int>& list_);

		static int double_find_test(const std::vector<double>& vec, const std::deque<double>& deq, const std::list<double>& list_);
		static int double_sort_test(std::vector<double> vec, std::deque<double> deq, std::list<double> list_);
		static int double_popF_test( std::vector<double> vec, std::deque<double> deq,std::list<double> list_);
		static int double_popB_test( std::vector<double> vec, std::deque<double> deq, std::list<double> list_);
		static int double_pushF_test(const std::vector<double>& vec, const  std::deque<double>& deq, const  std::list<double>& list_);
		static int double_pushB_test(const std::vector<double>& vec, const  std::deque<double>& deq, const  std::list<double>& list_);

		static int str_find_test(const std::vector<std::string>& vec, const std::deque<std::string>& deq, const	std::list<std::string>& list_);
		static int str_sort_test(std::vector<std::string> vec, std::deque<std::string> deq, std::list<std::string> list_);
		static int str_popF_test( std::vector<std::string> vec,  std::deque<std::string> deq,   std::list<std::string> list_);
		static int str_popB_test( std::vector<std::string> vec,  std::deque<std::string> deq,   std::list<std::string> list_);
		static int str_pushF_test(const std::vector<std::string>& vec, const std::deque<std::string>& deq, const  std::list<std::string>& list_);
		static int str_pushB_test(const std::vector<std::string>& vec, const  std::deque<std::string>& deq, const  std::list<std::string>& list_);

	public:
		Test();

		void run();
		void start_char_test();
		void start_int_test();
		void start_double_test();
		void start_str_test();
	};

}