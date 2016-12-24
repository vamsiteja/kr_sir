#include<iostream>
using namespace std;
struct node
{int data;
struct node*next;
};
typedef struct node* lptr;

void pushend(lptr *l,int x)
{ lptr t=*l,t2=new node;t2->data=x;t2->next=NULL;
while(t->next!=NULL)
 t=t->next;   
 t->next=t2;
}

void removeDup(lptr*head)
{
    node *after = NULL;
    lptr curr = *head;
    while( curr->next != NULL )
    { after = curr->next; 
       while(after != NULL) 
       {
          if(curr->data == after->data) 
          {
             curr->next = after->next;
             after = after->next; 
          }
          else
          {
             after = after->next;
          }
       }
          curr = curr->next; 
    }
}

int main()
{int n,key,flag=0;
cout<<"enter the number of nodes u want to enter  "<<endl;cin>>n;
int d;cout<<"enter the data of linked lists"<<endl;cin>>d;
lptr l; 
l=new node;
l->data=d;
l->next=NULL;
for(int i=0;i<n-1;i++)
{cin>>d;
pushend(&l,d);
}
removeDup(&l);

while(l!=NULL)
{
 cout<<l->data;
 l=l->next;
		
}
return 0;
}

