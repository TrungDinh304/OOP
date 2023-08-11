#pragma once
#include"NVCongNhat.h"
#include"NVSanXuat.h"
#include"NhanVien.h"
#include<fstream>
class CongTy
{
private:
	NVCongNhat* congnhat;
	int n_congnhat;
	NVSanXuat* sanxuat;
	int n_sanxuat;

public:
	CongTy();
	CongTy(int, int);
	CongTy& operator = (const CongTy&);
	void Nhap();
	void Xuat();
	float tongLuong();
	NhanVien* NV_luongCaoNhat();
	float ave_luong();
	NhanVien* Tim_NV_ma(string);
	NhanVien* Tim_NV_hoten(string);
	int count_NgSinh_thang(int);
	void insert_NV();
	void remove_NV(string);
	void write_file_lower();
	~CongTy();

};

