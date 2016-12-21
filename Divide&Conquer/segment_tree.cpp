//creating segment tree inner nodes is the sum of its child nodes
#include<iostream>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>

using namespace std;

int getMid(int s,int e)
{
	return s+(e-s)/2;
}

//a recursive function to get the min value in a given range of aarray indexes.
//The following are parameters for this function

//st----->pointer to the segment tree
//index-->index of current node in the segment tree.Initially 0 is passed
//        as root is always at index 0.
//ss & se--->starting and ending index of the segment tree represented by the cureent node
//           i.e. st[index]
//qs & qe-->starting and ending index of query range


int MIN_QUERY_UTIL(int st[],int ss,int se,int qs,int qe,int index)
{
	//if segment of this node is a part of given range
	if(qs<=ss &&qe>=se)
		return st[index];

	//if segment of this node is outside the given range
	if(se<qs||ss>qe)
		return INT_MAX;

	//if part of this segment overlaps with the given range
	int mid=getMid(ss,se);
	return min(MIN_QUERY_UTIL(st,ss,mid,qs,qe,2*index+1),MIN_QUERY_UTIL(st,mid+1,se,qs,qe,2*index+2));

}

//return min of elments in range from index qs(query start) to qe(query end)
int MIN_QUERY(int st[],int n,int qs,int qe)
{
	//check for erronoemous input values
	if(qs<0||qe>n-1||qs>qe)
	{
		cout<<"invalid input";
		return -1;
	}

	return MIN_QUERY_UTIL(st,0,n-1,qs,qe,0);
}


//recursive function that construct the segment tree for array[ss..se]
//si is the index of current node in segemnt tree
int constructSTUtil(int array[],int ss,int se,int *st,int si)
{
	//if there is one element in the array,stotre it in the current node 
	//of segement tree
	if(ss==se)
	{
		st[si]=array[ss];
		return array[ss];
	}

	//if there are more then one elements,then recurse for left and right subtrees
	//and store the minimum oftwo values in this node
	int mid=getMid(ss,se);
	st[si]=min(constructSTUtil(array,ss,mid,st,si*2+1),constructSTUtil(array,mid+1,se,st,si*2+2));

	return st[si];
}

int *constructST(int array[],int total)
{
	//height of segment tree
	int x=(int)(ceil(log2(total)));

	//maximum size of the segment tree
	int max_size=2*(int)pow(2,x)-1;

	int *st=new int[max_size];

	//fill the allocated memory
	constructSTUtil(array,0,total-1,st,0);

	//print the segement tree
	cout<<"\nsegment tree is:\n";
	for(int i=0;i<max_size;i++)
		cout<<st[i]<<" ";

	return st;

}

int main(int argc, char const *argv[])
{
	int total;
	int *array;
	int *st;        //pointer to the segment tree array


	cout<<"enter total element:";
	cin>>total;

	array=new int[total];

	cout<<"\nenter elements:\n";
	for(int i=0;i<total;i++)
		cin>>array[i];

	st=constructST(array,total);
	

	int qs,qe;  //starting and ending index of query range
	cout<<"\nenter starting and ending index of query range:";
	cin>>qs;
	cin>>qe;

	cout<<"\nminimum value in this range is: "<<MIN_QUERY(st,total,qs,qe);

	return 0;
}