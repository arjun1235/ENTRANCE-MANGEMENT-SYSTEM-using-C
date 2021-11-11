 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#define Student struct Stud

void add(FILE * fp); //to add to list
void exam(FILE *fp);//for entrance examination
void show_record();
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen

struct Stud
{
    char name[100];
    char dob[20];
    char address[50];
    int ID;
    char ph[20];
    char gname[100];
    char email[100];
    char gph[20];

};


int main()
{
 FILE * fp;
 Student s;
int option;
char another;

if((fp=fopen("k:\\studentInfo.txt","a++"))==NULL)
{
    if((fp=fopen(":\\studentInfo.txt","r"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}

printHead();
printf("\n\n\t\tCREATED BY");
printf("\n\n\t\tARJUN CHHETRI");
printf("\n\n\t\tNIRAJ DUWAL");
printf("\n\n\t\tSURAJ AGRAHARI");
printf("\n\n\t\tPROJECT ON ENTRANCE MANAGEMENT SYSTEM");
printf("\n\n\n\t\tpress any key to continue");
getch();

while(1)
{
    printHead();
    printf("\n\t");
    printChar('-',64);

    printf("\n\n\t\t\t1. FORM FOR STUDENT");//ADD
    printf("\n\n\t\t\t2. ENTRANCE EXAMINATION");// BEFORE DELETE
    printf("\n\n\t\t\t3. MODIFY STUDENT RECORD");//MODIFY
    printf("\n\n\t\t\t4. DISPLAY STUDENT RECORD");//DISPLAY
    printf("\n\n\t\t\t5. Search Record");// RECORD
    printf("\n\n\t\t\t0. EXIT");
    printf("\n\t");
	printf("\n\t");
	printChar('-',64);
    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);
  

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: exam(fp);
                break;
        case 3: modify(fp);
                break;
        case 4: displayList(fp);
                break;
        case 5: searchRecord(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
return 1;

}

//----printing character ch at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void printHead()
{ system("cls");

printf("\n\n\t");
printChar('=',16);
printf("[ENTRANCE] [MANAGEMENT] [SYSTEM]");
printChar('=',16);
printf("\n");
}


// ==========FILLING STUDENT FORM==========================

void add(FILE * fp)
{
printHead();

char another='y';
Student s;
fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter date of birth of Student\t");
    fflush(stdin);
    fgets(s.dob,20,stdin);
    s.dob[strlen(s.dob)-1]='\0';

    printf("\n\n\t\tEnter Address\t");
    fflush(stdin);
    fgets(s.address,50,stdin);
    s.address[strlen(s.address)-1]='\0';

    printf("\n\n\t\tIdentification document no: \t");
    scanf("%d",&s.ID);

    printf("\n\n\t\tEnter student phone number\t");
    fflush(stdin);
    fgets(s.ph,20,stdin);
    s.ph[strlen(s.ph)-1]='\0';


    printf("\n\n\t\tEnter guardian name of Student\t");
    fflush(stdin);
    fgets(s.gname,100,stdin);
    s.gname[strlen(s.gname)-1]='\0';

    printf("\n\n\t\tEnter email ID Student\t");
    fflush(stdin);
    fgets(s.email,100,stdin);
    s.email[strlen(s.email)-1]='\0';

    printf("\n\n\t\tEnter student's guardian phone number\t");
    fflush(stdin);
    fgets(s.gph,20,stdin);
    s.gph[strlen(s.gph)-1]='\0';

    fwrite(&s,sizeof(s),1,fp);
    printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}

//===================ENTRANCE EXAMINATION===============
void exam(FILE *fp)
{
    printHead();
    int tempRoll,flag,siz,r;
    Student s;
    float countr;
    char another;
    siz=sizeof(s);
    fseek(fp,0,SEEK_END);
    printf("\n\n\t\t Do you want to take exam  (Y/N)\t");
    fflush(stdin);
    another=getch();

   if (another=='y'||another=='Y')
   {
    printf("\n\n\tEnter Identification Number of Student: ");
    scanf("%d",&tempRoll);
    rewind(fp);    
    while((fread(&s,siz,1,fp))==1)
    {
    if(s.ID==tempRoll)
        {flag=1;        
        break;
        }
    }
     if (flag==1)
      {countr=0.0;
      int i,m;
     bool arr[10]={0};
     int A[10];
     // srand(time(NULL));
     time_t t;
     srand((unsigned)time(&t));

   for (i=0;i<10;i++)
    {int r = rand()%10;
    if(!arr[r])
    A[i]= r;
    else
    i--;
    arr[r]=1;
     }

      for(i=0;i<10;i++)
        {
                //system("cls");
                     // A[i]=i;

     switch(A[i])
     {
		case 1:
		    system("cls");
		printf("\n\nSet A and B have 8 and 9 elements respectively, with 7 elements in common. The number of elements in A U B is :");
		printf("\n\nA.10.0\t\tB.15.0\n\nC.16.0\t\tD.17.0\n");
		if (toupper(getch())=='A')
		{
                                  countr++;
                                  printf("right");
                                  getch();
			                      break;
         }

         else  if (toupper(getch())=='C' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
            printf("you enter  wrong key");
        }
        case 2:
            system("cls");
		printf("\n\n\n If c(n+2, 4)= 6 c(n,2), then the value of n is ");
		printf("\n\nA.5 \t\tB.7\n\nC.8\t\tD.10\n");
		if (toupper(getch())=='B')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;

         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='A' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
            printf("you enter  wrong key");
        }
            case 3:
                system("cls");
		printf("\n\n\n Newton/Coulomb has the same dimension of......");
		printf("\n\nA.Volt/meter \t\tVolt-meter\n\nC.Farad/meter\t\tD.Farad-meter\n");
		if (toupper(getch())=='A')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 4:
            system("cls");
		printf("\n\n\n Among the following lights, which has minimum speed?");
		printf("\n\nA.Red \t\tB.violet\n\nC.Blue\t\tD.Green\n");
		if (toupper(getch())=='B')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='A' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 5:
            system("cls");
		printf("\n\n\n The maximum number of electrons which can be accommodated in an f-orbital is : ,");
		printf("\n\nA.2\t\tB.6\n\nC.10\t\tD.14\n");
		if (toupper(getch())=='A')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 6:
            system("cls");
		printf("\n\n\nNumber of electrons in CO2 molecule is......");
		printf("\n\nA.11\t\tB.22\n\nC.44\t\tD.32\n");
		if (toupper(getch())=='B')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='A' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 7:
            system("cls");
		printf("\n\n\n Bricks are laid ........... in construction of brick walls. ");
		printf("\n\nA.horizontally\t\tB.vertically\n\nC.inclined\t\tD.none of the all\n");
		if (toupper(getch())=='A')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 8:
            system("cls");
		printf("\n\n\nWhich of the following is a logic gates? ");
		printf("\n\nA.PUT\t\tB.THEN\n\nC.NOR\t\tD.WHEN\n");
		if (toupper(getch())=='C')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='A' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
             printf("you enter  wrong key");
        }
        case 9:
            system("cls");
		printf("\n\n\n I count __________ you. ");
		printf("\n\nA.on \t\tB.to\n\nC.at\t\tD.by\n");
		if (toupper(getch())=='A')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='B' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
            printf("you enter  wrong key");
        }
        case 10:
            system("cls");
		printf("\n\n\nHis hair is as black as___________ hair. ");
		printf("\n\nA.i \t\tB.my\n\nC.mine\t\tD.hers\n");
		if (toupper(getch())=='B')
		{
                    countr++;
                     printf("right");
                    getch();
			        break;
         }



         else  if (toupper(getch())=='C' ||  toupper(getch())=='A' ||  toupper(getch())=='D')
        {
                                  countr=countr-0.1;
                                  printf("wrong answer");
                                  getch();
		                          break;
        }
          else
        {
            printf("you enter  wrong key");
        }
      }
    }
     printf("\nTotal score=%f\n",countr);
     printf("\npress any key to go homepage\t");
    fflush(stdin);
    }
   else
    {
        printf("\n\t\t\t\t\tYOU HAVENOT REGISTER YET\n");
    }
   getch();
   }
}

//===========MODIFY A RECORD ===========================

void modify(FILE * fp)
{
printHead();

Student s;
int i,flag=0,tempRoll,siz=sizeof(s);
float cgpa;

printf("\n\n\tEnter identification Number of Student to MODIFY the Record : ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.ID==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");
    fputc('a',fp);
    fseek(fp,0,SEEK_CUR);

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter date of birth of Student\t");
    fflush(stdin);
    fgets(s.dob,20,stdin);
    s.dob[strlen(s.dob)-1]='\0';

    printf("\n\n\t\tEnter address\t");
    fflush(stdin);
    fgets(s.address,50,stdin);
    s.address[strlen(s.address)-1]='\0';

    printf("\n\n\t\tEnter identification number \t");
    scanf("%d",&s.ID);

    printf("\n\n\t\tEnter student phone number\t");
    fflush(stdin);
    fgets(s.ph,20,stdin);
    s.ph[strlen(s.ph)-1]='\0';

    printf("\n\n\t\tEnter guardian name of Student\t");
    fflush(stdin);
    fgets(s.gname,100,stdin);
    s.gname[strlen(s.gname)-1]='\0';

    printf("\n\n\t\tEnter  email ID of  Student\t");
    fflush(stdin);
    fgets(s.email,100,stdin); //fgets takes an extra \n character as input
    s.email[strlen(s.email)-1]='\0';

    printf("\n\n\t\tEnter student's guardian phone number\t");
    fflush(stdin);
    fgets(s.gph,20,stdin);
    s.gph[strlen(s.gph)-1]='\0';

}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");
system("pause");

}


//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{   printHead();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\t\tDATE OF BIRTH:%s",s.dob);
        printf("\n\t\tADDRESS: %s",s.address);
        printf("\n\t\tIDENTIFICATION DOCUMENT NO.:%d",s.ID);
        printf("\n\t\tPHONE NUMBER:%s",s.ph);
        printf("\n\t\tGURDAIN NAME:%s",s.gname);
        printf("\n\t\tEMAIL ADDRESS OF STUDENT:%s",s.email);
        printf("\n\t\tGURDAIN PHONE NUMBER:%s",s.gph);

    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void searchRecord(FILE *fp)
{
    printHead();

int tempRoll,flag,siz,i;
Student s;
char another='y';

siz=sizeof(s);

while(another=='y'||another=='Y')
  {
  printf("\n\n\tEnter Identification Number of Student to search the record : ");
  scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.ID==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\t\tDATE OF BIRTH:%s",s.dob);
        printf("\n\n\t\tADDRESS: %s",s.address);
        printf("\n\n\t\tIDENTICATION DOCUMENT NO.: %d",s.ID);
        printf("\n\n\t\tPHONE NUMBER:%s",s.ph);
        printf("\n\t\tGURDAIN NAME:%s",s.gname);
        printf("\n\t\tEMAIL OF STUDENT:%s",s.email);
        printf("\n\t\tGURDAIN PHONE NUMBER:%s",s.gph);

     }
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
  }
}
