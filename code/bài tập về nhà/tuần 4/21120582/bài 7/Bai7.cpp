#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<sstream>
#include<iomanip>
#include"ThienThach.h"
using namespace std;

vector<ThienThach> docfile()
{
    vector<ThienThach>result;
    string buffer;
    freopen("INPUT7.txt", "rt", stdin);
    while (!cin.eof())
    {
        string line;
        getline(cin, line);
        stringstream infor(line);


        getline(infor, buffer, ' ');
        string Matt = buffer;



        Point toadott;
        getline(infor, buffer, '(');
        getline(infor, buffer, ',');
        toadott.setX(stof(buffer));

        getline(infor, buffer, ' ');
        getline(infor, buffer, ')');
        toadott.setY(stof(buffer));

        getline(infor, buffer, ' ');
        getline(infor, buffer, ' ');
        double banKinhtt = stof(buffer);

        getline(infor, buffer);
        double vantoctt = stof(buffer);
        ThienThach temp(Matt,toadott,banKinhtt,vantoctt);   
        result.push_back(temp);

    }
    return result;
}


double tgMin(vector<ThienThach> list)
{
    double min = list[0].tg_chamDat();
    for (auto x : list)
    {
        if (x.tg_chamDat() < min)
            min = x.tg_chamDat();
    }
    return min;
}

void GhiFile(vector<ThienThach> source, double tg)
{
    freopen("OUTPUT7.txt", "wt", stdout);
    cout << "THIEN THACH DAU TIEN VA CHAM VAO TRAI DAT:" << endl;
    cout << "\t- Voi thoi gian: " << setprecision(3) << tg << endl;
    for (auto x : source)
    {
        cout << x.getMa() << " (" << x.getToaDo().getX() << ", " << x.getToaDo().getY() << ") ";
        cout << x.getbanKinh() << ' ' << x.getvantoc() << endl;
    }
}

int main()
{
    vector<ThienThach> test1 = docfile();
    double tgChamDatMin = tgMin(test1);
    cout << tgChamDatMin << endl;


    vector<ThienThach> xuat;
    for (auto x : test1)
    {
        //do dùng kiểu dữ liệu double có độ sai số nhất định nên sẽ có độ lệch chuẩn 
        //nên so sánh xấp xỉ
        if (x.tg_chamDat() - tgChamDatMin < 1e-10)
            xuat.push_back(x);
    }

    cout << xuat.size();

    GhiFile(xuat, tgChamDatMin);
    return 1;
    
}

