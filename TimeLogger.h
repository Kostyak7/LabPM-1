#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

namespace tlog {
	class TimeLogger {
	private:
		std::ofstream fin;
		std::chrono::steady_clock::time_point start_;
		//size_t duration;

		bool open_file(const std::string& path_name);
		void close_file();

	public:
		static const std::string find_FileName;
		static const std::string sort_FileName;
		static const std::string popF_FileName;
		static const std::string popB_FileName;
		static const std::string pushF_FileName;
		static const std::string pushB_FileName;

		TimeLogger(const std::string& path_name);
		TimeLogger(const std::string& path_name, bool& is_open);

		void reset_start();
		void log_duration(int size_, const std::string& type_);
		void log_duration(int size_, const std::string& type_, const std::string& message_);

		~TimeLogger();
	};
}