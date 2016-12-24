#include<iostream>
using namespace std;
struct node
{int data;
struct node*next;
};
typedef struct node* lptr;
void pushbeg(lptr *l,int x)
     { 
	   lptr t;   
       t=new node;
       t->data=x;
       t->next=*l;
       *l=t;
    }
int main()
{
int d;cout<<"enter the data of linked lists";cin>>d;
lptr l; 
l=new node;
l->data=d;l->next=NULL;
cin>>d;
pushbeg(&l,d);
while(l!=NULL)
{
 cout<<l->data;
 l=l->next;
		
}
return 0;
	
}

