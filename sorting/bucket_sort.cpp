//program for bucket sort

#include<iostream>
#include "sorting_utilites.h"

void bucket_sort(int n,int *array)
{
	//create n empty bucket
	vector<float> b[n];

	//put array elements in different buckets
	for(int i=0;i<n;i++)
	{
		int bi=n*array[i]; //index in bucket
		b[bi].push_back(array[i]);
	}

	//sort individual buckets
	for(int i=0;i<n;i++)
		sort(b[i].begin(),b[i],end());

	//concatenate all buckets
	int index=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<b[i].size();j++)
				array[index++]=b[i][j];
}

int main(int argc, char const *argv[])
{
	int n,r;
	float *array;

	//n will contain total number of elements
	cout<<"enter total array elements:";
	cin>>n;

	cout<<"\nenter range for array values:";
	cin>>r;

	//assign memory for array dynamically
	array=new float[n];

	//call function to generate array element
	array=generate_array(n,r,array);

	for(int i=0;i<n;i++)
		array[i]=array[i]/100;

    //call function for printing the array
    print_array(n,array);

    bucket_sort(n,array);

    cout<<endl;
	return 0;
}