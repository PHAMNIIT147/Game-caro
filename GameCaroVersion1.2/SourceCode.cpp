#include "Header.h"
short x, y, i, m, n, m1, n1, chonLua, dem1, dem2;
char a[79][27], key, ten1[20], ten2[20];//a[hang ngang][hang doc]
// trang tri
void GanDL()
{
    for (int i = 1; i <= 79; i++)
        for (int j = 1; j <= 27; j++)
            a[i][j] = ' ';
}
// duy chuyen con tro.
void gotoxy(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// xac dinh mau cua chu.
void txtColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//Chia luot.
short Chan(int i)
{
    if (i % 2 == 0)  return 1;
    else return 0;
}
// danh O va X.
char OX(short i)
{
    if (Chan(i) == 1) return 'X'; // danh x.
    else return 'O'; // danh o.
}
// danh O X theo luot
void danhOX(short x, short y)
{
    if (a[x][y] != 'X' && a[x][y] != 'O')
    {
        if (Chan(i) == 1) txtColor(11);
        else txtColor(12);
        a[x][y] = OX(i);// xet chan hay le de hien thi vao bang
        printf("%c", a[x][y]);
        i += 1;
    }
    else a[n][m];
    txtColor(7);
}
// duy chuyen
// dieu kien de con tro nam trong khung
void sangTrai()
{
    x -= 1;
    if (x < 15) x = 15;
}
void sangPhai()
{
    x += 1;
    if (x >= 75) x = 75;
}
void lenTren()
{
    y -= 1;
    if (y < 5) y = 5;
}
void xuongDuoi()
{
    y += 1;
    if (y >= 25) y = 25;
}
// vi tri con tro
void conTro(short x, short y)
{
    gotoxy(x, y);
    n = x; m = y;
}
void thongTin()
{
    txtColor(7);
    // thong tin toa do con tro 
    gotoxy(1, 1);
    printf("Location pointer(%d-%d) Weekly: %d", x - 15, y - 5,i);
    // trang tri tuong tac danh
    printf(" +An X, O: De Danh");
    // Hien thi huong dan duy chuyen con tro.
    gotoxy(0, 10);  txtColor(11); printf("PLAYER 1 DUNG\n A W D S\n"); txtColor(11); printf("PLAYER 2 DUNG\n  < ^ v >");
    gotoxy(0, 14); txtColor(9); printf("\n*B: De Thoat\n*R: Choi Lai\n");
    gotoxy(40, 3); txtColor(10); printf("LUOT CUA: %c", OX(i));// dien O or X khi toi luot danh.
    gotoxy(35, 27); txtColor(4); printf("DEV: PHAM THANH PHONG");
    gotoxy(83, 15); txtColor(2); printf("R de choi lai"); txtColor(12); printf(" -- B de thoat!");
    gotoxy(84, 21); txtColor(4); printf("Player O"); gotoxy(100, 21); txtColor(3); printf("Player X");
    /*dien thong tin vao khungDetail*/
    gotoxy(91, 19); txtColor(7);printf("xo TI SO ox");
    gotoxy(86, 23); txtColor(7); printf("%d/5", dem1);
    gotoxy(103, 23); txtColor(7); printf("%d/5", dem2);
}
// Xet khi O thang. Lay Cthuc code nguoi khac
short oWin()
{
    // xet hang ngang
    m1 = m; n1 = n;
    while (a[n1][m] == 'O')
        n1++;
    n1--; // chuyen con tro ra dau hang de xet , neu o khong nhap dau hang se khong xet
    if (a[n1][m] == 'O' && a[n1 + 1][m] == 'O' && a[n1 + 2][m] == 'O' && a[n1 + 3][m] == 'O' && a[n1 + 4][m] == 'O' && (a[n1 + 5][m] != 'X' || a[n1 - 1][m] != 'X')) return 1;
    else if (a[n1][m] == 'O' && a[n1 - 1][m] == 'O' && a[n1 - 2][m] == 'O' && a[n1 - 3][m] == 'O' && a[n1 - 4][m] == 'O' && (a[n1 - 5][m] != 'X' || a[n1 + 1][m] != 'X')) return 1;
    // xet hang doc
    while (a[n][m1] == 'O')
        m1++;
    m1--;
    if (a[n][m1] == 'O' && a[n][m1 + 1] == 'O' && a[n][m1 + 2] == 'O' && a[n][m1 + 3] == 'O' && a[n][m1 + 4] == 'O' && (a[n][m1 + 5] != 'X' || a[n][m1 - 1] != 'X')) return 1;
    else if (a[n][m1] == 'O' && a[n][m1 - 1] == 'O' && a[n][m1 - 2] == 'O' && a[n][m1 - 3] == 'O' && a[n][m1 - 4] == 'O' && (a[n][m1 - 5] != 'X' || a[n][m1 + 1] != 'X')) return 1;
    // theo duong cheo chinh
    while (a[n1][m1] == 'O')
        m1++, n1++;
    m1--, n1--;
    if (a[n1][m1] == 'O' && a[n1 + 1][m1 + 1] && a[n1 + 2][m1 + 2] == 'O' && a[n1 + 3][m1 + 3] == 'O' && a[n1 + 4][m1 + 4] == 'O' && (a[n1 + 5][m1 + 5] != 'X' || a[n1 - 1][m1 - 1] != 'X')) return 1;
    else if (a[n1][m1] == 'O' && a[n1 - 1][m1 - 1] && a[n1 + 2][m1 + 2] == 'O' && a[n1 + 3][m1 + 3] == 'O' && a[n1 + 4][m1 + 4] == 'O' && (a[n1 - 5][m1 - 5] != 'X' || a[n1 + 1][m1 + 1] != 'X')) return 1;
   // theo duong cheo phu
    while (a[n1][m1] == 'O')
        n1++; m1--;
    n1--; m1++;
    if (a[n1][m1] == 'O' && a[n1 + 1][m1 - 1] == 'O' && a[n1 + 2][m1 - 2] == 'O'&& a[n1 + 3][m1 - 3] == 'O' && a[n1 + 4][m1 - 4] == 'O' && (a[n1 + 5][m1 - 5] != 'X' || a[n1 - 1][m1 + 1] != 'X')) return 1;
    else if (a[n1][m1] == 'O' && a[n1 - 1][m1 + 1] == 'O' && a[n1 - 2][m1 + 2] == 'O' && a[n1 - 3][m1 + 3] == 'O' && a[n1 - 4][m1 + 4] == 'O' && (a[n1 - 5][m1 + 5] != 'X' || a[n1 + 1][m1 - 1] != 'X')) return 1;
    // thua
    return 0;
}
short xWin()
{
    // theo hang ngang  
    m1 = m; n1 = n;
    while (a[n1][m] == 'X')
        n1++;
    n1--;
    if (a[n1][m] == 'X' && a[n1 + 1][m] == 'X' && a[n1 + 2][m] == 'X' && a[n1 + 3][m] == 'X' && a[n1 + 4][m] == 'X' && (a[n1 + 5][m] != 'O' && a[n1 - 1][m] != 'O')) return 1;
    else if (a[n1][m] == 'X' && a[n1 - 1][m] == 'X' && a[n1 - 2][m] == 'X' && a[n1 - 3][m] == 'X' && a[n1 - 4][m] == 'X' && (a[n1 - 5][m] != 'O' && a[n1 + 1][m] != 'O')) return 1;
    // xet hang doc
    while (a[n][m1] == 'X')
        m1++;
    m1--;
    if (a[n][m1] == 'X' && a[n1][m1 + 1] == 'X' && a[n][m1 + 2] == 'X' && a[n][m1 + 3] == 'X' && a[n][m1 + 4] == 'X' && (a[n][m1 + 5] != 'O' || a[n][m1 - 1] != 'O')) return 1;
    else if (a[n][m1] == 'X' && a[n1][m1 - 1] == 'X' && a[n][m1 - 2] == 'X' && a[n][m1 - 3] == 'X'&& a[n][m1 - 4] == 'X' && (a[n][m1 - 5] != 'O' || a[n][m1 + 1] != 'O')) return 1;
    // xet duong cheo chinh
    while (a[n1][m1] == 'X')
        n1++; m1++;
    n1--; m1--;
    if (a[n1][m1] == 'X' && a[n1 + 1][m1 + 1] == 'X' && a[n1 + 2][m1 + 2] == 'X' && a[n1 + 3][m1 + 3] == 'X' && a[n1 + 4][m1 + 4] == 'X' && (a[n1 + 5][m1 + 5] != 'O' || a[n1 - 1][m1 - 1] != 'O')) return 1;
    else if (a[n1][m1] == 'X' && a[n1 - 1][m1 - 1] == 'X' && a[n1 - 2][m1 - 2] == 'X' && a[n1 - 3][m1 - 3] == 'X'&& a[n1 - 4][m1 - 4] == 'X' && (a[n1 - 5][m1 - 5] != 'O' || a[n1 + 1][m1 + 1] != 'O')) return 1;
    //xet duong cheo phu
    while (a[n1][m1] == 'X')
        n1++; m1--;
    n1--; m1++;
    if (a[n1][m1] == 'X' && a[n1 + 1][m1 - 1] == 'X' && a[n1 + 2][m1 - 2] == 'X' && a[n1 + 3][m1 - 3] == 'X' && a[n1 + 4][m1 - 4] == 'X' && (a[n1 - 5][m1 + 5] != 'O' || a[n1 + 1][m1 - 1] != 'O')) return 1;
    else if (a[n1][m1] == 'X' && a[n1 - 1][m1 + 1] == 'X' && a[n1 - 2][m1 + 2] == 'X' && a[n1 - 3][m1 + 3] == 'X' && a[n1 - 4][m1 + 4] == 'X' && (a[n1 + 5][m1 - 5] != 'O' || a[n1 - 1][m1 + 1] != 'O')) return 1;
    // thua
    return 0;
}
/*tim nguoi chien thang*/
void win()
{
    txtColor(12);
    if (oWin() == 1)
    {
        gotoxy(86, 23); txtColor(7); printf("%d", dem1++);
        gotoxy(83, 10); txtColor(4); printf("Player O WIN!,R de choi lai");
        if (dem1 == 5)
        {
            system("cls");
            gotoxy(25, 9); txtColor(4); outName1(ten1);
            gotoxy(20, 10); txtColor(7); printf("LA NGUOI CHIEN THANG");
            Sleep(3000);
            back();
        }
       /*thao tac tiep tuc or thoat dung man hinh Console*/
        key = _getch();
        if (key == 'r' || key == 'R') replay();
        else if (key == 'q' || key == 'Q') backHome();
    }
    else
    {
        if (xWin() == 1)
        {
            gotoxy(103, 23); txtColor(7); printf("%d", dem2++);
            gotoxy(83, 10); txtColor(2); printf("Player X WIN!,R de choi lai");
            if (dem2 == 5)
            {
                system("cls");
                gotoxy(25, 9); txtColor(3); outName2(ten2);
                gotoxy(20, 10); txtColor(7); printf("LA NGUOI CHIEN THANG");
                Sleep(3000);
                back();
            }
            key = _getch();
            if (key == 'r' || key == 'R') replay();
            else if (key == 'b' || key == 'B') backHome();
        }
    }
    txtColor(7);
}
// Choi lai game
void replay()
{
    if (oWin() == 1) {
        system("cls");
        GanDL();
        khungDetail();
        thongTin();
        txtColor(dem1); khung(); conTro(x, y);
    }
    else if (xWin() == 1) {
        system("cls");
        GanDL();
        khungDetail();
        thongTin();
        txtColor(dem2); khung(); conTro(x, y);
    }
    else { txtColor(7); system("cls"); GanDL(); khungDetail(); thongTin(); khung(); conTro(x, y); }

}
// cac phim dieu khien
void control()
{
    key = _getch();
    if (key == 'a' || int(key == 75)) sangTrai();  // 75 : a
    else if (key == 'd' || key == 'D' || int(key == 77)) sangPhai(); // 77 : d
    else if (key == 'w' || key == 'W' || int(key == 72)) lenTren();// 72 : w
    else if (key == 's' || key == 'S' || int(key == 80)) xuongDuoi();
    // thao tac danh O or X
    else if (key == 'x' || key == 'o' || key == 'O' || key == 'X') danhOX(n, m);
    // thao tac End
    else if (key == 'r' || key == 'R') replay();
    else if (key == 'b' || key == 'B') home(50);
}
// thong bao trang chu
void home(short n)
{
    system("cls");
    // Bang poster
    //goc nhon tren trai
    gotoxy(25, 5);
    printf("%c", 218);
    // hang ngang tren
    for (int i = 0; i <= 50; i++)
    {
        gotoxy(26 + i, 5);
        printf("%c", 196);
    }
    // goc nhon phai
    gotoxy(77, 5);
    printf("%c", 191);
    // cot phai 
    for (int i = 0; i <= 5; i++)
    {
        gotoxy(77, 6+ i);
        printf("%c", 179);
    }
    // goc nhon duoi phai
    gotoxy(77, 12);
    printf("%c", 217);
    // hang ngang duoi
    for (int i = 0; i <= 50; i++)
    {
        gotoxy(76 - i, 12);
        printf("%c", 196);
    }
    // goc nhon trai
    gotoxy(25, 12);
    printf("%c", 192);
    //cot trai
    for (int i = 0; i <= 5; i++)
    {
        gotoxy(25, 6 + i);
        printf("%c", 179);
    }

    /* khi title ben trong*/
    // trang tri game caro
    gotoxy(44, 6); txtColor(3); printf("x"); txtColor(4); printf("o"); txtColor(2);  printf(" GAME"); txtColor(4); printf(" C"); txtColor(5); printf("A"); txtColor(6); printf("R"); txtColor(12); printf("O"); txtColor(4); printf(" o"); txtColor(3); printf("x");
    gotoxy(48, 8); txtColor(7); printf("GAME OF");
    /*hang ngang*/
    for (int i = 26; i < 77; i++)
    {
        gotoxy(i, 9); txtColor(7); printf("%c", 196);
    }
    gotoxy(28, 11); txtColor(2); printf("PHAM THANH PHONG "); txtColor(3); printf("-- DEVELOPING IN VISUAL STUDIO"); 
    /*trang chu*/
    txtColor(12); gotoxy(33, 14); printf(">>  1 DE CHOI 2 NGUOI <<");
    txtColor(13); Sleep(n); gotoxy(33, 15); printf(">>  2 HUONG DAN CACH CHOI <<");
    txtColor(14); Sleep(n); gotoxy(33, 16); printf(">>  3 INTRODUCE VERSION <<");
    txtColor(6); Sleep(n); gotoxy(33, 17); printf(">>  4 LIEN HE LAP TRINH VIEN <<");
    txtColor(7); Sleep(n); gotoxy(33, 18); printf(">>  5 THOAT <<");
    /*vung nhap*/
    txtColor(3); gotoxy(35, 19);  printf("=> Ban chon [_]\b\b");
    /*chon number*/
    chonLua = _getch();
    printf("%c", char(chonLua));
    Sleep(300);
    if (chonLua == '1')
    {
        intName1(ten1); intName2(ten2);
        player2();
    }
    else if (chonLua == '2') huongDan(1);
    else if (chonLua == '3') version();
    else if (chonLua == '4') contract();
    else if (chonLua == '5') back();// lien he 
    else home(0);
    txtColor(7);
}
void khung()
{
    //gotoxy(hang ngang , dung);
    // Sleep(time) thoi gian tre.
    //txtColor(5);
    gotoxy(14, 4);
    printf("%c", 218);
    //ve hang ngang
    gotoxy(15, 4);
    for (short i = 0; i <= 60; i++)
    {
        printf("%c", 196);
        Sleep(5);// tao hieu ung ve mang hinh. Sleep(n);
    }
    // goc nhon tren phai
    gotoxy(76, 4);
    printf("%c", 191);
    // cot dung ben phai
    for (i = 0; i <= 20; i++)
    {
        gotoxy(76, i + 5);
        printf("%c", 179);
        Sleep(10);
    }
    // goc nhon duoi phai
    gotoxy(76, 26);
    printf("%c", 217);
    //ve hang ngang ben duoi
    for (short i = 0; i <= 60; i++)
    {
        gotoxy(75 - i, 26);
        printf("%c", 196);
        Sleep(5);
    }
    // goc nhon duoi trai
    gotoxy(14, 26);
    printf("%c", 192);
    //ve cot dung ben trai
    for (short i = 0; i <= 20; i++)
    {
        gotoxy(14, 25 - i);
        printf("%c",179);
        Sleep(5);
    }
    khungDetail();
}
void khungDetail()
{
    /*cot dung 1*/
    txtColor(2);
    for (int i = 0; i < 28; i++)
    {
        gotoxy(78, i); printf("%c", 186);
    }
    /*nga giao*/
    gotoxy(78, 28); printf("%c",202);
    /*hang ngang <-*/
    for (int i = 77; i > 0; i--)
    {
        gotoxy(i, 28); printf("%c", 205);
    }
    /*hang ngang ->*/
    for (int i = 0; i < 35; i++)
    {
        gotoxy(79 + i, 28); printf("%c", 205);
    }
    /*nga giao*/
    gotoxy(113, 28); printf("%c", 188);
    /*cot dung 2*/
    for (int i = 27; i > -1; i--)
    {
        gotoxy(113, i); printf("%c", 186);
    }
    /***********************/
    gotoxy(96, 28); printf("%c", 202);
    /*ben trong khung*/
    for (int i = 27; i > 20; i--)
    {
        gotoxy(96, i); printf("%c", 186);
    }
    gotoxy(96, 20); printf("%c", 203);
    for (int i = 95; i > 78; i--)
    {
        gotoxy(i, 20); printf("%c", 205);
    }
    gotoxy(78, 20);  printf("%c", 204);
    for (int i = 0; i < 17; i++)
    {
        gotoxy(97 + i, 20); printf("%c", 205);
    }
    gotoxy(113, 20); printf("%c", 185);
    /*******/
    gotoxy(78, 18); printf("%c", 204);
    for (int i = 0; i < 35; i++)
    {
        gotoxy(79 + i, 18);  printf("%c", 205);
    }
    gotoxy(113, 18); printf("%c", 185);
    /*******/
    gotoxy(78, 6);  printf("%c", 204);
    for (int i = 0; i < 35; i++)
    {
        gotoxy(79 + i, 6); printf("%c", 205);
    }
    gotoxy(113, 6); printf("%c", 185);
   // conTro(x, y);
}
// thao tac ve khung truy suat huong dan
void start()
{
    system("cls");
    txtColor(6);
    khung();
}
// An vao choi 2 nguoi
void player2()
{
    start();
    /*vi tri con tro se nam*/
    x = n = 45; y = m = 15;
    do
    {
        thongTin();
        conTro(x, y);
        // vi tri con tro se nam
        win();
        control();
    } while (key != 'b' || key != 'B');
    backHome();
}
void huongDan(short n)
{
    system("cls");
    gotoxy(40, 4);
    printf("HUONG DAN"); 
    gotoxy(3, 6); txtColor(7); printf("- DUNG"); txtColor(12); printf(" [Phim di chuyen]"); txtColor(7); printf(" hoac"); txtColor(12); printf(" [A W D S]"); txtColor(7); printf(" de di chuyen");
    gotoxy(3, 7); txtColor(6); printf("- P"); txtColor(7); printf(" va"); txtColor(6); printf(" O"); txtColor(7); printf(" de danh"); txtColor(4); printf(" O"); txtColor(3); printf("X");
    gotoxy(3, 8); txtColor(7); printf("- An"); txtColor(2); printf(" R"); txtColor(7); printf(" de choi lai"); txtColor(7); printf(". An"); txtColor(2); printf(" Q"); txtColor(7); printf(" de tro ve Trang Chu");
    gotoxy(3, 9); txtColor(7); printf("- Weekly chan"); txtColor(3); printf(" X"); txtColor(7); printf(" danh"); txtColor(7); printf(". Weekly le"); txtColor(4); printf(" O"); txtColor(7); printf(" danh.");
    gotoxy(3, 11); printf("Neu ti so 5 diem toi truoc thi nguoi do se thang");
    gotoxy(3, 10); txtColor(13); printf("***Thong tin chi tiet lien he:"); txtColor(2); printf(" phongpham663@gmail.com");
    gotoxy(40, 12); txtColor(3); printf(">> CHUC CAC BAN CHOI GAME VUI VE! <<");
    gotoxy(3, 17); txtColor(7); system("pause");
    if (n == 1) { txtColor(6); home(0); }
}
// thong tin phien ban hay nguoi thiet ke
void version()
{
    system("cls");
    gotoxy(25, 3);
    printf("DETAIL");
    gotoxy(15, 5); txtColor(1); printf("Ten tro choi: CO CARO \n");
    gotoxy(15,6); txtColor(14); printf("Version: 1.3");
    gotoxy(15, 7); txtColor(4);  printf("Thiet ke (Author): PHAM THANH PHONG (NIIT)");
    gotoxy(5, 9); txtColor(7); system("pause");
    txtColor(14);
    home(0);
}
// thoat ra khoi tro choi
void backHome()
{
    txtColor(10);
    gotoxy(31, 11); printf("CHAO BAN NHE! SEE YOU AGIAN^^");
    gotoxy(31, 12); printf("PHAM THANH PHONG");
    // lam trong cac thanh phan
    _getch();
    // thoat ra khoi man hinh Console
    txtColor(4);
    home(0);
}
// thoat tro choi
void back()
{
    system("cls");
    gotoxy(34, 12); txtColor(10); printf("CHAO BAN NHE! SEE YOU AGIAN ^^");
    gotoxy(34, 13); txtColor(7); printf("THIET KE BOI PHAM THANH PHONG");
    Sleep(2000);
    _getch();
    // lenh thoat chuong trinh
    ExitProcess(0);
}
void contract()
{
    system("cls");
    gotoxy(35, 2); txtColor(4); printf("THIET KE TRO CHOI");
    gotoxy(30, 4); txtColor(12); printf(" >>facebook: PHONG PHAM");
    gotoxy(30, 5); txtColor(2); printf(" >>Phone number: (+84)378053305");
    gotoxy(30, 6); txtColor(3); printf(" >>Instagram: _pham_thanh_phong_");
    gotoxy(5, 8); txtColor(7);  system("pause");
    txtColor(2);
    home(0);
}
/* Hien thi ten nguoi choi*/
void intName1(char ten1[])
{
    system("cls");
    gotoxy(40, 13); txtColor(4); printf("User Name X: \a"); txtColor(7); scanf("%s", ten1);
}
void outName1(char ten1[])
{
    _strupr(ten1);
    printf("%s", ten1);
}
void intName2(char ten2[])
{
    gotoxy(40, 15); txtColor(2); printf("User Name O: \a"); txtColor(7); scanf("%s", ten2);
}
void outName2(char ten2[])
{
    _strupr(ten2);
    printf("%s", ten2);
}
