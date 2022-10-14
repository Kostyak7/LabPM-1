#include "TimeLogger.h"


bool tlog::TimeLogger::db_mode = 0;

std::string tlog::TimeLogger::csv(const std::string& _name) {
	return "csv/" + _name + ".csv";
}

const std::string tlog::TimeLogger::db_name = "database.db";
const std::string tlog::TimeLogger::find_name = "find_time";
 const std::string tlog::TimeLogger::sort_name = "sorting_time";
 const std::string tlog::TimeLogger::popF_name = "pop_front_time";
 const std::string tlog::TimeLogger::popB_name = "pop_back_time";
 const std::string tlog::TimeLogger::pushF_name = "push_front_time";
 const std::string tlog::TimeLogger::pushB_name = "push_back_time";

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
	:start_(std::chrono::high_resolution_clock::now()),
	cur_name(path_name)
{
	if (!db_mode) open_file(csv(path_name));
	if (!db.is_open()) db.open_db(db_name);
	db.create_table(path_name);
}


tlog::TimeLogger::TimeLogger(const std::string& path_name, bool& is_open)
	:start_(std::chrono::high_resolution_clock::now()),
	cur_name(path_name)
{
	is_open = open_file(csv(path_name));
	if (!db.is_open()) db.open_db(db_name);
	db.create_table(path_name);
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
	if (!db_mode && fin.is_open()) {
		if (fin << duration) { fin << ";"; }
		if (fin << size_) { fin << ";"; }
		if (fin << type_) { fin << ";"; }
		fin << "\n";
	}
	db.insert(cur_name, duration, size_, type_);
	start_ += std::chrono::high_resolution_clock::now() - stop_;
}
void tlog::TimeLogger::log_duration(int size_, const std::string& type_, const std::string& message_) {
	auto stop_ = std::chrono::high_resolution_clock::now();
	size_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_ - start_).count();
	if (!db_mode && fin.is_open()) {
		if (fin << duration) { fin << ";"; }
		if (fin << size_) { fin << ";"; }
		if (fin << type_) { fin << ";"; }
		if (fin << message_) { fin << ";"; }
		fin << "\n";
	}
	db.insert(cur_name, duration, size_, type_, message_);
	start_ += std::chrono::high_resolution_clock::now() - stop_;
}

void tlog::TimeLogger::clear_info() {
	int stat_files = 0;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::find_name).c_str())) ? 0 : 1;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::sort_name).c_str())) ? 0 : 1;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::popF_name).c_str())) ? 0 : 1;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::popB_name).c_str())) ? 0 : 1;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::pushF_name).c_str())) ? 0 : 1;
	stat_files += (std::remove(tlog::TimeLogger::csv(tlog::TimeLogger::pushB_name).c_str())) ? 0 : 1;
	std::cout << "Removed " << stat_files << " statistics files\n";
	db.clear_table(tlog::TimeLogger::find_name);
	db.clear_table(tlog::TimeLogger::sort_name);
	db.clear_table(tlog::TimeLogger::popF_name);
	db.clear_table(tlog::TimeLogger::popB_name);
	db.clear_table(tlog::TimeLogger::pushF_name);
	db.clear_table(tlog::TimeLogger::pushB_name);
	std::cout << "DataBase: " << db_name << " truncated tables\n";
}