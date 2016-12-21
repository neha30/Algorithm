//find the max subarray

#include<iostream>
#include<limits>

using namespace std;

int max_subarray(int array[],int low,int high);
int cross_max_subarray(int array[],int low,int mid,int high);

int main(int argc, char const *argv[])
{
	int total;
	int *array;

	cout<<"enter total array element:";
	cin>>total;

	array=new int[total];

	cout<<"enter array element:\n";
	for(int i=0;i<total;i++)
		cin>>array[i];

	max_subarray(array,0,total-1);
	return 0;
}

int max_subarray(int array[],int low,int high)
{
	int mid;
	int left_sum,right_sum, cross_sum;
    if(low==high)
    	return array[low];
    else 
    {
    	mid=low+high/2;
        left_sum=max_subarray(array,low,mid);
        right_sum=max_subarray(array,mid+1,high);
        cross_sum=cross_max_subarray(array,low,mid,high);

        //finding the max from all three values
        if(left_sum>=right_sum && left_sum>=cross_sum)
        	return left_sum;
        
        if(right_sum>=left_sum&&right_sum>=cross_sum)
        	return right_sum;
        
       	return cross_sum;

    }
}

int cross_max_subarray(int array[],int low,int mid,int high)
{
	int left_sum=-234;	
	int right_sum=-234;
	int sum=0,i;
    

	//go from mid to low side
	for(i=mid;i>=low;i--)
	{
		sum=sum+array[i];
		if(sum>=left_sum)
			left_sum=sum;
	}

	//go from mid to high
	sum=0;
	for(i=mid+1;i<=high;i++)
	{
		sum=sum+array[i];
		if(sum>=right_sum)
			right_sum=sum;
	}
	return left_sum+right_sum;
}






