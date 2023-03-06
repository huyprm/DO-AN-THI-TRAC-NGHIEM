#pragma once
#include<iostream>

using namespace std;
#define MAX_LOP 500

//========== danh sach sinh vien ==========


//========== danh sach lop ==========



//========== danh sach mon hoc ==========


//========== danh sach diem thi ==========



//========== danh sach cau hoi thi ==========

struct CAUHOITHI {
	int ID;
	string MAMH;
	string ND;
	string DA;
};
struct List_CHT {
	CAUHOITHI cht;
	CAUHOITHI* left;
	CAUHOITHI* right;
};
struct SINHVIEN {
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string password;
	List_DIEM Diem;
};
struct List_SV {
	SINHVIEN sv;
	SINHVIEN* next;
};
struct LOP {
	string MALOP;
	string TENLOP;
	string NIENKHOA;
	List_SV dssv;
};
struct List_LOP {
	int n;
	LOP* nodeLOP[MAX_LOP];
};