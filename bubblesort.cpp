#include <iostream>
#include <cstdlib>
using namespace std;

/*int**/void bubblesort(int *arr,int n)
{
	// Declaring variables
	int j,i,swap,temp;
	
	//First for loop
	for(i=0;i<n-1;i++)
	{
		//setting swap to 0
		swap=0;
		
		//Second for loop
		for(j=0;j<n-i-1;j++)
		{
			//If current element is greater than the next element
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap++;
			}
		}
		
		//If no swapping is done i.e. array is sorted, then break
		if(swap==0)
		{
			break;
		}
	}
//	return arr;
}


/*int**/void selectionsort(int *arr,int n)
{
	//Declaring the variables
	int j,i,temp,min,sort;
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

/*int**/void insertionsort(int *arr,int n)
{
	//Declaring variables
	int j,i,num;
	
	//First for loop
	for(i=0;i<n;i++)
	{
		//Insert current element in sorted array
		num=arr[i];
		
		//assign j to current element index as index counter
		j=i;
		
		//shifting all elements greater than current element.
		while(j>0&&num<arr[j-1])
		{
			//Shift the element to right position
			arr[j]=arr[j-1];
			
			//decrease index counter by 1
			j--;
		}
		
		//place current element at appropriate position
		arr[j]=num;
	}
//	return arr;
}

/*int**/void mergearray(int *arr,int l,int m,int r)
{
	//Declaring variables
	int j,i,num,al1,al2,*temparr1,*temparr2;
	
	//length of array 1
	al1=m-l+1;
	
	//length of array 2
	al2=r-m;
	
	//create array 1 using malloc
	temparr1=(int*)malloc(sizeof(int)*al1);
	
	//create array 2 using malloc
	temparr2=(int*)malloc(sizeof(int)*al2);
	
	//copy all elements of partition into temp array
	for(i=0;i<al1;i++)
	{
		temparr1[i]=arr[l+i];
	}
	for(i=0;i<al2;i++)
	{
		temparr2[i]=arr[m+1+i];
	}
	
	//Set counters for sorting
	i=0;
	j=0;
	num=l;
	
	//Till both arrays are not exhusted
	while(i<al1&&j<al2)
	{
		//If first array element has smaller value
		if(temparr1[i]<temparr2[j])
		{
			arr[num]=temparr1[i];
			i++;
		}
		//If second array value has smaller value
		else
		{
			arr[num]=temparr2[j];
			j++;
		}
		num++;
	}
	
	//if array 2 is exhausted then copy all elements of array 1
	while(i<al1)
	{
		arr[num]=temparr1[i];
		i++;
		num++;
	}
	//if array 1 is exhausted then copy all elements of array 2
	while(j<al2)
	{
		arr[num]=temparr2[j];
		j++;
		num++;
	}
	
	//release the space of temp arrays
	free(temparr1);
	free(temparr2);
//	return arr;
}

/*int**/void mergesort(int *arr,int l,int r)
{
	//Declaring variables
	int m;
	
	//if partition has one or more than one elements
	if(r>l)
	{
		//Find approx middle of array
		m=(r+l)/2;
		//Recursive call for first partition
		mergesort(arr,l,m);
		//Recursive call for second partition
		mergesort(arr,m+1,r);
		//Merge the two partitions
		mergearray(arr, l, m, r);
	}
	
//	return arr;
}

int partition(int *arr,int l,int r)
{
	//Declaring variables
	int pivot,low,high,temp,sort=0,rev_sort=0,i;
	
	//Select first element as pivot element
	pivot=arr[l];
	
	//set low as left index index
	low=l;
	
	//set high as right index
	high=r;
	
	//while low index is less than high
	while(low<high)
	{
		//while greater element than pivot is not found
		while(arr[low]<=pivot&&low<r)
		{
			//check if array is already sorted
			if(arr[low]<=arr[low+1])
			{
				sort++;
			}
			//check if array is sorted in reverse order
			else if(arr[low]>=arr[low+1])
			{
				rev_sort++;
			}
			//increment to next index
			low++;
		}
		//while smaller element than pivot is not found 
		while(arr[high]>pivot&&high>=l)
		{
			//check if array is already sorted
			if(arr[high-1]<=arr[high])
			{
				sort++;
			}
			//check if array is sorted in reverse order
			else if(arr[high-1]>=arr[high])
			{
				rev_sort++;
			}
			//decrement to next index
			high--;
		}
		//two elements of are to be swapped
		if(low<high)
		{
			temp=arr[low];
			arr[low]=arr[high];
			arr[high]=temp;
		}
	}
	//if array is already sorted
	if(sort==r-l+1)
	{
		return -1;
	}
	
	//if array is sorted in reverse order
	if(rev_sort==r-l)
	{
		//Reverse the array
		for(i=0;i<=(r-l)/2;i++)
		{
			temp=arr[l+i];
			arr[l+i]=arr[r-i];
			arr[r-i]=temp;
		}
		return -1;
	}
	//place pivot element in proper position
	//cout<<r<<" "<<l<<"\n";
	arr[l]=arr[high];
	arr[high]=pivot;
	return high;
}

/*int**/void quicksort(int *arr,int l,int r)
{
	//Declaring variables
	int m;
	
	//if partition has one or more than one elements
	if(r>l)
	{
		//Take index of partition
		m=partition(arr, l, r);
		
		//if array is sorted, return
		if(m==-1)
		{
			return;
		}
		
		//Recursive call for first partition
		quicksort(arr,l,m-1);
		
		//Recursive call for second partition
		quicksort(arr,m+1,r);
	}
	
//	return arr;
}

int main(void)
{
	//Declering variables
	int n,*arr,i;
	
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
	
	//Sorting the array
	//arr=bubblesort(arr, n);
	//selectionsort(arr, n);
	quicksort(arr,0,n-1);
	
	//Displaying the final result
	cout<<"\nThe Sorted array is:- \n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
