#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
// trang tri
void GanDL();
// duy chuyen con tro ma mau 
void gotoxy(int, int);
void txtColor(int);
// Xet luot choi
short Chan(int);
char OX(short);
// lenh duy chuyen
void sangTrai();
void sangPhai();
void lenTren();
void xuongDuoi();
void conTro(short,short);
//Khung ban co
void khung();
void khungDetail();
// thao tac tuong tac
void danhOX(short, short);
void win();
//thong tin van dau
void home(short);
void thongTin();
void intName1(char ten1[]); void outName1(char ten1[]); void intName2(char ten2[]); void outName2(char ten2[]);
void huongDan(short);
// Dieu kien chien thang
short oWin();
short xWin();
//Thao tac bat dau
void start();
void player2();
void replay();
// thong tin version va lien he
void version();
void contract();
// thao tac Back
void backHome();
void back();
/*Tong ket cuoc choi*/
void tongKet(int, int);