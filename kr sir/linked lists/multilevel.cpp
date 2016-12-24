#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* l1;
	struct node* l2;
	struct node*l3;
};
typedef struct node* lptr;
void create(lptr &l)
{
	int d,a;
	if(l==NULL)
	{
		l=new node;
		l->l1=NULL;
		l->l2=NULL;
		l->l3=NULL;
		cout<<"enter the data"<<endl;
		cin>>a;
		l->data=a;
		cout<<"entre the number of links from this node"<<endl;	
		cin>>d;
		if(d==0)
		return;
		if(d>=1)
		 {cout<<"enter the first link"<<endl;
		 create(l->l1);}
		if(d>=2)
		{cout<<"enter the second branch"<<endl;
		create(l->l2);}
		if(d==3)
		{cout<<"enter the third branch"<<endl;
		create(l->l3);}
		
		 
	}
	else
	{ lptr t=l;
	  while(t->l1!=NULL)
	  t=t->l1;
	  t->l1=new node;
	  t=t->l1;
	  cout<<"enter the data"<<endl;
	  cin>>a;
	  t->data=a;
	  cout<<"entre the number of links from this node"<<endl;	
		cin>>d;
		t->l1=NULL;
		t->l2=NULL;
		t->l3=NULL;
		if(d==0)
		return;
		if(d>=1)
		 {cout<<"enter the first link"<<endl;
		 create(t->l1);}
		if(d>=2)
		{cout<<"enter the second branch"<<endl;
		create(t->l2);}
		if(d==3)
		{cout<<"enter the third branch"<<endl;
		create(t->l3);}
	}
	
}

void print(lptr &l)
{
	lptr t=l;
	if(t!=NULL)
	{ static int count,count1;
	   cout<<t->data<<" ";
	   if(t->l1==NULL && t->l2==NULL && t->l3==NULL)
	   return ;
	  
	   if(t->l1!=NULL)
	   {count++;
	   print(t->l1);
       }
	   
	   if(t->l2!=NULL)
	   {cout<<endl;
	   for(int i=0;i<count+2;i++)
	   cout<<" ";count1=count;
	   print(t->l2);
	   
	   }
	   
	   if(t->l3!=NULL)
	   {cout<<endl;
	   for(int j=0;j<count1+2;j++)
	   cout<<" ";
	   print(t->l3);
	   }
	   cout<<endl;
	}
	else
	return ;
	
}


int main()
{
	lptr l,l1;l=NULL;
	cout<<"start creating multilevel list"<<endl;
	create(l);
	l1=l;
	print(l1);
	
	
	return 0;
	
	
}
