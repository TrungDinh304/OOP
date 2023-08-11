//21120582: Đinh Hoàng Trung
//21120544: Lê Minh Sang
#include <iostream>
#include <string>
#include<vector>
#include<sstream>
#include <fstream>
using namespace std;



class NhanVat
{
protected:
    string maso;
    int sucmanh;
public:
    NhanVat()
    {
        maso = "";
    }
    NhanVat(string ms,int smanh)
    {
        maso = ms;
        sucmanh = smanh;
    }
    string getMaso()
    {
        return maso;
    }

    void setMaso(string ms)
    {
        maso = ms;
    }

    int getSuManh()
    {
        return sucmanh;
    }
    friend istream& operator>>(istream& in, NhanVat& a)
    {
        in >> a.maso;
        return in;
    }
    friend ostream& operator<<(ostream& out, NhanVat a)
    {
        out << a.maso;
        return out;
    }
};


class NongDan:public NhanVat
{
private:
    string phai;// Nam hoặc Nu
public:
    NongDan():NhanVat()
    {
        phai = "";
    }
    NongDan(string ms, string ph,int smanh) :NhanVat(ms,smanh)
    {
        phai = ph;
    }

    string getPhai()
    {
        return phai;
    }
    void setPhai(string ph)
    {
        phai = ph;
    }
    friend istream& operator<<(istream& in, NongDan& a)
    {
        in >> a.maso;
        in >> a.phai;
        return in;
    }

    friend ostream& operator<<(ostream& out, NongDan a)
    {
        out << a.maso << ' ';
        out << a.phai;
        return out;
    }

};


class ChienBinh :public NhanVat
{
private:
    int sucAn;//chén cơm/ngày
    string tamtrang;//vui, buồn
public:
    ChienBinh() :NhanVat()
    {
        sucAn = 0;
        tamtrang = "";
    }
    ChienBinh(string ms, int sucan, string tt, int smanh) :NhanVat(ms,smanh)
    {
        sucAn = sucan;
        tamtrang = tt;
    }

    int getSucAn()
    {
        return sucAn;
    }
    string getTamTrang()
    {
        return tamtrang;
    }
    void setSucAn(int sa)
    {
        sucAn = sa;
    }
    void setTamTrang(string tt)
    {
        tamtrang = tt;
    }
    friend istream& operator<<(istream& in, ChienBinh& a)
    {
        in >> a.maso;
        string temp;
        in >> temp;
        a.sucAn = stoi(temp);
        in >> a.tamtrang;
        return in;
    }

    friend ostream& operator<<(ostream& out, ChienBinh a)
    {
        out << a.maso << ' ';
        out << a.sucAn << ' ';
        out << a.tamtrang;
        return out;
    }
};



void read_file(string filename,int& songaychinhchien, vector<NongDan>& a, vector<ChienBinh>& b)
{
    ifstream fin;
    fin.open(filename);
    if (!fin)
    {
        cout << "Loi roi" << endl;
        return;
    }

    string line;
    getline(fin, line);
    songaychinhchien = stoi(line);
    while (!fin.eof())
    {
        vector<string> buffer;

        getline(fin, line);
        stringstream ss(line);

        while (!ss.eof())
        {
            string temp;
            ss >> temp;
            buffer.push_back(temp);
        }
        if (buffer.size() == 4)
        {
            ChienBinh init(buffer[0], stoi(buffer[1]), buffer[2],stoi(buffer[3]));
            b.push_back(init);
        }
        else if (buffer.size() == 3)
        {
            NongDan init(buffer[0], buffer[1],stoi(buffer[2]));
            a.push_back(init);
        }
    }
    fin.close();
}

void xuat(vector<NongDan>nd, vector<ChienBinh> cb,int songaychinhchien)
{
    float sochencom = 0;
    for (auto x : nd)
    {
        
        if (x.getPhai() == "Nam")
        {
            if (x.getSuManh() >= 80)
                sochencom += 10;
            else
            {
                sochencom += 8;
            }
        }
        else if (x.getPhai() == "Nu")
        {
            if (x.getSuManh() >= 70)
            {
                sochencom += 8;
            
            }
            else
            {
                sochencom += 6;
            }
        }
    }
    for (auto x : cb)
    {
       
        if (x.getSuManh() > 100)
        {
            sochencom += x.getSucAn();
        }
        else if (x.getTamTrang() == "Buon")
            sochencom += x.getSucAn()/2.0;
        else if (x.getTamTrang() == "Vui")
            sochencom += x.getSucAn();
    }
    float result = sochencom / 15.0;


    ofstream fout;
    fout.open("output.txt");
    fout << result*songaychinhchien;
    fout.close();
}



int main()
{
    vector<NongDan> nd;
    vector<ChienBinh> cb;
    int ngaycc = 0;
    read_file("INPUT.txt",ngaycc, nd, cb);
    xuat(nd, cb, ngaycc);
    return 0;
}

