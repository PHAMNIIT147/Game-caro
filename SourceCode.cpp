#include "Header.h"
short x, y, i, m, n, m1, n1, ChonLua;
char a[79][27], key;//a[hang ngang][hang doc]
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
void DanhOX(short x, short y)
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
void SangTrai()
{
    x -= 1;
    if (x < 16) x = 16;
}
void SangPhai()
{
    x += 1;
    if (x >= 75) x = 75;
}
void LenTren()
{
    y -= 1;
    if (y < 5) y = 5;
}
void XuongDuoi()
{
    y += 1;
    if (y >= 25) y = 25;
}
// vi tri con tro
void Contro(short x, short y)
{
    gotoxy(x, y);
    n = x; m = y;
}
void ThongTinTranDanh()
{
    txtColor(7);
    // thong tin toa do con tro 
    gotoxy(1, 1);
    printf("Location pointer(%d-%d) Weekly: %d\n +Q: Back to Home", x - 15, y - 5,i);
    // trang tri tuong tac danh
    printf(" +An P, O: De Danh");
    // Hien thi huong dan duy chuyen con tro.
    gotoxy(0, 4);
    txtColor(11);
    printf("PLAYER 1 DUNG\n A W D S\n");
    printf("PLAYER 2 DUNG\n  < ^ v >");
    txtColor(14);
    printf("\n\n>>P/S<<\nCHAN DAU\nCHAN DUOI\n");
    txtColor(12);
    printf("KHONG TINH\n\n");
    txtColor(9);
    printf("B: De Thoat\nR: Choi Lai\n");
    txtColor(10);
    printf("\nLUOT CUA: %c",OX(i));// dien O or X khi toi luot danh.
    // them 1 dong mau
}
// Xet khi O thang. Lay Cthuc code nguoi khac
short ConditionOWin()
{
    // xet hang ngang (xxxxxx , ooooo)
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
short ConditionXWin()
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
    if (a[n1][m1] == 'X' && a[n1 + 1][m1 + 1] == 'X' && a[n1 + 2][m1 + 2] == 'X' && a[n1 + 3][m1 + 3] == 'X' && a[n1 + 4][m1 + 4] == 'X' && (a[n1 + 5][m1 + 5] != 'O' || a[n1 - 1][m1 - 1] != 'O')) return 1;
    else if (a[n1][m1] == 'X' && a[n1 - 1][m1 - 1] == 'X' && a[n1 - 2][m1 - 2] == 'X' && a[n1 - 3][m1 - 3] == 'X' && a[n1 - 4][m1 - 4] == 'X' && (a[n1 - 5][m1 - 5] != 'O' || a[n1 + 1][m1 + 1] != 'O')) return 1;
    // thua
    return 0;
}
// Tim nguoi choi chien thang
void Win()
{
    txtColor(12);
    // Xet O chien thang
    if (ConditionOWin() == 1)
    {
        gotoxy(25, 15);
        txtColor(4);
        printf("O WIN ");
        gotoxy(25, 16);
        txtColor(2);
        printf("An R de choi lai. An Q de thoat!");
       /*thao tac tiep tuc or thoat
        dung man hinh Console*/
        key = _getch();
        if (key == 'r') Replay();
        else if (key == 'q') BackGoHome();
    }
    // xet X chien thang
    else
    {
        if (ConditionXWin() == 1)
        {
            gotoxy(25, 15);
            txtColor(3);
            printf("X WIN ");
            gotoxy(25, 16);
            txtColor(2);
            printf("An R de choi lai. An Q de thoat!");
            key = _getch();
            if (key == 'r' || key == 'R') Replay();
            else if (key == 'q' || key == 'Q') BackGoHome();
        }
    }
    txtColor(7);
}
// Choi lai game
void Replay()
{
    GanDL();
    system("cls");
    ThongTinTranDanh();
    txtColor(2); Khung(0); 
}
// cac phim dieu khien
void Control()
{
    key = _getch();
    if (key == 'a' || int(key == 75)) SangTrai();  // 75 : a
    else if (key == 'd' || int(key == 77)) SangPhai(); // 77 : d
    else if (key == 'w' || int(key == 72)) LenTren();// 72 : w
    else if (key == 's' || int(key == 80)) XuongDuoi();
    // thao tac danh O or X
    else if (key == 'p' || key == 'o') DanhOX(n, m);
    // thao tac End
    else if (key == 'r') Replay();
    else if (key == 'b') Home(50);
}
// thong bao trang chu
void Home(short n)
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
    gotoxy(44, 6); 
    txtColor(3); printf("x"); txtColor(4); printf("o"); txtColor(2);  printf(" GAME"); txtColor(4); printf(" C"); txtColor(5); printf("A"); txtColor(6); printf("R"); txtColor(12); printf("O"); txtColor(4); printf(" o"); txtColor(3); printf("x");
    gotoxy(48, 8); txtColor(7); printf("GAME OF");
    gotoxy(44, 9); txtColor(2); printf("PHAM THANH PHONG");
    gotoxy(38, 11); txtColor(3); printf("DEVELOPING IN VISUAL STUDIO"); 

    // Trang Chu
    txtColor(12);
    gotoxy(33, 14);
    printf(">> AN 1 DE CHOI 2 NGUOI <<");

    txtColor(13);
    Sleep(n);
    gotoxy(33, 15);
    printf(">> AN 2 DE HUONG DAN CACH CHOI <<");

    txtColor(14);
    Sleep(n);
    gotoxy(33, 16);
    printf(">> AN 3 DE INTRODUCE VERSION <<");
 
    txtColor(6);
    Sleep(n);
    gotoxy(33, 17);
    printf(">> AN 4 DE QUIT <<");

    txtColor(7);
    Sleep(n);
    gotoxy(33, 18);
    printf(">> AN 5 DE LIEN HE QTV <<");
    // lua chon menu
    txtColor(3);
    gotoxy(35, 19);
    printf("=> Ban chon [_]\b\b");
    ChonLua = _getch();
    printf("%c", char(ChonLua)); // in ra menu vua chon
    Sleep(300);
    if (ChonLua == '1') Player2();
    else if (ChonLua == '2') HuongDan(1);
    else if (ChonLua == '3') Detail();
    else if (ChonLua == '4') Back();
    else if (ChonLua == '5') Contract();// lien he 
    else Home(0);
    txtColor(7);
}
void Khung(short n)
{
    //gotoxy(hang ngang , dung);
    // Sleep(time) thoi gian tre.
    short i;
    //txtColor(5);
    gotoxy(14, 4);
    printf("%c", 218);
    //ve hang ngang
    gotoxy(15, 4);
    for (i = 0; i <= 60; i++)
    {
        printf("%c", 196);
        Sleep(20);// tao hieu ung ve mang hinh. Sleep(n);
    }
    // goc nhon tren phai
    gotoxy(76, 4);
    printf("%c", 191);
    // cot dung ben phai
    for (i = 0; i <= 20; i++)
    {
        gotoxy(76, i + 5);
        printf("%c", 179);
        Sleep(20);
    }
    // goc nhon duoi phai
    gotoxy(76, 26);
    printf("%c", 217);
    //ve hang ngang ben duoi
    for (i = 0; i <= 60; i++)
    {
        gotoxy(75 - i, 26);
        printf("%c", 196);
        Sleep(20);
    }
    // goc nhon duoi trai
    gotoxy(14, 26);
    printf("%c", 192);
    //ve cot dung ben trai
    for (i = 0; i <= 20; i++)
    {
        gotoxy(14, 25 - i);
        printf("%c",179);
        Sleep(20);
    }
}
// thao tac ve khung truy suat huong dan
void Start()
{
    system("cls");
    txtColor(6);
    Khung(3);
}
// An vao choi 2 nguoi
void Player2()
{
    Start();
    x = n = 15; y = m = 5;
    do
    {
        ThongTinTranDanh();
        // vi tri con tro se nam
        Contro(x, y);
        Win();
        Control();
    } while (key != 'q');
    BackGoHome();
}
void HuongDan(short n)
{
    system("cls");
    gotoxy(40, 4);
    printf("HUONG DAN"); 
    gotoxy(3, 6); txtColor(7); printf("- DUNG"); txtColor(12); printf(" [Phim di chuyen]"); txtColor(7); printf(" hoac"); txtColor(12); printf(" [A W D S]"); txtColor(7); printf(" de di chuyen");
    gotoxy(3, 7); txtColor(6); printf("- P"); txtColor(7); printf(" va"); txtColor(6); printf(" O"); txtColor(7); printf(" de danh"); txtColor(4); printf(" O"); txtColor(3); printf("X");
    gotoxy(3, 8); txtColor(7); printf("- An"); txtColor(2); printf(" R"); txtColor(7); printf(" de choi lai"); txtColor(7); printf(". An"); txtColor(2); printf(" Q"); txtColor(7); printf(" de tro ve Trang Chu");
    gotoxy(3, 9); txtColor(7); printf("- Weekly chan"); txtColor(3); printf(" X"); txtColor(7); printf(" danh"); txtColor(7); printf(". Weekly le"); txtColor(4); printf(" O"); txtColor(7); printf(" danh.");
    gotoxy(3, 10); txtColor(13); printf("***Thong tin chi tiet lien he:"); txtColor(2); printf(" phongpham663@gmail.com");
    gotoxy(40, 12); txtColor(3); printf(">> CHUC CAC BAN CHOI GAME VUI VE! <<");
    gotoxy(3, 17); txtColor(7); system("pause");
    if (n == 1) { txtColor(6); Home(0); }
}
// thong tin phien ban hay nguoi thiet ke
void Detail()
{
    system("cls");
    gotoxy(25, 3);
    printf("DETAIL");
    gotoxy(15, 5); txtColor(1); printf("Ten tro choi : CO CARO \n");
    gotoxy(15,6); txtColor(14); printf("Version: 1.1 \n");
    gotoxy(15, 7); txtColor(4);  printf("Thiet ke (Author): PHAM THANH PHONG (NIIT)");
    gotoxy(5, 9); txtColor(7); system("pause");
    txtColor(14);
    Home(0);
}
// thoat ra khoi tro choi
void BackGoHome()
{
    txtColor(10);
    gotoxy(31, 11); printf("CHAO BAN NHE! SEE YOU AGIAN^^");
    gotoxy(31, 12); printf("PHAM THANH PHONG");
    // lam trong cac thanh phan
    _getch();
    // thoat ra khoi man hinh Console
    txtColor(4);
    Home(0);
}
// thoat tro choi
void Back()
{
    system("cls");
    gotoxy(34, 12); txtColor(10); printf("CHAO BAN NHE! SEE YOU AGIAN ^^");
    gotoxy(34, 13); txtColor(7); printf("THIET KE BOI PHAM THANH PHONG");
    Sleep(2000);
    _getch();
    // lenh thoat chuong trinh
    ExitProcess(0);
}
 // lien he nguoi thiet ke
void Contract()
{
    system("cls");
    gotoxy(35, 2); txtColor(4); printf("THIET KE TRO CHOI");
    gotoxy(30, 4); txtColor(12); printf(" >>facebook: PHONG PHAM");
    gotoxy(30, 5); txtColor(2); printf(" >>Phone number: (+84)378053305");
    gotoxy(30, 6); txtColor(3); printf(" >>Instagram: _pham_thanh_phong_");
    gotoxy(5, 8); txtColor(7);  system("pause");
    txtColor(2);
    Home(0);
}