/*
Copyright Antuan (2009)
Shauntae Mitchell 0903759
This source code contains the main functions that involves the accounts processing.
And also additional functions.
*/

//All variables that are use for input has a pointer assigned to it.

#include "CUTE.cpp"
#include <string.h>
#define PAUSE system("pause");
#define CLEAR system("cls");
#define MAX_users 20


BOOL login();                   		  //This ask for username and password to login
void Frist_Login();                   //This ask for users choice, to login or to register
void Register(int *);                 //This gives user a chance to register if permitted by administrator
void newUser();                       //This function creates a new user
int permission();                     //This checks if the maximum amount of users is reach,stoping registration
void AmountUpdater(int *ptr_Amount);  //This incremenates the amount of user in the system when it detects a newuser
void reads(char *,int);               //This is our own input function that limits input.(prevent program crash)v.1 (beta)
void passwordMask(char *,int);        //This is the same as reads(...) function only it mask the output of the input..
void my_TouppersFunc(char *,int);	  //A little function to change a whoole string to uppercase

void Frist_Login()                    //Ask the users choice
{
  BOOL AccessGain=FALSE;                    //Breaks out of the loop(whole function) if accessgain is true

  char choice[2],*ptr_choice;         //Variable and pointer declarations and assignments
  ptr_choice=&choice[0];
  int Amount=0;
  int *ptr_Amount;
  ptr_Amount=&Amount;
  int i;

  while(AccessGain==FALSE)
   {
       CLEAR

      start_frame();

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

      reads(ptr_choice,1);                   //Passes the pointer to the variable "choice" and the amount of characters allowed
      my_TouppersFunc(ptr_choice,1);

		if(strcmp(choice,"L")==0)              //if the choice is L then login
			{
    		  AccessGain=login();               //"AccessGain" is equal TRUE or FALSE ,whatever the login() function returns
   		}
		else
		if(strcmp(choice,"R")==0)             //If the choice is R the register
			{
            Amount=permission();            //This checks if the maximum amount of user's is reach

            if((permission())>=MAX_users)   //If the function returns a value greater than the maximum amount of users then this is what will happen
              {
                  CLEAR
              		printf("\nAM SORRY BUT THE SYSTEM CANT HANDLE ANYMORE USERS\n");
                  printf("\nPLEASE SEE YOUR INSTRUCTOR FOR MORE DETAILS\n");
                  system("pause");
                  continue;                  //Starts over the loop
              }
            else                             //If the maximum amount of users is not reach to go register!
              {
              		Register(ptr_Amount);      //The register function is called pasing the pointer to the variable Amount
              }
   		}
      else
      if(strcmp(choice,"Q")==0)
      	{
               clear_innerbox();
   				gotoxy(28,30);
  					printf("PROGRAM WILL EXIT");
		   		gotoxy(28,33);
              	sleep(2);
              	exit(0);
         }
   }
}

BOOL login()                                  //Definition of the login function
{
   BOOL AccessGain=FALSE;                            //Variable to hold if user gains access or not, TRUE or FALSE
   BOOL flag=TRUE;
	char Entered_username[11],*ptr_Entered_username;                  //Other variable and pointer declarations and assigments.
	char Entered_password[5],*ptr_Entered_password;
   char username[MAX_users][15];
   char password[MAX_users][15];
   int i;

   ptr_Entered_username=&Entered_username[0];
   ptr_Entered_password=&Entered_password[0];    //Equivalent to ptr_Entered_pasword=Entered_password. (i think), works either way

   FILE *AccountsFile;                           //Creates a new file pointer

   AccountsFile=fopen("AccountsFile.txt","r+");  //Opens the file AccountsFile.txt file


  gotoxy(28,30);
  printf("ENTER YOUR USERNAME: ");
  gotoxy(28,31);
  printf("==>");

  reads(ptr_Entered_username,10);                   //The reads(....) accepts the username and password.

  gotoxy(28,35);
  printf("ENTER YOUR PASSWORD: ");
  gotoxy(28,36);
  printf("==>");
  passwordMask(ptr_Entered_password,4);             //.......


  for(i=0; i<MAX_users; i++)                        //This loops true the file that was opon to search for the entered details
  	  {
     		fscanf(AccountsFile, "%s\t%s",password[i],username[i]);          //this function reads true the file line by line.

     		if((strcmp(password[i],Entered_password)==0)&&(strcmp(username[i],Entered_username)==0))      //Checks each line if the username and password is equal to what was entered
     			{
              	AccessGain=TRUE;                    //If found AccessGain equal true

              	fclose(AccountsFile);               //Close the file that was open
              	return AccessGain;                  //Return this variable back to the caller function
              	break;                              //(Maybe unnessary),unreachable code i think
           	}// End of if Strcmp

     }//End of for(i=0; i<10; i++)

   clear_innerbox();
   gotoxy(28,30);
   printf("USER WAS NOT FOUND");
   gotoxy(28,33);

   getch();
   AccessGain=FALSE;                                  //If details was not found AccessGain equals false

fclose(AccountsFile);                                 //Close the file that was open
return AccessGain;                                    //Returns the value of AccessGain to the caller function. Sorry user, no access for you
}  //End of login()


void Register(int *ptr_Amount)                        //Main task of this function is to seek permission from administrator for registration
{
   char Entered_username[10],*ptr_Entered_username;    //Pointer and Variable declarations and assignments
	char Entered_password[5],*ptr_Entered_password;
   char choice[2],*ptr_choice;
   int temp_Amount[1];

   ptr_Entered_username=Entered_username;              //Assignments
   ptr_Entered_password=Entered_password;
   ptr_choice=choice;

   CLEAR
	printf("\nYOU NEED YOUR ADMINISTRATOR TO COMPLETE THIS TASK!\n\n");    //Make the user aware that he/she needs the administrator details to continue registration
   PAUSE

   while(1)                                             //Why do i love infinite loops?
   {
   		printf("\n\nENTER ADMIN USERNAME: ");
   		reads(ptr_Entered_username,10);                //reads() function Accepts the username

			printf("\n\nENTER ADMIN PASSWORD: ");
         passwordMask(ptr_Entered_password,4);          //passwordMask() function does the same as reads()function but maskes the input

         //Here this checks if the administrator username and password is correct
   		if((strcmp(Entered_username,"ADMIN")==0)&&(strcmp(Entered_password,"PASS")==0))
   			{
         			newUser();                //If the details are correct the user can go ahead and create a new user. (the newUser()function is called

                  temp_Amount[0] = *ptr_Amount+1;     //After the newUser()function the amount of user in the system is updated, (incremenated)
                  FILE *AmountFile;                   //Creates a new file pointer
   					AmountFile=fopen("Amount.txt","w+");       //Opens the text file in write mode
   					fprintf(AmountFile, "%d\n",temp_Amount[0]);     //fprintf function writes the new details into the text
   					fclose(AmountFile);                             //Closes the file that was open.
                  break;														//Breaks out of the loop and returns back to the caller function
      		}
   		else     //If the Administrator details where unaccepted then it comes here,prompts the user and starts over the loop,(function)
   			{
                  CLEAR
         			printf("\nDETAILS NOT ACCEPTED!\n");

                  printf("\nDO YOU WANT TO QUIT TO MAIN MENU?\n");
                  printf("\nY: FOR YES\n");
                  printf("\nR: FOR RETRY\n");

                  reads(ptr_choice,1);

                  if(strcmp(choice,"Y")==0)
                  	{
                     	break;
                     }
                  else
                  	{
                     	continue;
                     }
      		}
   }//End while
}

void newUser()                        //Main task is to create a new user
{
    int i;                            //Variable and pointer declarations and assignments
    char username[10][15];
    char password[10][15],*ptr_password;
    char temp_username[10][15],*ptr_temp_username;
    BOOL flag=TRUE;
    BOOL userexits;

    ptr_temp_username=temp_username[3];
    ptr_password=password[3];

    FILE *AccountsFile;               							 //Creates a new file pointer
    if((AccountsFile=fopen("AccountsFile.txt","a+"))==NULL)          //Opens the accounts file in append mode,
       {
           AccountsFile=fopen("AccountsFile.txt","w+");
           CLEAR
           printf("\nFATAL ERROR!: COULD NOT OPEN USER ACCOUNTS FILES\n");
           printf("\n\nSEE YOUR INSTRUCTOR FOR MORE DETAILS\n");
           PAUSE
           CLEAR
           printf("\n\nYOU CAN CONTINUE REGISTRATION THOUGH\n\n");
           PAUSE
       }
    do
    {
         CLEAR
     		printf("ENTER THE USERNAME YOU WANT TO USE: (NOT MORE THAN TEN LETTERS)\n==> ");
     		reads(ptr_temp_username,10);                      //Accepts the username the userwants to use

      	userexits=FALSE;                                  //This is like a flag(Based on Ms.Allen's work),its initiated as false,(cont'd...)
                                                           //if user name exis already it is made to be true and loop starts over to make user choose different name
         		for(i=0; i<=MAX_users; i++)                        //This loop reads through accounts file and checks if username exis already
   		 			{
                       fscanf(AccountsFile, "%s\t%s",password[i],username[i]);

           					if((strcmp(username[i],temp_username[3])==0))
               				{
                              CLEAR
                  				printf("\nUSER NAME ALREADY EXISTS!: %s\n",username[i]);
                     			printf("\n\nPLEASE CHOOSE ANOTHER USER NAME\n");
                  				PAUSE
                              userexits=TRUE;                                      //make userexits true to signal userexis already and starts over the loop
                     			break;
                           }// End of if Strcmp
       				}//End of for(i=0; i<10; i++)

    }while(userexits==TRUE);                //While user exis already continue looping

   //Accepts the password the user wants to use.................
	printf("\nENTER THE PASSWORD YOU WANT TO USE: (NOT MORE THAN FOUR LETTERS)\n==> ");
   passwordMask(ptr_password,4);

   fprintf(AccountsFile,"%s\t%s\n",password[3],temp_username[3]);		//Write the user details to file,(should have check for error,hope i dont lose mark)
   fflush(stdin);         //Get rid of any
   fclose(AccountsFile);  //Close the accounts file that was open.
}


int permission()      //Main task is to check the amount of users currently in the system before allowing a user to registor
{
   int MAX_num=1;     //Declaration of all needed variables.
	int num1=0;
   int x=0;

   FILE *Amount;      //Creates a new file pointer

   if((Amount=fopen("Amount.txt","r+"))==NULL)      //Opens the Amount.txt file in reading mode
      {
      	Amount=fopen("Amount.txt","w+");
         return 0;
      }
   for(x=1;x<=MAX_num;x++)               //reads the file to see how much users are currently in the system
   	{fscanf(Amount,"%d",&num1);}

   fclose(Amount);                       //Closes the file that was open
   return num1;                          //Returns the amount of users to the caller function
}

void reads(char *input,int MAX)			//Our own input function,It limits the user input, maybe it needs to be done better but for now it works with few or no bugs present
 {
   int i=0;                            //Variable declarations and assignments
   char line=NULL;

   while(1)                     			//While the user dont hit the return key, continue take input. (Shoud have done this in a do while loop)
        {                              //or i could say while(1), would make a difference
           line=getch();               //Get the user input character by character
           fflush(stdin);              //Flush any garbbage

           if(line==13)                //If the return key or enter key is press break out of the loop. 13 is the ASCII symbol for the enter key.
             {
               if(i!=0)
             		{break;}
               else
               	{continue;}
             }
           else                        //If the backspace key is press, then...,backspace, 8 is the ASCII symbol for the backspace key
           if(line==8)
           	{
            	if(i>0)                 //Checks first if the input can backspace any further, if not, then do nothing
            		{
              			printf("\b \b");
                 		i--;
              	 	}
            }
           else
           if(i<MAX)                   //If everything is ok then go ahead and put the character into the input variable to make one string.
            {
              		input[i]=line;
              		printf("%c",input[i]);   //Print the character entered,
              		i++;
            }
        }
    for(i=i;i<=MAX;i++)                //This makes the rest of the characters in the input variable equal to NULL,(nothing), if they werent used
    	{input[i]=NULL;}
 }

 void passwordMask(char *input,int MAX)      //This does the same thing as the read function(),but prints the characters entered as a "*"
 {

   int i=0;
   char line=NULL;

   i=0;
   while(line!=13)
        {
           line=getch();
           fflush(stdin);
           if(line==13)
            {
             	if(i!=0)
             		{break;}
               else
               	{continue;}
            }
           else
           if(line==8)
           	{
            	if(i>0)
            		{
              			printf("\b \b");
                 		i--;
              	 	}
            }
           else
           if(i<MAX)
            {
              		input[i]=line;
              		printf("*",input[i]);
              		i++;
            }
        }
    for(i=i;i<=MAX;i++)
    	{
         input[i]=NULL;
      }
 }

void my_TouppersFunc(char *line,int MAX)
{
     int i;

     for(i=0;i<MAX;i++)
     	{
       	line[i]=toupper(line[i]);
      }
}

