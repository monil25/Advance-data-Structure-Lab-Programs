/*Monil Dand
FE COMPS
BATCH-D1
ROLL NO-15
*/
/* PROGRAM 6. A record in an organisation’s payroll consists of one line for each employee consisting of:
NAME (20 characters), SEX (1 character M or F), SALARY (integer), DATE OF
BIRTH (3 integers YEAR MONTH DAY).
Write a program which will input 10 such records. Your program must then take in 5
amendments in the record set which will be in the same form as the record structure itself.
The amendments can contain new employees to be added (name different from existing
ones), employees left (salary given as 0) and update of salary(more or less). Your program
must then incorporate these amendments and also remove those employees who have reached
retirement age(Age 60).
*/
#include<stdio.h>
#include<string.h>
void input();
void nemployee();
void display();
void remployee();
void retire();
void salarychange();
struct employee  // declaration of struct
{
 char name[20];
 char sex[1];
 int salary;
 int dd;
 int mm;
 int yy;
};
struct employee s[15];// struct of size 15
static int n;
void main()
{// main opens
int choice;
input();// call to function input
int k=1;
for(k=1;k<=5;k++)
{
 printf("Enter Your Choice\n");
 printf("1.TO ADD EMPLOYEE\n");
 printf("2.TO REMOVE EMPLOYEE\n");
 printf("3.TO CHECK FOR RETIREMENT\n");
 printf("4.TO CHANGE THE SALARY\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
     printf("You Choose To Add New Employees\n");
     nemployee();// call to function nemployee
     break;
  case 2:
	printf("You Choose To Remove Emploees\n");
	remployee();// call to function remployee
	break;
  case 3:
	printf("You Choose To Check For $Retirement\n");
	retire();// call to function retire
	break;
  case 4:
	printf("You Choose To Change The Salary\n");
	salarychange();// call to function salary
	break;
 }
}
display();// call to function display
}// main closes
void input()
{
 int i;
 for(i=0;i<10;i++)
 {
  printf("ENTER THE NAME\n");
  scanf("%s",s[i].name);
  printf("ENTER THE GENDER\n");
  scanf("%s",s[i].sex);
  printf("ENTER THE SALARY\n");
  scanf("%d",&s[i].salary);
  printf("ENTER THE DATE OF BIRTH\n");
  scanf("%d",&s[i].dd);
  scanf("%d",&s[i].mm);
  scanf("%d",&s[i].yy);
  printf("THE BIRTH DATE IS %d/%d/%d \n",s[i].dd,s[i].mm,s[i].yy);
 }
}
void nemployee()
{
 int j=0;
 for(j=n;j<(n+1);j++)
 {
 printf("ENTER INFORMATION OF NEW EMPLOYEE TO BE ADDED\n");
 scanf("%s",s[j+10].name);
 scanf("%s",s[j+10].sex);
 scanf("%d",&s[j+10].salary);
 scanf("%d",&s[j+10].dd);
 scanf("%d",&s[j+10].mm);
 scanf("%d",&s[j+10].yy);
 }
 n++;
}
void display()
{
 int i=0;
 for(i=0;i<15;i++)
 {
  if(s[i].salary>=0)
  {
   printf("NAME IS %s\n",s[i].name);
   printf("SEX IS %s\n",s[i].sex);
   printf("SALARY IS %d\n",s[i].salary);
   printf("DOB IS %d/%d/%d \n",s[i].dd,s[i].mm,s[i].yy);
  }
  else
  {
  	continue;// if salary is less than zero,continue
  }
}
}
void remployee()
{
 int i=0,j=0;
 char ch[20];
 printf("Enter Name Of Employee To Be Removed\n");
 scanf("%s",ch);
 for(i=0;i<15;i++)
 {
 	j=strcmpi(ch,s[i].name);// comparsion of two strings
 	if(j==0)
 	{
 	 s[i].salary=0;	
	}
 }
}
void retire()
{
	int i,j=0,k=0;
	printf("Enter present year\n");
	scanf("%d",&j);
	for(i=0;i<15;i++)
	{
		if((j-s[i].yy)>60)
		{ 
		  s[i].salary=-1;
		}
	}
}
void salarychange()
{
	char sname[20];
	int i=0;
	printf("Enter Name Of Employee Whose Salary Is To Be Changed\n");
	scanf("%s",sname);
	for(i=0;i<15;i++)
	{
		if(strcmpi(sname,s[i].name)==0)
		{
			printf("ENTER NEW SALARY\n");
			scanf("%d",&s[i].salary);// changing the salary
		}
	}
}
//OUTPUT
/*
ENTER THE NAME
abc
ENTER THE GENDER
f
ENTER THE SALARY
1234
ENTER THE DATE OF BIRTH
12
3
2002
THE BIRTH DATE IS 12/3/2002
ENTER THE NAME
xyz
ENTER THE GENDER
m
ENTER THE SALARY
12345
ENTER THE DATE OF BIRTH
6
3
2000
THE BIRTH DATE IS 6/3/2000
ENTER THE NAME
efg
ENTER THE GENDER
m
ENTER THE SALARY
2345
ENTER THE DATE OF BIRTH
22
6
2002
THE BIRTH DATE IS 22/6/2002
ENTER THE NAME
hijk
ENTER THE GENDER
f
ENTER THE SALARY
23456
ENTER THE DATE OF BIRTH
23
2
1974
THE BIRTH DATE IS 23/2/1974
ENTER THE NAME
bcd
ENTER THE GENDER
m
ENTER THE SALARY
123456
ENTER THE DATE OF BIRTH
2
3
1969
THE BIRTH DATE IS 2/3/1969
ENTER THE NAME
lmn
ENTER THE GENDER
f
ENTER THE SALARY
23456
ENTER THE DATE OF BIRTH
23
6
1947
THE BIRTH DATE IS 23/6/1947
ENTER THE NAME
mnss
ENTER THE GENDER
m
ENTER THE SALARY
154698
ENTER THE DATE OF BIRTH
26
12
1900
THE BIRTH DATE IS 26/12/1900
ENTER THE NAME
stuv
ENTER THE GENDER
f
ENTER THE SALARY
123445
ENTER THE DATE OF BIRTH
5
6
2009
THE BIRTH DATE IS 5/6/2009
ENTER THE NAME
defgh
ENTER THE GENDER
f
ENTER THE SALARY
12233445
ENTER THE DATE OF BIRTH
14
12
2007
THE BIRTH DATE IS 14/12/2007
ENTER THE NAME
opq
ENTER THE GENDER
f
ENTER THE SALARY
123456
ENTER THE DATE OF BIRTH
17
6
2005
THE BIRTH DATE IS 17/6/2005
Enter Your Choice
1.TO ADD EMPLOYEE
2.TO REMOVE EMPLOYEE
3.TO CHECK FOR RETIREMENT
4.TO CHANGE THE SALARY
1
You Choose To Add New Employees
ENTER INFORMATION OF NEW EMPLOYEE TO BE ADDED
shlokasanjayshah
f
1234
6
3
2000
Enter Your Choice
1.TO ADD EMPLOYEE
2.TO REMOVE EMPLOYEE
3.TO CHECK FOR RETIREMENT
4.TO CHANGE THE SALARY
2
You Choose To Remove Emploees
Enter Name Of Employee To Be Removed
xyz
Enter Your Choice
1.TO ADD EMPLOYEE
2.TO REMOVE EMPLOYEE
3.TO CHECK FOR RETIREMENT
4.TO CHANGE THE SALARY
3
You Choose To Check For $Retirement
Enter present year
2018
Enter Your Choice
1.TO ADD EMPLOYEE
2.TO REMOVE EMPLOYEE
3.TO CHECK FOR RETIREMENT
4.TO CHANGE THE SALARY
4
You Choose To Change The Salary
Enter Name Of Employee Whose Salary Is To Be Changed
shlokasanjayshah
ENTER NEW SALARY
45454545
Enter Your Choice
1.TO ADD EMPLOYEE
2.TO REMOVE EMPLOYEE
3.TO CHECK FOR RETIREMENT
4.TO CHANGE THE SALARY
1
You Choose To Add New Employees
ENTER INFORMATION OF NEW EMPLOYEE TO BE ADDED
ssshah
f
122334
6
3
2000
NAME IS abc
SEX IS f
SALARY IS 1234
DOB IS 12/3/2002
NAME IS xyz
SEX IS m
SALARY IS 0
DOB IS 6/3/2000
NAME IS efg
SEX IS m
SALARY IS 2345
DOB IS 22/6/2002
NAME IS hijk
SEX IS f
SALARY IS 23456
DOB IS 23/2/1974
NAME IS bcd
SEX IS m
SALARY IS 123456
DOB IS 2/3/1969
NAME IS stuv
SEX IS f
SALARY IS 123445
DOB IS 5/6/2009
NAME IS defgh
SEX IS f
SALARY IS 12233445
DOB IS 14/12/2007
NAME IS opq
SEX IS f
SALARY IS 123456
DOB IS 17/6/2005
NAME IS shlokasanjayshah
SEX IS f
SALARY IS 45454545
DOB IS 6/3/2000
NAME IS ssshah
SEX IS f
SALARY IS 122334
DOB IS 6/3/2000
*/


