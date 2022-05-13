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


void push(LL *ll)
{
	node *p; 
	int i;
	printf("Enter the No to be entered\n");
	scanf("%d",&i);
	p=(node *)malloc(sizeof(node));
	p->data=i;
	p->next=NULL;
	if(1)
	{
		p->next= ll->start; 
		ll->start=p; 
	}
	printf("%d has been pushed on stack\n",i);
}

void display(LL *ll)
{
	node *p;
	int i=0;
	if(ll->start==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	p=ll->start;
	printf("data index\n");
	while(p!=NULL)
	{
	 printf("%d     %d\n",p->data,i++);
	 p=p->next;
	}
}

void peek(LL *ll)
{
	node *p;
	p=ll->start;
	 printf("Number on top of stack is %d\n",p->data);
}

void pop(LL *ll)
{
	node *p;
	if( ll->start == NULL)
	{
 	printf("Stack is empty");
 	return;
	}
 	p = ll->start;
 	if(ll->start == p)
 	{
 	ll->start = p->next;
	 }
 	printf("%d has been popped",p->data);
	 free(p);
}
 
int main()
{
LL llq;
llq.start=NULL;
int c;
while(1)
{
 printf("\nEnter your choice :\n1.Push on stack\n2.Pop of stack\n3.Display stack \n4.Peek on stack\n5.ClearScreen \n6.Exit\n");
 scanf("%d",&c);
 switch(c)
 {
 case 1 : {push(&llq); break;}
 case 2 : {pop(&llq); break;}
 case 3 : {display(&llq);break;}
 case 4 : {peek(&llq);break;}
 case 5 : {clrscr();break;}
 case 6 : {printf("Thank You");exit(0);}
 default: {printf("Enter a valid Option\n");break;}
 }
}
return 0;
}
