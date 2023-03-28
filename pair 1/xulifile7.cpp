#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;


class NhanVien
{
private:
    string Ten;
    string Phong;
public:
    NhanVien(string,string);
    void setTen(string);
    string getTen();
    void setPhong(string);
    string getPhong();
    string PhongMaxNV(vector<NhanVien>);
};

NhanVien::NhanVien(string Ten_init, string Phong_init)
{
    Ten = Ten_init;
    Phong = Phong_init;
}

void NhanVien::setTen(string Alter)
{
    Ten = Alter;
}

void NhanVien::setPhong(string Alter)
{
    Phong = Alter;
}

string NhanVien::getPhong()
{
    return Phong;
}

string NhanVien::getTen()
{
    return Ten;
}

vector<NhanVien> docFile(string fileName)
{
    vector<NhanVien> result;
    ifstream fin;
    fin.open(fileName); 
    if(!fin.is_open())
    {
        cout<<"Mo file that bai."<<endl;
        return result;
    }


    NhanVien temp("","");
    while(!fin.eof())
    {
        string buffer;
        getline(fin,buffer,' ');
        temp.setPhong(buffer);
        getline(fin,buffer);
        temp.setTen(buffer);
        result.push_back(temp);
    }
    fin.close();
    return result;
}
int getMaxPost(int* arr, int n)
{
    int max = 0;
    for( int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max = i;
    }
    return max;
}
string NhanVien::PhongMaxNV(vector<NhanVien> source)
{
    /*int n = source.size();
    int soNhanVien_1Phong[100]={0};
    for(int i=0;i<n;i++)
    {
        int len_tenphong = source[i].Phong.size();
        int sophong = stoi(source[i].Phong.substr(1,len_tenphong));
        soNhanVien_1Phong[sophong]++;
    }*/
    int n = source.size();
    int* demNhanVienPhong = new int[n]{0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(source[i].Phong==source[j].Phong)
                demNhanVienPhong[i]++;
        }
    }
    int maxPost=getMaxPost(demNhanVienPhong,n);
    return source[maxPost].Phong;
}


int main()
{
    vector<NhanVien> doc;
    doc = docFile("INPUT7.txt");
    string phongDongNhat = doc[0].PhongMaxNV(doc);
    for(int i =0;i<doc.size();i++)
    {
        cout<<doc[i].getPhong()<<' '<<doc[i].getTen()<<endl;
    }
    ofstream fout;
    fout.open("OUTPUT7.txt");
    fout<< phongDongNhat<<endl;
    for( int i = 0; i < doc.size();i++)
    {
        if(doc[i].getPhong()==phongDongNhat)
            fout<<doc[i].getTen()<<endl;
    }
    fout.close();
}