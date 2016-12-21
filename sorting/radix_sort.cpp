//program for radix sort

#include<iostream>
#include "sorting_utilities.h"

using namespace std;

//find the max element from the array
int get_max(int n,int array[])
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]>max)
			max=array[i];
	}

	return max;
}

void counting_sort(int n,int *array,int exp)
{
	int output[n];
	int i,count[10]={0};

	for(i=0;i<n;i++)
		count[(array[i]/exp)%10]++;

	for(i=1;i<10;i++)
		count[i]+=count[i-1];

	for(i=n-1;i>=0;i--)
	{
		output[count[(array[i]/exp)%10]-1]=array[i];
		count[(array[i]/exp)%10]--;
	}

	//copy the ouput array to original array
	for(i=0;i<n;i++)
		array[i]=output[i];
}

void radix_sort(int n,int *array)
{
	//find the maximum number to know the number of digits in it
	int max=get_max(n,array);

	for(int exp=1;max/exp>0;exp*=10)
		counting_sort(n,array,exp);
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

    radix_sort(n,array);

    print_array(n,array);
    cout<<endl;
	return 0;
}