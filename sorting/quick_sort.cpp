//program for quick sort

#include<iostream>
#include "sorting_utilities.h"

using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

int partition(int *array,int low,int high)
{
	int x=array[low];
	int left=low;

	for(int r=low+1;r<=high;r++)
	{
		if(array[r]<=x)
		{
			left++;
			swap(&array[left],&array[r]);
		}
	}
	swap(array[left],array[low]);
}

void quick_sort(int *array,int low,int high)
{
	if(low==high)
		return;
	else
	{
		int m=partition(array,low,high);        //index of pivote element
		quick_sort(array,low,m-1);              //call quick sort on left side
		quick_sort(array,m+1,high); 			//call quick sort on right side
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

    quick_sort(n,array);

    print_array(array,0,n-1);
    cout<<endl;
	return 0;
}