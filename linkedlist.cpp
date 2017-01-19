#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	clear();
	cout << "LinkedList is cleared" << endl;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	if (this != &source) {
		this->clear();
		Node* temp = source.head;
		while (temp != nullptr) {
			insert(temp->location, temp->year, temp->month, temp->temperature);
			temp = temp->next;
		}
	}
	return *this;
}

LinkedList::LinkedList(const LinkedList& source) {
	this->head = 0;               
	Node* sourceHead = source.head;
	while (sourceHead != nullptr)
	{
		this->insert(sourceHead->location, sourceHead->year, sourceHead->month, sourceHead->temperature);
		sourceHead = sourceHead->next;
	}
}

// inserts a new node into the list (sorts by location, year, month, and temperature)
void LinkedList::insert(int location, int year, int month, double temperature) {
	Node* newNode = new Node(location, year, month, temperature);
	Node* current;
	// case for the head end 
	if (head == nullptr || head->location >= newNode->location)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		current = head;
		while (current->next != nullptr && current->next->location < newNode->location) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void LinkedList::clear() {
	Node* current = head;
	while (current != nullptr) {
		Node* deleteNode = current;
		current = current->next;
		delete deleteNode;
	}
	head = tail = nullptr;
}

// Computes the average of a range of years given the location ID
double LinkedList::computeAvg(int location, int lowerYear, int upperYear) {
	Node* current;
	double totalTemp = 0.0;
	current = head;
	// if LinkedList is initially empty, throw exception
	if (head != nullptr) {
		//transverses through the linked list
		while (current != nullptr) {
			// checks if current node matches our requested location ID
			if (current->location == location) {
				// checks if current node is in our requested year range
				if (current->year >= lowerYear && current->year <= upperYear) {
					totalTemp += current->temperature;
				}
			}
			// update condition
			current = current->next;
		}
		// returns average by taking total temperature readings for 
		// the requested year range and dividing by number of years
		return (totalTemp / (upperYear - lowerYear));
	}
	else {
		throw runtime_error("List is empty! Cannot compute average!");
	}
}

// Computes the Mode of a range of years given the location ID
int LinkedList::computeMode(int location, int lowerYear, int upperYear) {
	Node* current;
	current = head;
	vector<int> temps;

	int counter = 1;
	int max = 0;
	int mode = 0;

	// if LinkedList is initially empty, throw exception
	if (head != nullptr) {
		//transverses through the linked list
		while (current != nullptr) {
			// checks if current node matches our requested location ID
			if (current->location == location) {
				// checks if current node is in our requested year range
				if (current->year >= lowerYear && current->year <= upperYear) {
					// inserts rounded temp into vector
					temps.push_back((int)round(current->temperature));
				}
			}
			// update condition
			current = current->next;
		}
		// sorts the vector of temperatures
		sort(temps.begin(), temps.end());
		// goes through sorted vector of temperatures and finds the mode
		for (int i = 0; i < temps.size() - 1; ++i) {
			if (temps.at(i) == temps.at(i + 1)) {
				counter++;
				if (counter > max) {
					max = counter;
					mode = temps.at(i);
				}
				else { counter = 1; }
			}
		}
		return mode;
	}
	else {
		throw runtime_error("List is empty! Cannot compute mode!");
	}
}

void LinkedList::print() const {
	print(cout);
}

void LinkedList::print(ostream& os) const {
	os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	Node* current = ll.head;
	if (current != nullptr) {
		while (current != nullptr) {
			os << current->location <<
				" " << current->year <<
				" " << current->month <<
				" " << current->temperature << 
				" " << endl;
			if (current == ll.tail) {
				os << endl;
			}
			current = current->next;
		}
	}
	else { os << "<Empty List>" << endl; }
	return os;
}
