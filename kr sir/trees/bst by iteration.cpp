#include<iostream>
using namespace std;
struct BSTnode{
	BSTnode*lc;
	int data;
	BSTnode *rc;
};
typedef struct BSTnode* BSTptr;

struct queue
   { 
      int size;
      int front;
      int rear;
      BSTptr elements[50];
   };
void enqueue(struct queue &q,BSTptr x)
  {
  	if((q.rear+1)%q.size==q.front)
  	cout<<"stack is full"<<endl;
  	else
     	{
		 q.rear=(q.rear+1)%q.size;
       	 q.elements[q.rear]=x;
    	 if(q.front==-1)
    	 q.front=0;
	   }
  }
  
BSTptr dequeue(struct queue &q)
    {
    	if(q.front!=-1)
        {
		
           if(q.front==q.rear)
	        {int k=q.front;
	          q.front=-1;
	          q.rear=-1;
	          return q.elements[k];
		    }	
          else
          {
      	    int k=q.front;
      	    q.front=(q.front+1)%q.size;
      	     return q.elements[k];
	       }
        }
    else
    cout<<"queue is empty";
  }
void levelorder(queue q,BSTptr T)
{
	enqueue(q,T);
	while(q.front!=-1)
	{
		T=dequeue(q);
		cout<<T->data<<" ";
		if(T->lc!=NULL)
		 enqueue(q,T->lc);
		 if(T->rc!=NULL)
		 enqueue(q,T->rc);
		 
	}
}
void print(BSTptr T)
{
	if(T!=NULL)
	{
		print(T->lc);
		cout<<T->data<<" ";
		print(T->rc);
	}
}
int main()
{ int n,d;
 cout<<"enter the number of nodes in tree"<<endl;
 cin>>n;
 BSTptr T=new BSTnode;
 cout<<"enter the data\n";
   cin>>d;
   T->data=d;
   T->lc=NULL;
   T->rc=NULL;
 
 for(int i=0;i<n-1;i++)
 { 
   BSTptr temp=T;
   cout<<"enter the data\n";
   cin>>d;
    
	while(temp!=NULL)
	{
		if(temp->data>d)
		{if(temp->lc==NULL)
		break;
		temp=temp->lc;}
		
		if(temp->data<d)
		{
		if(temp->rc==NULL)
		break;
		temp=temp->rc;}
	}
	if(temp->lc==NULL)
	{
	temp->lc=new BSTnode;
	temp=temp->lc;}
	if(temp->rc==NULL)
	{
	temp->rc=new BSTnode;
	temp=temp->rc;}
	
	temp->data=d;
	temp->lc=NULL;
	temp->rc=NULL;
	
}
struct queue q;
	q.size=50;
	q.front=-1;
	q.rear=-1;
//	levelorder(q,T);
print(T);
return 0;
	
	
}
