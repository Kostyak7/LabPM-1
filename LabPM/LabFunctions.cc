#include "LabFunctions.h"

std::vector<char> data::load_vector_char(const std::string& path_file) {
	std::vector<char> vec;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return vec;
	}
	for (char el; !fout.eof();) {
		if (fout >> el) vec.push_back(el);
	}
	fout.close();
	return vec;
}
std::vector<int> data::load_vector_int(const std::string& path_file) {
	std::vector<int> vec;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return vec;
	}
	for (int el; !fout.eof();) {
		if (fout >> el) vec.push_back(el);
	}
	fout.close();
	return vec;
}
std::vector<double> data::load_vector_double(const std::string& path_file) {
	std::vector<double> vec;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return vec;
	}
	for (double el; !fout.eof();) {
		if (fout >> el) vec.push_back(el);
	}
	fout.close();
	return vec;
}
std::vector<std::string> data::load_vector_string(const std::string& path_file) {
	std::vector<std::string> vec;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return vec;
	}
	for (std::string el; !fout.eof();) {
		if (fout >> el) vec.push_back(el);
	}
	fout.close();
	return vec;
}
std::list<char> data::load_list_char(const std::string& path_file) {
	std::list<char> list_;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return list_;
	}
	for (char el; !fout.eof();) {
		if (fout >> el) list_.push_back(el);
	}
	fout.close();
	return list_;
}
std::list<int> data::load_list_int(const std::string& path_file) {
	std::list<int> list_;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return list_;
	}
	for (int el; !fout.eof();) {
		if (fout >> el) list_.push_back(el);
	}
	fout.close();
	return list_;
}
std::list<double> data::load_list_double(const std::string& path_file) {
	std::list<double> list_;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return list_;
	}
	for (double el; !fout.eof();) {
		if (fout >> el) list_.push_back(el);
	}
	fout.close();
	return list_;
}
std::list<std::string> data::load_list_string(const std::string& path_file) {
	std::list<std::string> list_;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return list_;
	}
	for (std::string el; !fout.eof();) {
		if (fout >> el) list_.push_back(el);
	}
	fout.close();
	return list_;
}
std::deque<char> data::load_deque_char(const std::string& path_file) {
	std::deque<char> deq;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return deq;
	}
	for (char el; !fout.eof();) {
		if (fout >> el) deq.push_back(el);
	}
	fout.close();
	return deq;
}
std::deque<int> data::load_deque_int(const std::string& path_file) {
	std::deque<int> deq;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return deq;
	}
	for (int el; !fout.eof();) {
		if (fout >> el) deq.push_back(el);
	}
	fout.close();
	return deq;
}
std::deque<double> data::load_deque_double(const std::string& path_file) {
	std::deque<double> deq;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return deq;
	}
	for (double el; !fout.eof();) {
		if (fout >> el) deq.push_back(el);
	}
	fout.close();
	return deq;
}
std::deque<std::string> data::load_deque_string(const std::string& path_file) {
	std::deque<std::string> deq;
	std::ifstream fout(path_file);
	if (!fout.is_open()) {
		std::cout << "Unable to open file: " << path_file << "\n";
		return deq;
	}
	for (std::string el; !fout.eof();) {
		if (fout >> el) deq.push_back(el);
	}
	fout.close();
	return deq;
}