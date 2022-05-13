#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class LCS
{
	//skeleton of LCS class.
public:
	void solve_lcs(string s1,string s2);
	void print_table(int m,int n,int* t1,string str,string s1,string s2);
	
};

int main()
{
	//declaring Variables
	int n,m,i;
	string s1,s2;
	//taking Input from user
	cout<<"Enter the First string\n";
	cin>>s1;
	cout<<"Enter the Second String\n";
	cin>>s2;
	
	
	LCS knap;
	//calling solve function.
	/*if(s1.length()<=s2.length())
	{
		knap.solve_lcss(s1,s2);
	}
	else{
		knap.solve_lcss(s2,s1);
	}*/
	knap.solve_lcs(s1,s2);
}

void LCS::solve_lcs(string s1,string s2)
{
	//declaring variables
	int i,j,count=0,*t1,*t2,row,prevrow,m,n;
	string solvec = "";
	
	m=s1.length();
	n=s2.length();
	//creating tables using malloc
	t1=(int*)malloc(sizeof(int)*(n+1)*(m+1));
	t2=(int*)malloc(sizeof(int)*(n+1)*(m+1));
	
	//creating solution vector.
	//solvec=(int*)malloc(sizeof(int)*(n));
	
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
		
		
		//for columns in tables t1 & t2
		for(j=1;j<=m;j++)
		{
			//if both the chracters are same
			
			if(s1[j-1]==s2[i-1])
			{
				//max(V[i-1,j],V[i-1,j-w]+pft)
				*(t1+row+j) = *(t1+prevrow+(j-1))+1;
				*(t2+row+j) = 1;
			}
			else if(*(t1+row+j-1)>*(t1+prevrow+j))
			{
				
				*(t1+row+j)=*(t1+row+j-1);
				*(t2+row+j)=3;
			}
			else
			{
				//else then fill previous values in the tables.
				*(t1+row+j)=*(t1+prevrow+j);
				*(t2+row+j)=2;
			}
		}
	}
	
	//Calculation for the solution vector
	j=m;
	for(i=n;i>=0;i--)
	{
		for(;j>=0;)
		{
			//cout<<i<<" "<<j;
			if(*(t2+(m+1)*i+j)==1)
			{
				
				j--;
				solvec+=s2[i-1];
				break;
			}
			else if(*(t2+(m+1)*i+j)==2)
			{
				break;
			}
			j--;
		}
	}
	//For printing the values;
	print_table(m,n,t1,"Solution Table/C Table",s1,s2);
	print_table(m,n,t2,"Vector Table/B Table",s1,s2);
	cout<<"\nHere\n1 => diagonal\n2 => vertical\n3 => horizontal\n";
	cout<<"\nSolution Vector is\n[ ";
	for(i=solvec.length()-1;i>=0;i--)
	{
		cout<<solvec[i];
	}
	cout<<" ]";
}

void LCS::print_table(int m,int n,int* t1,string str,string s1,string s2)
{
	//declaring the variables
	int i,j;
	
	//printing the title if table
	cout<<"\n\n";
	cout<<str;
	cout<<endl;
	//printing first string values.
	cout<<"   ";
	for(i=0;i<=m;i++)
	{
		if(i==0)
		{
			cout<<"   ";
		}
		else
		{
			cout<<s1[i-1]<<"  ";
		}
		
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
		if(i==0)
		{
			cout<<"  "<<"| ";
		}
		else
		{
			cout<<s2[i-1]<<"| ";
		}
		for(j=0;j<=m;j++)
		{
			cout<<*(t1+(m+1)*i+j)<<"  ";
			//cout<<*(t2+(m+1)*i+j)<<"  ";
		}
		cout<<"\n";
	}
}
