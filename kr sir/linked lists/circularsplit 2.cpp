#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* front;
    struct node* rear;
};
typedef struct node*lptr;
void addEnd(lptr* t,int d)
{
    lptr temp=*t;
    temp->front=new node;
    temp=temp->front;
    temp->data=d;
    temp->front=NULL;
    temp->rear=*t;
    *t=temp;
}
int main()
{
	

    int N,d,n,flag=1;
    lptr head=new node,tail,head1,head2;
	cout<<"enter the number of numbers u want to enter for circular node"<<endl;
    cin >>N;

    for(int i=0;i<N;i++)
    {
        cin >>d;
        if(i==0)
        {
            head->data=d;
            head->front=NULL;
            tail=head;
        }
        else if(i<N-1)
        {
            addEnd(&tail,d);
        }
        else if(i==N-1)
        {
            lptr temp=tail;
            tail->front=new node;
            tail=tail->front;
            tail->data=d;
            tail->front=head;
            tail->rear=temp;
            head->rear=tail;
        }
    }
    cout<<"enter the number of nodes for first loop"<<endl;
    cin>>n;
    head1=new node;
    cout<<"enter the data one by one into loop"<<endl;
    cin>>d;
    head1->data=d;
    head1->front=NULL;
    head1->rear=NULL;
    for(int i=0;i<n-1;i++)
    {lptr temp=head1;cin>>d;
    	while(temp->front!=NULL)
    	temp=temp->front;
    	temp->front=new node;
    	temp=temp->front;
    	temp->data=d;
    	temp->rear=NULL;
    	temp->front=NULL;
	}
	
	cout<<"enter the number of nodes for second loop"<<endl;
    cin>>n;
    head2=new node;
    cout<<"enter the data one by one into loop"<<endl;
    cin>>d;
    head2->data=d;
    head2->front=NULL;
    head2->rear=NULL;
    for(int i=0;i<n-1;i++)
    {
	   lptr temp=head2;
	    cin>>d;
    	while(temp->front!=NULL)
    	temp=temp->front;
    	temp->front=new node;
    	temp=temp->front;
    	temp->data=d;
    	temp->rear=NULL;
    	temp->front=NULL;
	}
	lptr temp1=head1,temp2=head2;
	while(temp1->front!=NULL)
	temp1=temp1->front;
	while(temp2->front!=NULL)
	temp2=temp2->front;
	temp1->front=head;
	temp2->front=head;
	temp1=head1;
	temp2=head2;
	//cout<<"hi";
	while(temp1!=NULL && flag!=0 && temp1!=head  )
	{
		if(flag==0 &&temp1==head)
		break;
		if(flag==1 && temp1==head)
		flag=0;
		cout<<temp1->data<<" ";
		temp1=temp1->front;
		
	}
	
	flag=1;
	while( temp2!=NULL && flag!=0 && temp2!=head )
	{   if(flag==0 &&temp2==head)
		break;
		if(flag==1 && temp2==head)
		flag=0;
		cout<<temp2->data<<" ";
		temp1=temp2->front;
		
	}
	
    
    
    
    
    
    
    
    
    
    return 0;}
