
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
	
	stack s1;
	s1.top=-1;
	s1.size=50;
	stack s2;
	s2.top=-1;
	s2.size=50;int max=0,x,y,z,a,n;cout<<"enter the number of elements of stack"<<endl;cin>>n;
	cout<<"enter the element in stack"<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>a;
	push(s1,a);
	push(s2,a);
	}
	for(int j=0;j<n-2;j++)
	{ x=pop(s1);y=pop(s1);z=pop(s1);
	  push(s1,z);
	  push(s1,y);
	  if(x+y+z>max)
	  max=x+y+z;
		
	}
		for(int k=0;k<n-2;k++)
	     { x=pop(s2);y=pop(s2);z=pop(s2);
	       push(s2,z);
	        push(s2,y);
	        if(max==x+y+z)
	       {
		      
	         break;}
	
          }
          cout<<"the maximum contigueous sum of numbers is"<<x<<" "<<y<<" "<<z;
   
    return 0;
	
	
	
	
	
}
