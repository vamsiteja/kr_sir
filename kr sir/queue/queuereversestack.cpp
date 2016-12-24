#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int element[10];
}q;
void enqueue(queue &q,int x)
{
		if(q.front==-1)
	    q.front=0;
		q.rear==(q.rear+1)%(q.size);
		q.element[q.rear++]=x;
}
int dequeue(queue &q)
{
	int t;
	if(q.front==-1)
	cout<<"empty\n";
	else
	{
		t=q.element[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%(q.size);
		}
		return t;
	}
	
}
struct stack
{
	int size;
	int top;
    int exp[10];
};
stack s;
void push(struct stack &s,int x)
{
	if(s.size-1==s.top)
	cout<<"stack is full\n";
	else
	s.exp[++s.top]=x;
}
int pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"stack is empty\n";
	else
	return s.exp[s.top--];
}
int main()
{
	int n,p,element[10];
	s.top=-1;
	cout<<"enter the number of elements\n";
	cin>>n;
	q.size=n;
	s.size=n;
	cout<<"enter the elements\n";
	for(int i=0;i<n;i++)
	{
	cin>>element[i];
	enqueue(q,element[i]);
	}
	for(int i=0;i<n;i++)
	{
	   p=dequeue(q);
	   cout<<p<<endl;
       push(s,p);
	}
	cout<<"elements of queue are\n";	
		for(int i=0;i<n;i++)
	{
	    p=pop(s);
	    cout<<p<<"\t";
       // enqueue(q,p);
	}
	//cout<<"elements of queue are\n";
   /* for(int i=0;i<n;i++)
	{
	   p=dequeue(q);
       cout<<p;
	} */
}
