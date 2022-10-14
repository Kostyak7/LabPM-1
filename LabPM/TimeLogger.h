#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

#include "sqlDataBase.h"

namespace tlog {
	class TimeLogger {
	private:
		sqll::SQLdb db;
		std::vector<sqll::LogTable> result;
		std::ofstream fin;
		std::string cur_name;
		std::chrono::steady_clock::time_point start_;
		//size_t duration;

		bool open_file(const std::string& path_name);
		void close_file();

	public:
		static bool db_mode;

		static std::string csv(const std::string& _name);

		static const std::string db_name;
		static const std::string find_name;
		static const std::string sort_name;
		static const std::string popF_name;
		static const std::string popB_name;
		static const std::string pushF_name;
		static const std::string pushB_name;

		TimeLogger(const std::string& path_name);
		TimeLogger(const std::string& path_name, bool& is_open);

		void reset_start();
		void log_duration(int size_, const std::string& type_);
		void log_duration(int size_, const std::string& type_, const std::string& message_);

		void clear_info();
		~TimeLogger();
	};
}