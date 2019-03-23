#ifndef NODE_H
#define NODE_H


class Node
{
public:
	Node(const char* string = "", Node* previous = nullptr);
	~Node();
	Node* getPrevious() const { return previous; }
	char* getString() const { return string; }
	void setPrevious(Node* previous) { this->previous = previous; }
	void setString(const char* string);
	friend class Stack;

private:
	Node* previous;
	char* string;
};
#endif // NODE_H
