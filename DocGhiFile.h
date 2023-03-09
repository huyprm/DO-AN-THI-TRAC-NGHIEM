#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"MonHoc.h"
#include"Lop.h"
#include"SinhVien.h"
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
		MONHOC mh;
		Doc_Thong_Tin_Mon_Hoc(fileIn, mh);
		addMonHoc(dsMonHoc, mh);
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
	fileIn.getline(l->nienkhoa, sizeof(l->nienkhoa), '\n');
	fileIn.getline(l->MALOP,sizeof(l->MALOP), '\n');
	fileIn.getline(l->TENLOP, sizeof(l->TENLOP), '\n');
}

void Doc_Danh_Sach_Lop_Hoc(DSLOP& dsLop) {
	ifstream fileIn("DanhSachLop.txt", ios::in);
	int n;
	fileIn >> n;
	fileIn.ignore();
	for (int i = 0; i < n; i++) {
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
		fileOut << dsLop.lh[i]->nienkhoa << endl;
		fileOut << dsLop.lh[i]->MALOP << endl;
		fileOut << dsLop.lh[i]->TENLOP << endl;
	}
	fileOut.close();
}


// Doc luu file danh sach sinh vien
void Doc_Thong_Tin_Sinh_Vien(ifstream& fileIn, SinhVien sv) {
	fileIn.getline(sv.MASV, sizeof(sv.MASV), '\n');
	fileIn.getline(sv.HO, sizeof(sv.HO), '\n');
	fileIn.getline(sv.TEN, sizeof(sv.TEN), '\n');
	fileIn.getline(sv.PHAI, sizeof(sv.PHAI), '\n');
	fileIn.getline(sv.password, sizeof(sv.password), '\n');
}

void Doc_Danh_Sach_Sinh_Vien(DSSV& dsSV) {
	ifstream fileIn("DanhSachSV.txt", ios::in);
	SinhVien sv;
	while(!fileIn.eof()){
		
		Doc_Thong_Tin_Sinh_Vien(fileIn, sv);
		Insert_last(dsSV, sv);
	}
	fileIn.close();
}

void Luu_Danh_Sach_Sinh_Vien(DSSV dsSV) {
	ofstream fileOut("DanhSachSV.txt", ios::out);
	DSSV node = dsSV;
	while(node !=NULL){
		fileOut << node->sv.MASV << endl;
		fileOut << node->sv.HO << endl;
		fileOut << node->sv.TEN << endl;
		fileOut << node->sv.PHAI << endl;
		fileOut << node->sv.password << endl;
		node = node->next;
	}
	fileOut.close();
}