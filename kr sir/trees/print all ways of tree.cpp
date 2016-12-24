#include<iostream>
using namespace std;
struct BSTnode{
	BSTnode*lc;
	int data;
	BSTnode *rc;
};
typedef struct BSTnode* BSTptr;
void insert(BSTptr *T,int k)
{
	if(*T==NULL)
	{
	 *T=new BSTnode;
	 (*T)->data=k;
	 (*T)->lc=NULL;
	 (*T)->rc=NULL;
	}
	else
	{
		if((*T)->data>k)
		insert(&(*T)->lc,k);
		else if((*T)->data<k)
		insert(&(*T)->rc,k);
		 else
		 cout<<"element already exists";
	
	
	}
}
struct queue
   { 
      int size;
      int front;
      int rear;
      int elements[50];
   };
void enqueue(struct queue &q,int x)
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
int dequeue(struct queue &q)
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
void print(BSTptr T,queue q)
{    int flag=-1;
    if(T->lc==NULL && T->rc==NULL)
    {
	cout<<T->data<<endl;
    return ;
	}
	if(T->lc!=NULL)
	{  flag=0;
	cout<<T->data<<" ";
	enqueue(q,T->data);
	print(T->lc,q);
	}
	

	if(T->rc!=NULL)
	{   if(flag==0)
	   {
	   int size1=(q.rear-q.front+q.size)%q.size+1;
		while(--size1)
		{
			int x=dequeue(q);
			cout<<x<<" ";
			enqueue(q,x);
		} flag=1;
		}
		cout<<T->data<<" ";
		print(T->rc,q);
	
	}
}
int main()
{
	int k,d;
  BSTptr T=NULL;
  cout<<"enter the number of nodes"<<endl;
  cin>>d;
  for(int i=0;i<d;i++)
	{   cout<<"enter data\n";cin>>k;
		insert(&T,k);
	}
  struct queue q;
	q.size=50;
	q.front=-1;
	q.rear=-1;
	print(T,q);
	return 0;
	
}
