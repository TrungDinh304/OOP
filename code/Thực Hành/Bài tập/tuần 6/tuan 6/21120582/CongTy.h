#pragma once
#include<fstream>
#include"NhanVien.h"
#include"NVCongNhat.h"
#include"NVSanXuat.h"

class CongTy
{
private:
	NhanVien** list;
	int n;
public:
	CongTy();
	CongTy(const CongTy& ini);
	CongTy& operator=(const CongTy&);
	void readfile(char* filename);
	void write_file(char* filename);
	void nhap();
	void xuat();
	float tongLuong();
	NhanVien* NV_LuongCaoNhat();
	float Luong_tr_binh();
	NhanVien* tim_NV_ma(char* maso);
	NhanVien* tim_NV_ten(char* ten); 
	int So_NV_sinh_thang(int thang);
	void them_N_capnhat(NhanVien* add);
	void Xoa_N_capnhat(char* maso);
	void xuat_file_luongthap();
};