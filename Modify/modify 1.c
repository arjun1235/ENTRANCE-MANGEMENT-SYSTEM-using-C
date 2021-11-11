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
    float Mark;
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

if((fp=fopen("k:\\student.txt","a++"))==NULL)
{
    if((fp=fopen(":\\student.txt","r"))==NULL)
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
printf("\n\n\n\t\tpress any key to continue\n\t");
printChar('-',64);
getch();

while(1)
{
    printHead();
    printf("\n\t");
    printChar(':',64);

    printf("\n\n\t\t\t1. FORM FOR STUDENT");//ADD
    printf("\n\n\t\t\t2. ENTRANCE EXAMINATION");// BEFORE DELETE
    printf("\n\n\t\t\t3. MODIFY STUDENT RECORD");//MODIFY
    printf("\n\n\t\t\t4. DISPLAY STUDENT RECORD");//DISPLAY
    printf("\n\n\t\t\t5. Search Record");// RECORD
    printf("\n\n\t\t\t0. EXIT");
    printf("\n\t");
	printf("\n\t");
	printChar('*',64);
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
    s.Mark=0;

    printf("\n\n\t\tEnter student phone number\t");
    fflush(stdin);
    fgets(s.ph,20,stdin);
    s.ph[strlen(s.ph)-1]='\0';


  printf("\n\n\t\tEnter email ID Student\t");
    fflush(stdin);
    fgets(s.email,100,stdin);
    s.email[strlen(s.email)-1]='\0';


    printf("\n\n\t\tEnter guardian name of Student\t");
    fflush(stdin);
    fgets(s.gname,100,stdin);
    s.gname[strlen(s.gname)-1]='\0';

  
    printf("\n\n\t\tEnter student's guardian phone number\t");
    fflush(stdin);
    fgets(s.gph,20,stdin);
    s.gph[strlen(s.gph)]='\0';

    fwrite(&s,sizeof(s),1,fp);
    printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);
    another=getche();
}
}

//===================ENTRANCE EXAMINATION===============
void exam(FILE *fp)
{
    printHead();
    int tempRoll,flag,siz,r;
    Student s;
    float countr;
    char another,cha;
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
                //system
				
				("cls");
                     // A[i]=i;

     switch(A[i])
     {
		case 1:
		a1:
		    system("cls");
		printf("\n\n\n\tQ.The word ‘engineer’ has its primary stress on its ______ syllable:\n");
		printf("\n\n\t(A) first \t\t(B) second \n\t(C) third \t\t(D) fourth");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a1;
		}
				
        
		case 2:
            system("cls");
		a2:
		printf("\n\n\n\tQ.Two and two _____ four.");
		printf("\n\n\n\t(A) makes \t\t\t(B) make \n\t(C) have made \t\t\t(D) will be made ");
		// ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}		else if(cha=='c'||cha=='C'||cha=='b'||cha=='B'||cha=='d'||cha=='D') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a2;
		}
				
		
		    case 3:
                system("cls");
		a3:
		printf("\n\n\n\t\tQ.pH of 0.2 N H2SO4 is:");
		printf("\n\n\n\t(A) 0.69 \t\t\t(B) 1.2 \n\t(C) 0.76 \t\t\t(D) 0.56");
		// ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}		else if(cha=='c'||cha=='C'||cha=='b'||cha=='B'||cha=='d'||cha=='D') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a3;
		}
		
		
			case 4:
            system("cls");
            a4:
		printf("\n\n\n \tQ.Catalytic oxidation of ammonia in air forms:");
		printf("\n\n\n\t(A)NO2 \t\t\t(B) N2O5 \n\t(C) N2O \t\t(D) NO");
		//ans d
		cha=getch();
		if (cha=='d'||cha=='D')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a4;
		}
		
		
		case 5:
        
		    system("cls");
		    a5:
		printf("\n\n\n\t\tQ.The magnetism of the magnet is due to:");
		printf("\n\n\n\t(A) the spin motion of electron \n\t\t(B) cosmic ray \n\t(C) the earth \n\t\t(D) pressure of big magnet inside the earth ");
		//ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}		else if(cha=='d'||cha=='D'||cha=='b'||cha=='B'||cha=='c'||cha=='C') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a5;
		}
		
		
        case 6:
            system("cls");
            a6:
		printf("\n\n\n\tQ.The maximum percentage of ingredients in cement is that of:");
		printf("\n\n\t(A) magnesia \t\t(B) lime \n\t(C) alumina \t\t(D) silica");
		//ans b
		cha=getch();
		if (cha=='b'||cha=='B')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='d'||cha=='D'||cha=='c'||cha=='C') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a6;
		}
		
		
        case 7:
            system("cls");
            a7:
		printf("\n\n\n\tQ.The second derivative of f(x) = 1/x at point (1,1) is equal to:");
		printf("\n\n\t(A) 1 \t\t\t(B) -1 \n\t(C) 2 \t\t\t(D) -2");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a7;
		}
		
		
		case 8:
            system("cls");
            a8:
		printf("\n\n\n\tQ.Which of the following is a logic gates? ");
		printf("\n\n\tA.PUT\t\tB.THEN\n\tC.NOR\t\tD.WHEN\n");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a8;
		}
		
		
		case 9:
            system("cls");
            a9:
		printf("\n\n\n\tQ.:If the line 2x+3y+4+k(-x+y+5)=0 is horizontal then the value of k is:");
		printf("\n\n\t(A) 0 \t\t\t(B) 1 \n\t(C) 3 \t\t\t(D) 2");
		//ans d
		cha=getch();
		if (cha=='d'||cha=='D')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a9;
		}
				
		
		case 10:
            system("cls");
            a10:
		printf("\n\n\t\tQ.:IUPAC name of CH3-CH2 - CH2 -CH (OCH3) - CO Br is:");
		printf("\n\t(A) 2- methoxylpentanoyl bromide \t\t\t\t(B) 3- methoxylpentanoyl bromide \n\t\t\t\t(C) 3-methoxyhexanoyl bromide \t\t(D) 2-methoxyhexanoyl bromide");
		//ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C') 
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a10;
		}
				
		} //s.ID;
    }
     fflush(stdin);    
    s.Mark=countr;
    fwrite(&s,sizeof(s),1,fp);
     system("cls");
    // printf("\n\n\t\tmark: %d",s.Mark);
      
     // printf("\n\n\n\n\t\t\tCongratulations %s you scored=%f\n",s.name,countr);
	 printf("\n\n\n\n\t\t\tCongratulations %s you scored=%f\n",s.name,s.Mark);
     printf("\t\t\tBest of luck for result\n");
	 printf("\t\t\tpress any key to go homepage\t");
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
		 printf("\n\tmark is=%f",s.Mark);
        printf("\n\t\tGURDAIN NAME:%s",s.gname);
        printf("\n\t\tEMAIL ADDRESS OF STUDENT:%s",s.email);
        printf("\n\t\tGURDAIN PHONE NUMBER:%s",s.gph);

    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}
//====================SEARCH =================
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
another=getch();
  }
}
