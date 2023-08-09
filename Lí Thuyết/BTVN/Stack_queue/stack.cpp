#include "stack.h"
#include<iostream>
using namespace std;

//khởi tạo stack rỗng
stack::stack()
{
	top = nullptr;
}

//khởi tạo stack với 1 node có data là tham số truyền vào
stack::stack(int init_data)
{
	top = new Node(init_data);
}

//hủy stack: xóa toàn bộ các node của stack
stack::~stack() {
	if (!top)
		return;
	Node* cur1 = top;
	Node* cur2 = cur1->getter_pNext();

	while (!cur2)
	{
		delete cur1;
		cur1 = cur2;
		if (!cur2)
			break;
		cur2 = cur2->getter_pNext();
	}
	top = nullptr;
}

//hàm getter và setter của top
Node* stack::getter_top()
{
	return top;
}
void stack::setter_top(Node* top_set)
{
	top = top_set;
}

//in ra toàn bộ Stack
void stack::Display()
{
	if (this->isEmpty()) {
		cout << "This is an empty stack." << endl;
		return;
	}
	
	cout << "Stack: ";
	Node* cur = top;
	while (cur)
	{
		cout << cur->getter_data() << ' ';
		cur = cur->getter_pNext();
	}
	cout << endl;
}

//thêm 1 phần tử vào đầu stack
void stack::push(int x)
{
	Node* newtop = new Node(x);

	newtop->setter_pNext(top);
	top = newtop;
}

//xóa 1 phần tử ở đầu stack
void stack::pop()
{
	if (isEmpty())
	{
		//cout << "This stack is currently empty." << endl;
		return;
	}

	Node* popNode = top;

	top = top->getter_pNext();
	popNode->setter_pNext(nullptr);
	delete popNode;
	/*popNode->deleteNode();*/
}

//lấy giá trị phần tử ở đầu của stack 
int stack::getTop()
{
	return top->getter_data();
}

//kiểm tra stack rỗng
bool stack::isEmpty()
{
	return !top;
}

//lấy kích thước của stack
int stack::getSize()
{
	int countElements = 0;
	Node* cur = top;
	while (cur)
	{
		countElements++;

		cur = cur->getter_pNext();
	}
	return countElements;
}

