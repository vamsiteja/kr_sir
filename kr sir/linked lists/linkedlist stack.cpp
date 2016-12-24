#include<iostream>
using namespace std;
typedef
struct node{
	int data;
	struct node*next;
	struct node*rear;
	};
typedef	struct node *lptr;

void push(lptr*s,int d)
{  lptr temp;temp=new node;
    temp->data=d;
    temp->next=NULL;
    temp->rear=NULL;
if(*s==NULL){
	*s=temp;
}
else
{   lptr temp2=*s;
	while(temp2->next!=NULL)
	temp2=temp2->next;
	temp2->next=temp;
	temp->rear=temp2;
	
}}


int pop(lptr *s)
{  if(*s!=NULL)
{
int k;lptr temp=*s,temp2;
  while(temp->next!=NULL)
  temp=temp->next;
  k=temp->data;
  temp2=temp;
  temp=temp->rear;
  temp->next=NULL;
  delete temp2;
  return k;}
  else
  {
  cout<<"stack is empty"<<endl;}
  
}
  	

  	
	

int main()
{    int n,d;lptr s=NULL;
	cout<<"entre the number of elements in the stack";
	cin>>n;cout<<"enter the data into stack";
	for(int i=0;i<n;i++)
	{ cin>>d;
	push(&s,d);
	}
	lptr temp=s;
	while(temp!=NULL)
	{cout<<temp->data<<" ";
	temp=temp->next;
	}
	int x=pop(&s);
	cout<<"pop= "<<x;temp=s;
	while(temp!=NULL)
	{cout<<temp->data<<" ";
	temp=temp->next;
	}
	return 0;
		 
	
}
