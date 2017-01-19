#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Assignment constructor
	LinkedList& operator=(const LinkedList& other);

	// Insert a record to the linked list
	void insert(int location, int year, int month, double temperature);

	// Clear the content of this linked list
	void clear();

	// Computes the average of a range of years given the location ID
	double computeAvg(int location, int lowerYear, int UpperYear);

	// Computes the Mode of a range of years given the location ID
	int computeMode(int location, int lowerYear, int UpperYear);

	friend std::ostream& operator<<(std::ostream&, const LinkedList&);

	void print() const;
	void print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
