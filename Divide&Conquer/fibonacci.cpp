//program for finding the fibonacci number for given input
//using divide and conquer its time complexity is exponential O(2^n).
//we can reduce its time complexity to linear timt using dunamic programming on which we will work later

#include<iostream>

using namespace std;

int fibonacci(int n);


int main(int argc, char const *argv[])
{
	int num,total;

	cout<<"enter number:";
	cin>>num;

    total=fibonacci(num);
    cout<<"fibonacci of num is: "<<total<<endl;
	return 0;
}

int fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;

	return (fibonacci(n-1)+fibonacci(n-2));
}