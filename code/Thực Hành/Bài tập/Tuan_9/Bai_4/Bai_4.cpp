#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include"CongTy.h"
using namespace std;




void menu()
{
	CongTy ct1;
	char filename[] = "ds_NhanVien.dat";
	ct1.read_file_binary(filename);
	cout << "## Da doc va luu danh sach nhan vien tu file ds_NhanVien.dat. ##" << endl;


	string option = "";
	do
	{
		cout << "\t\t\t==========================================================\n";
		cout << "\t\t\t|| Nhap mot trong cac tuy chon sau:                     ||\n";
		cout << "\t\t\t|| 1: Nhap danh sach nhan vien                          ||\n";
		cout << "\t\t\t|| 2: Xuat danh sach nhan vien                          ||\n";
		cout << "\t\t\t|| 3: Ghi danh sach nhan vien vao file ds_NhanVien.dat  ||\n";
		cout << "\t\t\t|| 4: Doc danh sach nhan vien tu file ds_NhanVien.dat   ||\n";
		cout << "\t\t\t|| 5: Tinh tong luong cua tat ca nhan vien              ||\n";
		cout << "\t\t\t|| 6: Tim nhan vien co luong cao nhat                   ||\n";
		cout << "\t\t\t|| 7: Tim nhan vien theo ma nhan vien                   ||\n";
		cout << "\t\t\t|| 8: Tim nhan vien theo ho ten                         ||\n";
		cout << "\t\t\t|| 9: Tim so nhan vien sinh vao thang nhap vao          ||\n";
		cout << "\t\t\t|| 10: Them mot nhan vien moi                           ||\n";
		cout << "\t\t\t||    cap nhat lai vao file ds_NhanVien.dat             ||\n";
		cout << "\t\t\t|| 11: Xoa mot nhan vien                                ||\n";
		cout << "\t\t\t||    cap nhat lai vao file ds_NhanVien.dat             ||\n";
		cout << "\t\t\t|| 12: Ghi tat ca nhan vien co muc luong thap hon       ||\n";
		cout << "\t\t\t||    luong trung binh vao file emp_LowerAvgSalary.dat  ||\n";
		cout << "\t\t\t|| 13: Doc file .dat voi duong dan duoc nhap vao.       ||\n";
		cout << "\t\t\t||                                                      ||\n";
		cout << "\t\t\t|| Nhap '0' hoac ki tu nao khac '1', '2', '3', '4',     ||" << endl;
		cout << "\t\t\t||               de ket thuc chuong trinh               ||" << endl;
		cout << "\t\t\t==========================================================" << endl;

		cout << "Nhap chuc nang muon test: ";
		cin >> option;
		if (option == "1")
		{
			ct1.nhap();
			cout << "## Danh Sach Vua Nhap: ##" << endl;
			ct1.xuat();
		}
		else if (option == "2")
		{
			cout << "## Danh sach nhan vien hien tai: ##" << endl;
			ct1.xuat();
		}
		else if (option == "3")
		{
			try
			{
				ct1.write_file_binary(filename);
				cout << "Da ghi danh sach nhan vien vao file " << filename << endl;
			}
			catch (...)
			{
				cout << "Ghi file that bai." << endl;
			}
		}
		else if (option == "4")
		{
			ct1.read_file_binary(filename);
			cout << "## Da doc danh sach nhan vien tu file: " << filename << " ##" << endl;
			cout << "\tDanh sach vua doc duoc:" << endl;
			ct1.xuat();
		}
		else if (option == "5")
		{
			float tong = ct1.tongLuong();
			cout << "- Tong luong cua tat ca nhan vien: " << long long(tong) << "VND." << endl;
		}
		else if (option == "6")
		{
			NhanVien* NVLuongcaonhat = ct1.NV_LuongCaoNhat();
			cout << "Nhan vien co luong cao nhat: " << endl;
			NVLuongcaonhat->Xuat();
			cout << "\tVoi so luong: " << long long(NVLuongcaonhat->tinhluong()) << " VND" << endl;
		}
		else if (option == "7")
		{
			try
			{
				char buffer[30] = "";
				cout << "Nhap ma nhan vien cua nhan vien can tim: ";
				cin >> buffer;
				NhanVien* cantim = ct1.tim_NV_ma(buffer);
				if (cantim == NULL)
					throw MyException("## Khong tim thay nhan vien co ma so can tim. ##");
				cout << "## Nhan vien can tim: ##" << endl;
				cantim->Xuat();
			}
			catch (MyException error)
			{
				cout << error.getMessage();
			}
		}
		else if (option == "8")
		{
			try
			{
				char buffer[30] = "";
				cout << "Nhap ho ten nhan vien cua nhan vien can tim: ";
				cin >> buffer;
				NhanVien* cantim = ct1.tim_NV_ten(buffer);
				if (cantim == NULL)
				{
					throw MyException("## Khong tim thay nhan vien co ho ten vua nhap. ##");
				}
				cout << "## Nhan vien can tim: ##" << endl;
				cantim->Xuat();
			}
			catch (MyException error)
			{
				cout << error.getMessage() << endl;
			}
		}
		else if (option == "9")
		{

			int thang = 0;
			cout << "Nhap thang can dem so nhan vien sinh vao thang do: ";
			cin >> thang;
			int sinhthang = ct1.So_NV_sinh_thang(thang);
			cout << "## So nhan vien sinh vao thang " << thang << ": " << sinhthang << " Nhan Vien. ##" << endl;
		}
		else if (option == "10")
		{
			try
			{
				NhanVien* themvao = NULL;
				cout << "Nhap nhan vien muon them vao danh sach: " << endl;
				int loai = 0;
				cout << "\tNhap loai nhan vien (1: Cong Nhat; 2: San Xuat):";
				cin >> loai;
				while (loai != 1 && loai != 2)
				{
					cout << "\tTham so nhap vao khong hop le xin vui long nhap lai (1: Cong Nhat; 2: San Xuat):";
					cin >> loai;
				}
				if (loai == 1)
				{
					themvao = new NVCongNhat;
				}
				else if (loai == 2)
					themvao = new NVSanXuat;
				themvao->Nhap();
				ct1.them_N_capnhat(themvao);
				cout << "Danh Sach sau khi them: " << endl;
				ct1.xuat();
				cout << "## Da cap nhat nhan vien vao danh sach thanh cong. ##" << endl;
			}
			catch (...)
			{
				cout << "## Cap nhat that bai. ##" << endl;
			}
		}
		else if (option == "11")
		{
			try
			{
				char buffer[30] = "";
				cout << "\tNhap ma so nhan vien muon xoa: ";
				cin >> buffer;
				ct1.Xoa_N_capnhat(buffer);
				cout << "Danh Sach sau khi xoa: " << endl;
				ct1.xuat();
				cout << "## Xoa nhan vien co ma " << buffer << " va cap nhat file thanh cong. ##" << endl;
			}
			catch (...)
			{
				cout << "Xoa nhan vien va cap nhat that bai." << endl;
			}
		}
		else if (option == "12")
		{
			ct1.xuat_file_luongthap();
			
			cout << "## Da cap nhat nhung nhan vien co luong thap hon luong trung binh cua cong ty vao file emp_LowerAvgSalary.dat ##" << endl;
		}
		else if (option == "13")
		{
			char buffer[50] = "";
			cout << "Nhap duong dan file muon doc: ";
			cin.ignore();
			cin.getline(buffer, 50, '\n');
			ct1.read_file_binary(buffer);
			cout << "Danh sach nhan vien doc duoc tu file " << buffer << ": " << endl;
			ct1.xuat();
		}
		else 
			break;

		system("pause");
		system("cls");
	} while (option != "0");
	cout << "****Ket Thuc Chuong Trinh.****" << endl;
}

int main()
{
	menu();
	/*CongTy a;
	char filename[] = "file_mau.dat";
	a.readfile(filename);
	a.xuat();
	cout << "=============================================================" << endl;
	char filename2[] = "ds_NhanVien.dat";
	a.write_file_binary(filename2);

	a.read_file_binary(filename2);
	a.xuat();*/
	

	return 0;
}


