#include<iostream>
using namespace std;
int add(int n)
{ static int sum;
if(n==0)
return sum;
else	
	sum=sum+n%10+add(n/10);
}
int main()
{
	
	int n,sum;
	cout<<"enter the number u want to find the sum of digits"<<endl;
	cin>>n;
	sum=add(n);
	cout<<sum;
	return 0;
}
