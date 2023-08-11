#pragma once
#include<vector>
#include<queue>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Graph
{
private:
	vector<vector<int>> aj_list;
	vector<int> Listline(string line)
	{
		vector<int>a;
		if (line.empty()) return a;

		stringstream S(line);
		while (!S.eof())
		{
			string buffer;
			getline(S, buffer, ' ');
			a.push_back(stoi(buffer));
		}
		return a;
	}
	void DFS(int start, bool* visitted);// in ra thứ tự duyệt của từng node theo thuật toán DFS
public:
	Graph();
	Graph(vector<vector<int>> list);
	Graph(const Graph& s);
	~Graph();

	void readFile(char* filename);
	void print_list();


	void BFS(int Start);// in ra thứ tự duyệt của từng node theo thuật toán BFS
	void print_DFS(int start);

};

