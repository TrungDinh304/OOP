#include "List.h"

List::List()
{
	Head = NULL;
	count = 0;
}

List::~List()
{
	Node* temp = Head;
	while (Head)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}

Node* List::makeNode(const string& value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void List::insert(int pos, const string& val)
{
	Node* ins_node = makeNode(val);
	if (pos == 0)
	{
		ins_node->next = Head;
		Head = ins_node;
		count++;
		return;
	}
	Node* front_Of_pos = Head;
	for (int i = 0; i < count; i++)
	{
		if (i == pos - 1)
			break;
		front_Of_pos = front_Of_pos->next;
	}

	ins_node->next = front_Of_pos->next;
	front_Of_pos->next = ins_node;
	count++;
}

void List::erase(int pos)
{
	if (count == 0 || !Head)
	{
		cout << "****Empty****" << endl;
		return;
	}
	if (pos > count - 1)
	{
		cout << "Invalid input value." << endl;
		return;
	}
	if (pos == 0)
	{
		Node* remove = Head;
		Head = Head->next;
		delete remove;
		count--;
		return;
	}
	Node* front = Head;
	for (int i = 0; i < count; i++)
	{
		if (i == pos - 1)
			break;
		front = front->next;
	}
	Node* remove = front->next;
	front->next = remove->next;
	count--;
	delete remove;
}

string List::get(int pos)const
{
	if (pos > count - 1)
	{
		cout << "Invalid input value." << endl;
		return "";
	}
	Node* cur = Head;
	for (int i = 0; i < count; i++)
	{
		if (i == pos )
			break;
		cur = cur->next;
	}
	return cur->data;
}

void List::print()const
{
	if (count == 0 || !Head)
	{
		cout << "****Empty****" << endl;
		return;
	}
	Node* cur = Head;
	cout << "-List-" << endl;
	while (cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
	cout << "-end-"<<endl;
}

int List::size()const
{
	return count;
}

