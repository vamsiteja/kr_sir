#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	struct node *rand;
	struct node*next;
};
typedef struct node *lptr;

void addEnd(lptr* L, int d)
{
    lptr t=*L;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=new node;
    t=t->next;
    t->data=d;
    t->rand=NULL;
    t->next=NULL;
}
void random(lptr*l,int count,int a)
{
	lptr t=*l,t2=*l;count--;a--;
	while(count)
	{   
		t=t->next;
		count--;
	}
	while(a)
	{  
	  t2=t2->next;a--;
	
	}
	t->rand=t2;
	
}
void printrand(lptr *l)
{
	lptr t=*l;
	cout<<t->data<<" ";
	t=t->rand;
	while(t!=NULL && t->rand!=t)
	{ 
	
		cout<<t->data<<" ";
		t=t->rand;
	}
}

int main()
{ int n,d,k,p;
cout<<"enter the number of nodes";
cin>>n;k=n;p=n;
cout<<"enter the data of each node"<<endl;
cin>>d;
lptr l;
l=new node;
l->data=d;
l->next=NULL;
l->rand=NULL;
for(int i=0;i<n-1;i++)
{   cin>>d;
	addEnd(&l,d);
}n=n-1;
	while(n--)
	{ 

	int r=rand()%k+1;
	  
	  random(&l,5-p+1,r);p--;
		
	}
	printrand(&l);
	return 0;
}
