#include <iostream>
#include"stack.h"
#include"queue.h"
using namespace std;




int main()
{

	//Mở comment để xem kết quả test Stack
	stack test1;
	test1.push(8);

	cout << "size of this stack: " << test1.getSize() << endl;

	test1.Display();
	test1.pop();

	cout << "after once pop: " << endl;
	cout << '\t';
	test1.Display();


	test1.push(8);
	test1.push(7);
	test1.push(6);
	test1.push(5);
	test1.push(4);
	test1.push(3);

	cout << "size of this stack after push some elements: " << test1.getSize() << endl << '\t';
	test1.Display();

	test1.pop();
	cout << "size of this stack after once pop: " << test1.getSize() << endl << '\t';
	test1.Display();
	cout << "top of this stack: " << test1.getTop() << endl;
	if (test1.isEmpty())
		cout << "this is an empty stack." << endl;
	else
		cout << "this stack is not empty." << endl;

	//Queue
	/*queue test2(10);

	cout << "Size of this queue: " << test2.getSize() << endl;
	test2.Display();
	test2.dequeue();

	cout << "After once dequeue: " << endl;
	cout << '\t';
	test2.Display();


	test2.enqueue(8);
	test2.enqueue(7);
	test2.enqueue(6);
	test2.enqueue(5);
	test2.enqueue(4);
	test2.enqueue(3);
	test2.enqueue(2);

	cout << "Size of this queue after enqueue some elements: " << test2.getSize() << endl << '\t';
	test2.Display();


	test2.dequeue();
	cout << "Size of this queue after once dequeue: " << test2.getSize() << endl << '\t';
	test2.Display();



	cout << "Head of this queue: " << test2.getHead() << endl;
	if (test2.isEmpty())
		cout << "This is an empty queue." << endl;
	else
		cout << "This queue is not empty." << endl; */


	return 0;
}



