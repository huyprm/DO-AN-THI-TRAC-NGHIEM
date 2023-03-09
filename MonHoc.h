#pragma once
#include<iostream>
#include"Struct.h"
#include<string>
#include"ThuVien.h"
#define MAX_MONHOC 300

struct MONHOC {
	char MaMH[15];
	char TenMH[255];
};
struct List_MONHOC { 
	int n;
	MONHOC nodeMONHOC[MAX_MONHOC];
};
typedef List_MONHOC DSMH;


bool isEmpty(DSMH dsMonHoc) {
	return (dsMonHoc.n == 0);
}

bool isFull(DSMH dsMonHoc) {
	return (dsMonHoc.n == MAX_MONHOC);
}

void createDSMH(DSMH& dsMonHoc) {
	dsMonHoc.n = 0;
}

void printMonHoc(DSMH dsMonHoc) {
	if (isEmpty(dsMonHoc)) {
		cout << "Danh sach trong" << endl;
		return;
	}
	for (int i = 0; i < dsMonHoc.n; i++) {
		cout << "Ma mon hoc: " << dsMonHoc.nodeMONHOC[i].MaMH << "   ";
		cout << "Ten mon hoc: " << dsMonHoc.nodeMONHOC[i].TenMH << endl;
	}
}

int ktMa(DSMH dsMonHoc, char Ma[]) {
	for (int i = 0; i < dsMonHoc.n; i++) {
		if (strcmp(dsMonHoc.nodeMONHOC[i].MaMH , Ma)==0)return i;
	}
	return -1;
}

void addMonHoc(DSMH& dsMonHoc, MONHOC MH) {
	if (isFull(dsMonHoc)) {
		return;
	}
	if (ktMa(dsMonHoc, MH.MaMH) != -1) {
		return;
	}
	dsMonHoc.nodeMONHOC[dsMonHoc.n] = MH;
	dsMonHoc.n++;
}

void deleteMonHoc(DSMH& dsMonHoc) {
	if (isEmpty(dsMonHoc)) {
		return;
	}
	char MaMH[15];
	cout << "Nhap ma mon hoc can xoa: ";
	cin >> MaMH;
	InHoa(MaMH);
	if (ktMa(dsMonHoc, MaMH) != -1) {
		int k = ktMa(dsMonHoc, MaMH);
		for (int i = k; i < dsMonHoc.n - 1; i++) {
			dsMonHoc.nodeMONHOC[i] = dsMonHoc.nodeMONHOC[i + 1];
		}
		dsMonHoc.n--;
		cout << "Xoa thanh cong\n";
	}
	else {
		cout << "Ma mon hoc khong ton tai\n";
		return;
	}
}

void adjustInfo_MonHoc(DSMH& dsMonHoc) {
	char MaMH[15];
	cout << "Nhap ma mon hoc can chinh sua: ";
	cin >> MaMH;
	InHoa(MaMH);
	if (ktMa(dsMonHoc, MaMH)!=-1) {
		int n = ktMa(dsMonHoc, MaMH);
		cout << "Nhap ma mon hoc: ";
		cin >> MaMH;
		strcpy_s(dsMonHoc.nodeMONHOC[n].MaMH,sizeof(dsMonHoc.nodeMONHOC[n].MaMH), MaMH);
		cout << "Nhap ten mon hoc: ";
		cin.ignore();
		cin.getline(MaMH,sizeof(MaMH));//nhap ten vao bien MaMH
		strcpy_s(dsMonHoc.nodeMONHOC[n].TenMH, sizeof(dsMonHoc.nodeMONHOC[n].TenMH),MaMH);
	}
	else {
		cout << "Ma khong ton tai\n";
	}
}

//Nhap mon hoc tu ban phim
void nhapmonhoc(MONHOC &mh) {
	cout << "Nhap ma mon hoc: ";
	cin >> mh.MaMH;
	InHoa(mh.MaMH);
	cout << "Nhap ten mon hoc: ";
	cin.ignore();
	cin.getline(mh.TenMH,sizeof(mh.TenMH));
}


