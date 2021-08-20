
Lastupdate  2017.11.30 by clccclcc

테스터 플랫폼: Visual studio 2017, Codingground (클라우드), Linux(Centos6, Ubuntu 16.04)

----------------------------------
0. 컴파일 
----------------------------------

0. mtg.h  에서 아래 3개의 모드 중 한가지만 선택하고 나머지는 주석 처리가 필요 

 //#define _LINUX_    //linux curses mode (추가 라이브러리(curses) 설치 필요)
 #define _LINUX1_     //linux default mode (추가 라이브러리 없음)
 //#define _MSWINDOWS_  //ms-windows mode 


1.1 linux 
$ gcc -o game *.c  

1.2 linux (curses lib 사용)
//curses lib 설치 
$ sudo apt-get install ncurses-dev   <= ubuntu
$ sudo yum install ncurses-deve      <= centos 
//컴파일 
$ gcc -o game *.c  -lncurses

1.3 ms-windows   


----------------------------------
1. API 
----------------------------------
1.1 공통 (ms-windows , linx(curses), linux)
void _BeginWindow() 
void _EndWindow() 
void _DrawText(int x,int y,char* msg) 
void _Invalidate() 
char _GetKey()
long _GetTickCount()
void _Delay(int time)
void _MessageBox(int x,int y,int w,int h,char* msg)


1.2 Linux  only (curset lib 사용)
void _DrawChar(int x,int y,int key)
void _ShowCharCode()

1.3 Ms-Windows only 
void _SetColor(int color)
void _InvalidateBack()
void _DrawTextOrg(int x,int y,char* msg)
void _DrawTextColor(int x,int y,char* msg,int color)
void _BitBlt()
void _MessageBoxEx(int x,int y,int w,int h,char* msg)
void _MessageBoxColor(int x,int y,int w,int h,char* msg,int color)
void _MessageBoxExColor(int x,int y,int w,int h,char* msg,int color)

