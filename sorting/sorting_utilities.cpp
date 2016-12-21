#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "sorting_utilities.h"


//function for generating array element
int *generate_array(int n,int r,int *array)
{
	time_t t;
	
	//initilaize random number generator
	srand((unsigned)time(&t));

	for(int i=0;i<n;i++)
		array[i]=rand()%r;

	return array;
}

void print_array(int n,int array[])
{
	std::cout<<"\narray elements are:\n";
	for(int i=0;i<n;i++)
		std::cout<<array[i]<<" ";
}