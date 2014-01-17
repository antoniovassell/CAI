//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
//#include <dos.h>
#include <iostream>

void upLine(int, int, int);
void gotoxy(int , int );
void downLine(int,int,int);
void rightLine(int, int, int);
void At(int x, int y, unsigned char What);
void clear_innerbox();
void start_frame();

void start_frame()
{
 	int y1=0,y2=43,x1=0,x2=80;

   rightLine(y1,x1,x2);
   rightLine(y1+1,x1,x2);
   downLine((x2/3),y1,y2);
   downLine(((x2/3)*2),y1,y2);
   rightLine(((y2/3)*2),(x2/3),(x2/3)*2);
   rightLine(y2,x1,x2);
}
void clear_innerbox()
{
   int a=0,b=0;
   for(a=28;a<=48;a++)
    	{
          for(b=30;b<=39;b++)
             {
             	printf(" ");
               gotoxy(a,b);
             }
      }
 }



//void Fullscreen();

//int main()
/*
   Fullscreen();
   system("color fc");
   int x=0,y=0,z=0;

      for(y=0;y<20;y++)
      {
      	gotoxy(x,y);
         textbackground(4);
         cprintf(" ");
         Sleep(10);
      }

      for(x=0;x<79;x++)
      {
      	gotoxy(x,y);
       textbackground(4);
       cprintf(" ",x);
        Sleep(10);
      }

      for(y=20;y>=0;y--)
     {
      	gotoxy(x,y);
         textbackground(4);
         cprintf(" ",y);
         Sleep(10);
     }

     gotoxy(0,0);
     for(x=0;x<=79;x++)
     {
       gotoxy(x,y);
       textbackground(4);
       cprintf(" ",x);
       Sleep(0);
     }
     //upLine(12,20,40);
     downLine(25,0,20);
     downLine(0,20,40);
     downLine(10,20,40);
     downLine(20,20,40);
     downLine(30,20,40);
     downLine(40,20,40);
     downLine(50,20,40);
     downLine(60,20,40);
     downLine(70,20,40);
     downLine(79,20,40);
     rightLine(40,1,79);

gotoxy(40,9);
cprintf("Loading..");

for(z=25;z<79;z++)
{
    gotoxy(z,10);
    textbackground(1);
    cprintf(" ");
    Sleep(90);
}
gotoxy(39,12);
cprintf("WELCOME");
getch();
return 0;
}
*/
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
void Fullscreen()
{
     HWND hWnd;                                                    //Creating a new handle for a window
     SetConsoleTitle("ANTUAN THE GREAT");                          //Changes the title of the window......
     hWnd = FindWindow(NULL, "ANTUAN THE GREAT");                  //Assigns this window to the handle we created....Something like that

     SendMessage(hWnd, WM_SYSKEYDOWN, VK_RETURN, 0xFF000000);      //Passed the boring stuff, this is the nice part,puts the window in fullscreen

}
*/
void downLine(int startx, int start_y,int end_y)
{
      int x=startx,y=1;

   	for(y=start_y; y<=end_y; y++)
         {
         	gotoxy(x,y);
            textbackground(2);
            cprintf(" ");
         }
}

void upLine(int startx, int start_y, int end_y)
{
		int x=startx,y=1;

      for(y=end_y;y>=start_y;y--)
      {
      		gotoxy(x,y);
            textbackground(3);
            cprintf(" ");
      }
}

void rightLine(int start_y, int start_x, int end_x)
{
    int y=start_y, x=1;
	 for(x=start_x; x<end_x; x++)
    {
            gotoxy(x,y);
       		textbackground(2);
            cprintf(" ");

       		//cprintf("\192");
    }
}


void At(int x, int y, unsigned char What)
{
    static HANDLE hOut;
    static bool First = TRUE;
    COORD Position;

    if(First)
    {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        First = FALSE;
    }

    Position.X = x;
    Position.Y = y;

    SetConsoleCursorPosition(hOut,
                             Position);

    cout << What <<flush;

    return;
}
