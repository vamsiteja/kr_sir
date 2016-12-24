#include<iostream>
using namespace std;
int add(int n, int &sum)
{ 
if(n==0)
return sum;
else	
	sum+n%10+add(n/10,sum);
}
int main()
{
	
	int n,sum;
	cout<<"enter the number u want to find the sum of digits"<<endl;
	cin>>n;
	add(n,sum);
	cout<<sum;
	return 0;
}
