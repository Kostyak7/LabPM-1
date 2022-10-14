#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>

namespace data {

	std::vector<char> load_vector_char(const std::string& path_file);
	std::vector<int> load_vector_int(const std::string& path_file);
	std::vector<double> load_vector_double(const std::string& path_file);
	std::vector<std::string> load_vector_string(const std::string& path_file);
	std::list<char> load_list_char(const std::string& path_file);
	std::list<int> load_list_int(const std::string& path_file);
	std::list<double> load_list_double(const std::string& path_file);
	std::list<std::string> load_list_string(const std::string& path_file);
	std::deque<char> load_deque_char(const std::string& path_file);
	std::deque<int> load_deque_int(const std::string& path_file);
	std::deque<double> load_deque_double(const std::string& path_file);
	std::deque<std::string> load_deque_string(const std::string& path_file);
}
