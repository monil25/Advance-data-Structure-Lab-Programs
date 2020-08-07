/*Question:
NAME : monil dand
ROLL NO: 15
 Imagine an IPL coach is maintaining the records for the all batsman in his team. The data
which he needs is players name, country and his score. The coach can have 10 to 15 standby
batsman. Out of this standby coach needs to identify candidate batsman which can play in the
tournament. The condition for selection is that the batsman has better score than average of
all standby batsman. Write a program such that coach should be able to add new batsman,
remove a batsman, display all batsman, display average score and display list of batsman
who qualify based on condition from list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct batsman
{
        char name[20];
        char country[20];
        int score;
        struct batsman *next;
}bat;
void add(bat **p,char *name,char *country,int score)\
{
	bat *new;
	new=(bat*)malloc(sizeof(bat));
	strcpy(new->name,name);
	strcpy(new->country,country);
	new->score=score;
	new->next=NULL;
	if(*p==NULL)
		*p=new;
	else
	{
		bat *temp=*p;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
}
void rem(bat **p,char *name)
{
	bat *temp=*p,*prev;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			break;
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Batsman not there\n");
		return;
	}
	if(temp==*p)
		*p=temp->next;
	else
		prev->next=temp->next;
	free(temp);
}
void display(bat *p)
{
	int i=1;
	printf("Sr.\tName\t\tCountry\t\tScore\n");
	while(p!=NULL)
	{
		printf("%d:\t%s\t\t%s\t\t%d\n",i,p->name,p->country,p->score);
		p=p->next;
		i++;
	}
}
float average(bat *p)
{
    float avg=0;
    int i=0;
    while(p!=NULL)
    {
        avg=avg+p->score;
        i++;
        p=p->next;
    }
    return avg/i;
}
void qualify(bat *p,float avg)
{
    int i=1;
    printf("The qualified batsman are as follows\n");
    while(p!=NULL)
    {
        if(p->score>avg)
        {
            printf("%d:\t%s\t\t%s\t\t%d\n",i,p->name,p->country,p->score);
            i++;
        }
        p=p->next;
    }
}
int main()
{
        bat *first;
        first=NULL;
        int n,score;
        float avg;
        char name[20],country[20];
        do
        {

            printf("Enter 1 to add a batsman\nEnter 2 to remove a batsman\nEnter 3 to display\nEnter 4 to display average score\nEnter 5 to display list of qualifying batsman\nEnter 0 to exit\n");
            scanf("%d",&n);
            switch(n)
            {
                    case 1:
                        printf("Enter name,country,score\n");
                        scanf("%s%s%d",name,country,&score);
                        add(&first,name,country,score);
                        break;
                    case 2:
                        printf("Enter name\n");
                        scanf("%s",name);
                        rem(&first,name);
                        break;
                    case 3:
                        display(first);
                        break;
                    case 4:
                        printf("The average score is %0.2f\n",average(first));
                        break;
                    case 5:
                        avg=average(first);
                        qualify(first,avg);
                        break;
            }
        }while(n!=0);
        return 0;
}
/*Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
1
Enter name,country,score
monil
india
45
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
1
Enter name,country,score
hey
india
34
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
1
Enter name,country,score
hii
78
45
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
2
Enter name
hii
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
3
Sr.	Name		Country		Score
1:	monil		india		45
2:	hey		india		34
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
4
The average score is 39.50
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
5
The qualified batsman are as follows
1:	monil		india		45
Enter 1 to add a batsman
Enter 2 to remove a batsman
Enter 3 to display
Enter 4 to display average score
Enter 5 to display list of qualifying batsman
Enter 0 to exit
0
*/
