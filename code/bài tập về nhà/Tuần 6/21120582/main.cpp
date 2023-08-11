#include"List.h"


int main()
{
	List l;
	//đọc file và test các hàm theo yêu cầu
	l.docfile();
	l.xuat();
	l.writefile("OUTPUT.txt");
	l.sapxep_nsx_tang();
	l.writefile("NgaySX_tang.txt");
	l.sapxep_giagiam();
	l.GhiFileGia("GiaGiam.txt");
	//mở comment để test hàm nhập xuất
	/*l.nhap();
	l.xuat();*/
	return 0;
}