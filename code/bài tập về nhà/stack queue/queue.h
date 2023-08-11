#pragma once
#include"Node.h"

class queue
{
private:
	Node* Head;
	Node* Tail;
public:
	queue();
	queue(int);
	~queue();
	void setter_Head(Node*);
	Node* getter_Head();
	void setter_Tail(Node*);
	Node* getter_Tail();
	void Display();
	void enqueue(int);
	void dequeue();
	int getHead();
	int getSize();
	bool isEmpty();
};

