#include "Stack.h"

//constructor
Stack::Stack()
{
	head = NULL;
}
//pushes value onto Stack and reassigns head of Stack to latest
//value put on
void Stack::push(float number)
{
	Node *temp = new Node;
	temp->num = number;
	temp->next = head;
	head = temp;
}

//pops number off Stack and returns value, making the head of the list
//equal to the next value, error checks for empty head value
float Stack::pop()
{
	float number = 0;
	if (head != NULL)
    {
		number = head->num;
		head = head->next;
    }
	else
		return 0;
	return number;
}

//prints the value of num in the first node of the linked list
//referred to as the head
void Stack::printHead(){
	head->print();
	cout << endl;
}
//void Stack::print()
//{
//	Node* temp = head;
//	while(temp->next != NULL){
//		cout << temp->num << " ";
//		temp = temp->next;
//	}
//	cout << temp->num << endl;
//}
