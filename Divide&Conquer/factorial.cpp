//Program for finding the factorial of a number recursively

#include<iostream>

using namespace std;

int factorial(int num);

int main(int argc, char const *argv[])
{
	int num;
	int total;

	cout<<"enter number:";
	cin>>num;

    total=factorial(num);

    cout<<"factorail is: "<<total<<endl;
	return 0;
}

int factorial(int num)
{
    if(num<=1)
       return 1;
    
    return (num*factorial(num-1));    	
}