#include <iostream>
#include<vector>
using namespace std;


class atm
{
private:
	int amount;
	int to500;
	int to200;
	int to100;
	int to50;
public:
	atm();
	void rut();
	void intienConlai();
};

atm::atm()
{
	amount = 10100000;
	to500 = 10;
	to200 = 20;
	to100 = 10;
	to50 = 2;
}




void atm::rut()
{
	int amt = 0;
	cout << "Nhap so tien muon rut: ";
	cin >> amt;
	int tienrut = amt;
	try
	{
		if (amt > amount)
			throw "Hien cay ATM khong du so tien ban can.";
		if (amt < 0)
			throw  "So tien nhap vao < 0.";
		if (amt % 50000 != 0)
			throw "Khong hte rut voi so tien khong chia het cho 50.000";
		// if check máy còn đủ 4 loiaj tiền + throw
		if (amt < 850000)
			throw "Khong du de rut moi loai mot to.";
		try {
			vector<int> tohet;
			if (to500 == 0)
			{
				tohet.push_back(500);
			}
			if (to200 == 0)
			{
				tohet.push_back(200);
			}
			if (to100 == 0)
			{
				tohet.push_back(100);
			}
			if (to50 == 0)
			{
				tohet.push_back(50);
			}
			if (tohet.size() > 0)
				throw tohet;
			
		}
		catch (vector<int> menhgia)
		{
			for (auto x : menhgia)
				cout << "Xin loi! khong the doi tien le voi menh gia: " << x << "000 VMD." << endl;
			exit(0);
		}
		

		int to500r = 0;
		int to200r = 0;
		int to100r = 0;
		int to50r = 0;

		if (amt % 50000 != 0)
			throw(amt);


		if (amt - 500000 >= 0 && to500)
		{
			amt -= 500000;
			to500r++;
			to500--;
		}
		if (amt - 200000 >= 0 && to200 && to200 > to500)
		{
			amt -= 200000;
			to200r++;
			to200--;
		}

		if (amt - 100000 >= 0 && to100 )
		{
			amt -= 100000;
			to100r++;
			to100--;
		}

		if (amt - 50000 >= 0 && to50)
		{
			amt -= 50000;
			to50r++;
			to50--;
		}

			
		while (amt - 500000 >= 0 && to500)
		{
			amt -= 500000;
			to500r++;
			to500--;
		}
		while (amt - 200000 >= 0 && to200 && to200 > to500)
		{
			amt -= 200000;
			to200r++;
			to200--;
		}
		while (amt - 100000 >= 0 && to100)
		{
			amt -= 100000;
			to100r++;
			to100--;
		}
			
		while (amt - 50000 >= 0 && to50)
		{
			amt -= 50000;
			to50r++;
			to50--;
		}

		amount -= tienrut;
		
		cout << "So to 500.000: " << to500r << endl;
		cout << "So to 200.000: " << to200r << endl;
		cout << "So to 100.000: " << to100r << endl;
		cout << "So to 50.000: " << to50r << endl;
		cout << "============================================================" << endl;
	}
	catch (const char* a)
	{
		cout << a << endl;
		return;
	}
}

void atm::intienConlai()
{
	cout << "So to 500.000 con lai: " << to500 << endl;
	cout << "So to 200.000 con lai: " << to200 << endl;
	cout << "So to 100.000 con lai: " << to100 << endl;
	cout << "So to 50.000 con lai: " << to50 << endl;
}

int main()
{
	atm a;
	cout << "=========================================" << endl;
	cout << "| Nhap bat ki de rut                    |" << endl;
	cout << "| 0. De ket thuc                        |" << endl;
	cout << "=========================================" << endl;
	int opt = -1;
	cin >> opt;

	while (opt != 0) {
		a.rut();
		a.intienConlai();
		cout << "=========================================" << endl;
		cout << "| Nhap bat ki de tiep tuc rut           |" << endl;
		cout << "| 0. De ket thuc                        |" << endl;
		cout << "=========================================" << endl;

		cin >> opt;
	}

	return 0;
}