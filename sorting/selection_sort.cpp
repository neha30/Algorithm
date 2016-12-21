//program for selection sort
//Time complexity:
//       			BC(when array is already or almost sorted)   |      WC
// #comparison          n^2										 |      n^2
//#swaps                n                                        |      n^2
//TC=O(n^2) because of comaprison

//algorithm-
//1) find the minimum value in the list
//2) swap it with the vaue in the current position
//3) repeat this process for all the element until entire array will get sorted


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

void selection_sort(int n,int *array)
{
	int i,j,min;

	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(array[j]<array[min])
				min=j;
		}
		swap(&array[i],&array[min]);
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

    selection_sort(n,array);

    print_array(n,array);
    cout<<endl;
	return 0;
}