#pragma once
#include<iostream>
#include<string.h>
using namespace std;
//ham in hoa tat ca cac ky tu
void InHoa(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 97 && s[i] <= 122) s[i] -= 32;
    }
}
void InHoa(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 97 && s[i] <= 122) s[i] -= 32;
    }
}
// xoa ky tu  khoang trang du thua trong chuoi
int xoa(char* a, int q)
{
    int n = strlen(a), i;
    for (i = q; i <= n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 0;
}
int xoakhoangtrang(char* a)
{
    int i, n = strlen(a);
    for (i = 0; i < n; i++)
    {
        if (a[0] == 32)
        {
            xoa(a, 0);
            n--;
        }
        if (a[n - 1] == 32)
        {
            xoa(a, n - 1);
            n--;
        }
        if (a[i] == 32 && a[i + 1] == 32)
        {
            xoa(a, i);
            i--;
            n--;
        }
    }
    return 0;
}
void chuanHoa(char* s) {
    InHoa(s);
    xoakhoangtrang(s);
}

//ham chi nhan chu va so. cac ky tu khac thi tu dong nuot
void ChiNhanChuVaSo(char* s) {

}
//ham ve khung
//void box(int x, int y,int w, int h) {
//    for (int ix = x; ix <= x + w; ix++) {
//        gotoxy(ix, y);
//        cout << char(196);
//        gotoxy(ix, y+h);
//        cout << char(196);
//}
//    for (int iy = y; iy <= y + h; iy++) {
//        gotoxy(x, iy);
//        cout << char(179);
//        gotoxy(x + w, iy);
//        cout << char(179);
//    }
//    gotoxy(x, y);
//    cout << char(218);
//    gotoxy(x + w, y);
//    cout << char(191);
//    gotoxy(x, y + h);
//    cout << char(192);
//    gotoxy(x + w, y + h);
//    cout << char(217);
//}
//
//ham bao loi 
