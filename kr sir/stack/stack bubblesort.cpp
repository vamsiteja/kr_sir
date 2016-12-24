#include<iostream>
using namespace std;

struct stack {
	int size;
	int elements[50];
	int top;
};


void push(struct stack &s,int x)
{if(s.size-1==s.top)
cout<<"stact is full";
else
{	s.top++;
	s.elements[s.top]=x;
}
}



int pop(struct stack &s)
{int k;
	if(s.top==-1)
	{cout<<"stack is empty";return -1;}
	else
	{k=s.top;s.top--;
	return (s.elements[k]);}
	}
	
int main()
{
   stack s1,s2;int n,a,x,y,m;
   s1.top=-1;
	s1.size=50;
	s2.top=-1;
	s2.size=50;
   cout<<"enter the number of elements in bubble sort"<<endl;cin>>n;cout<<"enter the elements"<<endl;
   for(int i=0;i<n;i++)
   {cin>>a;push(s1,a);}
   
  for(int j=0;j<n-1;j++)
   { 
       for(int k=0;k<n-1;k++)
       { x=pop(s1);
       y=pop(s1);
       if(x>y)
         {
		 push(s2,y);
		 push(s1,x);}
        else if(y>x)
		      {
		        push(s2,x);
		        push(s1,y);}	
		}
	
	   for(int l=0;l<n-1;l++)
	        {
			m=pop(s2);
	          push(s1,m);}
	       	
		   
   	
   	
   	
   }
   	
cout<<"the sorted order is :"<<endl; 
for(int p=0;p<n;p++)	
{
	x=pop(s1);
	cout<<x<<" ";
	   } 
	   return 0;  	
	
	
}
