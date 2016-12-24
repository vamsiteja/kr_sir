#include<iostream>
using namespace std;
struct BSTnode{
	BSTnode*lc;
	int data;
	BSTnode *rc;
};
typedef struct BSTnode* BSTptr;
void insert(int a[],BSTptr& T,int low,int high)
{   if(low>high)
    {T=NULL;
     return;
	}

  else if(high==low )
	{ T=new BSTnode;
	 (T)->data=a[low];
	 (T)->lc=NULL;
	 (T)->rc=NULL;
	 
	}
	else
	{ T=new BSTnode;
	 int mid=(low+high)/2;
	 (T)->lc=NULL;
	 (T)->rc=NULL;
	 (T)->data=a[mid];
	 insert(a,(T)->lc,low,mid-1);
   	 insert(a,(T)->rc,mid+1,high);
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

int main()
{
	int n;
	cout<<"enter the number of elements in sorted array"<<endl;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int low=1,high=n;
	BSTptr T=NULL;
	insert(a,T,low,high);
	cout <<T->data<<endl;
	struct queue q;
	q.size=50;
	q.front=-1;
	q.rear=-1;
	levelorder(q,T);

	return 0;
	
}
