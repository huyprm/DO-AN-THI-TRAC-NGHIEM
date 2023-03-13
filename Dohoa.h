#pragma once
#include"graphics.h"
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<iostream>
#include<string.h>
#pragma comment (lib, "graphics.lib")

#define WIDTH 1300
#define HEIGHT 700
#define MAU_NEN COLOR(211, 233, 242)
using namespace std;


//Tao man hinh dang nhap
void tao_khung_dang_nhap() {

	//set screen va dat mau nen background 
	initwindow(WIDTH, HEIGHT, "Thi_Trac_Nghiem", 0, 0);
	setfillstyle(SOLID_FILL, MAU_NEN);//mau background
		bar(0, 0, 1300, 700);
	setbkcolor(MAU_NEN); //mau nen
	setcolor(BLACK);//mau chu
	
	char s0[] = { "Thi Trac Nghiem" };
	char s1[] = { "Login your account" };
	char s2[] = { "User name" };
	char s3[] = { "Please enter password" };
	char s4[] = { "LOGIN" };

	//tao khung dang nhap lon 
	setcolor(COLOR(4, 92, 133));
	setlinestyle(SOLID_LINE, 0, 5);
		rectangle(400, 300, 850, 610);
	setlinestyle(SOLID_LINE, 0, 1); 
		rectangle(410, 310, 840, 600);

		rectangle(450, 390, 800, 425);//khung user 
		rectangle(450, 450, 800, 485);//khung password

	setfillstyle(SOLID_FILL, COLOR(35, 81, 232));// set kieu cho khung login
		bar(450, 520, 800, 555);//khung login

	setcolor(BLACK);
		outtextxy(550, 340, s1);
		outtextxy(460, 400, s2);
		outtextxy(460, 460, s3);

	setcolor(WHITE);
	setbkcolor(COLOR(35, 81, 232));
		outtextxy(600, 530, s4);

	setcolor(COLOR(14, 10, 245));
	setbkcolor(MAU_NEN);
	settextstyle(9, HORIZ_DIR, 8);
		outtextxy(250, 150, s0);


	getch();

	cleardevice();
	/*getch();*/
}
void xulyLogin() {

}