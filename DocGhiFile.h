#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"MonHoc.h"
using namespace std;

// Doc luu file MonHoc.h
void Doc_Thong_Tin_Mon_Hoc(ifstream & fileIn, MONHOC & MH) {
	getline(fileIn, MH.MaMH, '\n');
	getline(fileIn,MH.TenMH,'\n');
}
void Doc_Danh_Sach_Mon_Hoc(DSMH & dsMonHoc) {
	ifstream fileIn("DanhSachMonHoc.txt",ios::in);
	int n;
	fileIn >> n;
	fileIn.ignore();
	for (int i = 0; i < n; i++) {
		MONHOC MH;
		Doc_Thong_Tin_Mon_Hoc(fileIn, MH);
		addMonHoc(dsMonHoc, MH);
	}
	fileIn.close();
}
void Luu_Danh_Sach_Mon_Hoc(DSMH dsMonHoc) {
	ofstream fileOut("DanhSachMonHoc.txt",ios::out);
	fileOut << dsMonHoc.n << endl;
	for (int i = 0; i < dsMonHoc.n; i++) {
		fileOut << dsMonHoc.nodeMONHOC[i].MaMH << endl;
		fileOut << dsMonHoc.nodeMONHOC[i].TenMH << endl;
	}
	fileOut.close();
}