#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"MonHoc.h"
using namespace std;

// Doc luu file MonHoc.h
void Doc_Thong_Tin_Mon_Hoc(ifstream & fileIn, MONHOC & MH) {
	fileIn.getline(MH.MaMH,sizeof(MH.MaMH), '\n');
	fileIn.getline(MH.TenMH,sizeof(MH.TenMH),'\n');
}

void Doc_Danh_Sach_Mon_Hoc(DSMH &dsMonHoc) {
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


//Doc ghi file Lop.h
void Doc_Thong_Tin_Lop_Hoc(ifstream& fileIn, Lop* l) {
	fileIn.getline(l->MALOP,sizeof(l->MALOP), '\n');
	fileIn.getline(l->TENLOP, sizeof(l->TENLOP), '\n');
}

void Doc_Danh_Sach_Lop_Hoc(DSLOP& dsLop) {
	ifstream fileIn("DanhSachLop.txt", ios::in);
	fileIn >> dsLop.soLuong;
	fileIn.ignore();
	for (int i = 0; i < dsLop.soLuong; i++) {
		dsLop.lh[i]=new Lop;
		Doc_Thong_Tin_Lop_Hoc(fileIn, dsLop.lh[i]);
		Themlop(dsLop, dsLop.lh[i]);
	}
	fileIn.close();
}

void Luu_Danh_Sach_Lop_Hoc(DSLOP dsLop) {
	ofstream fileOut("DanhSachLop.txt", ios::out);
	fileOut << dsLop.soLuong << endl;
	for (int i = 0; i < dsLop.soLuong; i++) {
		fileOut << dsLop.lh[i]->MALOP << endl;
		fileOut << dsLop.lh[i]->TENLOP << endl;
	}
	fileOut.close();
}