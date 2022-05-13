#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class item
{
	//define structure of item
public:
	double weight;
	double profit;
};

class knapsack
{
	//skeleton of knapsack class.
public:
	void solve_knapsack(int n,int m,item* list);
	void print_table(int m,int n,int* t1,string str);
	
};

int main()
{
	//declaring Variables
	int n,m,i,twgt=0;
	item *itemlist;
	//double *items,*sol,profit;
	
	//taking Input from user
	cout<<"Enter the number of items\n";
	cin>>n;
	cout<<"Enter the capacity of knapsack\n";
	cin>>m;
	
	//creting list of items
	itemlist=(item *)malloc(sizeof(item )*n);
	
	//taking input of items.
	cout<<"Enter the items:     w p\n";
	for(i=0;i<n;i++)
	{
		cout<<"wgh & pft of item "<<i+1<<": ";
		cin>>itemlist[i].weight>>itemlist[i].profit;
		twgt+=itemlist[i].weight;
	}
	if(m<=twgt)
	{
		//creting object of knapsack class
		knapsack knap;
		//calling solve function.
		knap.solve_knapsack(n,m,itemlist);
	}
	else
	{
		cout<<"\nERROR:\nCapacity of Knapsack exceeds weight of items\n\nTry again by re-running";
	}
}

void knapsack::solve_knapsack(int n,int m,item* list)
{
	//declaring variables
	int i,j,count=0,*t1,*t2,*solvec,row,prevrow,wgt,pft;
	double *sol,frac;
	
	//creating tables using malloc
	t1=(int*)malloc(sizeof(int)*(n+1)*(m+1));
	t2=(int*)malloc(sizeof(int)*(n+1)*(m+1));
	
	//creating solution vector.
	solvec=(int*)malloc(sizeof(int)*(n));
	
	//setting all values to 0
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			*(t1+(m+1)*i+j)=0;
			*(t2+(m+1)*i+j)=0;
		}
	}
	
	//for rows in tables t1 and t2.
	for(i=1;i<=n;i++)
	{
		//indices to be moved to reach current & prev row
		row=(m+1)*(i);
		prevrow=(m+1)*(i-1);
		
		//storing weight of current item
		wgt=(int)list[i-1].weight;
		
		//storing profit of current item
		pft=(int)list[i-1].profit;
		
		//for columns in tables t1 & t2
		for(j=1;j<=m;j++)
		{
			//capacity of sack is greater then weight
			if(j>=wgt)
			{
				//max(V[i-1,j],V[i-1,j-w]+pft)
				if(*(t1+prevrow+(j-wgt))+pft>*(t1+prevrow+j))
				{
					//if yes, then update the tables
					*(t1+row+j) = *(t1+prevrow+(j-wgt))+pft;
					*(t2+row+j) = 1;
					/*cout<<prevrow<<"\n";
					cout<<row<<"\n";
					cout<<i<<"\n";
					cout<<j<<"\n";
					cout<<pft<<"\n";
					cout<<"\n\n";
					*/
				}
				else
				{
					//else then fill previous values in the tables.
					*(t1+row+j)=*(t1+prevrow+j);
					*(t2+row+j)=0;
				}
			}
			else
			{//if capacity of sack is less than the weight.
				*(t1+row+j)=*(t1+prevrow+j);
				*(t2+row+j)=0;
			}
		}
	}
	
	//Calculation for the solution vector
	for(i=n,j=m;i>0,j>0;i--)
	{
		solvec[i-1]=*(t2+(m+1)*(i)+j);
		j = j-((int)list[i-1].weight*solvec[i-1]);
	}
	
	//For printing the values;
	print_table(m,n,t1,"V/Profit Table");
	print_table(m,n,t2,"Keep Table");
	cout<<"\nSolution Vector is\n[ ";
	for(i=0;i<n;i++)
	{
		cout<<solvec[i]<<"  ";
	}
	cout<<"]";
}

void knapsack::print_table(int m,int n,int* t1,string str)
{
	//declaring the variables
	int i,j;
	
	//printing the title if table
	cout<<"\n\n";
	cout<<str;
	cout<<endl;
	//printing sack weight values.
	cout<<"   ";
	for(i=0;i<=m;i++)
	{
		cout<<i<<"  ";
	}
	cout<<endl;
	cout<<" ";
	cout<<"---";
	for(i=0;i<=m;i++)
	{
		cout<<"---";
	}
	cout<<endl;
	
	//printing the table
	for(i=0;i<=n;i++)
	{
		cout<<i<<"| ";
		for(j=0;j<=m;j++)
		{
			cout<<*(t1+(m+1)*i+j)<<"  ";
			//cout<<*(t2+(m+1)*i+j)<<"  ";
		}
		cout<<"\n";
	}
}
