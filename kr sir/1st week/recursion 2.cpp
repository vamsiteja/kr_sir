#include<iostream>
using namespace std;
int febo(int n)
{
	if(n==0 ||n==1)
	return 1;
	else 
	return febo(n-1)+febo(n-2);
	}
	int main()
	{
		int n,f;
		cout<<"enter the nth febonachi nuber u want "<<endl;
		cin>>n;
		f=febo(n);
		cout<<f;
		return 0;
		
		
		
	}
