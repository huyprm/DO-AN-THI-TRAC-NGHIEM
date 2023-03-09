#pragma once
#include<iostream>
#include <cstddef>
#include<iomanip>
#include"DanhSachDiem.h"
using namespace std;

struct SinhVien {
	char MASV[11];
	char HO[51];
	char TEN[20];
	char PHAI[5];
	char password[20];
	/*DIEM Diem=NULL;*/
};
struct nodeSinhVien {
	SinhVien sv;
	nodeSinhVien* next;
};
typedef nodeSinhVien* DSSV;


void createDSSV(DSSV& FirstSV) {
	FirstSV = NULL;
}

bool isEmpty(DSSV FirstSV) {
	return (FirstSV == NULL ? 1 : 0);
}

void Insert_first(DSSV& FirstSV, SinhVien x) {
	DSSV p = new nodeSinhVien();
	p->sv = x;
	p->next = FirstSV;
	FirstSV = p;
}

void Insert_after(DSSV& FirstSV, SinhVien x) {
	DSSV p;
	if (FirstSV == NULL)
		return;
	else
	{
		p = new nodeSinhVien();
		p->sv = x;
		p->next = FirstSV->next;
		FirstSV->next = p;
	}
}
void Insert_last(DSSV& FirstSV, SinhVien sv) {
	if (isEmpty(FirstSV)) Insert_first(FirstSV, sv);
	else {
		DSSV p = FirstSV;
		for (p ; p->next!= NULL; p = p->next);
		DSSV temp = new nodeSinhVien;
		temp->sv = sv;
		temp->next = NULL;
		p->next = temp;
	}
}

//xoa node dau danh sach lien ket don
void Deleta_first(DSSV& FirstSV) {
	DSSV p;
	if (isEmpty(FirstSV)) return;
	else {
		p = FirstSV;
		FirstSV = p->next;
		delete p;
	}
}

void Delete_after(DSSV FirstSV)
{
	DSSV q;
	// neu p la NULL hoac p chi nut cuoi
	if ((FirstSV == NULL) || (FirstSV->next == NULL))
		printf("khong xoa sinh vien nay duoc");
	else
	{
		q = FirstSV->next;  // q chi nut can xoa
		FirstSV->next = q->next;
		delete q;
	}
}

//tim kiem sinh vien theo masv 
DSSV Search_info(DSSV FirstSV, SinhVien sv)
{
	DSSV p = new nodeSinhVien();
	for (p = FirstSV; p != NULL; p = p->next)
		if (p->sv.MASV == sv.MASV) return p;
	return NULL;
}

int ktTrungMASV(DSSV FirstSV, char a[]) {
	DSSV p;
	for (p = FirstSV; p->next != NULL; p = p->next) {
		if (FirstSV->sv.MASV == a) return 1;
	}
	return 0;
}

void xuatDSSV(DSSV FirstSV) {
	DSSV p = new nodeSinhVien;
	cout << setw(10) << "MSSV" << setw(11) << "Ho" << setw(51) << "Ten" << setw(20) << "Phai" << endl;
	for (p = FirstSV; p != NULL; p = p->next) {
		cout << setw(10) << p->sv.MASV << setw(11) << p->sv.HO << setw(51) << p->sv.TEN << setw(20) << p->sv.PHAI << endl;
	}
}
void nhapsinhvien(SinhVien& sv) {
	cout << "Nhap ma so sinh vien: ";
	cin >> sv.MASV;
	InHoa(sv.MASV);

	cout << "\nNhap ho sinh vien: ";
	cin.ignore();
	cin.getline(sv.HO, sizeof(sv.HO));
	validateText(sv.HO);

	cout << "\nNhap ten sinh vine: ";
	cin >> sv.TEN;
	validateText(sv.TEN);

	cout << "\nNhap phai cua sinh vien: ";
	cin >> sv.PHAI;
	InHoa(sv.PHAI);
	 
	cout << "\nNhap password cua sinh vien: ";
	cin >> sv.password;
	xoaSpace(sv.password);
}
