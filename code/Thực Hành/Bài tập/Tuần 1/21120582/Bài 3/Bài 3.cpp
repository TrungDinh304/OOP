#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"DanhSach.h"
using namespace std;


int main()
{
	

	//đọc file input và ghi kết quả vừa đọc vào file output
	DanhSach a;
	char doc[] = "INPUT.txt";
	char ghi[] = "OUTPUT.txt";
	a.read_File(doc);
	a.write_File(ghi, 0);


	//ghi các học sinh có điểm trung bình thấp hơn trung bình lớp vào file OUTPUT2.txt
	char ghi2[] = "OUTPUT2.txt";
	a.SV_lower_tblop(ghi2);

	//thêm 1 sinh viên vào mảng và UPDATE vào file UPDATE.txt
	char ghi3[] = "UPDATE.txt";
	char tendem[30] = "Nguyen Quynh";
	char ma_dem[30] = "211205XX";

	date ngaydem(19, 3, 2003);
	SinhVien add(tendem, ghi, ngaydem, 8, 9, 9);
	
	a.insert_N_updateF(add, ghi3);


	/*
	freopen("list.txt", "wt", stdout);
	cout << a.getN() << endl;
	for (int i = 0; i < a.getN(); i++)
	{
		a.getList()[i].xuatSinhVien(1);
	}*/

	//xuat ra file Birth day các sinh viên có ngày sinh nhặt trùng với ngày hiện tại
	char bod[] = "BIRTH.txt";
	a.W_file_cur_bod_sv(bod, 1);;
	

	
	

	return 0;


}

