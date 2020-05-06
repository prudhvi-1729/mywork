#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define item int
#define MAXSIZE 5
item Q[MAXSIZE];
int front,rear;
int qEmpty()
{
	if(rear==front)
		return 1;
	else
		return 0;
}
void addQ(item x)
{
	Q[rear]=x;
}
item deleteQ()
{
	item x;
	front=(front+1)%MAXSIZE;
	x=Q[front];
	return x;
}
int qFull()
{
	rear=(rear+1)%MAXSIZE;
	if(rear==front)
		if(front==0)
			rear=MAXSIZE-1;
		else
			rear=rear-1;
	else
		return 0;
}
int main()
{
	int x,ch;
	front=rear=0;
	do
	{
		printf("\n 1.INSERTION \n 2.DELETION \n 3.EXIT ");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter element to be inserted : ");
				scanf("%d",&x);
				if(!qFull())
					addQ(x);
				else
					printf("\n Queue is Full.");
				break;
			
			case 2:
				if(!qEmpty())
				{
					deleteQ();
					printf("\n Deleted element : %d\n",x);
				}
				else
					printf("\n Queue is Empty.");
				break;
			
			case 3:
				exit(1);
			
			default:
				printf("\n Please enter right choice.");
		}
	}
	while(ch<=3);
}
