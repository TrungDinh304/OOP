#include "Node.h"

//hàm khởi tạo không có tham số đầu vào tạo ra 1 node có giá trị là 0 
Node::Node()
{
	data = 0;
	pNext = nullptr;
}

//khởi tạo 1 node với có data của node bằng giá trị tham số kiểu int truyền vào
Node::Node(int data_init)
{
	pNext = nullptr;
	data = data_init;
}

//phương thức hủy node
//do khi khởi tạo ko cấp phát nên hủy phương thức hủy không cần giải phóng vùng nhớ
Node::~Node()
{

}


//lấy giá trị thuộc tính data của 1 node
int Node::getter_data()
{
	return data;
}

//thay đổi giá trị thuộc tính data bằng với tham số truyền vào
void Node::setter_data(int set)
{
	data = set;
}

//thay đổi giá trị của thuộc tính pNext 
void Node::setter_pNext(Node* pNext_init)
{
	pNext = pNext_init;
}

//lấy giá trị thuộc tính pNext của 1 node
Node* Node::getter_pNext()
{
	if (!this)
		return nullptr;

	return pNext;
}






