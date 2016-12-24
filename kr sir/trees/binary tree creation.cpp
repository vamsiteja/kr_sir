#include<iostream>
using namespace std;
struct BSTnode{
	BSTnode*lc;
	int data;
	BSTnode *rc;
};
typedef struct BSTnode* BSTptr;
void insert(BSTptr *T,int d)
{   int k;
	if(*T==NULL)
	{
	 *T=new BSTnode;
	 (*T)->data=d;
	 (*T)->lc=NULL;
	 (*T)->rc=NULL;
	}
	cout<<"enter the left node data -1 if nothing"<<endl;
	cin>>k;
	if(k!=-1)
	insert(&(*T)->lc,k);
	cout<<"enter the right node data -1 if nothing"<<endl;
	cin>>k;
	if(k!=-1)
	insert(&(*T)->rc,k);
	
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

struct stack
{
    char top;
    int size;
    int max_size;
    int  elements[10001];
};
void push(stack& s,int  x)
{
    if(s.size==s.max_size)
        return;
    else
    {
        s.size++;
        s.elements[s.size-1]=x;
    }

}
int pop(stack& s)
{
    if(s.size==0)
        return '-1';
    else
    {
        s.size--;
        return s.elements[s.size];
    }
}
void reverse(queue q,BSTptr T,stack s)
{ 
   enqueue(q,T);
   while(q.front!=-1)
    { T=dequeue(q);
     push(s,T->data);
     if(T->rc!=NULL)
     enqueue(q,T->rc);
     if(T->lc!=NULL)
     enqueue(q,T->lc);
    }
  while(s.size!=0)
    { int a=pop(s);
      cout<<a<<" ";
    }
}
int main()
{   int k,d;
  BSTptr T=NULL;
  cout<<"enter the data for root node"<<endl;
  cin>>d;
  insert(&T,d);
  //print(T);
  struct queue q;
	q.size=50;
	q.front=-1;
	q.rear=-1;
	levelorder(q,T);

	stack s;
	s.size=0;
    s.max_size=1000;
    //reverse(q,T,s);
  return 0;
}
  
