
/*In the name of God
*** Towers of Hanoi ***
By Mobin Lotfizadeh Dehkordi
2017 December 6th*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int nsource,ndest,ntemp;
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ClearConsoleToColors(int ForgC, int BackC)
 {
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coord = {0, 0};
 DWORD count;
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void Hi()
{
    int i;
    char ch=219;
    for (i=5;i<25;i++)
    {
        gotoxy(20,i);
        printf("%c" ,ch);
    }
    for (i=5;i<25;i++)
    {
        gotoxy(21,i);
        printf("%c" ,ch);
    }
    for (i=20;i<50;i++)
    {
        gotoxy(i,14);
        printf("%c" ,ch);
    }
    for (i=5;i<25;i++)
    {
        gotoxy(50,i);
        printf("%c" ,ch);
    }
    for (i=5;i<25;i++)
    {
        gotoxy(49,i);
        printf("%c" ,ch);
    }
    for (i=75;i<95;i++)
    {
        gotoxy(i,5);
        printf("%c" ,ch);
    }
    for (i=6;i<24;i++)
    {
        gotoxy(84,i);
        printf("%c" ,ch);
    }
    for (i=6;i<24;i++)
    {
        gotoxy(85,i);
        printf("%c" ,ch);
    }
    for (i=75;i<95;i++)
    {
        gotoxy(i,24);
        printf("%c" ,ch);
    }
    Sleep(1500);

}
void drawAnima(int n)
{
    int i,j,x1=50-n,y1=24;
    for (j=n;j>0;j--)
    {
        drawDisk(j,x1,y1,'C');
        y1+=-1;
        x1+=1;
    }
}
void drawFirst(int n)
{
    int i,j,x1=20-n,y1=24;
    for (j=n;j>0;j--)
    {
        drawDisk(j,x1,y1,'C');
        y1+=-1;
        x1+=1;
    }
}
void drawRods()
{
    int i;
    char c=186,e=223;
    for (i=10;i<25;i++)
    {
        gotoxy(20,i);
        printf("%c", c);
    }
    for (i=10;i<25;i++)
    {
        gotoxy(50,i);
        printf("%c", c);
    }
    for (i=10;i<25;i++)
    {
        gotoxy(80,i);
        printf("%c", c);
    }
    for (i=7;i<95;i++)
    {
        gotoxy(i,25);
        printf("%c", e);
    }
}
void drawDisk(int n,int x, int y, char CorD)
{
int i;
char ch=219;
if(CorD=='D')ch=' ';
gotoxy(x,y);
for(i=0;i<2*n+1;i++)
    printf("%c" ,ch);
}
void moveUp(int x1,int y1,int x2,int y2,int n)
{

    int i;
    for (i=y1;i>=y2;i--)
    {
        drawDisk(n,x1,i,'C');
        Sleep(80);
        drawDisk(n,x1,i,'D');
        gotoxy(x1+n,i);
        printf("%c" ,186);
    }
}
void moveDown(int x1,int y1,int x2,int y2,int n)
{

    int i;
    for (i=y1+1;i<=y2;i++)
    {
        drawDisk(n,x1,i,'C');
        Sleep(80);
        drawDisk(n,x1,i,'D');
        gotoxy(x1+n,i);
        printf("%c" ,186);
    }
    drawDisk(n,x1,i,'C');

}
void moveRight(int x1,int y1,int x2,int y2,int n)
{

    int i;
    for (i=x1;i<=x2;i++)
    {
        drawDisk(n,i,y1,'C');
        Sleep(80);
        drawDisk(n,i,y1,'D');
    }
}
void moveLeft(int x1,int y1,int x2,int y2,int n)
{

    int i;
    for (i=x1;i>=x2;i--)
    {
        drawDisk(n,i,y1,'C');
        Sleep(80);
        drawDisk(n,i,y1,'D');
    }
}
void moveDisk(int n, int source, int dest)
{
    if(source==1 && dest==2)
    {
        moveUp(20-n,25-nsource,20-n,9,n);
        moveRight(20-n,9,50-n,9,n);
        moveDown(50-n,9,50-n,23-ntemp,n);
    }
    if(source==2 && dest==1)
    {
        moveUp(50-n,25-ntemp,50-n,9,n);
        moveLeft(50-n,9,20-n,9,n);
        moveDown(20-n,9,20-n,23-nsource,n);
    }
    if(source==1 && dest==3)
    {
        moveUp(20-n,25-nsource,20-n,9,n);
        moveRight(20-n,9,80-n,9,n);
        moveDown(80-n,9,80-n,23-ndest,n);
    }
    if(source==3 && dest==1)
    {
        moveUp(80-n,25-ndest,80-n,9,n);
        moveLeft(80-n,9,20-n,9,n);
        moveDown(20-n,9,20-n,23-nsource,n);
    }
    if(source==2 && dest==3)
    {
        moveUp(50-n,25-ntemp,50-n,9,n);
        moveRight(50-n,9,80-n,9,n);
        moveDown(80-n,9,80-n,23-ndest,n);
    }
    if(source==3 && dest==2)
    {
        moveUp(80-n,25-ndest,80-n,9,n);
        moveLeft(80-n,9,50-n,9,n);
        moveDown(50-n,9,50-n,23-ntemp,n);
    }
}
void hanoi( int n, int source, int dest, int temp)
{
if (n>0) {
hanoi(n-1, source, temp, dest);
if(source==1 && dest==2)
    {
        moveDisk(n,1,2);
        nsource--;
        ntemp++;
    }
if(source==2 && dest==1)
    {
        moveDisk(n,2,1);
        nsource++;
        ntemp--;
    }
if(source==1 && dest==3)
    {
        moveDisk(n,1,3);
        nsource--;
        ndest++;
    }
if(source==3 && dest==1)
    {
        moveDisk(n,3,1);
        nsource++;
        ndest--;
    }
if(source==2 && dest==3)
    {
        moveDisk(n,2,3);
        ntemp--;
        ndest++;
    }
if(source==3 && dest==2)
    {
        moveDisk(n,3,2);
        ndest--;
        ntemp++;
    }
hanoi(n-1, temp, dest, source);
}
return;
}

main()
{
hidecursor();
int n,i;
ClearConsoleToColors(4,7);
Hi();
system("cls");
for (i=1;i<=15;i++)
{
    gotoxy(35,6);
    printf("*** WELCOME TO TOWERS OF HANOI ***\n\n");
    drawRods();
    drawAnima(i);
    Sleep(50);
}
system("cls");
for (i=15;i>=1;i--)
{
    gotoxy(35,6);
    printf("*** WELCOME TO TOWERS OF HANOI ***\n\n");
    drawRods();
    drawAnima(i);
    Sleep(50);
    system("cls");
}
system("cls");
gotoxy(38,4);
printf("*** WELCOME TO TOWERS OF HANOI ***");
gotoxy(38,6);
printf("Please Enter the number of disks: " ) ;
scanf("%d", &n);
gotoxy(38,6);
printf("   Playing Hanoi for %d disks ...      " ,n) ;
nsource=n;
ndest=0;
ntemp=0;
drawRods();
drawFirst(n);
hanoi(n,1,3,2);
gotoxy(38,6);
printf("             DONE !!!               ");
gotoxy(20,25);
}
