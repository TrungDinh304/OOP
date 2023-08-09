#pragma once
class Node {
private:
	int data;
	Node* pNext;
public:
	Node();
	Node(int);
	~Node();
	void setter_data(int);
	int getter_data();
	void setter_pNext(Node*);
	Node* getter_pNext();
};


