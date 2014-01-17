#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <dos.h>
#include "CUTE.cpp"
#include "LOGIN.cpp"

void Fullscreen();
void certificate();

int main()
{
      Fullscreen();

      int y1=0,y2=43,x1=0,x2=80;
    /*
      rightLine(y1,x1,x2);
      rightLine(y1+1,x1,x2);
      downLine((x2/3),y1,y2);
      downLine(((x2/3)*2),y1,y2);
      rightLine(((y2/3)*2),(x2/3),(x2/3)*2);
      rightLine(y2,x1,x2);
    */
      system("color cf");
      certificate();
    /*
      gotoxy(28,7);
      printf("WELCOME TO CAI-ULTIMATE");
      gotoxy(28,10);
		printf("WHAT DO YOU WANT TO DO?");
      gotoxy(30,12);
		printf("L: TO LOGIN");
      gotoxy(30,15);
		printf("R: TO REGISTER");
      gotoxy(30,18);
      printf("Q: TO QUIT");
      gotoxy(30,21);
      printf("==> ");


      gotoxy(28,30);
      printf("ENTER YOUR USERNAME: ");
      gotoxy(28,31);
      printf("==>");

      gotoxy(28,35);
  		printf("ENTER YOUR PASSWORD: ");
      gotoxy(28,36);
      printf("==>");

      clear_innerbox()
      int a=0,b=0;
      for(a=28;a<=48;a++)
      	{
             for(b=30;b<=39;b++)
                 {
                 	printf(" ");
                  gotoxy(a,b);
                 }
         }

      //while()



 */
//printf("\n");
//system("pause");
getch();
return 0;
}

void certificate()
{
      char name[26],*ptr_name;
   	ptr_name=name;

      system("cls");
      printf("\n\nYOU HAVE COMPLETED THE PROGRAM WITH FLYING COLORS!\n\n");

      printf("\n\n\nENTER YOUR FULL NAMAE SO WE CAN CREATE A CERTIFICATE FOR YOU (No more than 25 Letters)\n==> ");
      reads(ptr_name,25);

      my_TouppersFunc(ptr_name,25);

      system("cls");
      gotoxy(4,7);
      printf(" ####   #    ###       ### ### ###   ##### ### ###   ##   #    ##### #####");
      gotoxy(4,8);
		printf("##  #   ##    #         #   #   #      #    #   ##  ##    ##     #    #  #");
      gotoxy(4,9);
		printf("#      # #    #         #   #   #      #    #   ### ##   # #     #    ### ");
      gotoxy(4,10);
		printf("#      ####   #  #####  #   #   #      #    #   # ## #   ####    #    #   ");
      gotoxy(4,11);
		printf("##    #   #   #         #   #   #  #   #    #   # #  #  #   #    #    #  #");
      gotoxy(4,12);
		printf(" #### #   ## ###        #####  #####  ###  ### ###  ### #   ##  ###  #####");

      gotoxy(9,14);
      printf(" #### ##### #####  ##### ### ##### ###  ####   #    ##### #####");
      gotoxy(9,15);
		printf("##  #  #  #  #  #    #    #   #  #  #  ##  #   ##     #    #  #");
      gotoxy(9,16);
		printf("#      ###   #  #    #    #   ###   #  #      # #     #    ### ");
      gotoxy(9,17);
		printf("#      #     ###     #    #   #     #  #      ####    #    #   ");
      gotoxy(9,18);
		printf("##     #  #  # ##    #    #   #     #  ##    #   #    #    #  #");
      gotoxy(9,19);
		printf(" #### ##### ### ##  ###  ### ##    ###  #### #   ##  ###  #####");

      gotoxy(9,22);
      printf("______________________________________________________________________");
	   gotoxy(8,24);
		printf("(T ) H ) I ) S )  ( I ) S )  ( T ) O )  ( C ) E ) R ) T ) I ) F ) Y )");
      gotoxy(9,25);
      printf("______________________________________________________________________");

      gotoxy(28,30);
      printf("%s",name);

      gotoxy(30,35);
		printf(" ( F ) O ) R )");
      gotoxy(15,37);
      printf("( C ) A ) I )  -  ( U ) L ) T ) I ) M ) A ) T ) E )");
      gotoxy(1,39);
      printf(" ( P ) R ) O ) G ) R ) A ) M )   ( C ) O ) M ) P ) L ) E ) T ) I ) O ) N )");

getch();
}




void Fullscreen()
{
     HWND hWnd;                                                    //Creating a new handle for a window
     SetConsoleTitle("CAI");                          //Changes the title of the window......
     hWnd = FindWindow(NULL, "CAI");                  //Assigns this window to the handle we created....Something like that

     SendMessage(hWnd, WM_SYSKEYDOWN, VK_RETURN, 0xFF000000);      //Passed the boring stuff, this is the nice part,puts the window in fullscreen

}