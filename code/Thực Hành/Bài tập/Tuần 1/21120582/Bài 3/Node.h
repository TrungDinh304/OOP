#pragma once
#include"SinhVien.h"
class Node {
public:
	SinhVien data;
	Node* pnext;
	Node();
	Node(const SinhVien&);
	Node& operator=(const Node&);
};