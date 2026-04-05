// intlist.cpp
// Implements class IntList
// Shaolun Han April.4th

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if (source.head == nullptr) {
    	head = nullptr;
	tail = nullptr;
	return;
    }
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    Node* thisNode = head;
    Node* copyNode = source.head->next;
    while (copyNode != nullptr) {
    	Node* newNode = new Node;
	newNode->info = copyNode->info;
	newNode->next = nullptr;
	thisNode->next = newNode;
	thisNode = newNode;
	copyNode = copyNode->next;
    }
    tail = thisNode;
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* thisNode = head;
    while (thisNode != nullptr) {
    	Node* temp = thisNode->next;
	delete thisNode;
	thisNode = temp;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node* sumNode = head;
    int sum = 0;
    while (sumNode != nullptr) {
    	sum += sumNode->info;
	sumNode = sumNode->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* containNode = head;
    while (containNode != nullptr) {
    	if (containNode->info == value) return true;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) return 0;
    Node* maxNode = head->next;
    int max = head->info;
    while (maxNode != nullptr) {
    	if (max > maxNode->info) max = maxNode->info;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double average = static_cast<double>(sum()) / count();
    return average;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* temp = new Node;
    temp->info = value;
    temp->next = head;
    head = temp;
    if (tail == nullptr) {
    	tail = temp;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* temp = new Node;
    temp->info = value;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// return count of values
int IntList::count() const {
    Node* countNode = head;
    int count = 0;
    while (countNode != nullptr) {
	count++;
	countNode = countNode->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = tail = nullptr;
    Node* srcNode = source.head;
    while (srcNode != nullptr) {
        push_back(srcNode->info);
        srcNode = srcNode->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
