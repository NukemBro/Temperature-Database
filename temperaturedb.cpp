#include "temperaturedb.h"
#include "linkedlist.h"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	ifstream in_file{ filename };
	ofstream out_file{ "results.dat" };
	int pullNums;
	vector<int> data(4);
	if (in_file.is_open()) {
		while (in_file >> pullNums) {
			for (int i = 0; i < 4; ++i) {
				in_file >> data[i];
			}
			if (data[1] < 1800 || data[1] > 2016) {
				throw runtime_error("Invalid Year");
			}
			if (data[2] < 0 || data[2] > 12) {
				throw runtime_error("Invalid Month");
			}
			if (data[3] < -50.00 || data[3] > 50.00) {
				throw runtime_error("Invalid Temperature");
			}
			if (data[3] != -99.99) {
				records.insert(data[0], data[1], data[2], data[3]);
			}
		}
	}
	records.print();
	records.print(out_file);
	in_file.close();
	out_file.close();
}

void TemperatureDatabase::performQuery(const string& filename) {
	int pullNums;
	vector<int> data(3);
	string pullQueries;

	ifstream in_file{ filename };
	ofstream out_file{ "results.dat" };
	if (in_file.is_open()) {
		while (in_file >> pullNums) {
			for (int i = 0; i < 3; ++i) {
				in_file >> data[i];
			}
		}
		while (in_file >> pullQueries) {
			if (pullQueries == "AVG") {
				double average = records.computeAvg(data[1], data[2], data[3]);
			}
			else if (pullQueries == "MODE") {
				int mode = records.computeMode(data[1], data[2], data[3]);
			}
		}
		records.print();
		records.print(out_file);
		in_file.close();
		out_file.close();
	}
}