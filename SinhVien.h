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
	int PHAI = 0;//0:male 1:female
	char password[20];
	DIEM Diem;
};
struct nodeSinhVien {
	SinhVien sv;
	nodeSinhVien* next;
};
typedef nodeSinhVien* DSSV;


void khoiTaoDSSV(DSSV& FirstSV) {
	FirstSV = NULL;
}

int isEmpty(DSSV FirstSV) {
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
		DSSV p = new nodeSinhVien();
		for (p = FirstSV; p->next != NULL; p = p->next);
		Insert_after(p, sv);
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
void nhapSinhVien(DSSV& FirstSV) {

}
void xuatDSSV(DSSV FirstSV) {
	DSSV p = new nodeSinhVien();
	cout << setw(10) << "MSSV" << setw(11) << "Ho" << setw(51) << "Ten" << setw(20) << "Phai" << endl;
	for (p = FirstSV; p != NULL; p = p->next) {
		cout << setw(10) << p->sv.MASV << setw(11) << p->sv.HO << setw(51) << p->sv.TEN << setw(20) << p->sv.PHAI << endl;
	}
}

