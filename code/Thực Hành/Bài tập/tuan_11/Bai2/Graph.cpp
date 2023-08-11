#include "Graph.h"

Graph::Graph()
{
}

Graph::Graph(vector<vector<int>> list)
{
	aj_list = list;
}

Graph::Graph(const Graph& s)
{
	aj_list = s.aj_list;
}

Graph::~Graph()
{
}

void Graph::readFile(char* filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Loi mo file.!!!\n";
		return;
	}

	string t;
	getline(fin, t);
	int n = 0;
	n = stoi(t);
	for (int i = 0; i < n; i++)
	{
		string buffer;
		getline(fin, buffer);
		aj_list.push_back(Listline(buffer));
	}
}

void Graph::print_list()
{

	cout << "\nList with " << aj_list.size() << "  vertices." << endl;
	int count = 0;
	for (auto x : aj_list)
	{
		cout << "[" << count++ << "]: ";
		for (auto y : x)
		{
			cout << y << ' ';
		}
		cout << endl;
	}

}

void Graph::BFS(int Start)
{
	int n = aj_list.size();
	bool* visited = new bool[n] {0};

	cout << "[" << Start << "] ";
	visited[Start] = 1;

	queue<int> travel;
	travel.push(Start);
	while(!travel.empty())
	{
		int current_vertice = travel.front();
		travel.pop();
		for (auto x : aj_list[current_vertice])
		{
			if (visited[x] == 0)
			{
				travel.push(x);
				visited[x] = 1;
				cout << "[" << x << "] ";
			}
		}
	}
	cout << endl;
	delete[]visited;
}

void Graph::print_DFS(int start)
{
	bool* visitted = new bool[aj_list.size()] {0};
	DFS(start, visitted);
	cout << endl;
	delete[]visitted;
}

void Graph::DFS(int start, bool* visitted)
{
	visitted[start] = 1;
	cout << "[" << start << "] ";
	for (auto x : aj_list[start])
	{
		if (visitted[x] == 0)
		{
			DFS(x, visitted);
		}
	}
}



