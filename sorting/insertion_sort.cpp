//program for insertion sort


#include<iostream>
#include "sorting_utilities.h"

using namespace std;

void insertion_sort(int n,int *array)
{
	int current,i,j;

	for(i=1;i<n;i++)
	{
		current=array[i];
		j=i-1;
		while(j>=0 && current<array[j])
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=current;
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

    insertion_sort(n,array);

    print_array(n,array);
	return 0;
}