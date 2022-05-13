#include <iostream>
#include <cstdlib>
using namespace std;


/*int**/void selectionsort(int *arr,int n)
{
	//Declaring the variables
	int j,i,temp,min,sort;
	//int run=0;
	cout<<"sorting";
	
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
			if(arr[min]>arr[j])
			{
				min=j;
			}
			
			//if the unsorted part of array is in correct order
			if(arr[j-1]<arr[j])
			{
				sort++;
			}
			//run++;
		}
		
		//if min element is not current element, then swap
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
		
		//if after swapping the array is sorted, then break
		if(i+sort+2==n-1||i+sort==n-1)
		{
			break;
		}
	}
//	cout<<run;
//	return arr;
}

int itr_linearsearch(int *a,int n,int target)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==target)
		{
			return i;
		}
	}
	return -1;
}

int itr_binarysearch(int *a,int n,int target)
{
	int low=0,high=n-1,mid;
	selectionsort(a, n);
	while(low<=high)
	{
		mid=(low+high)/2;
		//cout<<"\nlow"<<low<<"		high"<<high<<"		mid"<<mid;
		if(a[mid]==target)
		{
			return mid;
		}
		else if(a[mid]>target)
		{
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}

int rec_binarysearch(int a[],int low,int high,int target)
{
	int mid;
	mid = (low+high)/2;
	//cout<<"\nlow"<<low<<"		high"<<high<<"		mid"<<mid;
	if(low>high)
	{
		return -1;
	}
	else if(a[mid]==target)
	{
		return mid;
	}
	else if(a[mid]>target)
	{
		return rec_binarysearch(a,low,mid-1,target);
	}
	return rec_binarysearch(a,mid+1,high,target);
}

int rec_linearsearch(int *a,int i,int n,int target)
{
	if(a[i]==target)
	{
		return i;
	}
	else if(i==n)
	{
		return -1;
	}
	return rec_linearsearch(a, i+1, n, target);
	
}

void find_min_max(int a[],int low,int high,int *min,int *max)
{
	int minr,minl,maxr,maxl,mid;
	if (low==high)
	{
		*min=*max=a[low];
		//cout<<"low=high";
	}
	else if(low+1==high)
	{
		if(a[low]<a[high])
		{
			*min=a[low];
			*max=a[high];
		}
		else
		{
			*min=a[high];
			*max=a[low];
		}
		//cout<<"low+1=high";
		return;
	}
	else
	{
		//cout<<"else";
		mid=(low+high)/2;
		//cout<<low<<" "<<mid<<" "<<high<<" ";
		find_min_max(a,low,mid,&minl,&maxl);
		find_min_max(a,mid+1,high,&minr,&maxr);
		if(maxr<maxl)
		{
			*max=maxl;
		}
		else
		{
			*max=maxr;
		}
		
		if(minl<minr)
		{
			*min=minl;
		}
		else
		{
			*min=minr;
		}
	}
}

int main(void)
{
	//Declering variables
	int n,*arr,i,target,index,min,max;
	
	//Asking for No. of elements in array
	cout<<"Enter the no of elements in array:-\n";
	cin>>n;
	
	//Creating array of given size using malloc
	arr=(int*)malloc(sizeof(int)*n);
	
	//Taking input of elements of array
	cout<<"Enter the array\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	//cout<<"Enter the target element:-\n";
	//cin>>target;
	//index=itr_linearsearch(arr, n, target);
	//index=itr_binarysearch(arr, n, target);
	//index=rec_linearsearch(arr, 0, n, target);
	//selectionsort(arr, n);
	//index=rec_binarysearch(arr, 0, n-1, target);
	
	//Displaying the final result
	//cout<<"\nIndex of target element:- \n";
	//cout<<index<<" ";
	find_min_max(arr,0,n-1,&min,&max);
	cout<<"min- "<<min<<"\n";
	cout<<"max- "<<max<<"\n";
	return 0;
}
