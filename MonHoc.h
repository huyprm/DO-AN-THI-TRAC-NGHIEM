#pragma once
#include<iostream>
#include"Struct.h"
#include<string>
#include"ThuVien.h"
#define MAX_MONHOC 300

struct MONHOC {
	string MaMH;
	string TenMH;
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
	for (int i = 0; i < dsMonHoc.n; i++) {
		cout << "Ma mon hoc: " << dsMonHoc.nodeMONHOC[i].MaMH << "   ";
		cout << "Ten mon hoc: " << dsMonHoc.nodeMONHOC[i].TenMH << endl;
	}
}
int ktMa(DSMH dsMonHoc, string Ma) {
	for (int i = 0; i < dsMonHoc.n; i++) {
		if (dsMonHoc.nodeMONHOC[i].MaMH == Ma)return i;
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
	string MaMH;
	cout << "Nhap ma mon hoc can xoa: ";
	cin >> MaMH;
	InHoa(MaMH);
	if (ktMa(dsMonHoc, MaMH) != -1) {
		for (int i = 0; i < dsMonHoc.n; i++) {
			if (dsMonHoc.nodeMONHOC[i].MaMH == MaMH) {
				for (int j = i; j < dsMonHoc.n - 1; j++) {
					dsMonHoc.nodeMONHOC[j] = dsMonHoc.nodeMONHOC[j + 1];
				}
			}
		}
		dsMonHoc.n--;
	}
	else return;
}
void adjustInfo_MonHoc(DSMH& dsMonHoc) {
	string MaMH;
	cout << "Nhap ma mon hoc can chinh sua: ";
	cin >> MaMH;
	if (ktMa(dsMonHoc, MaMH)!=-1) {
		int n = ktMa(dsMonHoc, MaMH);
		string TenMH;
		cout << "Nhap ma mon hoc: ";
		cin >> MaMH;
		dsMonHoc.nodeMONHOC[n].MaMH = MaMH;
		cout << "Nhap ten mon hoc: ";
		cin >> TenMH;
		dsMonHoc.nodeMONHOC[n].TenMH = TenMH;
	}
	else {
		cout << "Ma khong ton tai";
	}
}


