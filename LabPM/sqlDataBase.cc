#include "sqlDataBase.h"

int sqll::SQLdb::callback(void* data, int argc, char** argv, char** azColName) {
	if (argc) {
		std::vector<LogTable> &res = *((std::vector<LogTable>*)data);
		LogTable el;
		std::string expression, colName;
		for (int i = 0; i < argc; ++i) {
			expression = argv[i] ? argv[i] : "NULL";
			colName = azColName[i];
			if (colName == "id" && expression != "NULL") { el.id = atoi(expression.c_str()); }
			if (colName == "duration" && expression != "NULL") { el.duration = atoll(expression.c_str()); }
			if (colName == "size" && expression != "NULL") { el.size = atol(expression.c_str()); }
			if (colName == "type_" && expression != "NULL") { el.type = expression; }
			if (colName == "message_" && expression != "NULL") { el.message = expression; }
		}
		res.push_back(el);
	}
	return 0;
}

sqll::SQLdb::SQLdb() {

}

std::string sqll::SQLdb::get_DBname() {
	return DBname;
}
std::vector<std::string> sqll::SQLdb::get_tables() {
	return tables;
}

bool sqll::SQLdb::is_open() {
	return db_is_open;
}

bool sqll::SQLdb::open_db(const std::string& db_name) {
	if (sqlite3_open(db_name.c_str(), &db)) {
		std::cout << "Unable to open file: " << db_name << "\n";
		return 1;
	}
	else {
		DBname = db_name;
		db_is_open = 1;
		return 0;
	}
}
void sqll::SQLdb::close_db() {
	sqlite3_close(db);
	db_is_open = 0;
}

int sqll::SQLdb::check( int result) {
	if (result != SQLITE_OK) {
		std::cout << stderr << " SQL error: " << zErrMsg << "\n";
		sqlite3_free(zErrMsg);
	}
	return result;
}

bool sqll::SQLdb::create_table(const std::string& table_name) {
	std::string sql_request = "\
		CREATE TABLE IF NOT EXISTS " + table_name + "(\
		id INTEGER PRIMARY KEY AUTOINCREMENT,\
		duration BIGINT NOT NULL,\
		size INT NOT NULL,\
		type_ VARCHAR(30) NOT NULL,\
		message_ VARCHAR(30)\
		);";
	int res = 0;
	if (res = sqlite3_exec(db, sql_request.c_str(), callback, 0, &zErrMsg)) {
		return 1;
	}
	if (zErrMsg != "database is locked") check(res);
	//std::cout << "Table: " << table_name << " created successfully\n";
	tables.push_back(table_name);
	return 0;
}

bool sqll::SQLdb::insert(const std::string& table_name, size_t duration, int size_, const std::string& type_) {
	std::string sql_request =
		"INSERT INTO " + table_name + "(duration, size, type_) "\
		"VALUES(" + std::to_string(duration) +"," + std::to_string(size_) + ",'" + type_ + "');";

	int deep = 0, res = 0;
	while (deep++ < 10000 && 5 == (res = sqlite3_exec(db, sql_request.c_str(), callback, 0, &zErrMsg)) == 5) {
		boost::posix_time::time_duration interval(boost::posix_time::milliseconds(rand() % 1000 + 10));
		auto delay(interval);
	}
	check(res);
	//std::cout << "Success insert in table: " << table_name << "\n";
	return 0;
}

bool sqll::SQLdb::insert(const std::string& table_name, size_t duration, int size_, const std::string& type_, const std::string& message_) {
	std::string sql_request =
		"INSERT INTO " + table_name + "(duration, size, type_, message_)"\
		"VALUES(" + std::to_string(duration) + "," + std::to_string(size_) + ",'" + type_ + "','" + message_ + "');";

	int deep = 0, res = 0;
	while (deep++ < 10000 && 5 == (res = sqlite3_exec(db, sql_request.c_str(), callback, 0, &zErrMsg))) {
		boost::posix_time::time_duration interval(boost::posix_time::milliseconds(rand() % 1000 + 10));
		auto delay(interval);
	}
	check(res);
	//std::cout << "Success insert in table: " << table_name << "\n";
	return 0;
}

bool sqll::SQLdb::select(const std::string& table_name, std::vector<LogTable>& result_) {
	const char* data = "Callback function called";
	std::string sql_request = "SELECT * FROM " + table_name + ";";

	result_.clear();
	if (check(sqlite3_exec(db, sql_request.c_str(), callback, (void*)&result_, &zErrMsg))) {
		return 1;
	}

	std::cout << "Success select in table: " << table_name << "\n";
	return 0;
}
bool sqll::SQLdb::clear_table(const std::string& table_name) {
	std::string sql_request = "DELETE FROM " + table_name + ";";

	if (check(sqlite3_exec(db, sql_request.c_str(), callback, 0, &zErrMsg))) {
		return 1;
	}
	std::cout << "Success truncate table: " << table_name << "\n";
	return 0;
}

sqll::SQLdb::~SQLdb() {
	if (db_is_open) close_db();
}
