#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack
{
private:
	class Node* top;
public:
	void Push(const char* string);
	void Pop();
	const char* Top();
	void Reverse();
	void operator - (Stack& stack);
	friend ostream& operator <<(ostream& out, const Stack& stack);
	friend istream& operator >>(istream& in, Stack& stack);
	Stack();
	~Stack();
	Stack(const Stack& stackCopy);
};

#endif // STACK_H
