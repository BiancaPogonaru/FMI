#include <string.h>
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(const char* string, Node* previous)
{
	this->string = new char[strlen(string) + 1];
	strcpy(this->string, string);
	this->previous = previous;
}

Node::~Node()
{
	this->previous = nullptr;
	delete[] this->string;
}

void Node::setString(const char* string)
{
	if (this->string)
	{
		delete[] this->string;
	}

	this->string = new char[strlen(string) + 1];
	strcpy(this->string, string);
}
