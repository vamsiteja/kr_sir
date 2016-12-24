#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*next;
};
typedef struct node * lptr;
void enque(lptr *front,lptr *rear,int x){
	lptr temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(*front==NULL && *rear==NULL)
	{*front=temp;
	 *rear=temp;
	 return;
	}
	else
	(*rear)->next=temp;
	*rear=temp;
}
int deque(lptr *front,lptr *rear){
	lptr temp;
	temp=*front;
	if(*front==*rear)
	{
	*front==NULL; *rear==NULL;
	}
	else 
	*front=(*front)->next;
	delete temp;
}
int main()
{
	int n,d;lptr temp;
	cout<<"enter the number of members in queue";
	cin>>n;
	lptr front=NULL,rear=NULL;
	cout<<"enter the data one by one";
	for(int i=0;i<n;i++)
	{cin>>d;
	  enque(&front,&rear,d);
	}
	deque(&front,&rear);
	deque(&front,&rear);temp=front;
	for(int j=0;j<n-2;j++)
	{cout<<temp->data;
	temp=temp->next;
	}
	return 0;
}
