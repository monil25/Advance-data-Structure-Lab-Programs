/*
Name:Monil Dand 
FE COMPS,D1
ROLL NO:15
1. Consider a student record with the fields name, rollno and marks. Write a program to write n such student records into a file. Write a function which then reads the file and prints on the console only those records where marks are greater than 50.  (Odd rollnos)*/

#include<stdio.h>
void main()
{       int roll,n,i;					
        char name[10];
        float marks;
        FILE *p1,*p2;				//using the struct FILE include in stdio.h & creating to pointers
        p1 = fopen("file.txt","w");                 //opening file "file.txt" with the mode as write.
        					//or it creates a file named file.txt if it doesnt exist
        printf("Enter thE no. of students:  ");
        scanf("%d",&n);					//taking input of the no of students
        printf("Roll NO:\tName\t\tMarks\n");
        for(i=0;i<n;i++)
        {
                
                scanf("%d%s%f",&roll,name,&marks);			//taking the input of deatails of each student
                fprintf(p1,"%d\t%s\t%.2f\n",roll,name,marks);		//printning it in the file
        }
        fclose(p1);							//closing the file
        p2 = fopen("file.txt","r");		//opening he file with pointer p2 .with the intention to read
   	
   	printf("----------------------------------------\n");
   	printf("The students with marks greater than 50 are:\n");
	printf("Roll NO:\tName\t\tMarks\n");     
        while(fscanf(p2,"%d%s%f",&roll,name,&marks)==3)  //checking if the no of columns exceed 3 and goes to feof
        {       
                float k=50;
                
                if ( marks > k)				//if marks are greater than 50.0 print the details of the student
                 	printf("%d\t\t%s\t\t%.2f\n",roll,name,marks);
        }                
                
        fclose(p2);			//closing the file 
}           

/*
Output:
 gcc exp5.c
arnab@arnab-VirtualBox:~/Desktop/pmds$ ./a.out
Enter the no. of students:  5
Roll NO:	Name		Marks
1	 	a		51
2		b		49
3		c		55
4		d		40
5		e		50
----------------------------------------
The students with marks greater than 50 are:
Roll NO:	Name		Marks
1		a		51.00
3		c		55.00

*/               
        
  


