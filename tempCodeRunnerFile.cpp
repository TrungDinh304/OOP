in;
}

ostream&operator<<(ostream &out,const PhanSo& src){
    out << "("<< src._tu << "/" << src._mau << ")\n";
    return out;
}

void PhanSo::toigian()
{
    int uocChung=UCLN(_mau,_tu);
    _mau/=uocChung;
    _tu/=uocChung;
}

int main(){
    PhanSo s1(1,6), s2(1,6);
    PhanSo s3 = s1 + s2;
