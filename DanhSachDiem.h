#pragma once
#include"SinhVien.h"
struct DIEMMH {
	char MaMH[15];
	float Diem;
};
struct List_DIEM {
	DIEMMH diem;
	List_DIEM* next;
};
typedef List_DIEM* DIEM;


void creatListDIEM(DIEM& d) {
	d = NULL;
}

void addHead(DIEM& p, DIEMMH d) {
	DIEM q = new List_DIEM;
	q->diem = d;
	q->next = p;
	p = q;
}

void addAfter(DIEM &p, DIEMMH d) {
	if (p == NULL) {
		cout << "khong the them diem vao danh sach" << endl;
	}
	else {
		DIEM q = new List_DIEM;
		q->diem = d;
		q->next = p->next;
		p->next = q;
	}
}

void addTail(DIEM& p, DIEMMH d) {
	if (p == NULL) addHead(p, d);
	else {
		DIEM node = p;
		while (node->next != NULL) node = node->next;
		DIEM temp = new List_DIEM;
		temp->diem = d;
		temp->next = NULL;
		node->next = temp;
	}
}

bool ktDaThiMonHoc(DIEM p, char MaMH[]) {
	DIEM node = p;
	while (node != NULL) { 
		if (strcmp(node->diem.MaMH, MaMH) == 0) {
			return true;
		}
		node = node->next;
	}
	return false;
}
void printList_DIEM(DIEM p) {
	DIEM node = p;
	while (node != NULL) {
		cout << node->diem.MaMH << ' ' << node->diem.Diem;
		node = node->next;
	}
}
