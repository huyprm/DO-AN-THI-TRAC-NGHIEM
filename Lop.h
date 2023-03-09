#pragma once
#include<iostream>
#include<string>
#include"ThuVien.h"
#include"SinhVien.h"
using namespace std;
#define MAXLOP 500

struct Lop {
	char MALOP[16];
	char TENLOP[51];
	char nienkhoa[20];
	DSSV Dssv;
};
struct DanhSachLop {
	Lop* lh[MAXLOP];
	int soLuong;
};
typedef struct DanhSachLop DSLOP;


bool isFull(DSLOP dsLop) {
	return(dsLop.soLuong == MAXLOP);
}

bool isEmpty(DSLOP dsLop) {
	return(dsLop.soLuong == 0);
}

void createLOP(DSLOP& dsLOP) {
	dsLOP.soLuong = 0;
}

//ham kiem tra trung ma lop
int ktTrungMALOP(char a[], DSLOP dsLop) {
	for (int i = 0; i < dsLop.soLuong; i++) {
		if (!strcmp(dsLop.lh[i]->MALOP,a)) return i;
	}
	return -1;
}

//void themLop(DSLOP& dsLop, Lop* lop) {
//	if (isFull(dsLop)) {
//		cout << "Lop da du so luong!" << endl;
//		return ;
//	}
//	if (ktTrungMALOP(lop->MALOP, dsLop) < 0) {
//		cout << "Ma lop hoc bi trung." << endl;
//		return ;
//	}
//	dsLop.lh[dsLop.soLuong] = new Lop;
//	dsLop.lh[dsLop.soLuong] = lop;
//	dsLop.soLuong++;
//}
void Themlop(DSLOP& dsLop, Lop* p) {
	if (isFull(dsLop)) {
		cout << "Lop da du so luong!" << endl;
		return;
	}
	if (ktTrungMALOP(p->MALOP, dsLop)!=-1) {
		cout << "Ma lop hoc bi trung." << endl;
		return;
	}
	dsLop.lh[dsLop.soLuong] = new Lop;
	dsLop.lh[dsLop.soLuong] = p;
	dsLop.soLuong++;
}

// ham in ra danh sach thong thuong
void xuatDSLOP(DSLOP dsLop) {
	cout << setw(20) << "Nien khoa" << setw(16) << "Ma Lop" << setw(50) << "Ten lop\n";
	for (int i = 0; i < dsLop.soLuong; i++) {
		cout << setw(20) << dsLop.lh[i]->nienkhoa << setw(16) << dsLop.lh[i]->MALOP << setw(50) << dsLop.lh[i]->TENLOP << endl;
	}
}

void xuatDSLOPtheokhoa(DSLOP dsLop, char nienkhoa[]) {
	bool kt = false;
	for (int i = 0; i < dsLop.soLuong; i++) {
		if (strcmp(dsLop.lh[i]->nienkhoa, nienkhoa) == 0) {
			cout << "Ma lop: " << dsLop.lh[i]->MALOP;
			cout << "\tTen lop: " << dsLop.lh[i]->TENLOP << endl;
			kt = true;
		}
	}
	if (!kt) cout << "Ma khong ton tai" << endl;
}

//in ra danh sach lop co cung nien khoa nien khoa
void XoaLop(DSLOP& dsLop) {
	cout << "Neu Ma Lop da ton tai thi moi co the xoa!" << endl;
	char a[16];
	cout << "Nhap ma lop :";
	cin.ignore();
	cin.getline(a, 16);
	chuanHoa(a);
	int l = ktTrungMALOP(a, dsLop);
	cout << "kq  " << l << endl;
	if (l == -1) {
		cout << "Ma lop khong ton tai!" << endl;
		return;
	}
	else {
		for (int i = l; i < dsLop.soLuong - 1; i++) {
			dsLop.lh[i] = dsLop.lh[i + 1];
		}
		Lop* tmp = dsLop.lh[dsLop.soLuong - 1];
		dsLop.soLuong--;
		cout << "Da xoa thanh cong!" << endl;
	}
}

void hieuchinhLop(DSLOP& dsLop) {
	cout << "Nhap Ma Lop muon hieu chinh:" ;
	cin.ignore();
	char a[16];
	cin.getline(a, sizeof(a));
	chuanHoa(a);
	int kt = ktTrungMALOP(a, dsLop);
	if (kt < 0) {
		cout << "Ma khong ton tai!" << endl;
		system("pause");
	}
	else {
		cout << "nhap nien khoa moi: ";
		cin.ignore();
		cin.getline(dsLop.lh[kt]->nienkhoa, 20);
		chuanHoa(dsLop.lh[kt]->nienkhoa);
		cout << "Nhap ma lop moi: ";
		cin >> dsLop.lh[kt]->MALOP;
		InHoa(dsLop.lh[kt]->MALOP);
		cout << "Nhap Ten Lop moi: ";
		cin.ignore();
		cin.getline(dsLop.lh[kt]->TENLOP, 51);
		cout << "Da thanh doi thong tin thanh cong" << endl;
	}
}
void nhaplophoc(Lop*& l) {
	l = new Lop;
	cout << "Nhap nien khoa lop: ";
	cin.ignore();
	cin.getline(l->nienkhoa, sizeof(l->nienkhoa));
	xoaSpace(l->nienkhoa);
	cout << "Nhap ma lop hoc: ";
	cin >> l->MALOP;
	InHoa(l->MALOP);
	cout << "Nhap ten lop hoc: ";
	cin.ignore();
	cin.getline(l->TENLOP, sizeof(l->TENLOP));
}




