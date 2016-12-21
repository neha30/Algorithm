//program for couting sort
//couting xort assmues that every element is in the range 0 to k
//couting sort determines, for each input element x, the number of elements less than x. It uses this information to place element
// x directly into its position in the output array.

//a[0,,n-1]--->input array
//b[0,n-1]---->hold the sorted output
//c[0,k] ----->provides temporary working storage

#include<iostream>
#include "sorting_utilities.h"

using namespace std;

void couting_sort(int n,int r,int *a)
{
	int *c;
	int *b;

	//this array will hold the output
	b=new int[n];

	//create array dynamicaaly
	c=new int[r+1];

	//initialize array 'c' every element to 0
	for(int i=0;i<r+1;i++)
		c[i]=0;

	//store the count for every element
	//after this c[i] will contain number of elements equal to i
	for(int i=0;i<n;i++)
		c[a[i]]++;

	//after this c[i] will contain number of elements less than or equal to i
	for(int i=1;i<r+1;i++)
		c[i]=c[i]+c[i-1];


	for(int i=n-1;i>=0;i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}

	print_array(n,b);
}

int main(int argc, char const *argv[])
{
	int n,r;
	int *a;

	//n will contain total number of elements
	cout<<"enter total array elements:";
	cin>>n;

	cout<<"\nenter range for array values:";
	cin>>r;

	//assign memory for array dynamically
	a=new int[n];

	//call function to generate array element
	a=generate_array(n,r,a);

    //call function for printing the array
    print_array(n,a);

    couting_sort(n,r,a);

    cout<<endl;
	return 0;
}
