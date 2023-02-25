#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/thread/mutex.hpp>
#include "sqlite3.h"


namespace sqll {

	struct LogTable {
		int id;
		long long duration;
		long size;
		std::string	type;
		std::string message;
	};

	class SQLdb {
	private:
		std::string DBname;
		bool db_is_open = 0;
		std::vector<std::string> tables;

		sqlite3* db = nullptr;
		char* zErrMsg = 0;

		int check(int result);
		static int callback(void* data, int argc, char** argv, char** azColName);

	public:
		SQLdb();
		bool is_open();
		std::string get_DBname();
		std::vector<std::string> get_tables();

		bool open_db(const std::string& db_name);
		void close_db();

		bool create_table(const std::string& table_name);

		bool insert(const std::string& table_name, size_t duration, int size_, const std::string& type_);
		bool insert(const std::string& table_name, size_t duration, int size_, const std::string& type_, const std::string& message_);
		bool select(const std::string& table_name, std::vector<LogTable>& result_);
		bool clear_table(const std::string& table_name);

		~SQLdb();
	};
}