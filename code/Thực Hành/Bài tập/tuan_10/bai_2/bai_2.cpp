#include <iostream>
#include"QLPhim.h"
using namespace std;

void menu()
{
	QLPhim ql;
	char filename[] = "ds_phim.dat";
	ql.read_bin_file(filename);
	cout << "## Da doc file ds_phim.dat. ##" << endl;

	string option = "";
	do
	{
		cout << "\t\t\t==========================================================\n";
		cout << "\t\t\t|| Nhap mot trong cac tuy chon sau:                     ||\n";
		cout << "\t\t\t|| 1: Nhap danh sach phim                               ||\n";
		cout << "\t\t\t|| 2: Xuat danh sach phim                               ||\n";
		cout << "\t\t\t|| 3: Ghi danh sach phim vao file ds_phim.dat           ||\n";
		cout << "\t\t\t|| 4: Doc danh sach phim tu file ds_phim.dat            ||\n";
		cout << "\t\t\t|| 5: Them mot phim moi vao danh sach ma                ||\n";
		cout << "\t\t\t||   khong thay doi thu tu san co (tang dan theo nam SX)||\n";
		cout << "\t\t\t|| 6: Xoa mot phim theo Nha San Xuat                    ||\n";
		cout << "\t\t\t||                                                      ||\n";
		cout << "\t\t\t|| Nhap '0' hoac ki tu nao khac '1', '2', '3', '4',     ||" << endl;
		cout << "\t\t\t||               de ket thuc chuong trinh               ||" << endl;
		cout << "\t\t\t==========================================================" << endl;

		cout << "Nhap chuc nang muon test: ";
		cin >> option;

		if (option == "1")
		{
			ql.input();
			cout << "## Danh sach phim vua moi nhap: ##" << endl;
			ql.print();
		}
		else if (option == "2")
		{
			ql.print();
		}
		else if (option == "3")
		{
			ql.write_bin_file(filename);
			cout << "## Dach Sach phim vua duoc ghi vao file ds_phim.dat ##" << endl;
		}
		else if (option == "4")
		{
			ql.read_bin_file(filename);
			cout << "## Danh sach phim vua doc tu file ds_phim.dat: ##" << endl;
			ql.print();
		}
		else if (option == "5")
		{
			Phim add;
			cout << "Nhap phim muon them: " << endl;
			cin >> add;
			ql.insert_Phim(add);
			cout << "## Danh sach phim sau khi them vao: ##" << endl;
			ql.print();
		}
		else if (option == "6")
		{
			cout << "Nhap Nha san xuat cua cac phim muon xoa: ";
			char temp[MaxnhaSX] = "";
			cin.ignore();
			cin.getline(temp, MaxnhaSX, '\n');
			ql.remove_phim_NSX(temp);
			cout << "Danh sach sau khi xoa phim cua Nha San Xuat " << temp << ": " << endl;
			ql.print();
		}

		system("pause");
		system("cls");
	} while (option != "0");
	cout << "****Ket Thuc Chuong Trinh.****" << endl;
}

int main()
{
	menu();
	
	return 0;
}

