#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"date.h"
#include"DocGia.h"
#include<vector>

using namespace std;
class list
{
private:
	vector<DocGia> l;
	vector<treem> nhoc;
	vector<nguoilon> cu;
public:
	void readfile()
	{
		ifstream fin;
		fin.open("INPUT.txt");
		if (!fin.is_open())
		{
			cout << "Loi r ma: " << endl;
			return;
		}
		
		while (!fin.eof())
		{
			string line;
			getline(fin, line);
			stringstream inf(line);
			while (!inf.eof())
			{
				string buffer;
				string m;
				string ht;
				string gt;
				date ns;
				string cm;
				int sm;
				getline(inf, m, ',');
				getline(inf, ht, ',');
				getline(inf, gt, ',');
				getline(inf, buffer, ' ');
				getline(inf, buffer, ',');
				ns.str_todate(buffer);

				getline(inf, cm, ',');
				getline(inf, buffer, ' ');
				getline(inf, buffer, '\n');
				sm = stoi(buffer);
				DocGia temp(m, ht, gt, ns, sm, cm);
				l.push_back(temp);
				date cur;
				cur.Cur_date();
				if (cur.getnam() - temp.getNamSinh() > 12)
				{
					cout << cur.getnam() - temp.getNamSinh() << endl;
					nguoilon temp2(m, ht, gt, ns, sm, cm);
					cu.push_back(temp2);
				}
				else
				{
					cout << cur.getnam() - temp.getNamSinh() << endl;
					treem temp2(m, ht, gt, ns, sm, cm);
					nhoc.push_back(temp2);
				}
			}

		}
		fin.close();
	}

	void write()
	{
		ofstream fout;
		fout.open("OUTPUT.txt");

		int troai = 0;
		int gei = 0;
		for (auto x : cu)
		{
			cout << x.getGT() << endl;
			if (x.getGT() == " M")
				troai++;
			else if (x.getGT() == " F")
				gei++;
		}

		fout << "Adult: " << cu.size() << '(' << troai << " M, " << gei << " F)" << endl;
		troai = 0;
		gei = 0;
		for (auto x : nhoc)
		{
			if (x.getGT() == " M")
				troai++;
			else if (x.getGT() == " F")
				gei++;
		}
		fout << "Children: " << nhoc.size() << '(' << troai << "M, " << gei << "F)" << endl;
		int stt = 1;

		for (auto x : l)
		{
			fout << stt << '.' << x.getma() << ',' << x.gethote() << ',' << x.getGT() << ',' << x.getNgayS() << ',' << x.getCM() << '.' << endl;
		}
		fout.close();
	}

	void write_tt()
	{
		ofstream fout;
		fout.open("OUTPUT2.txt");
		float tongtrem = 0;
		for (auto x : nhoc)
		{
			tongtrem += x.tinhtien();
		}
		for (auto y : cu)
		{
			tongtrem += y.tinhtien();
		}
		fout << tongtrem;
		fout.close();
	}
};

