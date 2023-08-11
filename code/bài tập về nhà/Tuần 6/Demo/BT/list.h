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
			getline(inf, buffer, ',');
			ns.str_todate(buffer);
			getline(inf, cm, ',');
			getline(inf, buffer, '\n');
			sm = stoi(buffer);
			DocGia temp(m, ht, gt, ns, sm, cm);
			l.push_back(temp);
			date cur;
			cur.Cur_date();
			if (cur.getnam() - temp.getNamSinh()> 12)
			{
				nguoilon temp2(m, ht, gt, ns, sm, cm);
				cu.push_back(temp2);
			}
			else
			{
				treem temp2(m, ht, gt, ns, sm, cm);
				nhoc.push_back(temp2);
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
			if (x.getGT() == " M")
				troai++;
			else if (x.getGT() == " F")
				gei++;
		}

		fout << "Adult: " << cu.size() << '(' << troai << "M, " << gei << "F)" << endl;
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
			fout << stt << '.' << x.getma() << ',' << x.gethote() << ',' << x.getGT() << ',' << x.getNgayS().toString() << ',' << x.getCM() << '.' << endl;
		}
		fout.close();
	}


};

