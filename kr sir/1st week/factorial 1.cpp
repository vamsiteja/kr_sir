#include<iostream>
using namespace std;
int factorial(int n)
{if(n==0 ||n==1)
 return 1;
 else return n*factorial(n-1);
}
int main()
{
	
	int n,fact;
	cout<<"enter the factorail number u want"<<endl;
	cin>>n;
	fact=factorial(n);
	cout<<fact;
	return 0;
}
