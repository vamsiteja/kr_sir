#include<iostream>
using namespace std;
struct node
{int data;
struct node*next;
};
struct node1
{
    int data;
    struct node* front;
    struct node* rear;
};typedef struct node1* lptr1;
typedef struct node* lptr;

void addEnd(lptr1 * t,int d)
{
    lptr1 temp=*t;
    temp->front=new node1;
    temp=temp->front;
    temp->data=d;
    temp->front=NULL;
    temp->rear=*t;
    *t=temp;
}

void pushend(lptr *l,int x)
{ 
    lptr t=*l,t2=new node;t2->data=x;t2->next=NULL;
    while(t->next!=NULL)
    t=t->next;   
    t->next=t2;
}
 
 
 void split(lptr *l1,lptr *l2)
 { 
    lptr t1,t2;
    int flag=1;
     for(t1=*l1;t1!=NULL;t1=t1->next)
 	   {
 	   	 for(t2=*l2;t2!=NULL;t2=t2->next)
 	   	 if(t1==t2)
 	   	  {flag=0;break;
			  }
		 if(flag==0)
		 break;
 	   	
	   }
	   lptr temp=*l2;
	while(temp!=t2)
	{  
	   cout<<temp->data;
	   temp=temp->next;
    }
 	
 	
 	
 }
 
 
 
 
 int main()
 { 
 int n,key;lptr l[2],temp[2];
 for(int i=0;i<2;i++)
  {
 
          cout<<"enter the number of nodes u want to enter  "<<endl;cin>>n;
          int d;cout<<"enter the data of linked lists"<<i<<endl;cin>>d;
          l[i]=new node;
		  l[i]->data=d;
		  l[i]->next=NULL;
          for(int j=0;j<n-1;j++)
           {cin>>d;
             pushend(&l[i],d);
            }
    }
 
for(int j=0;j<2;j++)
{
           temp[j]=l[j];
          while(temp[j]->next!=NULL)
          {
             temp[j]=temp[j]->next;
		  }
}
for(int p=0;p<2;p++)
temp[p]->next=l[2];
for(int k=0;k<2;k++)
{      lptr temp=l[k];

cout<<k+1<<"loop is "<<endl;
      while(temp!=NULL)
       {
           cout<<temp->data<<" ";
            temp=temp->next;
		
        } cout<<endl;
}

int N,d;
    lptr1 head=new node,tail;
	cout<<"enter the number of numbers u want to  for circular enter"<<endl;
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
            lptr1 temp=tail;
            tail->front=new node;
            tail=tail->front;
            tail->data=d;
            tail->front=head;
            tail->rear=temp;
            head->rear=tail;
        }
    }
    for(int j=0;j<2;j++)
{
           temp[j]=l[j];
          while(temp[j]->next!=NULL)
          {
             temp[j]=temp[j]->next;
		  }
}
for(int p=0;p<2;p++)
temp[p]->next=head;
temp[0]=l[0];
temp[1]=l[1];
for(int q=0;q<2;q++)
{ int flag=0;
   while(temp[q]!=head && flag==1 )
   {  cout<<temp[q]->data;
      if(temp[q]==head)
      flag=1;
   }
}


return 0;
}

	

