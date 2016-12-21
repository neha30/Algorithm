//givena set of n points S={p1,p2..pn} where pi-(xi,yi) find the pair of points having smallest distance among all pairs.
struct Point
{
	int x,y;
};


#include<iostream>

using namespace std;

float closest_pair(struct Point *p,int n)
{
	 qsort(p,n,)
}

int main(int argc, char const *argv[])
{
	int total;
	int val1,val2;
	Point *p;

	cout<<"enter total points:";
	cin>>total;

    p=new Point[total];

	cout<<"\nenter points:\n";
	for(int i=0;i<total;i++)
    {
       cin>>val1;
       cin>>val2;
       p[i].x=val1;
       p[i].y=val2;
    }

    int n=sizeof(p)/sizeof(p[0]);

    closest_pair(p,n);
	return 0;
}