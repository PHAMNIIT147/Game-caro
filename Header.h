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
void SangTrai();
void SangPhai();
void LenTren();
void XuongDuoi();
void Contro(short,short);
//Khung ban co
void Khung(short);
void VeDung();
// thao tac tuong tac
void DanhOX(short, short);
void Win();
//thong tin van dau
void Home(short);
void ThongTinTranDanh();
void HuongDan(short);
// Dieu kien chien thang
short ConditionOWin();
short ConditionXWin();
//Thao tac bat dau
void Start();
void Player2();
void Replay();
// thong tin version va lien he
void Detail();
void Contract();
// thao tac Back
void BackGoHome();
void Back();