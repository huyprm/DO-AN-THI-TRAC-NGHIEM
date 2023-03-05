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
	int soLuong = 0;
};
typedef struct DanhSachLop DSLOP;
bool isFull(DSLOP dsLop) {
	return(dsLop.soLuong == MAXLOP);
}
bool isEmpty(DSLOP dsLop) {
	return(dsLop.soLuong == 0);
}
//ham kiem tra trung ma lop
int ktTrungMALOP(char a[], DSLOP dsLop) {
	for (int i = 0; i < dsLop.soLuong; i++) {
		if (!strcmp(dsLop.lh[i]->MALOP,a)) return i;
	}
	return -1;
}
void themLop(DSLOP& dsLop, Lop lop) {
	if (isFull(dsLop)) {
		cout << "Lop da du so luong!" << endl;
		return ;
	}
	if (ktTrungMALOP(lop.MALOP, dsLop) < 0) {
		cout << "Ma lop hoc bi trung." << endl;
		return ;
	}
	dsLop.lh[dsLop.soLuong] = new Lop;
	*dsLop.lh[dsLop.soLuong] = lop;
	dsLop.soLuong++;
}

// ham in ra danh sach thong thuong
void xuatDSLOP(DSLOP dsLop) {
	cout << setw(16) << "Ma lop" << setw(51) << "Ten lop" << setw(20) << "Nien khoa\n";
	for (int i = 0; i < dsLop.soLuong; i++) {
		cout << setw(16) << dsLop.lh[i]->MALOP << setw(51) << dsLop.lh[i]->TENLOP << setw(20) << dsLop.lh[i]->nienkhoa << endl;
	}
}
//in ra danh sach lop co cung nien khoa nien khoa
void Themlop(DSLOP& dsLop) {
	Lop* p = new Lop;
	cout << "Nhap ma lop: ";
	cin.ignore();
	cin.getline(p->MALOP, 16);
	chuanHoa(p->MALOP);
	cout << "Nhap ten lop: ";
	cin.getline(p->TENLOP, 51);
	chuanHoa(p->TENLOP);
	cout << "Nhap nien khoa: ";
	cin.getline(p->nienkhoa, 20);
	dsLop.lh[dsLop.soLuong] = p;
	dsLop.soLuong++;
}
int KTMALOP(char a[], DSLOP dslop) {
	for (int i = 0; i < dslop.soLuong; i++) {
		if (dslop.lh[i]->MALOP == a) return i;
	}
	return -1;
}
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
		system("pause");
	}
	else {
		for (int i = l; i < dsLop.soLuong - 1; i++) {
			dsLop.lh[i] = dsLop.lh[i + 1];
		}
		Lop* tmp = dsLop.lh[dsLop.soLuong - 1];
		dsLop.soLuong--;
		cout << "Da xoa thanh cong!" << endl;
		system("pause");
	}
}
void hieuchinhLop(DSLOP& dsLop) {
	cout << "Nhap Ma Lop muon hieu chinh:" << endl;
	cin.ignore();
	char a[16];
	cin.getline(a, 16);
	chuanHoa(a);
	int kt = ktTrungMALOP(a, dsLop);
	if (kt < 0) {
		cout << "Ma khong ton tai!" << endl;
		system("pause");
	}
	else {
		cout << "Nhap Ten Lop: ";
		cin.ignore();
		cin.getline(dsLop.lh[kt]->TENLOP, 51);
		chuanHoa(dsLop.lh[kt]->TENLOP);
		cout << "nhap nien khoa: ";
		cin.getline(dsLop.lh[kt]->nienkhoa, 20);
		cout << "Da thanh doi thong tin thanh cong" << endl;
		system("pause");
	}
}



