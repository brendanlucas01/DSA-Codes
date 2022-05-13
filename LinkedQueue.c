#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
typedef struct node
{
	int data; 
	struct node *next;
}node;


typedef struct 
{
	node *start;
}LL;

void enqueue(LL *ll)
{
	node *p,*q; 
	int i;
	printf("Enter the No to be enqueued\n");
	scanf("%d",&i);
	p=(node *)malloc(sizeof(node));
	p->data=i;
	p->next=NULL;
	if(ll->start==NULL) 
		{
 			ll->start=p;
		}
		else
		{
 			q=ll->start;
			 while(q ->next!=NULL) 
			 {
				q=q->next;
 			 }
 			q->next=p;
		}
	printf("%d has been successfully enqueued\n",i);
}

void display(LL *ll)
{
	node *p;
	int i=0;
	if(ll->start==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	p=ll->start;
	printf("data index\n");
	while(p!=NULL)
	{
	 printf("%d     %d\n",p->data,i++);
	 p=p->next;
	}
	return;
}


void dequeue(LL *ll)
{
	node *p;
	if( ll->start == NULL)
	{
 	printf("Queue is empty");
 	return;
	}
 	p = ll->start;
 	if(ll->start == p)
 	{
 	ll->start = p->next;
	 }
 	printf("%d has been dequeued",p->data);
	 free(p);
}

int main()
{
LL llq;
llq.start=NULL;
int c;
while(1)
{
 printf("\nEnter your choice :\n1.Enqueue a Nunber\n2.Display queue \n3.Dequeue Number\n4.ClearScreen \n5.Exit\n");
 scanf("%d",&c);
 switch(c)
 {
 case 1 : {enqueue(&llq); break;}
 case 2 : {display(&llq);break;}
 case 3 : {dequeue(&llq); break;}
 case 4 : {clrscr();break;}
 case 5 : {printf("Thank You");exit(0);}
 default: {printf("Enter a valid Option\n");break;}
 }
}
return 0;
}
