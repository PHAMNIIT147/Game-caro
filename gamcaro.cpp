/*
- Chuong trinh choi co caro
- ver 1.1
* Co gi moi ver 1.1
		+ Them mau me vao cac menu lua chon.
		+ Hien thi luot choi O, X.
		+ Sua toa do
*/
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
//x: chieu Ngang; y: chien doc
using namespace std;
char a[79][24], key;
short x,y,i,m,n,m1,n1, LuaChon; //m1,n1: phuc vu cho viec kiem tra Dieu Kien chien thang
//Cac thu tuc trang tri
void GanDL(){
    for (int i=1; i<=79; i++)
        for (int j=1; j<=24; j++)
            a[i][j]=' ';
}
void MoDau(short);
void Choi2Nguoi();
void ChoiVoiMayDangXayDung();
void ChoiVoiMay(short);
void ThongTin();
void Thoat();
void HuongDan(short);
void VeKhung(short);
void ChoiLai();

void Goto(int x, int y){
    COORD co = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , co);
}

void TextColor(int x)//Xac dinh mau cua chu
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x);
}
//Tro Choi
short Chan(short i){// Kiem tra chan le de phuc vu cho chia luot
    if (i%2==0) return 1;
    else return 0;
}

char OX(short i){
    if (Chan(i)==1) return 'O';
    else return 'X';
}

void VeOX(short x, short y){//Ve O, X theo luot
    if (a[x][y] != 'X' && a[x][y] != 'O'){
         if (Chan(i)==1) TextColor(11); else TextColor(12);
         a[x][y]=OX(i);
         cout<<a[x][y];
         i+=1;
    }
    else a[n][m];
    TextColor(7);
}

void AnSangTrai(){
    x-=1;
    if (x<13) x=13;
}

void AnSangPhai(){
    x+=1;
    if (x>=77) x=77;
}

void AnLenTren(){
    y-=1;
    if (y<3) y=3;
}

void AnXuongDuoi(){
    y+=1;
    if (y>=24) y=24;
}

void ConTro(short x, short y){  //Phuc vu cho di chuyen
    Goto(x,y);
    n=x;m=y;
}

void ThongTinTranDau(){
    TextColor(7);
    //Thong tin
    Goto(0,0); cout<<"Toa Do: "<<x-12<<"-"<<y-2<<"    Q : Thoat tran dau."<<endl<<"Luot thu: "<<i;
    //Trang tri
    cout<<"     M, E: choi.";
    TextColor(12); cout<<"           B15D44-b2tind44.tk";
    Goto(0,4); TextColor(11);cout<<"Nguoi Choi 1"<<endl<<"A,D,W,S"<<endl<<endl;
               cout<<"Nguoi choi 2"<<endl<<"Phim di "<<endl<<"chuyen"<<endl<<endl;
    TextColor(14); cout<<"p/s:"<<endl<<"Chan dau,"<<endl<<"chan duoi "<<endl; TextColor(12); cout<<"khong";TextColor(14); cout<<" tinh"<<endl<<endl;
    TextColor(9); cout<<"B: Back"<<endl<<"R: Choi lai"<<endl;
    TextColor(10); cout<<endl<<"Luot: "<<OX(i);
    TextColor(7);
}

short DKOChienThang(){//Dieu kien de ben O chien thang
    //Theo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='O')
        n1++;
    n1--;
    //Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet
    if ((a[n1][m]=='O') && (a[n1+1][m]=='O') && (a[n1+2][m]=='O') && (a[n1+3][m]=='O') && (a[n1+4][m]=='O') && ((a[n1+5][m] != 'X') || (a[n1-1][m] != 'X')) ) return 1; else
    if ((a[n1][m]=='O') && (a[n1-1][m]=='O') && (a[n1-2][m]=='O') && (a[n1-3][m]=='O') && (a[n1-4][m]=='O') && ((a[n1-5][m] != 'X') || (a[n1+1][m] != 'X')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='O')
        m1++;
    m1--;
    //Theo duong cheo chinh
    if ((a[n][m1]=='O') && (a[n][m1+1]=='O') && (a[n][m1+2]=='O') && (a[n][m1+3]=='O') && (a[n][m1+4]=='O') && ((a[n][m1+5] != 'X') || (a[n][m1-1] != 'X')) ) return 1; else
    if ((a[n][m1]=='O') && (a[n][m1-1]=='O') && (a[n][m1-2]=='O') && (a[n][m1-3]=='O') && (a[n][m1-4]=='O') && ((a[n][m1-5] != 'X') || (a[n][m1+1] != 'X')) ) return 1;
    //Theo duong cheo phu
    m1=m; n1=n;
    while (a[n1][m1]=='O'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='O') && (a[n1+1][m1+1]=='O') && (a[n1+2][m1+2]=='O') && (a[n1+3][m1+3]=='O') && (a[n1+4][m1+4]=='O') && ((a[n1+5][m1+5] != 'X') || (a[n1-1][m1-1] != 'X')) ) return 1; else
    if ((a[n1][m1]=='O') && (a[n1-1][m1-1]=='O') && (a[n1-2][m1-2]=='O') && (a[n1-3][m1-3]=='O') && (a[n1-4][m1-4]=='O') && ((a[n1-5][m1-5] != 'X') || (a[n1+1][m1+1] != 'X')) ) return 1;
    m1=m; n1=n;
    while (a[n1][m1]=='O'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='O' && (a[n1+1][m1-1])=='O' && (a[n1+2][m1-2])=='O' && (a[n1+3][m1-3])=='O' && (a[n1+4][m1-4]=='O' ) && ((a[n1+5][m1-5] != 'X') || (a[n1-1][m1+1] != 'X')) ) return 1; else
    if ((a[n1][m1])=='O' && (a[n1-1][m1+1])=='O' && (a[n1-2][m1+2])=='O' && (a[n1-3][m1+3])=='O' && (a[n1-4][m1+4]=='O' ) && ((a[n1-5][m1+5] != 'X') || (a[n1+1][m1-1] != 'X')) ) return 1;

    return 0;
}

short DKXChienThang(){ //Dieu kien de ben X chien thang
    //THeo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='X') {
        n1++;
    }
    n1--;
    //Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet duoc
    if ((a[n1][m]=='X') && (a[n1+1][m]=='X') && (a[n1+2][m]=='X') && (a[n1+3][m]=='X') && (a[n1+4][m]=='X') && ((a[n1+5][m] != 'O') || (a[n1-1][m] != 'O')) ) return 1; else //Theo Hang ngang
    if ((a[n1][m]=='X') && (a[n1-1][m]=='X') && (a[n1-2][m]=='X') && (a[n1-3][m]=='X') && (a[n1-4][m]=='X') && ((a[n1-5][m] != 'O') || (a[n1+1][m] != 'O')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='X') {
        m1++;
    }
    m1--;
    if ((a[n][m1]=='X') && (a[n][m1+1]=='X') && (a[n][m1+2]=='X') && (a[n][m1+3]=='X') && (a[n][m1+4]=='X') && ((a[n][m1+5] != 'O') || (a[n][m1-1] != 'O')) ) return 1; else //Theo Hang doc
    if ((a[n][m1]=='X') && (a[n][m1-1]=='X') && (a[n][m1-2]=='X') && (a[n][m1-3]=='X') && (a[n][m1-4]=='X') && ((a[n][m1-5] != 'O') || (a[n][m1+1] != 'O')) ) return 1;
    //Theo duong cheo chinh
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='X') && (a[n1+1][m1+1]=='X') && (a[n1+2][m1+2]=='X') && (a[n1+3][m1+3]=='X') && (a[n1+4][m1+4]=='X') && ((a[n1+5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1; else //Theo Duong cheo chinh
    if ((a[n1][m1]=='X') && (a[n1-1][m1-1]=='X') && (a[n1-2][m1-2]=='X') && (a[n1-3][m1-3]=='X') && (a[n1-4][m1-4]=='X') && ((a[n1-5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1;
    //Theo duong cheo phu
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='X' && (a[n1+1][m1-1])=='X' && (a[n1+2][m1-2])=='X' && (a[n1+3][m1-3])=='X' && (a[n1+4][m1-4]=='X' ) && ((a[n1+5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1; else //Theo Duong cheo phu
    if ((a[n1][m1])=='X' && (a[n1-1][m1+1])=='X' && (a[n1-2][m1+2])=='X' && (a[n1-3][m1+3])=='X' && (a[n1-4][m1+4]=='X' ) && ((a[n1-5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1;
    //Khong chien thang
    return 0;
}
// Ai do chien thang
void ChienThang(){
    TextColor(12);
    if ((DKOChienThang()==1)){
        Goto(27,3); TextColor(11); cout<<"O chien thang. An R de choi lai. Q de thoat";
        key=getch();
        if (key=='r' || key=='R') ChoiLai();
        else
            if (key=='q' || key=='Q') Thoat(); else MoDau(50);
    }
    else
        if ((DKXChienThang()==1)){
            Goto(27,3);  TextColor(12); cout<<"X Chien Thang. An R de choi lai. Q de thoat";
            key=getch();
        if (key=='r' || key=='R') ChoiLai();
        else
            if (key=='q' || key=='Q') Thoat(); else MoDau(50);
        }
    TextColor(7);
}

void ChoiLai(){ //Khoi phuc nguyen hien trang
    GanDL();
    i=0; x=13; y=3;
    system("cls");
    ThongTinTranDau();
    VeKhung(0);
}

void TuongTacPhim(){
    key=getch();
    if (key=='a' || key=='A' || int (key==75)) AnSangTrai(); else
    if (key=='d' || key=='D' || int (key==77)) AnSangPhai(); else
    if (key=='w' || key=='W' || int (key==72)) AnLenTren(); else
    if (key=='s' || key=='S' || int (key==80)) AnXuongDuoi(); else
    if (key=='e' || key=='E' || key=='m' || key=='M') VeOX(n,m); else
    if (key=='r' || key=='R') ChoiLai();
    if (key=='b' || key=='B') MoDau(50);
}

main(){
    GanDL();
    MoDau(100);//=)) viet mot luc, xem lai cha dung den main() nua
}

void MoDau(short n){
    system("cls");
    TextColor(11);
    Goto(31,6);cout<<"1. Choi 2 nguoi."<<endl;
    Sleep(n); Goto(31,7);cout<<"2. Choi voi may."<<endl;
    Sleep(n); Goto(31,8);cout<<"3. Huong Dan."<<endl;
    Sleep(n); Goto(31,9);cout<<"4. Gioi thieu chuong trinh."<<endl;
    Sleep(n); Goto(31,10);cout<<"5. Thoat"<<endl;
    Sleep(n); Goto(31,11);cout<<"Menu: ";
    LuaChon=getch();
    cout<<char (LuaChon);
    Sleep(200);
    if (LuaChon== '1') Choi2Nguoi(); else
    if (LuaChon== '2') ChoiVoiMay(50); else
    if (LuaChon== '3') HuongDan(1); else
    if (LuaChon== '4') ThongTin(); else
    if (LuaChon== '5') Thoat(); else MoDau(0);
    TextColor(7);

}

void VeKhung(short n){
    short i;
    Goto(12,2);
    for (i=0; i<=65; i++){
        cout<<"*"; Sleep(n);
    }
    for (i=0; i<=22; i++) {
        Goto(12,i+2);
        Sleep(n);
        cout<<"*";
    }
    Goto(12,24);
    for (i=0; i<=65; i++) {
        cout<<"*"; Sleep(n);
    }

    for (i=0; i<=22; i++) {
        Goto(78,i+2);
        Sleep(n);
        cout<<"*";
    }
}

void BatDau(){
    system("cls");
    HuongDan(2);
    system("cls");
    VeKhung(3);
}

void Choi2Nguoi(){
    BatDau();
    x=n=13; y=m=3;
    i=0;
    do{
        ThongTinTranDau();
        ConTro(x,y);
        ChienThang();
        TuongTacPhim();
    } while (key != 'q' && key != 'Q');
    Thoat();
}

void ChoiVoiMay(short n){
    system("cls");
    Sleep(n);Goto(31,6);cout<<"Choi Voi May:";
    Sleep(n);Goto(31,7); cout<<"  1. De";
    Sleep(n);Goto(31,8);cout<<"  2. BT";
    Sleep(n);Goto(31,9);cout<<"  3. Kho";
    Sleep(n);Goto(31,10);cout<<"  4. Back";;
    Sleep(n);Goto(31,11); cout<<"menu: ";
    LuaChon=getch();
    cout<<char (LuaChon);
    Sleep(200);
    if (LuaChon=='1' || LuaChon =='2' || LuaChon=='3') ChoiVoiMayDangXayDung(); else
    if (LuaChon== '4') MoDau(50); else ChoiVoiMay(0);

}

void ChoiVoiMayDangXayDung(){
    TextColor(9);  cout<<endl<<endl<<"Chuc nang dang duoc xay dung! Ge tham";
    TextColor(12); cout<<" http://b2tind44.tk/";
    TextColor(9);  cout<<"de biet them chi tiet"<<endl;
    TextColor(7);
    system("pause");
    MoDau(50);
}

void HuongDan(short k){
    cout<<endl<<endl<<"                             HUONG DAN"<<endl<<endl;
    cout<<"Dung";
    TextColor(12); cout<<" phim di chuyen";
    TextColor(7);  cout<<" hoac";
    TextColor(12); cout<<" A,D,W,S";
    TextColor(7);  cout<<" de di chuyen. Dung phim";
    TextColor(12); cout<<" E";
    TextColor(7);  cout<<" va";
    TextColor(12); cout<<" M";
    TextColor(7);  cout<<" de choi."<<endl<<"Chuc vui!"<<endl;;
    system("pause");
    if (k==1) MoDau(0);
}

void ThongTin(){
    TextColor(11);
    cout<<endl;
    cout<<"Name: Caro"<<endl;
    cout<<"Ver: 1.1"<<endl;
    cout<<"Author: b2tind44.tk"<<endl;
    system("pause");
    TextColor(7);
    MoDau(0);
}

void Thoat(){
    TextColor(10);
    Goto(31,11); cout<<"Xin Chao! Hen Gap lai!";
    Goto(31,12); cout<<" http://b2tind44.tk/";
    getch();
    ExitProcess(0);
}
