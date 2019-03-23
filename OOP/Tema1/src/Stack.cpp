#include "Stack.h"
#include "Node.h"
#include <string.h>
#include <fstream>

void Stack::Push(const char* string)
{
	if (!string) return;

	Node* newNode = new Node(string, top);
	top = newNode;
}

void Stack::Pop()
{
	if (!top) return;

	Node* temp = top->getPrevious();
	delete top;
	top = temp;
}

const char* Stack::Top()
{
	return top->getString();
}

void Stack::Reverse()
{
	Node* temp = top;
	Node* next = nullptr;
	Node* previous = nullptr;

	while (temp)
	{
		previous = temp->getPrevious();   // elementul din dreapta lui temp
        temp->setPrevious(next);
		next = temp;                    // elementul din stanga lui temp ajunge temp
		temp = previous;                // se modifica temp spre dreapta
	}

	top = next;
}

void Stack::operator-(Stack& stack)
{
	Stack tempStack = stack;
	while (strcmp(tempStack.Top(), this->Top()) == 0)
	{
		tempStack.Pop();
		this->Pop();
	}
}

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
}

Stack::Stack(const Stack& stackCopy)
{
    top = nullptr;
	Node* temp = stackCopy.top;
	while (temp)
	{
		this->Push(temp->getString());
		temp = temp->getPrevious();
	}
	this->Reverse();
}

ostream& operator<<(ostream& out, const Stack& stack)
{
	Node* temp = stack.top;

	while (temp != nullptr)
	{
		out << temp->getString() << endl;
		temp = temp->getPrevious();
	}

	return out;
}

istream& operator>>(istream& in, Stack& stack)
{
    ifstream *fileStream = dynamic_cast<std::ifstream*>(&in);   // convert din ifstream in istream
    const bool isConsole = fileStream == nullptr;

	char string[255];
	if(isConsole) {
        in.get(); // Golim buffer-ul
    }
	while (true)
	{

		in.getline(string, 255);        // citeste un element pana la endl
		if (strlen(string) <= 0) break;  // conditia de oprire
		stack.Push(string);
	}

	return in;
}
