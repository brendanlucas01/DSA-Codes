#include <iostream>
#include <cstdlib>
using namespace std;

class item
{// declaring structure of each item
public:
	double weight;
	double profit;
	double ratio;
	int index;
};

class knapsack
{//skeleton of class knapsack
public:
	double* solve_knapsack(int n,int* m,double *profit,item* list);
	
	void sortitems(item *arr,int n);
};

int main()
{
	//declaring variables
	int n,m,i;
	item *itemlist;
	double *items,*sol,profit;
	
	//taking input
	cout<<"Enter the number of items\n";
	cin>>n;
	cout<<"Enter the capacity of knapsack\n";
	cin>>m;
	itemlist=(item *)malloc(sizeof(item )*n);
	cout<<"Enter the items:     w p\n";
	for(i=0;i<n;i++)
	{
		cout<<"wgh & pft of item "<<i+1<<": ";
		cin>>itemlist[i].weight>>itemlist[i].profit;
		
		//calculating ratio of profit/weight
		itemlist[i].ratio=itemlist[i].profit/itemlist[i].weight;
		//setting index
		itemlist[i].index=i+1;
	}
	//Object creation
	knapsack knap;
	
	//sorting array of items
	knap.sortitems(itemlist,n);
	
	//display sorted array
	cout<<"\nSorted Table based on ratio is\n";
	for(i=0;i<n;i++)
	{
		cout<<itemlist[i].index<<") ";
		cout<<itemlist[i].weight<<" ";
		cout<<itemlist[i].profit<<" ";
		cout<<itemlist[i].ratio<<"\n";
	}
	
	//calling solve function to solve problem
	sol = knap.solve_knapsack(n,&m,&profit,itemlist);
	
	//displaying values
	cout<<"\nTotal profit is: "<<profit;
	cout<<"\nRemining capacity is: "<<m;
}

void knapsack::sortitems(item *arr,int n)
{
	//Declaring the variables
	int j,i,min,sort;
	item temp;
	//int run=0;
	
	//First for loop
	for(i=0;i<n-1;i++)
	{
		//Set minimum varible index to current index
		min=i;
		
		//To check if other elements in array are sorted
		sort=0;
		
		//Second for loop
		for(j=i+1;j<n;j++)
		{
			//if current element is less than the min element, then make current element as min
			if(arr[min].ratio<arr[j].ratio)
			{
				min=j;
			}
			
			//if the unsorted part of array is in correct order
			if(arr[j-1].ratio>=arr[j].ratio)
			{
				sort++;
			}
			//run++;
		}
		
		//if min element is not current element, then swap
		//cout<<min<<" "<<sort<<"\n";
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
		
		//if after swapping the array is sorted, then break
		if(i+sort==n-1)
		{
			break;
		}
	}
//	cout<<run;
//	return arr;
}

double* knapsack::solve_knapsack(int n,int* m,double *profit,item* list)
{
	//declaring variables
	int i,count=0;
	double *sol,frac;
	
	//start with 0 profit
	*profit=0;
	
	//check i is less than no of items and sack is not full.
	for(i=0;i<n&&*m>0;i++)
	{
		//if sack capacity is greater than wgt of item i.e. not the last item.
		if(*m>int(list[i].weight))
		{
			count++;
			*profit=*profit + list[i].profit;
			*m = *m - list[i].weight;
		}
		//if sack capacity less or equal to wgt of item then fraction if item will be selected.
		else
		{
			count++;
			*profit=*profit + list[i].ratio*(*m);
			frac = *m/list[i].weight;
			*m = 0;
		}
	}
	
	//create solution array
	sol = (double *)malloc(sizeof(double)*count);
	
	//insert values of solution vector
	for(i=0;i<count-1;i++)
	{
		sol[i]=1;
	}
	sol[count-1]=frac;
	
	//display the solution vector
	cout<<"\nThe solution vector is: \n";
	for(i=0;i<count;i++)
	{
		cout<<sol[i]<<" ";
	}
	return sol;
}
