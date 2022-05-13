#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

void rabin_krap(char s1[],char s2[])
{
	int m,n,i,j,p=0,t=0,h,d=256,q=101;
	n=strlen(s1);
	m=strlen(s2);
	h=((int)pow(d,m-1))%q;
	//cout<<h<<"\n";
	for(i=0;i<m;i++)
	{
		p=(d*p+s2[i])%q;
		t=(d*t+s1[i])%q;
	}
	
	for(i=0;i<=n-m;i++)
	{
		cout<<"p :"<<p<<" t :"<<t<<"\n";
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				//cout<<i<<" "<<j<<"\n";
				//cout<<s1[i+j]<<" "<<s2[j]<<"\n\n";
				if(s1[i+j]!=s2[j])
				{
					break;
				}
			}
			if(j==m)
			{
				cout<<"Match found at index: "<<i<<"\n\n";
			}
		}
		
		if(i<n-m)
		{
			//t=(d*(t-s1[i]*h)+s1[i+m])%q;
			//cout<<s1[i]<<" "<<s1[i+m]<<"\n";
			t = (d*(t - s1[i]*h) + s1[i+m])%q; 
			if(t<0)
			{
				t=t+q;
			}
			cout<<t<<"\n";
		}
	}
}

void brendan_rabin_krap(char s1[],char s2[])
{
	int m,n,i,j,p=0,t=0,h,d=256,q=101;
	n=strlen(s1);
	m=strlen(s2);
	//h=((int)pow(d,m-1))%q;
	for(i=0;i<m;i++)
	{
		p=+s2[i];
		t=+s1[i];
	}
	
	for(i=0;i<=n-m;i++)
	{
		cout<<"p :"<<p<<" t :"<<t<<"\n";
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				//cout<<i<<" "<<j<<"\n";
				//cout<<s1[i+j]<<" "<<s2[j]<<"\n\n";
				if(s1[i+j]!=s2[j])
				{
					break;
				}
			}
			if(j==m)
			{
				cout<<"Match found at index: "<<i<<"\n\n";
			}
		}
		
		if(i<n-m)
		{
			//t=(d*(t-s1[i]*h)+s1[i+m])%q;
			//cout<<s1[i]<<" "<<s1[i+m]<<"\n";
			t = t - s1[i] + s1[i+m]; 
			if(t<0)
			{
				t=t+q;
			}
			cout<<t<<"\n";
		}
	}
}

void getarray(char s2[],int lps[])
{
	int i=1,p=0,m;
	m=strlen(s2);
	lps[0]=0;
	while(i<m)
	{
		if(s2[i]==s2[p])
		{
			p++;
			lps[i]=p;
			i++;
		}
		else
		{
			if(p!=0)
			{
				p=lps[p-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMP(char s1[],char s2[])
{
	int m,n,i=0,j=0,*lps;
	n=strlen(s1);
	m=strlen(s2);
	lps=(int*)malloc(sizeof(int)*m);
	getarray(s2, lps);
	while(i<n)
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"Pattern found at index "<<i-j<<"\n";
			j=lps[j-1];
		}
		else if(i<n&&s1[i]!=s2[j])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

void native_match(char s1[],char s2[])
{
	int m,n,i,j;
	n=strlen(s1);
	m=strlen(s2);
	for(i=0;i<=n-m;i++)
	{
		for(j=0;j<m;j++)
		{
			//cout<<i<<" "<<j<<"\n";
			//cout<<s1[i+j]<<" "<<s2[j]<<"\n\n";
			if(s1[i+j]!=s2[j])
			{
				break;
			}
		}
		if(j==m)
		{
			cout<<"Match found at index: "<<i<<"\n\n";
		}
	}
}


int main()
{
	char s1[100],s2[20];
	cout<<"Enter the main string: ";
	gets(s1);
	cout<<"Enter the part to be searched: ";
	gets(s2);
	//cout<<s1<<s2;
	native_match(s1, s2);
	//rabin_krap(s1, s2);
	//KMP(s1, s2);
	return 0;
}
