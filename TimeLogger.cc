#include "TimeLogger.h"

const std::string tlog::TimeLogger::find_FileName = "csv/find_time.csv";
const std::string tlog::TimeLogger::sort_FileName = "csv/sorting_time.csv";
const std::string tlog::TimeLogger::popF_FileName = "csv/pop_front_time.csv";
const std::string tlog::TimeLogger::popB_FileName = "csv/pop_back_time.csv";
const std::string tlog::TimeLogger::pushF_FileName = "csv/push_front_time.csv";
const std::string tlog::TimeLogger::pushB_FileName = "csv/push_back_time.csv";

bool tlog::TimeLogger::open_file(const std::string& path_name) {
	close_file();
	bool is_new = !std::ifstream(path_name);
	fin.open(path_name, std::ios::app);
	if (!fin.is_open()) {
		std::cout << "File: " << path_name << " wasn`t opened!\n";
		return false;
	}
	if (is_new) {
		fin << "sep = ;\n";
		fin << "duration, ns;size;type;message\n";
	}
	return true;
}

void tlog::TimeLogger::close_file() {
	if (fin.is_open()) fin.close();
}

tlog::TimeLogger::TimeLogger(const std::string& path_name)
	:start_(std::chrono::high_resolution_clock::now())
{
	open_file(path_name);
}

tlog::TimeLogger::TimeLogger(const std::string& path_name, bool& is_open)
	:start_(std::chrono::high_resolution_clock::now())
{
	is_open = open_file(path_name);
}

tlog::TimeLogger::~TimeLogger() {
	close_file();
}


void tlog::TimeLogger::reset_start() {
	start_ = std::chrono::high_resolution_clock::now();
}
void tlog::TimeLogger::log_duration(int size_, const std::string& type_) {
	auto stop_ = std::chrono::high_resolution_clock::now();
	size_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_ - start_).count();
	if (fin << duration) { fin << ";"; }
	if (fin << size_) { fin << ";"; }
	if (fin << type_) { fin << ";"; }
	fin << "\n";
	start_ += std::chrono::high_resolution_clock::now() - stop_;
}
void tlog::TimeLogger::log_duration(int size_, const std::string& type_, const std::string& message_) {
	auto stop_ = std::chrono::high_resolution_clock::now();
	size_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_ - start_).count();
	if (fin << duration) { fin << ";"; }
	if (fin << size_) { fin << ";"; }
	if (fin << type_) { fin << ";"; }
	if (fin << message_) { fin << ";"; }
	fin << "\n";
	start_ += std::chrono::high_resolution_clock::now() - stop_;
}