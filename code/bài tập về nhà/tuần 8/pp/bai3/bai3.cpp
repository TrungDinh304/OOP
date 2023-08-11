#include <iostream>
using namespace std;

class atm
{
private:
    int amount;
    int to500;
    int to200;
    int to100;
    int to50;
    bool khongdu(int);
public:
    atm();
    void rut();
};

atm::atm()
{
    amount = 10100000;
    to500 = 10;
    to200 = 20;
    to100 = 10;
    to50 = 2;
}

bool atm::khongdu(int menhgia)
{
    if (menhgia == 200000)
    {
        if (to50 * 50000 + to100 * 100000 + 200000 * to200 < 200000)
            return 1;
        else
            return 0;
    }
    else if (menhgia == 500000)
    {
        if (to500 > 0)
            return 0;
        if (to50 * 50000 + to100 * 100000 >= 500000)
            return 0;
        if (to200 >= 2 && to50 * 50000 + to100 * 100000 >= 100000)
            return 0;
        if (to200 >= 1 && to50 * 50000 + to100 * 100000 >= 300000)
            return 0;
        return 1;
    }
}

void atm::rut()
{
    int amt = 0;
    cout << "Nhap so tien muon rut: ";
    cin >> amt;

    try
    {
        if (amt > amount)
            throw "Xin loi! khong the doi tien le voi menh gia do ATM khong du tien.";
        if (amt < 0)
            throw "Xin loi! khong the doi so tien am.";
        if (amt % 50000 != 0)
            throw "Xin loi! khong the doi tien le voi menh gia ";
        int to500r = 0;
        int to200r = 0;
        int to100r = 0;
        int to50r = 0;
        try
        {
            if (to50 == 0 || to100 == 0 || to200 == 0 || to500 == 0)
                throw "Xin loi! khong the doi tien le voi menh gia ";
            if (amt < 50000 + 100000 + 200000 + 500000)
                throw(amt);
            if (amt % 50000 != 0)
                throw "Xin loi! khong the doi tien le voi menh gia ";
            to500r = 1; to500--;
            to100r = 1; to100--;
            to200r = 1; to200--;
            to50r = 1; to50--;
            amt -= 50000 + 100000 + 200000 + 500000;
            while (amt > 0)
            {
                if (amt <= 50000 && to50 <= 0)
                    throw "Xin loi! khong the doi tien le voi menh gia ";
                else if (amt <= 100000 && to100 <= 0 && to50 < 2)
                    throw "Xin loi! khong the doi tien le voi menh gia ";
                else if (amt <= 200000 && khongdu(200000))
                    throw "Xin loi! khong the doi tien le voi menh gia ";
                else if (amt <= 50000 && khongdu(500000))
                    throw "Xin loi! khong the doi tien le voi menh gia ";

                while (amt - 500000 >= 0 && to500)
                {
                    amt -= 500000;
                    to500r++;
                    to500--;
                }
                while (amt - 200000 >= 0 && to200)
                {
                    amt -= 200000;
                    to200r++;
                    to200--;
                }
                while (amt - 100000 >= 0 && to100)
                {
                    amt -= 100000;
                    to100r++;
                    to100--;
                }
                while (amt - 50000 >= 0 && to50)
                {
                    amt -= 50000;
                    to50r++;
                    to50--;
                }
            }


            cout << "So to 500.000: " << to500r << endl;
            cout << "So to 200.000: " << to200r << endl;
            cout << "So to 100.000: " << to100r << endl;
            cout << "So to 50.000: " << to50r << endl;

        }
        catch (const char* a)
        {
            cout << a << endl;
        }



    }
    catch (const char* a)
    {
        cout << a << endl;
    }
}

int main()
{
    atm a;
    a.rut();
    a.rut();
    return 0;
}