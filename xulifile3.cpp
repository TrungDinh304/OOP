#include<iostream>
#include"PhanSo.h"
#include<fstream>
using namespace std;
#define Max 100


void DocFile(PhanSo result[], string filename,int& n)
{
    ifstream fin;
    fin.open(filename); 
    if(!fin.is_open())
    {
        cout<<"Mo file that bai."<<endl;
        return;
    }
    n=0;
    while (!fin.eof())
    {
        int tu=0;
        int mau=0;
        fin>>tu;
        fin>>mau;
        PhanSo temp(tu,mau);
        result[n].setTu(tu);
        result[n].setMau(mau);
        n++;
    }

    fin.close();
}


int main ()
{
    PhanSo result[Max];
    int n=0;
    DocFile(result,"INPUT3.txt",n);
    PhanSo sum;
    for(int i=0;i<n;i++)
    {
        sum=sum+result[i];
    }
    ofstream fout;
    fout.open("OUTPUT3.txt");
    fout<<sum.getTu()<<' '<<sum.getMau()<<'\n';
    fout.close();
    return 1;
}