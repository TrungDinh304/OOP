#include "Node.h"
Node::Node()
{
	SinhVien a;
	data = a;
	pnext = NULL;
}

Node::Node(const SinhVien& init)
{
	data = init;
	pnext = NULL;
}
Node& Node::operator=(const Node& other)
{
	data = other.data;
	pnext = other.pnext;
	return *this;
}