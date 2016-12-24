#include<iostream>
#include<string>
using namespace std;
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
int main()
{
	struct queue q;
	q.size=50;
	q.front=-1;
	q.rear=-1;
	
	string str;
	cout<<"input the string "<<endl;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{ 
		enqueue(q,str[i]);
	
	}
	
	
	cout<<endl;
	
	
	while(q.front!=-1)
	{int x=dequeue(q);
	cout<<x<<" ";
	}
	return 0;
	
}
