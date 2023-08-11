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
public:
    NhanVat()
    {
        maso = "";
    }
    NhanVat(string ms)
    {
        maso = ms;
    }
    string getMaso()
    {
        return maso;
    }

    void setMaso(string ms)
    {
        maso = ms;
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
    NongDan(string ms, string ph) :NhanVat(ms)
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
    ChienBinh(string ms, int sucan, string tt) :NhanVat(ms)
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



void read_file(string filename, vector<NongDan>& a, vector<ChienBinh>& b)
{
    ifstream fin;
    fin.open(filename);
    if (!fin)
    {
        cout << "Loi roi" << endl;
        return;
    }

    string line;
   
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
        if (buffer.size() == 3)
        {
            ChienBinh init(buffer[0], stoi(buffer[1]), buffer[2]);
            b.push_back(init);
        }
        else if (buffer.size() == 2)
        {
            NongDan init(buffer[0], buffer[1]);
            a.push_back(init);
        }
    }
    fin.close();
}

void xuat(vector<NongDan>nd, vector<ChienBinh> cb)
{
    float sochencom = 0;
    for (auto x : nd)
    {
        if (x.getPhai() == "Nam")
            sochencom += 10;
        else if (x.getPhai() == "Nu")
            sochencom += 8;
    }
    for (auto x : cb)
    {
        if (x.getTamTrang() == "Buon")
            sochencom += x.getSucAn()/2.0;
        else if (x.getTamTrang() == "Vui")
            sochencom += x.getSucAn();
    }
    float result = sochencom / 15.0;
    ofstream fout;
    fout.open("output.txt");
    fout << result;
    fout.close();
}



int main()
{
    vector<NongDan> nd;
    vector<ChienBinh> cb;
    read_file("INPUT.txt", nd, cb);
    xuat(nd, cb);
    return 0;
}

