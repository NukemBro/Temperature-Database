#ifndef NODE
#define NODE

struct Node {
	
	// Data fields
	Node* next;
	int location;
	int year;
	int month; 
	double temperature;

	// Default constructor
	Node() : next(nullptr) {
		location = 0;
		year = 0;
		month = 0;
		temperature = 0.0;
	}
	// This constructor creates a new node with all of our weather info
	Node(int location, int year, int month, double temperature) : next(nullptr) {
		this->location = location;
		this->year = year;
		this->month = month;
		this->temperature = temperature;
	}

	virtual ~Node() {}
};

#endif
