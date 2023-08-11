//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int main() {
//    system("cls");
//
//    //Đọc file
//    freopen("in.txt", "r", stdin);
//    int a, b;
//    cin >> a >> b;
//
//    //Ghi file
//    freopen("out.txt", "w", stdout);
//    cout << b << " " << a;
//
//    //Chuyển stream cin về console (chịu, dòng dưới không đúng)
//    freopen("CON", "r", stdin);
//    int c = 0, d = 0;
//    cin >> c >> d;
//
//    //Chuyển stream cout về console
//    freopen("CON", "w", stdout);
//    cout << c << " " << d << endl;
//
//    cout << "end of program" << endl;
//    return 0;
//}
#include<iostream>
#include<cstring>
using namespace std;



//class base {
//private:
//	char* m_ptr;
//public:
//	base() { m_ptr = _strdup("default"); }
//	base(const base& b) { m_ptr = _strdup("copy"); }
//	virtual void foo() { cout << m_ptr << endl; }
//};
//
//class derive : public base {
//public:
//	void foo()
//	{
//		cout << "derive" << endl;
//		base::foo();
//	}
//};
//void bar(base* obj1, base obj2)
//{
//	obj1->foo();
//	obj2.foo();
//}
//
//int main()
//{
//	derive d;
//	bar(&d, d);
//	return 1;
//}



class fibo {
private:
	int n;
	int* elements;
public:
	fibo(int init_sz)
	{
		if (init_sz < 2)
			return;
		n = init_sz;
		elements = new int[n];
		elements[0] = 0;
		elements[1] = 1;
		for (int i = 2; i < n; i++)
		{
			elements[i] = elements[i - 1] + elements[i - 2];
		}

	}
	friend ostream& operator<<(ostream& out, const fibo& xuat)
	{
		for (int i = 0; i < xuat.n; i++)
		{
			out << "F[" << i << "]: " << xuat.elements[i] << endl;
		}
		return out;
	}
	~fibo()
	{
		delete[]elements;
	}

};



int main()
{
	fibo a(30);
	cout << a;
	return 1;
}