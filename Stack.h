#ifndef STACK_H_
#define STACK_H_

#include "header.h"

//class to hold first struct and perform operations including pop, push
//and printing the first value in the list at the head
class Stack
{
private:
	Node *head;
public:
	Stack();
	void push(float);
	float pop();
//	void print();
	void printHead();
};


#endif /* STACK_H_ */
