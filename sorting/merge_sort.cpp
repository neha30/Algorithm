//program for merge sort

#include<iostream>
#include "sorting_utilities.h"

using namespace std;

void merge(int *array,int low,int mid,int high)
{
	int i=low;   //i is the index of left side of array
	int j=mid+1;  //j is the index of right side of array
	int k=0;  //k is the index of temp array
	int *temp,l;
	int total=mid-low+1+(high-mid);

	temp=new int[total];

	while(i<=mid && j<=high)
	{
		if(array[i]<array[j])
			temp[k++]=array[i++];
		else
			temp[k++]=array[j++];		
	}

	while(i<=mid)
		temp[k++]=array[i++];

	while(j<=high)
		temp[k++]=array[j++];

    int m=0;
	for(l=low;l<=high;l++)
		array[l]=temp[m++];
}

int merge_sort(int *array,int low,int high)
{
	
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(array,low,mid);
		merge_sort(array,mid+1,high);
		merge(array,low,mid,high);
	}
}

int main(int argc, char const *argv[])
{
	int n,r;
	int *array;

	//n will contain total number of elements
	cout<<"enter total array elements:";
	cin>>n;

	cout<<"\nenter range for array values:";
	cin>>r;

	//assign memory for array dynamically
	array=new int[n];

	//call function to generate array element
	array=generate_array(n,r,array);

    //call function for printing the array
    print_array(n,array);

    merge_sort(array,0,n-1);

    print_array(n,array);
	return 0;
}