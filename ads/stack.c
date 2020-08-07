/*
NAME: monil dand, ROLL NO. 15, BATCH: D1, FE COMPS
POSTFIX EVALUATION
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct stack
{
	int k;
	struct stack *next;
};
struct stack* alloc(int a) //allocating memory for struct pointer
{
	struct stack* temp;
	temp = (struct stack*)malloc(sizeof(struct stack));
	temp->k = a;
	return temp;
}
void push (int a, struct stack* *top, struct stack* *bot)                //to store in stack
{
	struct stack* temp;
	 temp = alloc(a);
	if((*bot) == NULL)                                                //first element condition
	{
		
		(*bot) = temp;
		(*bot)->next = NULL;
		(*top) = (*bot);
	}
	else
	{
		(*top)->next  = temp;
		(*top)= temp;
		(*top)->next = NULL; 
		
	}		
}
int pop(struct stack* *top, struct stack* *bot)                         // extracting from stack
{
	struct stack *temp;
	temp = *bot;
	int m = (*top)->k;
	if ((*top)== (*bot))
	{	free(*top);
		*top = NULL;
		*bot = NULL;
	}
	else
	{	while (temp->next != (*top))                            //finding the second elememt from top
		{
			temp = temp->next;
		}
		free((*top));
		(*top)= temp;
		(*top)->next = NULL;
	}
	return m;                                               // returning the extracted value
}

void main()
{
	struct stack *bot = NULL;
	struct stack *top = NULL;

	char a[20];
	printf("Enter the string\n");
	scanf("%s",a);
	int l = strlen(a);                                      //storing length of the string
	                                                        //calc(l,a, &bot, &top );
	int m,n;
	int i = 0;
	for(i = 0; i< l; i++)                                            // loop for accessing every element of string
	{
		if(a[i] >= 48 && a[i]<= 57)                                     //integer check
		{
			push(a[i]- 48, &top, &bot);                             // converting to integer
		}
		else // case for operator
		{
			m = pop(&top, &bot);
			n = pop(&top, &bot);
			switch (a[i])
			{
				case '*' : push(m*n, &top, &bot);
					break;
				case '+' : push(m+n, &top, &bot);
					break;
				case'-':  push(n-m, &top, &bot);
					break;
				case '/': push(n/m , &top, &bot);
					break;	 		 
			}	
		}

	}
	int j = pop(&top, &bot);                                                // accessing the last element
	if (bot == NULL)
	printf("The value of the expression is: %d \n", j);
	else
	printf("The expression cannot be evaluated \n");
}
/*
OUTPUT:
~/Desktop/Arnab21$ ./a.out
Enter the string
45*5-4+
The value of the expression is: 19 
student@CC-Lab-007-U11:~/Desktop/Arnab21$ 



*/








































