#pragma once
#include<iostream>
#include<string.h>
using namespace std;

struct CAUHOITHI {
	int ID;
	string MAMH;
	string ND;
	char DA;
	char dapanA[126];
	char dapanB[126];
	char dapanC[126];
	char dapanD[126];
};
struct List_CHT {
	int ID;// Key
	CAUHOITHI cht;
	List_CHT* left;
	List_CHT* right;
};
typedef List_CHT* CHT;
bool checkTree(CHT CauHoiThi) {
	if (CauHoiThi == NULL)return true;
	return false;
}
void createTreeCHT(CHT& CauHoiThi) {
	CauHoiThi = NULL;
}
// kiem tra trung cau hoi
bool kiemtraCauHoi(CHT root, CAUHOITHI cht) {
	if (root != NULL) {
		CHT p = root;
		CHT arr[1000];
		int i = -1;
		while (p != NULL) {
			arr[++i] = p;
			p = p->left;
		}
		if (i != -1) {
			p = arr[i--];
			if (p->cht.MAMH == cht.MAMH && p->cht.ND == cht.ND && p->cht.DA == cht.DA && p->cht.dapanA == cht.dapanA && p->cht.dapanB == cht.dapanB && p->cht.dapanC == cht.dapanC && p->cht.dapanD == cht.dapanD)
				return false;
			p = p->right;
		}
	}
	return true;
}
void addCauHoiThi(CHT& p, int ID, CAUHOITHI cht) {
	if (p==NULL) {
		p= new List_CHT;
		p->ID = ID;
		p->cht = cht;
		p->left = NULL;
		p->right = NULL;
	}
	else {
		if (ID < p->ID) {
			addCauHoiThi(p->left, ID, cht);
		}
		else addCauHoiThi(p->right, ID, cht);
	}
}
// cap phat id cho cau hoi
int randIdCauHoi(int id) {

}
void check(CHT p, CAUHOITHI cht) {
	if (kiemtraCauHoi(p, cht)) {
		int id = cht.ID;
		addCauHoiThi(p, id, cht);
		cout << "Add cau hoi vao danh sach thanh cong" << endl;
	}
	else cout << "Cau hoi da co trong danh sach" << endl;
}

