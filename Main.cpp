#include "Header.h"

int main()
{
  
    GanDL();
    Home(100);

    //thong tin nguoi thiet ke 
    gotoxy(25, 27);
    txtColor(5);
    printf(">>> THIET KE:");
    gotoxy(39, 27);
    txtColor(3);
    printf("PHAM THANH PHONG(NIIT) <<<");
    txtColor(7);
    gotoxy(2, 28);
    system("pause");
    return 0;
}
