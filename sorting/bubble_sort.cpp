//Program for bubble sort
//time complexity  BC-O(n)       when input array is already sorted
//                 WC-O(n^2)
//It works by iterating the input array from first element to last,comapring each pair of elements and swapping them if needed.
//Bubble sort contines its iteration until no swaps are needed. 


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

void bubble_sort(int n,int *array)
{
	int i,pass;
	bool flag=true;

	//in every pass traverse the array
	for(pass=0;pass<n&&flag;pass++)
	{
		flag=false;
		for(i=0;i<n-pass;i++)
		{
			if(array[i]>array[i+1])
			{
				swap(&array[i],&array[i+1]);
				flag=true;
			}
		}
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

    bubble_sort(n,array);

    print_array(n,array);
	
	return 0;
}