#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;



class tennhanvat{
private:
    string ten;
    int dodaiten;
public:
    tennhanvat();
    tennhanvat(string, int);
    int demkituten();
    string getTen();
    void setTen(string);
    int getDodaiten();
    void setDodaiten(int);

    
    tennhanvat& operator =(const tennhanvat& source);
    bool operator > (const tennhanvat&);
};

string tennhanvat::getTen()
{
    return ten;
}

int tennhanvat::getDodaiten()
{
    return dodaiten;
}

void tennhanvat::setTen(string alter)
{
    ten = alter;
}

void tennhanvat::setDodaiten(int alter)
{
    dodaiten=alter;
}

tennhanvat::tennhanvat()
{
    ten = "unknow";
    dodaiten=0;
}

tennhanvat::tennhanvat(string ten_init, int dodaiten_init)
{
    ten=ten_init;
    dodaiten=dodaiten_init;
}

int tennhanvat::demkituten()
{
    dodaiten=ten.length();
}

tennhanvat& tennhanvat::operator=(const tennhanvat& source)
{
    this->ten= source.ten;
    this->dodaiten=source.dodaiten;
    return *this;
}

bool tennhanvat::operator> (const tennhanvat& other)
{
    return dodaiten > other.dodaiten;
}

class listnhanvat{
private:
    vector<tennhanvat> list;
    int n;
public:
    int getN();
    void docfile(string fileName);
    tennhanvat GetLongest();
};



int listnhanvat::getN()
{
    return n;
}

void listnhanvat::docfile(string filename)
{
    ifstream fin;
    fin.open(filename); 
    if(!fin.is_open())
    {
        cout<<"Mo file that bai."<<endl;
        return;
    }

    while (!fin.eof())
    {
        string buffer;
        getline(fin,buffer);
        tennhanvat temp(buffer,buffer.size());
        list.push_back(temp);
    }
    n=list.size();
    fin.close();
}


tennhanvat listnhanvat::GetLongest()
{
    tennhanvat max;
    for(int i = 0; i < n; i++)
    {
        if(list[i] > max)
            max=list[i];
    }
    return max;
}

int main()
{
    listnhanvat doc;
    doc.docfile("INPUT4.txt");
    tennhanvat ghi = doc.GetLongest();
    ofstream fout;
    fout.open("OUTPUT4.txt");
    fout<<ghi.getTen()<<' '<<ghi.getDodaiten()<<'\n';
    fout.close();

    return 1;
}




