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


int main()
{int n,key,flag=0;
cout<<"enter the number of nodes u want to enter  "<<endl;cin>>n;
int d;cout<<"enter the data of linked lists"<<endl;cin>>d;
lptr l; l=new node;l->data=d;l->next=NULL;
for(int i=0;i<n-1;i++)
{cin>>d;
pushend(&l,d);
}
cout<<"enter the value u want to search:"<<endl;
cin>>key;
while(l!=NULL)
{
 if(l->data==key)
 {cout<<"yes exists"<<endl;flag=1;
 break;
 }
 l=l->next;
		
}
if(flag!=1)
cout<<"doesnot exists";

return 0;
	
}

