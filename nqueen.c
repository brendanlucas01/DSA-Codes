/*************  N-QUEEN PROBLEM *************/
#include<stdio.h>
#include<math.h>

int n=0,col[20]={0},count=0;  
// column array and count getting initialized to zero
void solution()
{
	int i,j;
	for(i=1;i<=n;i++)  
 	/* loop for printing the solution vector  which will show us the placement of all the queens */ 
	{
		for(j=1;j<col[i];j++)
			printf("x\t");
		printf("q%d\t",i);
		for(;j<n;j++)
			printf("x\t");
		printf("\n");
	}
}


int place(int q,int c) 
 /* function will return true or false based on whether the queen is placed or not ; q is the row no. and c is the column no. */
{	
	int k;
	for(k=1;k<=q-1;k++)
	{
		if(c==col[k] || abs(k-q)==abs(col[k]-c))  // checks for (column attack or diagonal attack)
			return 0;
	}
	return 1;
}

void nqueen(int q) 
 /* only row no. is needed to pass as a parameter to nqueen function since queen no. is same as that of the row no. */
{	
	int c,i;
	for(c=1;c<=n;c++)
	{
		if(place(q,c))   // will call the place function 
		{
			col[q]=c;
			if(q==n)   // if all the queens are placed on the chessboard
			{	
				count++;
				printf("\n----------SOLUTION NUMBER : %d¬¬----------\n\n",count);
				// suggests that multiple no. of solutions are possible
				solution(); 
 				// call to solution function to display the result 
			}
			else 
 			/* else not placed then it will call the nqueen function and it will try to place the next queen */ 
				nqueen(q+1);  //function call
		}
	}
}

int main()
{
	input n
	nqueen(1); //place the first queen
}
