// Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Graph.h"

int main()
{
    Graph a;
    char filename[] = "aj_list.txt";
    a.readFile(filename);
    a.print_list();
    cout << "BFS: ";
    a.BFS(0);
    cout << "DFS: ";
    a.print_DFS(0);
    return 1;
}

