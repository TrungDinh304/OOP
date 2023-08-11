#include <iostream>
using namespace std;
 
int main()
{
    try
    {
       throw 10;
    }
    catch (int param)
    {
        cout << "int exceptionn";
    }
    catch (...)
    {
        cout << "default exceptionn";
    }
    
 
    return 0;
}