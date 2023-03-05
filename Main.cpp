#include<iostream>
#include<fstream>
#include<string.h>
#include"graphics.h"
#include"Lop.h"
#include"SinhVien.h"
#include"MonHoc.h"
#include"DocGhiFile.h"
#pragma comment(lib,"graphics.lib")
void menu() {
	bool kt = true;
	DSLOP ds;
	//doclop(ds);

	system("cls");
	cout << "================Menu===========";
	cout << "\n\n\t1.them lop:";
	cout << "\n\n\t2.hieu chinh sinh vien:";
	cout << "\n\n\t3.xuat lop:";
	cout << "\n\n\t4. xoa lop";
	cout << "\n\n\t5.Thoat";
	cout << "\n\n===================================\n";

	while (kt) {
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			Themlop(ds);
			break;
		case 2:
			hieuchinhLop(ds);
			system("pause");
			break;


		case 3:
			xuatDSLOP(ds);
			break;
			system("pause");
		case 4:
			XoaLop(ds);
			system("pause");
			break;
		case 5:
			kt = false;
			break;
		default:
			break;
		}
	}
}
void abc() {
	bool kt = true;
	DSMH ds;
	createDSMH(ds);
	ifstream fileInput("DanhsachMonHoc.txt");
	fileInput.open("DanhsachMonHoc.txt");
	/*Doc_Danh_Sach_Mon_Hoc(fileInput, ds);*/
	
	while (kt) {
		cout << "================Menu===========";
		cout << "\n\n\t1.them mon:";
		cout << "\n\n\t2.hieu chinh thong tin mon hoc:";
		cout << "\n\n\t3.xuat mon hoc:";
		cout << "\n\n\t4. xoa mon hoc";
		cout << "\n\n\t5.Thoat";
		cout << "\n\n===================================\n";
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		/*case 1:
			addMonHoc(ds);
			break;*/
		case 2:
			deleteMonHoc(ds);
			break;
		case 3:
			printMonHoc(ds);
			break;
	/*	case 4:
				XoaLop(ds);
				system("pause");
				break;*/
		case 5:
			kt = false;
			break;
		default:
			break;
		}
	}
	fileInput.close();
}

int main()
{
	bool kt = true;
	DSMH ds;
	createDSMH(ds);
	Doc_Danh_Sach_Mon_Hoc(ds);
	printMonHoc(ds);
	cout << "-----------------------------\n";
	deleteMonHoc(ds);
	Luu_Danh_Sach_Mon_Hoc(ds);
	/*adjustInfo_MonHoc(ds);
	Luu_Danh_Sach_Mon_Hoc(ds);*/
	printMonHoc(ds);
	return 0;
}
