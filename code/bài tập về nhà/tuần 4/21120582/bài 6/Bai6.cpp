#define _CRT_SECURE_NO_WARNINGS
#include"PhieuBau.h"
#include <iostream>
#include<vector>
#include<sstream>
using namespace std;



vector<PhieuBau> ReadFile(char filename[])
{
    vector<PhieuBau> result;
    freopen(filename, "rt", stdin);
    string buffer;

    pair<Time, Time> KhungGio;
    pair<string, string> str_khunggio;
    getline(cin, str_khunggio.first, ' ');
    getline(cin, str_khunggio.second);
    KhungGio.first.str_to_time(str_khunggio.first);
    KhungGio.second.str_to_time(str_khunggio.second);

    PhieuBau temp;

    while (!cin.eof())
    {
        string line;
        getline(cin, line);
        stringstream line_inf(line);

        vector<string> buffer_line;
        while (!line_inf.eof())
        {
            string a;
            line_inf >> a;
            buffer_line.push_back(a);
        }
        //gán mã
        temp.setMa(buffer_line[0]);

        //kiểm tra hợp lệ
        Time bau;
        bau.str_to_time(buffer_line[buffer_line.size() - 1]);
        temp.Hople(KhungGio.first, KhungGio.second, bau);


        buffer = "";
        for (int i = 1; i < buffer_line.size() - 2; i++)
        {
            buffer += buffer_line[i] + " ";
        }
        buffer += buffer_line[buffer_line.size() - 2];

        //gan ten
        temp.setTen(buffer);
        result.push_back(temp);

    }
    return result;
}

int getmax(int* a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

vector<string> CS_PhieuBau_Max(vector<PhieuBau> list, int& max)
{
    vector<string> result;
    int n = list.size();
    int* SoPhieu = new int[n] {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (list[i].getTen() == list[j].getTen() && list[j].getHople())
            {
                SoPhieu[i]++;
            }
        }
    }


    max = getmax(SoPhieu, n);

    for (int i = 0; i < n-1; i++)
    {
        if (SoPhieu[i] == max)
            result.push_back(list[i].getTen());
        if (SoPhieu[i] == 0)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (list[j].getTen() == list[i].getTen())
                SoPhieu[j] = 0;
        }
    }
    return result;
}


void WriteFile(char* fileout, vector<string> Casi, int max)
{
    freopen(fileout, "wt", stdout);

    for (auto x : Casi)
    {
        cout << x << ' ' << max << endl;
    }
}

int main()
{
    char filename[] = "INPUT6.txt";
    vector<PhieuBau> doc = ReadFile(filename);
    int PhieuMax = 0;
    vector<string> top1 = CS_PhieuBau_Max(doc, PhieuMax);
    char fileout[] = "OUTPUT6.txt";
    WriteFile(fileout, top1, PhieuMax);

   

    return 0;

}
