#include<iostream>
using namespace std;
void snm(int a[],int &sum,int &min,int &max,int i)
{if(i==1)
 {sum=sum+a[i-1];
 if(a[i-1]>max)max=a[i-1];
 if(a[i-1]<min)min=a[i-1];
 }
 else {
 sum=sum+a[i-1];
 if(a[i-1]>max)max=a[i-1];
 if(a[i-1]<min)min=a[i-1];
 snm(a,sum,min,max,i-1);
}
	
}
int main()
{int sum,min,max,n;
cout<<"enter the number of numbers u want to enter"<<endl;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
	cin>>a[i];
	
}
min=a[n-1];
max=a[n-1];sum=0;
snm(a,sum,min,max,n);
cout<<max<<endl<<min<<endl<<sum;
return 0;
}
