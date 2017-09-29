#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//This struct holds a numerical value and a pointer to the next value
//Also implementing a function that prints the value of num
//This struct is later used as nodes for a linked list of values
struct Node
{
	float num;
	Node *next;

	void print(){
		cout << num;
	}
};

#endif /* HEADER_H_ */
