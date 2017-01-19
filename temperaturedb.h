#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "linkedlist.h"
#include "node.h"

class TemperatureDatabase {
public:
	// Default constructor/destructor
	TemperatureDatabase() {}
	~TemperatureDatabase() {}

	// Reads in the temperature data from the data files
	void loadData(const std::string& data_file);

	// performs indicated queries
	void performQuery(const std::string& query_filename);

private:
	LinkedList records;
};

#endif
