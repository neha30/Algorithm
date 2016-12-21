//Question: There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after 
//merging the above 2 arrays(i.e. array of length 2n).

#include<iostream>
#include<algorithm>       //it includes the max min function 

using namespace std;

int find_median(int *arr1,int *arr2,int total);
int median(int *arr,int total);


int main(int argc, char const *argv[])
{
	int *arr1;
	int *arr2,total;
	int result;

	cout<<"enter arraystotal element:";
	cin>>total;

    //creating array dynamically
	arr1=new int[total];
	arr2=new int[total];

	cout<<"\nenter array1 element:\n";
	for(int i=0;i<total;i++)
		cin>>arr1[i];

	cout<<"\nenter array2 element:\n";
	for(int i=0;i<total;i++)
		cin>>arr2[i];

    //call function which will find the median
	result=find_median(arr1,arr2,total);
	
	cout<<"\nmedian is: "<<result<<endl;

	return 0;
}

int find_median(int *arr1,int *arr2,int total)
{
	int m1,m2;

	//if no element in array
	if(total<=0)
		return -1;

	//if both array contain one element
	if(total==1)
	    return ((arr1[0]+arr2[0])/2);
	
	//if both array sontain two element then return this    
	if(total==2)
	    return ((max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2);	

	//find the median of both array
	m1=median(arr1,total);
	m2=median(arr2,total);

    //if both the median are same
    if(m1==m2)
    	return m1;

    //median will lie from either from m1 to last element of arr1 or first element of arr2 to m2
    if(m1<m2)
    {
    	if(total%2==0)
    		return find_median(arr1+total/2-1,arr2,total-total/2+1);

    	return find_median(arr1+total/2,arr2,total-total/2);     	
    }

    //m1>m2
    //then median will lie either from first element to m1 of arr1 or m2 to last element of arr2
    if(total%2==0)
    	return find_median(arr1,arr2+total/2-1,total-total/2+1);

    return find_median(arr1,arr2+total/2,total-total/2);


}

//function to get the median of sorted array
int median(int *arr,int n)
{
     if(n%2==0)
     	return ((arr[n]+arr[n-1])/2);

     return (arr[n]/2);
}