// CauThu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <iostream>
using namespace std;
class cauthu
{
protected:
    string soAo;
    string vitri;
    int sucLuc;
public:
    cauthu(string sa, string vt, int sl)
    {
        soAo = sa;
        vitri = vt;
        sucLuc = sl;
    }

    string getSoAo()
    {
        return soAo;
    }
    string getViTri()
    {
        return vitri;
    }
    int getSucLuc()
    {
        return sucLuc;
    }
    void setSoAo(string sa)
    {
        soAo = sa;
    }
    void setvitri(string Vitri)
    {
        vitri = Vitri;
    }
    void setSucLuc(int sl)
    {
        sucLuc = sl;
    }
};


class cauthu_thidau :public cauthu
{
private:
    int chuyen;
    int sut;
public:
    cauthu_thidau(string sa, string vt, int ch, int s, int s_l) :cauthu(sa, vt, s_l)
    {
        chuyen = ch;
        sut = s;
    }
    friend ostream& operator<<(ostream& out, cauthu_thidau a)
    {
        out << a.soAo << ' ' << a.vitri << ' ' << a.sut << ' ' << a.chuyen << ' ' << a.sucLuc;
        return out;
    }
};


class doithidau
{
private:
    vector<cauthu> DuBi;
    vector<cauthu_thidau> chinhthuc;
public:
    vector<cauthu> getDuBi()
    {
        return DuBi;
    }
    vector<cauthu_thidau>getChinhThuc()
    {
        return chinhthuc;
    }
    void setDuBI(vector<cauthu>db)
    {
        DuBi = db;
    }
    void setChinhThuc(vector<cauthu_thidau>ct)
    {
        chinhthuc = ct;
    }

    void readfile(string filename)
    {
        ifstream fin;
        fin.open(filename);
        if (!fin)
        {
            cout << "Loi oi" << endl;
            return;
        }
        string line;

        while (!fin.eof())
        {
            vector<string> buffer;
            getline(fin, line);
            stringstream s(line);
            while (!s.eof())
            {
                string temp;
                s >> temp;
                buffer.push_back(temp);
            }

            if (buffer.size() == 4)
            {
                cauthu temp(buffer[0], buffer[1] + ' '+ buffer[2], stoi(buffer[3]));
                DuBi.push_back(temp);
            }
            else if (buffer.size() == 6)
            {
             cauthu_thidau temp(buffer[0], buffer[1] + ' ' + buffer[2], stoi(buffer[3]), stoi(buffer[4]), stoi(buffer[5]));
             chinhthuc.push_back(temp);
            }
        }
        fin.close();
    }

    cauthu_thidau getMax_sl(string vitri)
    {
        int max = 0;
        for (auto x : DuBi)
        {
            if (x.getViTri() == vitri)
                if (x.getSucLuc() > max)
                    max = x.getSucLuc();
        }

        for (auto x : chinhthuc)
        {
            if (x.getViTri() == vitri)
                if (x.getSucLuc() > max)
                    max = x.getSucLuc();
        }
        for (auto x : chinhthuc)
        {
            if (x.getViTri() == vitri)
                if (x.getSucLuc() == max)
                    return x;
        }
        for (auto x : DuBi)
        {
            if (x.getViTri() == vitri)
                if (x.getSucLuc() == max)
                {
                    cauthu_thidau result(x.getSoAo(), x.getViTri(), 8, 8, x.getSucLuc());
                    return result;
                }
        }

        return chinhthuc[0];
    }

    void write_file(string filename)
    {
        ofstream fout;
        fout.open(filename);

        for (auto x : DuBi)
        {
            string gjfjh = x.getSoAo();
            gjfjh[0] = 'C';
            cauthu_thidau temp(gjfjh, x.getViTri(), 8, 8, x.getSucLuc());
            chinhthuc.push_back(temp);
        }
        int n = chinhthuc.size();
        int cnt = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                
                for (int k = j+1; k < n; ++k) {
                    
                    if (chinhthuc[i].getSucLuc() + chinhthuc[j].getSucLuc() + chinhthuc[k].getSucLuc() > 150)
                    {
                        fout << cnt << endl;
                        fout << chinhthuc[i] << endl;
                        fout << chinhthuc[j] << endl;
                        fout << chinhthuc[k] << endl;
                        cnt++;
                    }
                    if (cnt == 3)
                        return;
                }
                if (cnt == 3)
                    return;
            }
        }



        fout.close();
    }
};


int main()
{
    doithidau a;
    a.readfile("input.txt");
    a.write_file("ouput.txt");
    return 0;
}

