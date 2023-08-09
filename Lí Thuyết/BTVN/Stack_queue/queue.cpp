#include "queue.h"
#include<iostream>
using namespace std;

//khởi tạo 1 queue rỗng
queue::queue()
{
	Tail = Head = nullptr;
}

//khởi tạo queue với 1 node có data là tham số truyền vào
queue::queue(int data)
{
	Head = Tail = new Node(data);
}

//hủy queue: xóa toàn bộ node của queue
queue::~queue()
{
	if (!Head)
		return;
	Node* cur1 = Head;
	Head = Head->getter_pNext();
	while (Head)
	{
		delete cur1;
		cur1 = Head;
		Head = Head->getter_pNext();
	}
	Head = Tail = nullptr;
}

//hàm setter và getter cho thuộc tính Head
void queue::setter_Head(Node* Head_init)
{
	Head = Head_init;
}
Node* queue::getter_Head()
{
	return Head;
}

//Hàm setter và getter cho thuộc tính Tail
void queue::setter_Tail(Node* Tail_init)
{
	Tail = Tail_init;
}
Node* queue::getter_Tail()
{
	return Tail;
}

//Hàm in ra cả hàng đợi 
void queue::Display()
{
	if (isEmpty()) {
		cout << "This is an empty queue." << endl;
		return;
	}

	cout << "Queue: ";
	Node* cur = Head;
	while (cur)
	{
		cout << cur->getter_data() << ' ';
		cur = cur->getter_pNext();
	}
	cout << endl;
}

//thêm 1 số vào cuối hàng đợi 
void queue::enqueue(int x)
{
	Node* newNode = new Node(x);

	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = newNode;
		return;
	}
	Tail->setter_pNext(newNode);
	Tail = newNode;
}

//xóa 1 node ở đầu hàng đợi 
void queue::dequeue()
{
	if (isEmpty())
	{
		cout << "Empty Queue." << endl;
		return;
	}
	if (Head == Tail && Head != nullptr)
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	Node* dequeueNode = Head;
	Head = Head->getter_pNext();
	dequeueNode->setter_pNext(nullptr);
	delete dequeueNode;
}

//lấy giá trị đầu của hàng đợi
int queue::getHead()
{
	return Head->getter_data();
}

//lấy kích thước của hàng đợi 
int queue::getSize()
{
	int count = 0;
	Node* cur = Head;
	while (cur)
	{
		count++;
		cur = cur->getter_pNext();
	}
	return count;
}

//kiểm tra hàng đợi có rỗng hay không
bool queue::isEmpty()
{
	return Head == nullptr && Tail == nullptr;
}