//program for couting the inversion in array

#include<iostream>

using namespace std;


int merge_sort(int *array,int n);
int merge_sort_util(int *array,int *temp,int start,int end);
int merge(int *array,int *temp,int start,int mid,int end);

int main(int argc, char const *argv[])
{
	int *array,n;
	int result;

	cout<<"enter total element:";
	cin>>n;

    //creating array dynamically
	array=new int[n];

    cout<<"\nenter array element:\n";
    for(int i=0;i<n;i++)
         cin>>array[i];

    result=merge_sort(array,n); 

    cout<<"\ntotal inversion pairs are:"<<result<<endl;
	return 0;
}

int merge_sort(int *array,int n)
{
    int *temp=new int[n];
    return (merge_sort_util(array,temp,0,n-1));
}

int merge_sort_util(int *array,int *temp,int start,int end)
{
	int mid,inv_count=0;
	if(start==end)
		return inv_count;
    else
    {
    	//inversion count will be the sum of inversin in left and right subtree
     	mid=(start+end)/2;
     	inv_count=merge_sort_util(array,temp,start,mid);
     	inv_count+=merge_sort_util(array,temp,mid+1,end);
     	
     	inv_count+=merge(array,temp,start,mid,end);

    }

    return inv_count;
}

int merge(int *array,int *temp,int start,int mid,int end)
{
	int i,j,k;
	int inv_count=0;

    i=start;     //i is the index of left subarray
    j=mid+1;     //j is the index of right subarray
    k=start;     //k is index of temp array

	while((i<=mid)&&(j<=end))
	{
		if(array[i]<=array[j])
		{
			temp[k]=array[i];
			i++;
			k++;
		}
		else
		{
			inv_count+=mid-i+1;
			temp[k]=array[j];
			k++;
			j++;
		}
	}	

	while(i<=mid)
	{
		
		temp[k]=array[i];
		k++;
		i++;
	}

	while(j<=end)
	{
		
		temp[k]=array[j];
		k++;
		j++;
	}

    cout<<"\ntemp array content:\n";
    //copy the temp array into original array
    for(int l=0;l<=end;l++)
    {
    	cout<<temp[l]<<" "; 
    	array[l]=temp[l];
    }

    cout<<"\nprint inversion count:"<<inv_count<<endl;
	return inv_count;
}