#pragma once
#include<iostream>
#include<string.h>
using namespace std;


void InHoa(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 97 && s[i] <= 122) s[i] -= 32;
    }
}

int xoa(char* a, int q)
{
    int n = strlen(a), i;
    for (i = q; i < n-1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = '\0';
    return 0;
}

void xoaSpace(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n;) {
        if (s[i] == ' ') xoa(s, i), n--;
        else i++;
    }
}

// Tat ca in hoa va khong co khoang trang VD: N21DCCN129
void chuanHoa(char* s) {
    InHoa(s);
    xoaSpace(s);
}

//xoa khoang trang cuoi chuoi
void xoaKhoangTrangCuoi(char* str) {
    if (str[strlen(str) - 1] == ' ') //xoa khoang trang cuoi chuoi
        xoa(str, strlen(str) - 1);
}

//xoa khoang trang dau chuoi va ke nhau
void xoaKhoangTrangDauVaKeNhau(char* str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ' ' && str[i + 1] == ' ')  //Neu cac khoang trang ke nhau
        {
            xoa(str, i);
            i--;
        }
    if (str[0] == ' ') //xoa khoang trang dau chuoi
        xoa(str, 0);
}
/*
    Xoa khoang trang va In hoa ky tu dau 
*/
void validateText(char s[]) {
    xoaKhoangTrangDauVaKeNhau(s);
    xoaKhoangTrangCuoi(s);

    for (int i = 0; s[i] != '\0'; i++)  //in hoa chu cai dau cua tung tu`
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if (s[i - 1] == ' ' || i == 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
        }
    }
}