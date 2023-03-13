#include<iostream>
#include<fstream>
#include<string.h>
#include"graphics.h"
#include"Lop.h"
#include"SinhVien.h"
#include"MonHoc.h"
#include"DocGhiFile.h"
#include"DanhSachDiem.h"
#include"Dohoa.h"
#pragma comment(lib,"graphics.lib")

void testLOPHOC() {
	bool kt = true;
	DSLOP ds;
	createLOP(ds);
	Doc_Danh_Sach_Lop_Hoc(ds);
	cout << "================Menu===========";
	cout << "\n\n\t1.them lop:";
	cout << "\n\n\t2.hieu chinh sinh vien:";
	cout << "\n\n\t3.xuat lop:";
	cout << "\n\n\t4. xoa lop";
	cout << "\n\n\t5.xuat danh sach theo nien khoa:";
	cout << "\n\n\t6.Thoat";
	cout << "\n\n===================================\n";

	while (kt) {
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			Lop * l;
			nhaplophoc(l);
			Themlop(ds,l);
			break;
		case 2:
			hieuchinhLop(ds);
			break;
		case 3:
			xuatDSLOP(ds);
			break;
		case 4:
			XoaLop(ds);
			break;
		case 5:
			char nienkhoa[20];
			cout << "Nhap nien khoa can xem danh sach lop: ";
			cin.ignore();
			cin.getline(nienkhoa, sizeof(nienkhoa));
			xoaSpace(nienkhoa);
			xuatDSLOPtheokhoa(ds, nienkhoa);
			break;
		case 6:
			kt = false;
			Luu_Danh_Sach_Lop_Hoc(ds);
			break;
		default:
			break;
		}
	}
}

void testMONHOC() {
	bool kt = true;
	DSMH ds;
	createDSMH(ds);
	Doc_Danh_Sach_Mon_Hoc(ds);
	while (kt) {
		cout << "================Menu===========";
		cout << "\n\n\t1.them mon:";
		cout << "\n\n\t4.hieu chinh thong tin mon hoc:";
		cout << "\n\n\t3.xuat mon hoc:";
		cout << "\n\n\t2. xoa mon hoc";
		cout << "\n\n\t5.Thoat";
		cout << "\n\n===================================\n";
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;

		switch (luachon){
		case 1:
			MONHOC mh;
			nhapmonhoc(mh);
			addMonHoc(ds, mh);
			break;
		case 2:
			deleteMonHoc(ds);
			break;
		case 3:
			printMonHoc(ds);
			break;
		case 4:
			adjustInfo_MonHoc(ds);
			break;
		case 5:
			kt = false;
			Luu_Danh_Sach_Mon_Hoc(ds);
			break;
		default:
			break;
		}
	}
}

//dang co bug o testSINHVIEN
void testSINHVIEN() {
	bool kt = true;
	DSSV ds;
	SinhVien sv;
	createDSSV(ds);
	Doc_Danh_Sach_Sinh_Vien(ds);
	while (kt) {
		cout << "================Menu===========";
		cout << "\n\n\t1.them sinh vien";
		cout << "\n\n\t2.xuat danh sach sinh vien";
		cout << "\n\n\t3.Thoat";
		cout << "\n\n===================================\n";
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		
		switch (luachon) {
		case 1:
			
			nhapsinhvien(sv);
			Insert_last(ds,sv);
			break;
		case 2:
			xuatDSSV(ds);
			break;
		case 3:
			kt = false;
			Luu_Danh_Sach_Sinh_Vien(ds);
			break;
		default:
			break;
		}
	}
}

int main()
{
	tao_khung_dang_nhap();
	return 0;
}
