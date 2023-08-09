#pragma once
#include"Node.h"
class stack {
private:
	Node* top;
public:
	stack();
	stack(int);
	~stack();
	Node* getter_top();
	void setter_top(Node*);
	void Display();
	void push(int x);
	void pop();
	int getTop();
	bool isEmpty();
	int getSize();
};


