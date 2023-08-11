#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int speed = 0;
    while (true)
    {
        char a = _getch();
        try
        {
            if (speed >= 20)
                throw(speed);
        
            if (int(a) == 72)
            {
                speed++;
                cout << "Speed: " << speed << " km/h" << endl;

            }
            else if (int(a) == 80)
            {
                speed--;
                if (speed < 0)
                    continue;
                cout << "Speed: " << speed << " km/h" << endl;
            }
            else if (speed < 0)
                throw(speed);
        }
        catch (...)
        {
            if (speed < 0)
            {
                cout << "toc do khong the am." << endl;
                speed = 1;
            }
            else
            {
                cout << "OVERSPEED" << endl;

                while (speed > 0)
                {
                    speed--;
                    cout << "Speed: " << speed << " km/h" << endl;
                }
            }
        }
    }
    


    return 0;
}