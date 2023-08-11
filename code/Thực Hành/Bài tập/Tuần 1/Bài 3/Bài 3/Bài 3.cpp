#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"DanhSach.h"
using namespace std;


void menu()
{

	char chay = '\0';
	do
	{
		system("cls");
		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t|   Danh sach sinh vien da duoc doc tu file INPUT.txt        |" << endl;
		cout << "\t\t\t==============================================================" << endl;
		DanhSach a;

		char doc[] = "INPUT.txt";
		a.read_File(doc);


		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t|   1. Ghi danh sach Sinh vien hien co vao file OUTPUT.txt   |" << endl;
		cout << "\t\t\t|   2. Ghi danh sach Sinh vien co diem trung binh thap hon   |" << endl;
		cout << "\t\t\t|      trung binh lop vao file OUTPUT2.txt                   |" << endl;
		cout << "\t\t\t|   3. Nhap 1 Sinh vien va Thêm 1 sinh viên vào Danh Sach    |" << endl;
		cout << "\t\t\t|      và UPDATE vào file INPUT.txt                          |" << endl;
		cout << "\t\t\t|   4. Xuat ra file Birth day các sinh vien co ngay sinh     |" << endl;
		cout << "\t\t\t|      nhat trung voi ngay hien tai                          |" << endl;
		cout << "\t\t\t|   5. In danh sach SinhVien ra man hinh console.            |" << endl;
		cout << "\t\t\t| Nhap '0' hoac ki tu nao khac '1', '2', '3', '4',           |" << endl;
		cout << "\t\t\t|               de ket thuc chuong trinh                     |" << endl;
		cout << "\t\t\t==============================================================" << endl;

		cout << "Nhap chuc nang muon test: ";
		cin >> chay;

		if (chay == '1')
		{
			int in_xeploai = 0;
			cout << "Ban co muon in sep loai khong (0: khong, 1: co): ";
			cin >> in_xeploai;

			char ghi[] = "OUTPUT.txt";
			a.write_File(ghi, in_xeploai);
			cout << "Da xuat ra file OUTPUT.txt." << endl;
		}
		else if (chay == '2')
		{
			char ghi2[] = "OUTPUT2.txt";
			a.SV_lower_tblop(ghi2);
			cout << "Da xuat ra file OUTPUT2.txt." << endl;
		}
		else if (chay == '3')
		{
			char ghi3[] = "INPUT.txt";
			SinhVien add;
			cout << "Nhap thong tin sinhvien muon them vao: " << endl;
			cin >> add;

			a.insert_N_updateF(add, ghi3);
			cout << "Da update vào file INPUT.txt." << endl;
		}

		else if (chay == '4')
		{
			char bod[] = "BIRTH.txt";
			a.W_file_cur_bod_sv(bod, 1);
			cout << "Da xuat ra file BIRTH.txt." << endl;
		}
		else if (chay == '5')
		{
			int in_xeploai = 0;
			cout << "Ban co muon in sep loai khong (0: khong, 1: co): ";
			cin >> in_xeploai;
			cout << "Danh Sach Sinh Vien: " << endl;
			for (int i = 0; i < a.getN(); i++)
			{
				cout << a.getList()[i];
				if (in_xeploai)
					cout << '|' << a.getList()[i].xeploai();
				cout << endl;
			}
		}
		else
		{
			chay = '0';
		}

		system("pause");
	} 
	while (chay != '0');
	cout << "****Ket Thuc Chuong Trinh.****" << endl;
}

int main()
{
	menu();
	return 0;
}

